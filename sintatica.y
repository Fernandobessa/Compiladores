%{
#include <iostream>
#include <string>
#include <sstream>
#include "variaveis.h"

#define YYSTYPE atributos

using namespace std;


struct atributos
{
	string label;
	string traducao;
	int tipo;
};

// Variaveis Planistas
string error_msg = "Wubba Lubba Dub Dub";

maps* tack = criarMaps();
varsDeclaradas varsDec;

// Functions
int yylex(void);
void yyerror(string);
string declararVars();
variavel criadorDeVariavel(string, string, string, int);
string gerar_nomes_var();
int get_var_tipo_token(string);
string get_var_tipo(int);
atributos logic(int, string, int, string, string);
atributos arith_com_cast(int, string, int, string, string);
int typeOfArith(int, int);
atributos arith(atributos, atributos, string);
variavel get_var(string);
%}

%token TK_NUM TK_REAL TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
%token TK_EQUAL TK_GTE TK_LTE TK_NEQUAL
%token TK_AND TK_OR TK_NOT
%token TK_FIM TK_ERROR

// ordem das operacoes?! bottom -> up	
%start S
%left '+' '-'
%left '*' '/'
%right '='

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << declararVars() << "\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			| // vazio
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| DECLARATION ';'
			{
				$$ = $1;

				cout << "AQUIII ________ \n" << "Label: " << $1.label << "\nTrad: " << $1.traducao << "\n ACABOUU ---" <<endl; 
			}
			| ATRIB ';'
			{
				$$ = $1;
			}
			;

DECLARATION	: TIPO VARLIST
			{
				$2.tipo = $1.tipo;
				$$.traducao = $1.traducao + $2.traducao;

				// cout << "AQUIII ________ \n" << "Label: " << $$.label << "\nTrad: " << $$.traducao << "\n ACABOUU ---" <<endl; 

			}
			;

TIPO 		: TK_TIPO_INT
			{
				$$.tipo = TK_TIPO_INT;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_FLOAT
			{
				$$.tipo = TK_TIPO_FLOAT;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_CHAR
			{
				$$.tipo = TK_TIPO_CHAR;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_BOOL
			{
				$$.tipo = TK_TIPO_BOOL;
				$$.traducao = $1.traducao;
			}
			| TK_TIPO_STRING
			{
				$$.tipo = TK_TIPO_STRING;
				$$.traducao = $1.traducao;
			}
			// isso seria pra declarar variavel sem o tipo antes do nome da mesma [to-do], rever isso
			| TK_TIPO_VAR
			{
				$$.traducao = $1.traducao;
			}
			;

VARLIST 	: VARLIST ',' TK_ID
			{
				cout << "VARLIST, TK_ID _______" <<endl;

				string nome = gerar_nomes_var();
				$$.traducao = $1.traducao + $3.traducao;

				variavel v = criadorDeVariavel($3.label, nome, get_var_tipo($0.tipo), 0);
				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->v[0][$3.label].var_name << endl;
				// cout << " ->>>> " << tack->v[0][$3.label].temp_name << endl;
				// cout << " ->>>> " << tack->v[0][$3.label].tipo << endl;

			}
			| VARLIST ',' ATRIB
			{
				// verificar [to-do] tudo
				$$.traducao = $1.traducao + $3.traducao;

				$1.tipo = $0.tipo;
				$3.tipo = $0.tipo;

			}
			| TK_ID '=' E	
			{	
				

				cout << "TK_ID = E_______ " << $1.label <<endl;
				string nome = gerar_nomes_var();
				// inferir tipo
				string tipo_v = "";

				// se o tipo foi dito -> int x = 9
				if (get_var_tipo($0.tipo) != "")
				{	
					// cout << "1" << endl;
					tipo_v = get_var_tipo($0.tipo);
				}
				else // se tipo nao foi dito -> x = 9
				{
					// cout << "2" << endl;
					// cout << $3.tipo << endl;

					tipo_v = get_var_tipo($3.tipo);
				}

				// tipo da expressao = bool e tipo da variavel nao for bool
				if ($3.tipo == TK_TIPO_BOOL && tipo_v != "bool")
				{
					cout << error_msg << endl;
					exit(0);
				}


				variavel v = criadorDeVariavel($1.label, nome, tipo_v, 0);

				// addVarEsc(tack, v);

				cout << " ->>>> " << tack->v[0][$1.label].var_name << endl;
				cout << " ->>>> " << tack->v[0][$1.label].temp_name << endl;
				cout << " ->>>> " << tack->v[0][$1.label].tipo << endl;

				cout << " ->>>> " << get_var_tipo($3.tipo) << endl;


				cout << " ->>>> " << get_var($1.label).var_name << endl;
				cout << " ->>>> " << get_var($1.label).temp_name << endl;
				cout << " ->>>> " << get_var($1.label).tipo << endl;


				variavel minha_var = get_var($1.label);

				// variavel com tipo diferente da expressao
				if (minha_var.tipo != get_var_tipo($3.tipo))
				{
					string nomeReal = gerar_nomes_var();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					$$.traducao = $1.traducao + $3.traducao; 
					$$.traducao += "\t" + nome + " = (" + minha_var.tipo + ") " + $3.label +";\n";
					$$.traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, minha_var.tipo, 0);
				}
				else{ // se o tipo eh igual

					$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";

				}
				



					 
			}
			| TK_ID
			{
				cout << "TK_ID _______" <<endl;

				// tipo nome_var;
				$$.traducao = $1.traducao;
				$$.label = $1.label;

				variavel v = criadorDeVariavel($$.label, gerar_nomes_var(), get_var_tipo($0.tipo), 0);

				// cout << v.var_name << endl;

				// addVarEsc(tack, v);

				// for (int i = 0; i < tack->v.size(); ++i)
				// {
					cout << " ->>>> " << tack->v[0][$$.label].var_name << endl;
					cout << " ->>>> " << tack->v[0][$$.label].temp_name << endl;
					cout << " ->>>> " << tack->v[0][$$.label].tipo << endl;
					 
				// }

			}
			;

ATRIB 		: TK_ID '=' E
			{
				variavel v = get_var($1.label);
				string nome = v.temp_name;

				



				// variavel nao existe
				if (nome == "")
				{
					string tipo_v;

					nome = gerar_nomes_var();


					// cout << get_var_tipo($-2.tipo) << endl;

					// cout << get_var_tipo($3.tipo) << endl;

					// $-2 pois pra chegar em ATRIB eu vim por VARLIST de DECLARATION
					// se vier direto de COMANDO deve ser $0
					if (get_var_tipo($-2.tipo) != "")
					{	
						tipo_v = get_var_tipo($-2.tipo);
						cout << "1" << endl;
					}
					else // se tipo nao foi dito -> x = 9
					{
						tipo_v = get_var_tipo($3.tipo);
						cout << "2" << endl;
						
					}

					// tipo da expressao = bool e tipo da variavel nao for bool
					if ($3.tipo == TK_TIPO_BOOL && tipo_v != "bool")
					{
						cout << error_msg << endl;
						exit(0);
					}

					v = criadorDeVariavel($1.label, nome, tipo_v, 0);



				}
				else{
					// if (get_var_tipo($0.tipo) != "")
					// {	
					// 	tipo_v = get_var_tipo($0.tipo);
					// 	cout << "1" << endl;
					// }
					
					if ($3.tipo == TK_TIPO_BOOL && v.tipo != "bool")
					{
						cout << error_msg << endl;
						exit(0);
					}
				}




				if (v.tipo != get_var_tipo($3.tipo))
				{
					string nomeReal = gerar_nomes_var();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					$$.traducao = $1.traducao + $3.traducao; 
					$$.traducao += "\t" + nome + " = (" + v.tipo + ") " + $3.label +";\n";
					$$.traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, v.tipo, 0);
				}
				else{ // se o tipo eh igual

					$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";

				}

				cout << "TA AQUI2" << endl;




			}
			;

E 			: '(' E ')'
			{
				$$ = $2;
			}
			| '-'E
			{
				$$.tipo = $2.tipo;

				string nome = gerar_nomes_var();
				// temp(x+1) = -temp(x); usa -temp(x)
				// $$.label = "-" + $2.label; 
				// temp(x+1) = -temp(x); usa temp(x+1)
				$$.label = nome;

				$$.traducao = $2.traducao + "\t" + nome + " = -" + $2.label + ";\n";

				variavel v = criadorDeVariavel(nome, nome, get_var_tipo($$.tipo), 0);

				 

			}
			| E '-' E
			{
				$$ = arith($1, $3, "-");
			}
			| E '+' E
			{
				$$ = arith($1, $3, "+");
			}
			| E '*' E
			{
				$$ = arith($1, $3, "*");
			}
			| E '/' E
			{
				$$ = arith($1, $3, "/");
			}
			| E '>' E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, ">");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E '<' E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, "<");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_GTE E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, ">=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_LTE E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, "<=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_EQUAL E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, "==");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_NEQUAL E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = logic($1.tipo, $1.label, $3.tipo, $3.label, "!=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_AND E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = gerar_nomes_var();

				$$.traducao = $1.traducao + $3.traducao + "\t" + ;

				$$.label = nome;
			}
			| E TK_OR E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = gerar_nomes_var();

				$$.traducao = $1.traducao + $3.traducao + "\t" + ;

				$$.label = nome;
			}
			| TK_NOT E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = gerar_nomes_var();

				$$.traducao = $1.traducao + $3.traducao + "\t" + ;

				$$.label = nome;
			}
			| TK_NUM
			{
				$$.tipo = TK_TIPO_INT;

				string nome = gerar_nomes_var();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, get_var_tipo($$.tipo), 0);

			}
			| TK_REAL
			{
				$$.tipo = TK_TIPO_FLOAT;

				string nome = gerar_nomes_var();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, get_var_tipo($$.tipo), 0);

			}
			| TK_CHAR
			{
				$$.tipo = TK_TIPO_CHAR;

				string nome = gerar_nomes_var();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, get_var_tipo($$.tipo), 0);
				// [to-do] checar isso $1.label.size() - 2

			}
			| TK_ID
			{
				variavel v = get_var($1.label);


				// verifica se variavel existe
				if (v.var_name == "")
				{
					cout << error_msg << endl;
					exit(0);
				}
				else{
					$$.traducao = $1.traducao;
					$$.label = v.temp_name;
					$$.tipo = get_var_tipo_token(v.tipo);
				}

				cout << "TA AQUI" << endl;
				cout << v.var_name << endl;

			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	for (int i = 0; i < varsDec.size(); ++i)
	{
		cout << " ->>>> " << get_var(varsDec[i].var_name).var_name << endl;
		cout << " ->>>> " << get_var(varsDec[i].var_name).temp_name << endl;
		cout << " ->>>> " << get_var(varsDec[i].var_name).tipo << endl;
	}

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string declararVars(){
	return getDeclaradas(varsDec);
}
variavel criadorDeVariavel(string nome, string temp_nome, string tipo, int tamanho){
	variavel v = criarVar(nome, temp_nome, tipo, tamanho);
	addVarEsc(tack, v);
	varsDec.push_back(v);

	return v;
}

string gerar_nomes_var(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "temp_" + to_string(num_para_gerar_nomes++);
}

int get_var_tipo_token(string tipo){

	if (tipo == "int")
		return TK_TIPO_INT;
	if (tipo == "float")
		return TK_TIPO_FLOAT;
	if (tipo == "char")
		return TK_TIPO_CHAR;
	if (tipo == "bool")
		return TK_TIPO_BOOL;
	// if (tipo == "string")
	// 	return TK_TIPO_STRING;

	return 0;
}

string get_var_tipo(int tipo){

	if (tipo == TK_TIPO_INT)
		return "int";
	if (tipo == TK_TIPO_FLOAT)
		return "float";
	if (tipo == TK_TIPO_CHAR)
		return "char";
	if (tipo == TK_TIPO_BOOL)
		return "bool";
	// if (tipo == TK_TIPO_STRING)
	// 	return "string";

	return "";
}

atributos logic(int t1, string atr1_label, int t2, string atr2_label, string sinal){

	atributos retorno;
	// o retorno de uma expressao logica deve ser bool
	retorno.tipo = TK_TIPO_BOOL;
	string nome = gerar_nomes_var();

	// usando a mesma da arith, depois devo mudar pra uma tabela [to-do]
	int tipo_das_entradas = typeOfArith(t1, t2);

	if (tipo_das_entradas == TK_TIPO_INT)
	{
		retorno.label = nome;

		retorno.traducao = "\t" + nome + " = " + atr1_label + " " + sinal + " " + atr2_label + ";\n";

		// tipo da variavel deve ser do tipo int por ser um bool, ou deve ser o tipo da tipo_das_entradas? [to-do]
		variavel v =  criadorDeVariavel(nome, nome, get_var_tipo(tipo_das_entradas), 0);
	}
	else if(tipo_das_entradas == TK_TIPO_FLOAT){

		string nomeReal = gerar_nomes_var();
		
		retorno.label = nomeReal;

		// variavel usada pra fazer o cast pra float
		variavel v =  criadorDeVariavel(nome, nome, "float", 0);
		// int por ser bool? [to-do]
		v =  criadorDeVariavel(nomeReal, nomeReal, "int", 0);

		if (t1 == TK_TIPO_INT)
		{
			retorno.traducao = "\t" + nome + " = (float) " + atr1_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (t2 == TK_TIPO_INT)
		{	
			retorno.traducao = "\t" + nome + " = (float) " + atr2_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nomeReal + ";\n";
		}

	}




	return retorno;


}

int typeOfArith(int t1, int t2){

	// verificando com if, deveria ter uma tabela, fazer depois por demandar mais tempo

	if ( (t1 != TK_TIPO_FLOAT && t1 != TK_TIPO_INT) || (t2 != TK_TIPO_FLOAT && t2 != TK_TIPO_INT) )
	{
		// tipo de operadores invalidos
		cout << error_msg << endl;
		exit(0);

	}

	if (t1 == TK_TIPO_FLOAT || t2 == TK_TIPO_FLOAT)
	{
		return TK_TIPO_FLOAT;
	}
	else{
		return TK_TIPO_INT;
	}
}

atributos arith_com_cast(int tipo1, string atr1_label, int tipo2, string atr2_label, string sinal){

	int tipo_atual = typeOfArith(tipo1, tipo2);

	string line = "", line2 = "";

	string nome = gerar_nomes_var();
	string nomeReal = gerar_nomes_var();

	// devo castiar
	if (tipo_atual == TK_TIPO_FLOAT)
	{
		
		if (tipo1 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr1_label + ";\n";
			line2 = "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (tipo2 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr2_label + ";\n";
			line2 = "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nome + ";\n";
		}

		variavel v = criadorDeVariavel(nome, nome, get_var_tipo(tipo_atual), 0);
		v = criadorDeVariavel(nomeReal, nomeReal, get_var_tipo(tipo_atual), 0);

	}

	atributos turn;
	turn.traducao = line + line2;
	turn.label = nomeReal;
	return turn;

}

atributos arith(atributos a1, atributos a2, string sinal){
	
	atributos retorno;
	retorno.tipo = typeOfArith(a1.tipo, a2.tipo);
	

	// sem precisar cast
	if (a1.tipo == a2.tipo)
	{
		string nome = gerar_nomes_var();
		
		retorno.traducao = a1.traducao + a2.traducao + "\t" + nome + " = " + a1.label + " " + sinal + " " + a2.label + ";\n";
	
		retorno.label = nome;

		variavel v = criadorDeVariavel(nome, nome, get_var_tipo(retorno.tipo), 0);

	}
	else{ // CASTando

		// fazer o cast dependendo do tipo
		atributos atr = arith_com_cast(a1.tipo, a1.label, a2.tipo, a2.label, sinal);
		atr.tipo = retorno.tipo;

		retorno.traducao = a1.traducao + a2.traducao + atr.traducao;
	
		retorno.label = atr.label;
	}
	

	return retorno;
}	


variavel get_var(string name){

	return tack->v[tack->escopo_num][name];
}




