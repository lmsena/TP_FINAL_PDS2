#ifndef LEITURA_H
#define LEITURA_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<set>
#include<map>
using namespace std;

class Leitura{

    public:
        //cria um contrutor para abrir arquivo
        Leitura(int qtdArquivos);
        void ReadFile(int qtdArquivos);
        //~Leitura();
        //

    private:
        ifstream arquivo_;
        vector <string> nomeArquivo;
        int quantidadeArquivos;

};





#endif
