#include <cstdlib>
#include <iostream>
#include "pilha.hpp"

Pilha::Pilha(int tamanho) {
    this->redefinir(tamanho);
}

void Pilha::redefinir(int tamanho) {
    this->topo = -1,
    this->capacidade = tamanho -1;	
}

bool Pilha::estaVazia() {
    if (this->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

bool Pilha::estaCheia() {
    if (this->topo == this->capacidade) {
        return 1;
    } else {
        return 0;
    }
}

bool Pilha::empilhar(int valor) {
    if (this->estaCheia())
        return 0;
    this->topo++;
    this->conteudo.push_back(valor);
    return 1;
}

int Pilha::desempilhar() {
    int aux = this->conteudo[this->topo];
    if (this->estaVazia())
        return 0;
    this->topo--;
    return aux;
}

int Pilha::retornaTopo() {
    return this->conteudo[this->topo];
}

// Exercício 1
void Pilha::invertePilha() {
    int auxPosicao = this->topo;
    std::vector<int> vetorCopia = this->conteudo;

    for (int i = 0; i <= this->capacidade; i++) {
        this->conteudo[auxPosicao] = vetorCopia[i];
        auxPosicao--;
    }
}

// Exercício 2
void Pilha::media(){
    int maior = 0;
    int menor;
    int soma =0;
    float media;
    float mediaMaiorMenor;

    for (int i=0; i < this->topo; i++){
        if (maior < this->conteudo[i]) {
            maior = this->conteudo[i];
        }

        menor = maior;
        if (menor > this->conteudo[i]) {
            menor = this->conteudo[i];
        }
        soma = soma + this->conteudo[i];
    }

    media = float(soma)/this->capacidade;
    mediaMaiorMenor = (maior + menor)/2;

    std::cout << "Média entre todos elementos: " << media << "\n";
    std::cout << "Maior: " << maior << " Menor: " << menor << " Média entre eles: " << mediaMaiorMenor << "\n";
}

// Exercício 3
void Pilha::verificaMaiorPilha(Pilha pilha){
    if (this->topo > pilha.topo) {
        std::cout << "A pilha que chamou a função tem mais elementos\n";
    } else {
        std::cout << "A pilha que foi chamada pela função tem mais elementos\n";
    }
} 

// Exercício 4
void Pilha::verificaPilhaIgual(Pilha pilha){
    int aux = 0;

    if (this->capacidade != pilha.capacidade) {
        std::cout << "As pilhas são diferentes\n";
    } else {
        for (int i=0; i < this->topo; i++) {
            if (this->conteudo[i] == pilha.conteudo[i]) {
                aux++;
            } else {
                std::cout << "As pilhas são diferentes\n";
                break;
            }
        }
    }

    if(aux == this->topo) std::cout << "As pilhas são iguais! \n";
} 

// Exercício 5
void Pilha::retornaImpar(){
    int flag = 0;
    for (int i = 0; i<this->topo; i++){
        if (this->conteudo[i]%2 != 0) {
            std::cout << this->conteudo[i] << " ";
            flag++;
        } 
    }

    if (flag == 0) {
        std::cout << "Não há números ímpares";
    }
    std::cout << "\n";
}