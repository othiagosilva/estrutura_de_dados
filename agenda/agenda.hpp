#pragma once
#include <string>

// por algum motivo, nem o "pause" e nem o "read" funcionam no replit, no Microsoft Visual Studio Community funcionou.
#ifndef _WIN32
#define CLEAR "clear"
#define PAUSE "read"
#else
#define CLEAR "cls"
#define PAUSE "pause"
#endif

struct Agenda {
		std::string nome[1000];
		std::string email[1000];
		int dia[1000] = {0};
		int mes[1000] = {0};
		int ano[1000] = {0};
        int aniversariantesCadastrados = 0;
} typedef Agenda;

inline void menu(){
	
	std::cout << "*********** AGENDA ANIVERSARIANTES ***********\n";
	std::cout << "1- Cadastrar Aniversariante\n";
	std::cout << "2- Excluir Aniversariante\n";
	std::cout << "3- Alterar Data de Aniversário\n";
	std::cout << "4- Consultar Aniversariantes por Data\n";
	std::cout << "5- Consultar Aniversariantes por Mês\n";
	std::cout << "6- Consultar Aniversariantes por Letra Inicial\n";
	std::cout << "7- Mostrar Aniversariantes em Ordem Alfabética\n";
	std::cout << "8- Mostrar Aniversariantes pelo Mês\n";
	std::cout << "9- Sair\n\n";
}
void redirecionar(int escolha, Agenda* cadastro);
void cadastroAniversariante(Agenda* cadastro);
void excluirAniversariante(Agenda* cadastro);
void alterarData(Agenda* cadastro);
void consultaAniversariantesData(Agenda* cadastro);
void consultaAniversariantesMes(Agenda* cadastro);
void consultaAniversariantesLetra(Agenda* cadastro);
void mostrarOrdemAlfabetica(Agenda* cadastro);
void mostrarOrdemMes(Agenda* cadastro);
bool verificaData(int dia, int mes, int ano);
void buscaAniversarianteData(int dia, int mes, int ano, Agenda* cadastro);
void buscaAniversarianteMes(int mes, Agenda* cadastro);
void buscaAniversarianteLetra(char letraInicial, Agenda* cadastro);