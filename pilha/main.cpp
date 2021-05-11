#include <iostream>
#include "pilha.hpp"
#include "pilhaCaracter.hpp"

using namespace std;

int main() {
    Pilha pilha1 = Pilha(5);
    pilha1.empilhar(5);
    pilha1.empilhar(2);
    pilha1.empilhar(3);
    pilha1.empilhar(7);
    pilha1.empilhar(10);
    
    cout << "Pilha Original\n";
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();

    cout << "\nExercício 1 \n";
    pilha1.empilhar(5);
    pilha1.empilhar(2);
    pilha1.empilhar(3);
    pilha1.empilhar(7);
    pilha1.empilhar(10);

    pilha1.invertePilha();
    
    cout << "Pilha Invertida\n";
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();
    cout << pilha1.retornaTopo() << "\n";
    pilha1.desempilhar();

    cout << "\nExercício 2 \n";
    pilha1.empilhar(5);
    pilha1.empilhar(2);
    pilha1.empilhar(3);
    pilha1.empilhar(7);
    pilha1.empilhar(10);
    
    pilha1.media();

    cout << "\nExercício 3 \n";
    Pilha pilha2 = Pilha(3);
    pilha2.empilhar(1);
    pilha2.empilhar(2);
    pilha2.empilhar(3);

    pilha1.verificaMaiorPilha(pilha2);
    pilha2.verificaMaiorPilha(pilha1);

    cout << "\nExercício 4\n";
    pilha1.invertePilha();

    Pilha pilha3 = Pilha(5);
    pilha3.empilhar(5);
    pilha3.empilhar(2);
    pilha3.empilhar(3);
    pilha3.empilhar(7);
    pilha3.empilhar(10);

    pilha1.verificaPilhaIgual(pilha2);
    pilha3.verificaPilhaIgual(pilha1);

    cout << "\nExercício 5\n";
    cout << "Números Ímpares\n";
    pilha1.retornaImpar();

    cout <<"\nExercício 6\n";
    PilhaCaracter pilhaCaracter1 = PilhaCaracter(5);
    pilhaCaracter1.empilhar('a');
    pilhaCaracter1.empilhar('r');
    pilhaCaracter1.empilhar('a');
    pilhaCaracter1.empilhar('r');
    pilhaCaracter1.empilhar('a');

    pilhaCaracter1.ehPalindromo();

    PilhaCaracter pilhaCaracter2 = PilhaCaracter(4);
    pilhaCaracter2.empilhar('o');
    pilhaCaracter2.empilhar('r');
    pilhaCaracter2.empilhar('l');
    pilhaCaracter2.empilhar('a');

    pilhaCaracter2.ehPalindromo();

    cout <<"\nExercício 7\n";
    PilhaCaracter pilhaCaracter3 = PilhaCaracter(20);
    pilhaCaracter3.empilhar('F');
    pilhaCaracter3.empilhar('A');
    pilhaCaracter3.empilhar('T');
    pilhaCaracter3.empilhar('E');
    pilhaCaracter3.empilhar('C');
    pilhaCaracter3.empilhar(' ');
    pilhaCaracter3.empilhar('R');
    pilhaCaracter3.empilhar('I');
    pilhaCaracter3.empilhar('B');
    pilhaCaracter3.empilhar('E');
    pilhaCaracter3.empilhar('I');
    pilhaCaracter3.empilhar('R');
    pilhaCaracter3.empilhar('A');
    pilhaCaracter3.empilhar('O');
    pilhaCaracter3.empilhar(' ');
    pilhaCaracter3.empilhar('P');
    pilhaCaracter3.empilhar('R');
    pilhaCaracter3.empilhar('E');
    pilhaCaracter3.empilhar('T');
    pilhaCaracter3.empilhar('O');

    pilhaCaracter3.inverterPalavra();
}