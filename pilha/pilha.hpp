#include<vector>

class Pilha {
    private:
        int topo;
        int capacidade;
        std::vector<int> conteudo; //alterei para um vetor, a maneira com malloc me confundiu
    public:
        void redefinir(int tamanho);
        Pilha(int tamanho);
        int recuperaTopo();
        int recuperaConteudo();
        bool estaVazia();
        bool estaCheia();
        bool empilhar(int valor);
        int desempilhar();
        int retornaTopo();
        void invertePilha();
        void media();
        void verificaMaiorPilha(Pilha pilha);
        void verificaPilhaIgual(Pilha pilha);
        void retornaImpar();
};