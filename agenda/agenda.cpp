#include <iostream>
#include <stdlib.h>
#include <string>
#include "agenda.hpp"

using namespace std;

void redirecionar(int escolha, Agenda* cadastro){
	
    system(CLEAR);
    
	switch(escolha)
	{
	case 1: cadastroAniversariante(cadastro);
		break;
	case 2: excluirAniversariante(cadastro);
		break;
	case 3: alterarData(cadastro);
		break;
	case 4: consultaAniversariantesData(cadastro);
		break;
	case 5: consultaAniversariantesMes(cadastro);
		break;
	case 6: consultaAniversariantesLetra(cadastro);
		break;
	case 7: mostrarOrdemAlfabetica(cadastro);
		break;
	case 8: mostrarOrdemMes(cadastro);
		break;
	default: exit(0);
	}
}

void cadastroAniversariante(Agenda* cadastro){
	for (int i = cadastro->aniversariantesCadastrados; i < 1000; i++) {
		cout <<"***** CADASTRAR ******\n";
		cout <<"Nome: ";
		cin >> cadastro->nome[i];
		cout <<"Email: ";
		cin >> cadastro->email[i];
		cout <<"Dia: ";
		cin >> cadastro->dia[i];
		cout <<"Mês: ";
		cin >> cadastro->mes[i];
		cout <<"Ano: ";
		cin >> cadastro->ano[i];
		
		int dia = cadastro->dia[i];
		int mes = cadastro->mes[i];
		int ano = cadastro->ano[i];
		bool verifica = verificaData(dia, mes, ano);

		system(PAUSE);

		if (verifica) {
			cadastro->aniversariantesCadastrados++;
            break;
		}
	}
}

void excluirAniversariante(Agenda* cadastro) {

	string nome;
	
	cout << "***** Excluir Aniversariante *****\n";
	cout << "Nome: ";
	cin >> nome;

    //Laço que realiza a exclusão de pessoas da agenda
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++){
		if(cadastro->nome[i] == nome){
			for(int j=i+1; j < cadastro->aniversariantesCadastrados; j++){
				cadastro->nome[i] = cadastro->nome[j];
                cadastro->email[i] = cadastro->email[j];
                cadastro->dia[i] = cadastro->dia[j];
                cadastro->mes[i] = cadastro->mes[j];
                cadastro->ano[i] = cadastro->ano[j];
                cadastro->aniversariantesCadastrados--;
			}
		}
	}
	
	system(PAUSE);
}

void alterarData(Agenda* cadastro){
	
	string nome;
	
	cout << "***** Alterar Data de Aniversário *****\n";
	cout << "Nome: ";
	cin >> nome;

	for (int i=0; i < cadastro->aniversariantesCadastrados; i++){
		if(cadastro->nome[i] == nome){
			cout << "Dia: ";
			cin >> cadastro->dia[i];
			cout << "Mes: ";
			cin >> cadastro->mes[i];
			cout << "Ano: ";
			cin >> cadastro->ano[i];
		} 
	}
	system(PAUSE);
}

void consultaAniversariantesData(Agenda* cadastro){
	int dia;
	int mes;
	int ano;
	
	cout << "***** Consultar Aniversariantes do Dia *****\n";
	cout << "Dia: ";
	cin >> dia;
	cout << "Mês: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;
	
	buscaAniversarianteData(dia, mes, ano, cadastro);
	system(PAUSE);
}

void consultaAniversariantesMes(Agenda* cadastro){
	int mes;
	
	cout << "***** Consultar Aniversariantes do Mês *****\n";
	cout << "Mês: ";
	cin >> mes;
	
	buscaAniversarianteMes(mes, cadastro);
	system(PAUSE);
}

void consultaAniversariantesLetra(Agenda* cadastro){
	char letraInicial;
	
	cout << "***** Consultar Aniversariantes pela Inicial *****\n";
	cout << "Letra Inicial: ";
	cin >> letraInicial;
	
	buscaAniversarianteLetra(letraInicial, cadastro);
	system(PAUSE);
}

void mostrarOrdemAlfabetica(Agenda* cadastro){
	
	string nomeOrdemAlfabetica[1000] = {};
	string maior;
	
    //Laço que preenche "nomeOrdemAlfabetica", que será organizada
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++) {
		nomeOrdemAlfabetica[i] = cadastro->nome[i];
	}
	
    //Laço que organiza em ordem alfabética
	for (int i=0; i < cadastro->aniversariantesCadastrados-1; i++){
		for(int j=i+1; j < cadastro->aniversariantesCadastrados; j++){
			if (nomeOrdemAlfabetica[i] > nomeOrdemAlfabetica[j]){
				maior = nomeOrdemAlfabetica[i];
				nomeOrdemAlfabetica[i] = nomeOrdemAlfabetica[j];
				nomeOrdemAlfabetica[j] = maior;
			}
		}
	}
	
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++){
		cout << nomeOrdemAlfabetica[i]<< "\n";
	}

	system(PAUSE);
}

void mostrarOrdemMes(Agenda* cadastro){
	
    struct Lista{
        string nome[1000];
        int mes[1000] = {0};
    }typedef Lista;

	Lista ordemMes;
	Lista maior;
	
    //Laço que preenche os dados da struct
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++) {
        ordemMes.nome[i] = cadastro->nome[i];
		ordemMes.mes[i] = cadastro->mes[i];
	}
	
    //Laço que organiza os dados de acordo com o mês
	for (int i=0; i < cadastro->aniversariantesCadastrados-1; i++){
		for(int j=i+1; j< cadastro->aniversariantesCadastrados; j++){
			if (ordemMes.mes[i] > ordemMes.mes[j]){
				maior.nome[i] = ordemMes.nome[i];
                maior.mes[i] = ordemMes.mes[i];

                ordemMes.nome[i] = ordemMes.nome[j];
				ordemMes.mes[i] = ordemMes.mes[j];

                ordemMes.nome[j] = maior.nome[i];
				ordemMes.mes[j] = maior.mes[i];
			}
		}
	}
	
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++){
		cout << "Nome: " << ordemMes.nome[i] << " | " << 
		"Mês: " << ordemMes.mes[i] << "\n";
	}

	system(PAUSE);
}

bool verificaData(int dia, int mes, int ano){
	
    //Verificação se os números são válidos
	if (dia < 1 || dia > 31) {
		cout << "Dia Inválido!\n";
		return 0;
	}
			
	if (mes < 1 || mes > 12) {
		cout << "Mês Inválido!\n";
		return 0;
	}
	
	if (ano < 1921 || ano > 2021) {
		cout << "Ano Inválido!\n";
		return 0;
	}
	
    //Verificação ano bissexto
	if( (ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0){	
		if (mes == 2 && dia > 29) {
			cout << "Dia Inválido!\n";
			return 0;
		}
	} else{
	
		if (mes == 2 && dia > 28) {
			cout << "Dia Inválido!\n";
			return 0;
		}
	}
	
    //Verificação de se o dia existe naquele mês
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || 
	mes == 12){
		if (dia > 31){
			cout << "Dia Inválido!\n";
			return 0;
		}
	}
	
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
		if (dia > 30){
			cout << "Dia Inválido!\n";
			return 0;
		}
	}
	
	return 1;
}
 
void buscaAniversarianteData(int dia, int mes, int ano, Agenda* cadastro) {
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++) {
		if (cadastro->dia[i] == dia && cadastro->mes[i] == mes && cadastro->ano[i] == ano) {
			cout << cadastro->nome[i] << "\n";
		}
	}
}

void buscaAniversarianteMes(int mes, Agenda* cadastro) {
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++) {
		if (cadastro->mes[i] == mes) {
			cout << cadastro->nome[i] << "\n";
		}
	}
}

void buscaAniversarianteLetra(char letraInicial, Agenda* cadastro) {
	for (int i=0; i < cadastro->aniversariantesCadastrados; i++) {
		if (cadastro->nome[i].at(0) == letraInicial) {
			cout << cadastro->nome[i] << "\n";
		}
	}
}