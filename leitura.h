#ifndef LEITURA_H
#define LEITURA_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<map>
#include <iostream>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

class Leitura{

    public:
        //cria um contrutor para abrir arquivo
        Leitura(int qtdArquivos);
        void ReadFile(int qtdArquivos);
        void Tudominusculo(string&word);
        void TiraCaracter(string&word);
        int Ocorrencias(string word,list<string>palavras);
        double indicie_invertido();
        //~Leitura();
        //

    private:
        ifstream arquivo_;
        string word;
        vector <string> nomeArquivo;
        int quantidadeArquivos;
        map<string, set<string> > palavras;
        set<string> nomesArquivos;
       
        //fazem a mesma variavel?
        list<string>listaPalavras;
        list<string> palavrasDoc;
        double indicieInvertido;
        



};





#endif
