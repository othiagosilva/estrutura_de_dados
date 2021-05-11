#include <iostream>
#include "calculadora.hpp"

using namespace std;

int main() {
    int escolha;
    Calculadora calculadora;

    imprimeMenu();

    bool parar = 0;
    while (!parar){
        cout << "\nOperação (número indicado no menu): ";
        cin >> escolha;

        escolhas(escolha, &parar, &calculadora);
        if (escolha == 5 || escolha < 0 || escolha > 5) continue;

        cout << "Primeiro número: ";
        cin >> calculadora.numeros[0];
        cout << "Segundo número: ";
        cin >> calculadora.numeros[1];

        bool operacaoValida = validarOperacao(escolha, &calculadora);

        if (operacaoValida){
            operacao(escolha, &calculadora);
        } else {
            continue;
        }
    }
}