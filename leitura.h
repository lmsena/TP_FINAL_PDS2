#ifndef LEITURA_H
#define LEITURA_H
#include"indice.h"
#include "ranking.h"
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

        //lê uma quantidade de arquivos e dentro dela será feita uma consulta de palavras e será gerado um ranking de arquivos que contem as palavras da busca
        void ReadFile(int qtdArquivos);

        //Cria um destrutor para a classe Leitura
        //~Leitura();
        //

    private:
        //ponteiro para ler as palavras do arquivo
        ifstream arquivo_;

        //vetor onde são armazenados os nomes dos arquivos
        vector <string> nomeArquivo;

        //quantidade de Arquivos lidos
        int quantidadeArquivos;


    friend class Ranking;

};





#endif
