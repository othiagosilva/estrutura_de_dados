#include <iostream>
#include "calculadora.hpp"

using namespace std;

void escolhas(int escolha, bool* parar, Calculadora* calculadora){
    if (escolha < 0 || escolha > 5){
            cout << "Insira uma operação válida!\n";
    }
    
    if (escolha == 0) {
        *parar = 1;
        exit(0);
    } 

    if (escolha == 5) {
        imprimeHistorico(calculadora);
    }
}

bool validarOperacao(int operacao, Calculadora* calculadora) {

    if (operacao == 4 && (calculadora->numeros[1] == 0)) {
        cout <<"Impossível dividir por 0!\n";
        return 0;
    }

    return 1;
}

void operacao(int escolha, Calculadora* calculadora){

    if (escolha == calculadora->operacoes[0]){
        calculadora->resultado = calculadora->numeros[0] + calculadora->numeros[1];
    }

    if (escolha == calculadora->operacoes[1]){
        calculadora->resultado = calculadora->numeros[0] - calculadora->numeros[1];
    }

    if (escolha == calculadora->operacoes[2]) {
        calculadora->resultado = calculadora->numeros[0] * calculadora->numeros[1];
    }

    if (escolha == calculadora->operacoes[3]) {
        calculadora->resultado = calculadora->numeros[0] / calculadora->numeros[1];
     }

    armazenaHistorico (escolha, calculadora);
    cout << "Resultado = " << calculadora->resultado << "\n";
     
}

void armazenaHistorico (int escolha, Calculadora* calculadora) {
    for (int i = calculadora->linhaHistorico; i < 10; i++) {
        calculadora->historicoResultados[i][0] = escolha;
        calculadora->historicoResultados[i][1] = calculadora->numeros[0];
        calculadora->historicoResultados[i][2] = calculadora->numeros[1];
        calculadora->historicoResultados[i][3] = calculadora->resultado;
        calculadora->linhaHistorico++;
        break;
    }
    if (calculadora->linhaHistorico > 9) {
        calculadora->linhaHistorico = 0;
    }
}

void imprimeHistorico(Calculadora* calculadora) {
    cout << "\n***** Histórico *****\n";
    for(int i = 0; i < calculadora->linhaHistorico; i++) {

        int posicao;
        defineOperador(calculadora, i, &posicao);

        cout << " " << calculadora->historicoResultados[i][1] << " " << calculadora->operadores[posicao] << " ";
        cout << calculadora->historicoResultados[i][2] << " = " << calculadora->historicoResultados[i][3] << "\n";
    }
    cout << "**********************\n";
}

void defineOperador(Calculadora* calculadora, int i, int* posicao){
    if (calculadora->historicoResultados[i][0] == calculadora->operacoes[0]) *posicao = 0;
    if (calculadora->historicoResultados[i][0] == calculadora->operacoes[1]) *posicao = 1;
    if (calculadora->historicoResultados[i][0] == calculadora->operacoes[2]) *posicao = 2;
    if (calculadora->historicoResultados[i][0] == calculadora->operacoes[3]) *posicao = 3;
}