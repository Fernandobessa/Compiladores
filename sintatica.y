%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;


struct atributos
{
	string label;
	string traducao;
};

int yylex(void);
void yyerror(string);
string gerar_nomes_var();
%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			|
			;

COMANDO 	: E ';'
			;

E 			: E '+' E
			{
				string nome = gerar_nomes_var();
				$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $1.label + " + " + $3.label + ";\n";
				$$.label = nome;
			}
			| TK_NUM
			{
				string nome = gerar_nomes_var();
				$$.traducao = "\t" + nome + " = " + $1.traducao + ";\n";
				$$.label = nome;
			}
			| TK_ID
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

string gerar_nomes_var(){
	static int num_para_gerar_nomes = 0;
	string nome;
	nome = "temp_" + to_string(num_para_gerar_nomes);

	num_para_gerar_nomes++;
	return nome;
}		
