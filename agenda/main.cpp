#include <iostream>
#include "agenda.hpp"

using namespace std;

int main(){
    
	int escolha;Agenda cadastro;
	
    while (1){
        system(CLEAR);
        menu();
        cout << "Escolha: ";
        cin >> escolha;
        redirecionar(escolha, &cadastro);
    }
}