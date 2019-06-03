#ifndef LEITURA_H
#define LEITURA_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<map>
using namespace std;

class Leitura{

    public:
        //cria um contrutor para abrir arquivo
        Leitura(int qtdArquivos);
        void ReadFile(int qtdArquivos);
        void Tudominusculo(string&word);
        void TiraCaracter(string&word);
        int TermFrequency(string word,vector< list<string> > palavras,int i);
        //~Leitura();
        //

    private:
        ifstream arquivo_;
        string word;
        //armazena as palavras de todos os documentos ou seja o list de cada arquivo
        vector < list<string> > palavrasDocs;
        //armazena as palavras de um unico arquivo
        list <string> wordFile;
        vector <string> nomeArquivo;
        int quantidadeArquivos;
        list<string>listaPalavras;



};





#endif
