#include"leitura.h"

//Retorna true se uma palavra pertence a um arquivo
bool Leitura::Pertence(string word){
    if(palavras.find(word)==palavras.end()){
        return false;
    }
    else{
        return true;
    }
}

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


        nomeArquivo.push_back("teste.txt");
        nomeArquivo.push_back("young.txt");
        nomeArquivo.push_back("music.txt");
       
        string wordAux;
       
     /*
      * forma para inserir quantidades grandes de arquivos  
  
        string wordQ;
        for(int q = 0; q<qtdArquivos; q++)
        {
            cout << "insira o nome do aruivo: "; 
            cin >> wordQ;
            nomeArquivo.push_back(wordQ);
        }
     */

    for(int i=0;i<qtdArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);
        while(!arquivo_.eof())
            {
            arquivo_>>word;
            Tudominusculo(word);
            //*****para testar a palavra depois de tirar carct e converter
            //cout<<word<<endl;
            
            //já insere a palavra lida e manipulada na lista de palavras do documento
            wordFile.push_back(word);
            if(!Pertence(word)){
                set<string>indicePalavras;
                indicePalavras.insert(nomeArquivo[i]);
                palavras[word]=indicePalavras;
            }
            else{
                set<string>indicePalavrasRepetidas=palavras[word];
                indicePalavrasRepetidas.insert(nomeArquivo[i]);
                palavras[word]=indicePalavrasRepetidas;
               // acesso alternativo a palavra word 
               // palavras.at(word) = indiciePalavrasRepetidas;
            }
          
          }
        palavrasDocs.push_back(wordFile);
        arquivo_.close();

    }

 set<string>::iterator ita;
    for(ita=palavras["ragnar"].begin();ita!=palavras["ragnar"].end();ita++){
       cout<<*ita<<endl;
    }

}
Leitura::Leitura(int qtdArquivos){
    quantidadeArquivos=qtdArquivos;
    ReadFile(qtdArquivos);

}
