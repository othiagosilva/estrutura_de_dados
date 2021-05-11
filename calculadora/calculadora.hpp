#pragma once
#include <iostream>

struct Calculadora {
    char operadores[4] = {'+', '-', 'x', '/'};
    int operacoes[4] = {1, 2, 3, 4}; //1- adição, 2- subtração, 3- multiplicação, 4- divisão; segue a ordem do menu.
    float numeros[2] = {0};
    float resultado = 0;
    float historicoResultados[10][4] ={ {0, 0, 0, 0} };
    int linhaHistorico = 0;
}typedef Calculadora;

inline void imprimeMenu() {
    std::cout << "***** Calculadora *****\n";
    std::cout << "1- Soma (+)\n";
    std::cout << "2- Subtração (-)\n";
    std::cout << "3- Multiplicação (x)\n";
    std::cout << "4- Divisão (/)\n";
    std::cout << "5- Histórico\n";
    std::cout << "0- Sair\n";
    std::cout << "***********************\n";
};
void escolhas(int escolha, bool* parar, Calculadora* calculadora);
bool validarOperacao(int operacao, Calculadora* calculadora);
void operacao(int escolha, Calculadora* calculadora);
void armazenaHistorico (int escolha, Calculadora* calculadora);
void imprimeHistorico(Calculadora* calculadora);
void defineOperador(Calculadora* calculadora, int i, int* posicao);