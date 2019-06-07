#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include"leitura.h"
#include "Indice.h"
#include<list>
#include<set>
#include<vector>
using namespace std;



//Le os arquivos
void Leitura::ReadFile(int qtdArquivos){


        Indice indice;
        nomeArquivo.push_back("teste.txt");
        nomeArquivo.push_back("young.txt");
        nomeArquivo.push_back("music.txt");
        string word;
        //unsigned int k;
        //set<string> nomesArquivos;


    for(int i=0;i<qtdArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);

      //insere o nome do arquivo no set para o map
      //nomesArquivos.insert(nomeArquivo[i]);

        while(!arquivo_.eof())
            {
            arquivo_>>word;
            indice.Tudominusculo(word);
            //*****para testar a palavra depois de tirar carct e converter
            //cout<<word<<endl;
            //já insere a palavra lida e manipulada na lista de palavras do documento
            indice.wordFile.push_back(word);
            if(!indice.Pertence(word)){
                set<string>indicePalavras;
                indicePalavras.insert(nomeArquivo[i]);
                indice.palavras[word]=indicePalavras;
            }
            else{
                set<string>indicePalavrasRepetidas=indice.palavras[word];
                indicePalavrasRepetidas.insert(nomeArquivo[i]);
                indice.palavras[word]=indicePalavrasRepetidas;
            }

            }
        indice.palavrasDocs.push_back(indice.wordFile);
        arquivo_.close();

    }

 set<string>::iterator ita;
    for(ita=indice.palavras["ragnar"].begin();ita!=indice.palavras["ragnar"].end();ita++){
       cout<<*ita<<endl;
    }

}
Leitura::Leitura(int qtdArquivos){
    quantidadeArquivos=qtdArquivos;
    ReadFile(qtdArquivos);

}
