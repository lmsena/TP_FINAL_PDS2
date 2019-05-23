#include"leitura.h"

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
int Leitura::Ocorrencias(string word,list<string>palavras){
    list<string>::iterator it;
    int ocorrencias=0;
    for(it=palavras.begin();it!=palavras.end();it++){
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

       // list<string> palavrasDoc;
       // map<string, set<string> > palavras;
       // set<string> nomesArquivos;


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
            palavrasDoc.push_back(word);
            //associa a palavra ao arquivo que a contem
            palavras[word]=nomesArquivos;
            }
    }
cout<<this->Ocorrencias("ragnar",palavrasDoc);
}
Leitura::Leitura(int qtdArquivos){
    ReadFile(qtdArquivos);

}


double Leitura::indicie_invertido()
{
    
    indicieInvertido = log2(quantidadeArquivos / Ocorrencias());
   
   // indicieInvertido = log2(quantidadeArquivos / (set<string>palavras.size()));
    
   // indicieInvertido = log2(quantidadeArquivos / (palavras.set<string>.size()));
    
    return indicieInvertido;
    
}


