#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include"leitura.h"
#include<list>
#include<set>
#include<vector>
using namespace std;




//converte os caracteres de uma string que são maiusculos para minusculo
void Leitura::Tudominusculo(string&word){
    for(unsigned int i=0;i<word.size();i++){
        word[i]=tolower(word[i]);

    }
    TiraCaracter(word);
}
//Remove da string os caracteres .?/,;][-)(:
void Leitura::TiraCaracter(string&word){
    for(unsigned int i=0;i<word.size();i++){
        if(word[i]=='.'||word[i]=='?'||word[i]=='/'||word[i]==';'||word[i]==']'||word[i]=='['||word[i]=='-'||word[i]==')'||word[i]=='('||word[i]==','||word[i]==':'||word[i]=='!'){
            word.erase(word.begin()+i);
            i=i-1;
        }
    }
}
//Retorna o numero de vezes que a palavra apareceu em um arquivo
int Leitura::TermFrequency(string word,vector< list<string> >palavras,int i){
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
//Le os arquivos
void Leitura::ReadFile(int qtdArquivos){


    for(int i=0;i<qtdArquivos;i++){
        cout<<"Digite o nome do arquivo no formato file.txt"<<endl;
        string auxiliar;
        cin>>auxiliar;
        nomeArquivo.push_back(auxiliar);
    }

        map<string, set<string> > palavras;
        string wordAux;
        //unsigned int k;
        set<string> nomesArquivos;


    for(int i=0;i<qtdArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);

      //insere o nome do arquivo no set para o map
      nomesArquivos.insert(nomeArquivo[i]);

        while(!arquivo_.eof())
            {
            arquivo_>>word;
            Tudominusculo(word);
            //*****para testar a palavra depois de tirar carct e converter
            cout<<word<<endl;
            //já insere a palavra lida e manipulada na lista de palavras do documento
            wordFile.push_back(word);
            //associa a palavra ao arquivo que a contem
            palavras[word]=nomesArquivos;
            }
        palavrasDocs.push_back(wordFile);
        arquivo_.close();
    //separa cada palavra e armazena o documento no set do map
        //for(unsigned int j = 0; j<word.size(); j++)
        //{
          //  if(word[j] == ' ' || word[j] == '\0')
            //{
              //  k = 0;
                //palavrasDoc.push_back(wordAux);
                //palavras[palavrasDoc.back()] = nomesArquivos;

           // } else
             //   {
               //     k = 0;
                 //   wordAux[k] = word[j];
                   // k++;
                //}
        //}
    }
cout<<this->TermFrequency("labrador",palavrasDocs,1);
}
Leitura::Leitura(int qtdArquivos){
    ReadFile(qtdArquivos);

}
