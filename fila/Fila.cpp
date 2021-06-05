#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Fila.h"

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
}

bool Fila::vazia() {
    return (inicio == NULL);
}

bool Fila::cheia() {
    return false;
}

bool Fila::inserir(int x) {
    PonteiroElemento p;
    p = new elemento;
    p->valor = x;
    if (vazia()) {
        inicio = p;
        fim = p;
    } else {
        fim->proximoElemento = p;
        fim = p;
    }
    p->proximoElemento = NULL;

    contadorElementos++;

    return true;
}

bool Fila::remover(int &x) {
    PonteiroElemento p;
    if (vazia())
        return false;
    x = inicio->valor;
    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL)
        fim = NULL;

    contadorElementos--;
    return true;
}


bool Fila::primeiro(int &x) {
    if (vazia()){
        return false;
    }

    x = inicio->valor;
    return true;
    
}

bool Fila::ultimo(int &x) {
	
    if (vazia()){
        return false;
    }

    x = fim->valor;
    return true;
}

bool Fila::esvaziar() {
    int x = 0;

	if (vazia()){
        return false;
    }
	
    for (int i = contadorElementos; i >=0 ; i--) {
        remover(fim->valor);
    }
    return true;
}

int Fila::tamanho() {
	if (vazia()){
        cout << "Fila vazia.";
        return 0;
    }

	cout << contadorElementos;
    return contadorElementos;
}

bool Fila::inverter() {
	if (vazia()){
        return false;
    }
    
    vector<int> filaCopia;
    int x;
    int auxContador = contadorElementos;

    while (remover(x)) {
        filaCopia.push_back(x);
    }

    for (int i = auxContador - 1; i >= 0; i--) {
        inserir(filaCopia[i]);
    }

    listar();
    return true;
}

string Fila::listar() {
	int y;
	Fila auxFila;
	string retorno = "";
	
	while (remover(y)) {
        if (inicio == NULL){
            retorno = retorno + to_string(y);
        } else {
		    retorno = retorno + to_string(y) + " ; ";
        }
		auxFila.inserir(y);
	}
	
	while (auxFila.remover(y)) {
		inserir(y);
	}

    return retorno;
}

bool Fila::estaNaFila(int x) {
	int y;
    int auxContador = contadorElementos;
    vector<int> filaVetor;

    while(remover(y)){
        filaVetor.push_back(y);
    }

    for (int i=0; i < filaVetor.size(); i++) {
        if (x == filaVetor[i]) {
            for (int j=0; j < auxContador; j++) {
                inserir(filaVetor[j]);
            }
            return true;
        } 
    }

    for (int i=0; i < auxContador; i++) {
        inserir(filaVetor[i]);
    }

    return false;
}

Fila Fila::interseccao(Fila auxFila) {
	int x;
    vector<int> filaVetor;
    Fila interseccao;

    while(auxFila.remover(x)) {
        filaVetor.push_back(x);
    }

    for (int i = 0; i < filaVetor.size(); i++) {
        if (estaNaFila(filaVetor[i])){
            interseccao.inserir(filaVetor[i]);
        }
        auxFila.inserir(filaVetor[i]);
    }

    return interseccao;
}

Fila Fila::uniao(Fila auxFila) {
    int x;
    int auxContador = contadorElementos;
    vector<int> filaVetor;
    vector<int> filaVetor1;
    Fila uniao;

    while(remover(x)) {
        filaVetor.push_back(x);
    }

    for(int i=0; i < auxContador; i++){
        inserir(filaVetor[i]);
        uniao.inserir(filaVetor[i]);
    }

    auxContador = auxFila.contadorElementos;
    while (auxFila.remover(x)){
        filaVetor1.push_back(x);
    }

    for (int i = 0; i < auxContador; i++){
        if (estaNaFila(filaVetor1[i])){
            continue;
        }
        uniao.inserir(filaVetor1[i]);
    }

    for (int i=0; i < auxContador; i++){
        auxFila.inserir(filaVetor1[i]);
    }

    return uniao;
}