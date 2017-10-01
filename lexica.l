%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM (-)?{DIGITO}+
REAL (-)?{NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"char"		{return TK_TIPO_CHAR;}

"bool"		{return TK_TIPO_BOOL;}

"string"	{return TK_TIPO_STRING;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.label = yytext; return TK_NUM; }
{REAL}		{ yylval.label = yytext; return TK_REAL;}
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
