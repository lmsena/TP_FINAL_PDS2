#define LEITURA_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<set>
#include<map>
#include <iostream>
#include<algorithm>
using namespace std;

class Leitura{

    public:
        //cria um contrutor para abrir arquivo
        Leitura(int qtdArquivos);
        void ReadFile(int qtdArquivos);
        void Tudominusculo(string&word);
        void TiraCaracter(string&word);
        //Retorna o numero de vezes que uma palavra ocorre em um arquivo
        int TermFrequency(string word,vector< list<string> > palavras,int i);
        //Retorna true se uma palavra pertence a um arquivo
        bool Pertence(string word);
        //Insere uma palavra no Map com seus respectivos arquivos
        void InsereMap(string word);
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
        map <string, set<string> >palavras;



};



#endif
