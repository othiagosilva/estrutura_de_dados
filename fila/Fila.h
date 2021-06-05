#pragma once
using namespace std;

class Fila {
    private:
        struct elemento {
            int valor;
            elemento *proximoElemento;
        };
        typedef elemento *PonteiroElemento;
        PonteiroElemento inicio;
        PonteiroElemento fim;
        int contadorElementos = 0;
    public:
        Fila();
        bool vazia();
        bool cheia();
        bool inserir(int x);
        bool remover(int &x);
        bool primeiro(int &x);
        bool ultimo(int &x);
        bool esvaziar();
        int tamanho();
        bool inverter();
        string listar();
        bool estaNaFila(int x);
        Fila interseccao(Fila auxFila);
        Fila uniao(Fila auxFila);
};
