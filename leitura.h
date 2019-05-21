
#ifndef LEITURA_H
#define LEITURA_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
using namespace std;

class Leitura{

    public:
        //cria um contrutor para abrir arquivo
        Leitura(int qtdArquivos);
        void ReadFile(int qtdArquivos);
        void Tudominusculo(string&word);
        void TiraCaracter(string&word);
        //~Leitura();
        //

    private:
        ifstream arquivo_;
        string word;
        vector <string> nomeArquivo;
        int quantidadeArquivos;
        list<string>listaPalavras;



};





#endif
