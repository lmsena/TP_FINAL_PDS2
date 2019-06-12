#include "leitura.h"
#include"ranking.h"
#include "indice.h"
#include <fstream>
using namespace std;




void Maquina_busca(int numberFiles,int palavrasToFind){
    Leitura leitura(numberFiles);
    Ranking ranking;
    Indice indice;
    leitura.ReadFile(leitura.quantidadeArquivos,indice);
    //colocado as coordenadas de cada palavra referente a cada cada arquivo em um vetor
    for(int i=0;i<leitura.quantidadeArquivos;i++){
        ranking.coordenadas_W(indice,i,leitura.quantidadeArquivos);
    }


    //Inicializadando a consulta de palavras
    ranking.consultaQ(indice,palavrasToFind);
    //Cria as coordenadas referente a busca e armazenando no vetor coordenadasBusca
    ranking.coordenadas_Q(indice,leitura.quantidadeArquivos);
    //Calculando a similaridade
    ranking.Similaridade(ranking.coordenadas_docs,ranking.coordenadasBusca);
    //Imprimindo o Ranking
    ranking.ImprimeRanking(leitura.nomeArquivo);



}

//ate aqui read


int main () {
  cout<<"TP FINAL DA DISCIPLINA PDS2 , ALUNOS: JOSE RAIMUNDO, LEONARDO E BRUNO"<<endl<<endl;
  Maquina_busca(4,2);
  return 0;
}
