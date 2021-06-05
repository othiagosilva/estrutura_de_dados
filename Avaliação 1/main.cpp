#include <iostream>
#include <cstdlib>
#include <string>
#include "Fila.h"

using namespace std;

//  Implemente um programa que implemente uma fila de impressão. 
//  Para cada arquivo a ser impresso devem ser armazenados: 
//  - id sequencial da impressão (começando em 1)
//  - nome do arquivo
//  - quantidade de folhas
//  Exceto o id sequencial, as outras informações devem ser digitadas pelo 
//  usuário. O programa também deve realizar um controle 
//  da quantidade de papel disponível na impressora, permitindo que o usuário 
//  realize a “inserção” de mais papel. Antes de inserir um novo documento na 
//  fila, o programa deve verificar se há papel suficiente na impressora para 
//  realizar a impressão. Se não houver papel suficiente, o programa não deve 
//  aceitar a impressão. Desenvolva métodos que:
//    a.	Permita inserir um arquivo na fila de impressão (retornar falso caso não haja papel); FEITO
//    b.	Remova um arquivo da fila da impressão (imprimir); FEITO
//    c.	Liste os arquivos da fila de impressão; FEITO
//    d.	Permita inserir mais folhas na impressora; FEITO
//    e.	Retorne o total de folhas disponíveis na impressora FEITO

int main() {
    Fila fila01;
    int y;
    int x;
    string z;

    fila01.inserir("arquivoTeste0", 3);
    fila01.inserir("arquivoTeste1", 2);
    fila01.inserir("documento1", 1);
    fila01.inserir("abc", 5);
    fila01.inserir("abc", 5);
    fila01.inserir("abc", 5);
    fila01.inserir("abc", 5);
    fila01.inserir("abc", 5);
    cout << fila01.listar();

    if(fila01.remover(y, z, x)){
        cout <<"\n" << z << " removido!\n\n";
    } else {
        cout << "Não foi possível remover!\n";
    }
    
    cout << fila01.listar();

    cout << "\nQuantidade de papel: " << fila01.listarFolhas();
    fila01.inserirFolhas(3);
    cout << "\nQuantidade de papel: " << fila01.listarFolhas();
    cout << endl;

}