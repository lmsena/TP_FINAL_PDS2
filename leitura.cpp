
#include"leitura.h"

using namespace std;

//Construtor para a classe Leitura
Leitura::Leitura(int qtdArquivos){
    quantidadeArquivos=qtdArquivos;

}



//Le os arquivos
void Leitura::ReadFile(int quantidadeArquivos,Indice &indice){
//Recebendo os nomes dos arquivos que serao lidos
    for(int i=0;i<quantidadeArquivos;i++){
        cout<<"Digite o nome do "<<i+1<<" arquivo no formato file.txt"<<endl;
        string arquivoTxt;
        cin>>arquivoTxt;
        nomeArquivo.push_back(arquivoTxt);
    }


    list<string>wordFile;


//Lendo e manipulando as palavras de cada arquivo
    for(int i=0;i<quantidadeArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);
        if(arquivo_.good()){
      while(!arquivo_.eof()){
            string word;
            arquivo_>>word;
            indice.Tudominusculo(word);
            //já insere a palavra lida e manipulada na lista de palavras do documento
            wordFile.push_back(word);
            //inserindo a palavra em um Map que relaciona  quais arquivos contem a palavra
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
    }
        else{
            cout<<"Nao foi possivel abrir o arquivo "<<nomeArquivo[i]<<endl;
            nomeArquivo.erase(nomeArquivo.begin()+i);
            quantidadeArquivos--;
            i--;
        }
        indice.palavrasDocs.push_back(wordFile);
        wordFile.clear();
        arquivo_.close();

    }
    if(quantidadeArquivos==0){
        cout<<"Nao foi possivel abrir nenhum arquivo"<<endl;
        exit(2);
    }
}


//contrutor p teste
Leitura::Leitura(int qtdArquivos, bool teste){
    quantidadeArquivos=qtdArquivos;
    Indice I();
    ReadFileTeste(quantidadeArquivos, &I);
    

}



//Le os arquivos para teste
void Leitura::ReadFileTeste(int quantidadeArquivos,Indice &indice){


    nomeArquivo.push_back("d1.txt");
    nomeArquivo.push_back("d2.txt");
    nomeArquivo.push_back("d3.txt");
    nomeArquivo.push_back("d4.txt");
    list<string>wordFile;


//Lendo e manipulando as palavras de cada arquivo
    for(int i=0;i<quantidadeArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);
        if(arquivo_.good()){
      while(!arquivo_.eof()){
            string word;
            arquivo_>>word;
            indice.Tudominusculo(word);
            //já insere a palavra lida e manipulada na lista de palavras do documento
            wordFile.push_back(word);
            //inserindo a palavra em um Map que relaciona  quais arquivos contem a palavra
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
    }
        else{
            cout<<"Nao foi possivel abrir o arquivo "<<nomeArquivo[i]<<endl;
            nomeArquivo.erase(nomeArquivo.begin()+i);
            quantidadeArquivos--;
            i--;
        }
        indice.palavrasDocs.push_back(wordFile);
        wordFile.clear();
        arquivo_.close();

    }
    if(quantidadeArquivos==0){
        cout<<"Nao foi possivel abrir nenhum arquivo"<<endl;
        exit(2);
    }
}


