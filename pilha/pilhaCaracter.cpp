#include <vector>
#include <iostream>
#include <ctype.h>
#include "pilhaCaracter.hpp"

PilhaCaracter::PilhaCaracter(int tamanho) {
    this->redefinir(tamanho);
}

void PilhaCaracter::redefinir(int tamanho) {
    this->topo = -1,
    this->capacidade = tamanho -1;	
}

bool PilhaCaracter::estaVazia() {
    if (this->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

bool PilhaCaracter::estaCheia() {
    if (this->topo == this->capacidade) {
        return 1;
    } else {
        return 0;
    }
}

bool PilhaCaracter::empilhar(char caracter) {
    if (this->estaCheia())
        return 0;
    this->topo++;
    this->conteudo.push_back(caracter);
    return 1;
}

void PilhaCaracter::desempilhar() {
    char aux = this->conteudo[this->topo];
    if (this->estaVazia()){
        std::cout <<"Vazia!";
    } else{
        this->topo--;
        std::cout << aux;
    }
}

void PilhaCaracter::ehPalindromo(){
    std::vector<char> auxVetor = this->conteudo;
    int auxPosicao = this->topo;

    for (int i = 0; i <= this->topo; i++) {
        this->conteudo[auxPosicao] = auxVetor[i];
        auxPosicao--;
    }

    int flag=0;
    for (int i=0; i<= this->topo; i++) {
        if (this->conteudo[i] == auxVetor[i]){ 
            flag++;
        }
    }

    if (flag == this->topo+1) std::cout <<"É palíndromo\n";
    else std::cout << "Não é palíndromo\n";
}

void PilhaCaracter::inverterPalavra(){

    std::cout << "Pilha Original\n";
    for (int i=0; i <= this->topo; i++){
        std::cout << this->conteudo[i] << "\n";
    }

    std::vector<char> vetorAux = this->conteudo;
    int proximaPalvra = 0;
    for (int i=0; i < this->topo; i++) {
        if (isspace(this->conteudo[i])){
            int posicao = i - 1;
            for (int j=proximaPalvra; j < i; j++){
                this->conteudo[j] = vetorAux[posicao];
                posicao--;
            }
            proximaPalvra = i + 1;
        }
        if (i+1 == this->topo){
            int posicao = this->topo;
            for (int j=proximaPalvra; j <= posicao+4; j++){
                this->conteudo[j] = vetorAux[posicao];
                posicao--;
            }
        }
    }

    std::cout << "\nPilha Invertida\n";
    for (int i=0; i <= this->topo; i++){
        std::cout << this->conteudo[i] << "\n";
    }
}