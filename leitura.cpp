#include"leitura.h"

using namespace std;



//Le os arquivos
void Leitura::ReadFile(int qtdArquivos){

    Indice indice;
    Ranking ranking;
    nomeArquivo.push_back("d1.txt");
    nomeArquivo.push_back("d2.txt");
    nomeArquivo.push_back("d3.txt");
    nomeArquivo.push_back("d4.txt");


//Lendo e manipulando as palavras de cada arquivo
    for(int i=0;i<qtdArquivos;i++){
        arquivo_.open(nomeArquivo[i].c_str(),std::ios::in);
        if(arquivo_.good()){
      while(!arquivo_.eof()){
            string word;
            arquivo_>>word;
            indice.Tudominusculo(word);
            //já insere a palavra lida e manipulada na lista de palavras do documento
            indice.wordFile.push_back(word);
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
        indice.palavrasDocs.push_back(indice.wordFile);
        indice.wordFile.clear();
        arquivo_.close();

    }
    //colocado as coordenadas de cada palavra referente a cada cada arquivo em um vetor
    for(int i=0;i<quantidadeArquivos;i++){
        ranking.coordenadas_W(indice,i,quantidadeArquivos);
    }

vector<double> teste=ranking.coordenadas_docs[1];
for(unsigned int i=0;i<teste.size();i++){
        cout<<teste[i]<<endl;

}
    ranking.consultaQ(indice);
    ranking.coordenadas_Q(indice,quantidadeArquivos);
    ranking.Similaridade(ranking.coordenadas_docs,ranking.coordenadasBusca);
    ranking.ImprimeRanking(nomeArquivo);
}
//Construtor para a classe Leitura
Leitura::Leitura(int qtdArquivos){
    quantidadeArquivos=qtdArquivos;
    ReadFile(qtdArquivos);

}
