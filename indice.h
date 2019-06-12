
#ifndef INDICE_H
#define INDICE_H
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<set>
#include<map>
using namespace std;

//classe para criar o indice invertido
class Indice{

public:
    //Construtor para Indice
    Indice();
    //RETORNA TRUE SE UMA PALAVRA PERTENCE A UM ARQUIVO
    bool Pertence(string word);
    //CONVERTE TODAS AS LETRAS DE UMA PALAVRA PARA MINUSCULO
    void Tudominusculo(string&word);
    //REMOVE CARACTERES , . ;: !][-()
    void TiraCaracter(string&word);
    //RETORNA QUANTAS VEZES UMA PALAVRA APARECE EM UM ARQUIVO
    int TermFrequency(string word,vector< list<string> >palavras,int i);
    //armazena as palavras de todos os documentos ou seja o list de cada arquivo
    vector <list <string> > palavrasDocs;

    //MAP QUE CONTEM O INDICE INVERTIDO
    map <string, set<string> >palavras;




friend class Ranking;

};

#endif
