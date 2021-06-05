#include <string>
#include <iostream>
#include "Fila.h"

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
    idSequencial = 1;
}

bool Fila::vazia() {
    return (inicio == NULL);
}

bool Fila::cheia() {
    return false;
}

bool Fila::inserir(string auxNomeArquivo, int auxQuantidadeFolhas) {
    if (quantidadeFolhasImpressora < auxQuantidadeFolhas) {
        std::cout << "Papel Insuficiente\n";
        return false;
    }

    PonteiroElemento p;
    p = new elemento;
    p->quantidadeFolhas = auxQuantidadeFolhas;
    p->nomeArquivo = auxNomeArquivo;
    p->id = idSequencial;
    idSequencial++;

    if (vazia()) {
        inicio = p;
        fim = p;
    } else {
        fim->proximoElemento = p;
        fim = p;
    }
    p->proximoElemento = NULL;

    quantidadeFolhasImpressora -= auxQuantidadeFolhas;

    return true;
}

bool Fila::remover(int &y, string &z, int &x) {
    PonteiroElemento p;
    if (vazia()) {
        return false;
    }
    idSequencial--;
    y = inicio->id;
    x = inicio->quantidadeFolhas;
    z = inicio->nomeArquivo;
    quantidadeFolhasImpressora += inicio->quantidadeFolhas;
    
    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL){
        fim = NULL;
        idSequencial = 1;
    }
    return true;
}

std::string Fila::listar() {
	int auxId;
    int auxQuantidadeFolhas;
    string auxNomeArquivo;
	Fila auxFila;
	string retorno = "";
	
	while (remover(auxId, auxNomeArquivo, auxQuantidadeFolhas)) {
        retorno = retorno + to_string(auxId) + " - " + auxNomeArquivo + " - " + to_string(auxQuantidadeFolhas) + "\n";
        inserirFolhas(auxQuantidadeFolhas);
        idSequencial--;
		auxFila.inserir(auxNomeArquivo, auxQuantidadeFolhas);
	}
	
	while (auxFila.remover(auxId, auxNomeArquivo, auxQuantidadeFolhas)) {
        quantidadeFolhasImpressora -= auxQuantidadeFolhas;
	    inserir(auxNomeArquivo, auxQuantidadeFolhas);
	}

    return retorno;
}

bool Fila::inserirFolhas(int auxFolhas) {
    quantidadeFolhasImpressora += auxFolhas;
    return true;
}

int Fila::listarFolhas() {
    return quantidadeFolhasImpressora;
}