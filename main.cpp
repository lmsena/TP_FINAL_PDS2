#include "leitura.h"
#include"ranking.h"
#include "indice.h"
#include <fstream>
using namespace std;




void Maquina_busca(int numberFiles){
    Leitura leitura(numberFiles);
    Ranking ranking;
    Indice indice;
    leitura.ReadFile(leitura.quantidadeArquivos,indice);
    //colocado as coordenadas de cada palavra referente a cada cada arquivo em um vetor
    for(int i=0;i<leitura.quantidadeArquivos;i++){
        ranking.coordenadas_W(indice,i,leitura.quantidadeArquivos);
    }

vector<double> teste=ranking.coordenadas_docs[1];
for(unsigned int i=0;i<teste.size();i++){
        cout<<teste[i]<<endl;

}
    ranking.consultaQ(indice);
    ranking.coordenadas_Q(indice,leitura.quantidadeArquivos);
    ranking.Similaridade(ranking.coordenadas_docs,ranking.coordenadasBusca);
    ranking.ImprimeRanking(leitura.nomeArquivo);



}

//ate aqui read


int main () {

    Maquina_busca(4);
  return 0;
}
