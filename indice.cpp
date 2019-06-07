 
#include "Indice.h"
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include<list>
#include<set>
#include<vector>
using namespace std;

//Retorna true se uma palavra pertence a um arquivo
bool Indice::Pertence(string word){
    if(palavras.find(word)==palavras.end()){
        return false;
    }
    else{
        return true;
    }
}

//converte os caracteres de uma string que são maiusculos para minusculo
void Indice::Tudominusculo(string&word){
    for(unsigned int i=0;i<word.size();i++){
        word[i]=tolower(word[i]);

    }
    TiraCaracter(word);
}

//Remove da string os caracteres .?/,;][-)(:
void Indice::TiraCaracter(string&word){
    for(unsigned int i=0;i<word.size();i++){
        if(word[i]=='.'||word[i]=='?'||word[i]=='/'||word[i]==';'||word[i]==']'||word[i]=='['||word[i]=='-'||word[i]==')'||word[i]=='('||word[i]==','||word[i]==':'||word[i]=='!'){
            word.erase(word.begin()+i);
            i=i-1;
        }
    }
}

//Retorna o numero de vezes que a palavra apareceu em um arquivo
int Indice::TermFrequency(string word,vector< list<string> >palavras,int i){
    list<string>aux=palavras[i];
    list<string>::iterator it;
    int ocorrencias=0;
    for(it=aux.begin();it!=aux.end();it++){
        if(*it==word){
            ocorrencias++;
        }

    }
    return ocorrencias;
}


double Indice::idf(string wordIDF)
{
   list<string>x;
   x = palavras[wordIDF];
  // x = palavras.at(wordIDF).second;
  // idf = log2(quantidadeArquivos / this->palavras->second.size());
   idf = log2(quantidadeArquivos / x.size());

    return idf;
}
