#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// variavel
typedef struct variavel
{
	string tipo;
	string var_name;
	string temp_name;

} variavel;

// tabela de variaveis
typedef map <string, variavel> Var_table;

typedef struct maps
{
	vector< Var_table > v;
	int escopo_num;
} maps;

void pushEsc(maps *tack, Var_table mapEsc){

	tack->v.push_back(mapEsc);
	tack->escopo_num += 1; // somando um pra indicar que adicionei e fui pro proximo escopo, 0 = global

}

Var_table popEsc(maps *tack)
{
	if(tack->v.empty()){
		cout << "Sem escopo pra remover :(" <<endl;
		exit(0);
	}

	// se tiver o que remover
	Var_table esc = tack->v.back();
	tack->v.pop_back();
	tack->escopo_num -= 1;

	return esc;
}

variavel criarVar(string nome, string temp_nome, string tipo){
	
	variavel var;
	var.tipo = tipo;
	var.var_name = nome;
	var.temp_name = temp_nome;

	return var;
}

maps* criarMaps(){

	maps *tack = (maps*) malloc(sizeof(maps));

	Var_table esc;

	pushEsc(tack, esc);
	// voltando pro escopo global, ja que a push adiciona 1 em escopo_num
	tack->escopo_num = 0;

	return tack;
}

void addVarEsc(maps *tack, variavel var){

	tack->v[tack->escopo_num][var.var_name] = var;
}

void addVarEscGlobal(maps *tack, variavel var){

	tack->v[0][var.var_name] = var;
}