#include <iostream>
#include "Fila.h"

using namespace std;

int main() {
    Fila fila01, fila02, fila03;
    int x;

    fila01.inserir(1);
    fila01.inserir(2);
    fila01.inserir(3);
    fila01.inserir(4);
    fila01.listar();

    fila01.primeiro(x);
    cout << "\nA) X primeiro: " << x;

    fila01.ultimo(x); 
    cout << "\nB) X último: " << x;

    cout << "\nC) Esvazia Fila: ";
    fila01.esvaziar();
    fila01.tamanho();

    cout << "\n\n----- Preenchendo Lista -----\n";
    fila01.inserir(1);
    fila01.inserir(2);
    fila01.inserir(3);
    fila01.inserir(4);
    cout << "\nNova lista: ";
    string ordemFila1 = fila01.listar();
    cout << ordemFila1;

    cout << "\nD) "; 
    fila01.tamanho();

    cout << "\nE) Inverter Fila: ";
    fila01.inverter();
    ordemFila1 = fila01.listar();
    cout << ordemFila1;

    cout << "\nF) Listar Fila: ";
    cout << ordemFila1;

    cout << "\nG)";
    if(fila01.estaNaFila(1)) {
        cout << "\nO valor está na fila\n";
    } else {
        cout << "\nO valor não está na fila\n";
    }

    fila02.inserir(3);
    fila02.inserir(4);
    fila02.inserir(5);
    fila01.inverter();

    cout << "\nH) Intersecção \n";
    cout << "Fila 1: ";
    ordemFila1 = fila01.listar();
    cout << ordemFila1;
    cout << "\nFila 2: ";
    string ordemFila2 = fila02.listar();
    cout << ordemFila2;
    cout << "\nFila com Intersecção: ";
    fila03 = fila01.interseccao(fila02);
    string ordemFila3 = fila03.listar();
    cout << ordemFila3;

    cout << "\n\nI) União \n";
    cout << "Fila 1: ";
    ordemFila1 = fila01.listar();
    cout << ordemFila1;
    cout << "\nFila 2: ";
    ordemFila2 = fila02.listar();
    cout << ordemFila2;
    cout << "\nFila com União: ";
    fila03 = fila01.uniao(fila02);
    ordemFila3 = fila03.listar();
    cout << ordemFila3;
    
}