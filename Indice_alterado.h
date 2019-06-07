#ifndef INDICE_H
#define INDICE_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<set>
#include<map>
using namespace std;


class Indice{

public:
    bool Pertence(string word);
    void Tudominusculo(string&word);
    void TiraCaracter(string&word);
    int TermFrequency(string word,vector< list<string> >palavras,int i);
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
