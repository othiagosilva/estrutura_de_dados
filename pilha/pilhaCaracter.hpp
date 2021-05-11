#include <vector>

class PilhaCaracter {
    private:
        int topo;
        int capacidade;
        std::vector<char> conteudo;
    public:
        void redefinir(int tamanho);
        PilhaCaracter(int tamanho);
        int recuperaTopo();
        int recuperaConteudo();
        bool estaVazia();
        bool estaCheia();
        bool empilhar(char palavra);
        void desempilhar();
        void invertePilha();
        void ehPalindromo();
        void inverterPalavra();
};