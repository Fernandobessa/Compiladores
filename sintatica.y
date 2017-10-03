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
string get_var_tipo(int);
atributos arith_com_cast(int, string, int, string, string);
int typeOfArith(int, int);
atributos arith(atributos, atributos, string);
%}

%token TK_NUM TK_REAL TK_STRING
%token TK_MAIN TK_ID TK_TIPO_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
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
			// | ATRIB
			// {
			// 	$$ = $1;
			// }
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

				variavel v = criadorDeVariavel($1.label, nome, tipo_v, 0);

				// addVarEsc(tack, v);

				cout << " ->>>> " << tack->v[0][$1.label].var_name << endl;
				cout << " ->>>> " << tack->v[0][$1.label].temp_name << endl;
				cout << " ->>>> " << tack->v[0][$1.label].tipo << endl;


				// $$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";
				$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";
					 
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
			| TK_STRING
			{
				$$.tipo = TK_TIPO_STRING;

				string nome = gerar_nomes_var();
				$$.traducao = "\tstrcpy( " + nome + " , " + $1.label + " );\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, get_var_tipo($$.tipo), $1.label.size() - 2);
				// [to-do] checar isso $1.label.size() - 2

			}
			| TK_ID
			{
				$$.traducao = $1.traducao;
			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

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

string get_var_tipo(int tipo){

	if (tipo == TK_TIPO_INT)
		return "int";
	if (tipo == TK_TIPO_FLOAT)
		return "float";
	if (tipo == TK_TIPO_CHAR)
		return "char";
	if (tipo == TK_TIPO_BOOL)
		return "bool";
	if (tipo == TK_TIPO_STRING)
		return "string";

	return "";
}	

int typeOfArith(int t1, int t2){

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
	}

	atributos turn;
	turn.traducao = line + line2;
	turn.label = nomeReal;
	return turn;

}

atributos arith(atributos a1, atributos a2, string sinal){
	
	atributos ss;
	ss.tipo = typeOfArith(a1.tipo, a2.tipo);
	

	// sem precisar cast
	if (a1.tipo == a2.tipo)
	{
		string nome = gerar_nomes_var();
		
		ss.traducao = a1.traducao + a2.traducao + "\t" + nome + " = " + a1.label + " " + sinal + " " + a2.label + ";\n";
	
		ss.label = nome;
	}
	else{ // CASTando

		// fazer o cast dependendo do tipo
		atributos atr = arith_com_cast(a1.tipo, a1.label, a2.tipo, a2.label, sinal);
		atr.tipo = ss.tipo;

		ss.traducao = a1.traducao + a2.traducao + atr.traducao;
	
		ss.label = atr.label;
	}
	

	return ss;
}	




