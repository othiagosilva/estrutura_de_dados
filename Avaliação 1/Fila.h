#pragma once
using namespace std;

class Fila {
    private:
        struct elemento {
            int quantidadeFolhas;
            std::string nomeArquivo;
            int id;
            elemento *proximoElemento;
        };
        typedef elemento *PonteiroElemento;
        PonteiroElemento inicio;
        PonteiroElemento fim;
        int idSequencial;
        int quantidadeFolhasImpressora = 0;
    public:
        Fila();
        bool vazia();
        bool cheia();
        bool inserir(string auxNomeArquivo, int auxQuantidadeFolhas);
        bool remover(int &y, string &z, int &x);
        string listar();
        int listarFolhas();
        bool inserirFolhas(int auxFolhas);
        bool imprimir();
};