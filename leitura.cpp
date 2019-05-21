#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include"leitura.h"
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

//Le os arquivos
void Leitura::ReadFile(int qtdArquivos){
    for(int i=0;i<qtdArquivos;i++){
        cout<<"Digite o nome do arquivo no formato file.txt"<<endl;
        string auxiliar;
        cin>>auxiliar;
        nomeArquivo.push_back(auxiliar);
    }
    for(int i=0;i<qtdArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);
        while(!arquivo_.eof()){
            arquivo_>>word;
            Tudominusculo(word);
            //*****para testar a palavra depois de tirar carct e converter
            cout<<word<<endl;
        }
    }
}
Leitura::Leitura(int qtdArquivos){
    ReadFile(qtdArquivos);

}
