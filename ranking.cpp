#include "ranking.h"



//construtor para a classe
Ranking::Ranking(){

}
 //calcula o idf de cada palavra
double Ranking::idf(string wordIDF,Indice indice,int quantidadeArquivos)
{
   double idf_;
   set<string> x;
   x = indice.palavras[wordIDF];
   double auxiliar=quantidadeArquivos;
   idf_ = log (auxiliar/x.size());
    return idf_;
}
// coordenadas de um vetor correspondente a um documento
// da base de dados (indicie 'W')
void Ranking::coordenadas_W(Indice indice, int posicao_doc,int quantidadeArquivos )
{
    map <string, set<string> >::iterator iter;
    vector<double> coordenadas;
    iter=indice.palavras.begin();
    iter++;
    for(iter=iter;iter!=indice.palavras.end();iter++){
        coordenadas.push_back(indice.TermFrequency(iter->first,indice.palavrasDocs,posicao_doc)*idf(iter->first,indice,quantidadeArquivos));
    }
    coordenadas_docs.push_back(coordenadas);
    coordenadas.clear();
}
//GERA O TERMINAL DE CONSULTA DE PALAVRAS NO PROMPT DE COMANDO
void Ranking::consultaQ(Indice indice){
    cout<<"Insira a quantidade de palavras que voce deseja procurar"<<endl;
    int quantidadePalavras;
    cin>>quantidadePalavras;
    for(int i=0;i<quantidadePalavras;i++){
        cout<<"Digite a palavra que voce deseja pesquisar"<<endl;
        string palavras;
        cin>>palavras;
        indice.Tudominusculo(palavras);
        palavrasBusca.push_back(palavras);

    }

        }
//RETORNA O NUMERO DE OCORRENCIAS DE UMA PALAVRA NA BUSCA
int Ranking::TermFrequency_Q(string word,vector<string>palavrasBusca){
    int ocorrencias=0;
    for(unsigned int i=0;i<palavrasBusca.size();i++){
        if(palavrasBusca[i]==word){
            ocorrencias++;
        }

    }
    return ocorrencias;
}
//Cria as coordenadas referente a busca e armazena no vetor coordenadasBusca
void Ranking::coordenadas_Q(Indice indice,int quantidadeArquivos){
    map <string, set<string> >::iterator iter;
    iter=indice.palavras.begin();
    iter++;
    for(iter=iter;iter!=indice.palavras.end();iter++){
        coordenadasBusca.push_back(TermFrequency_Q(iter->first,palavrasBusca)*idf(iter->first,indice,quantidadeArquivos));
    }

}
//CRIA UM VETOR COM SIMILARIDADE RELACIONADA A CADA ARQUIVO
void Ranking::Similaridade(vector <vector<double> >coordenadas_docs,vector<double> coordenadasBusca){
    double soma=0;
    for(unsigned int j=0;j<coordenadas_docs.size();j++){
        vector<double>aux=coordenadas_docs[j];

        for(unsigned int i=0;i<coordenadasBusca.size();i++){
            soma=(aux[i]*coordenadasBusca[i])+soma;

        }

    similaridade_.push_back(soma);
    soma=0;
    }
}
//RETORNA O MAIOR VALOR DE UM VETOR
double Ranking:: RetornavalorMaior(vector<double>pesos){
    double maximo=pesos[0];
    for(unsigned int i=1;i<pesos.size();i++){
            if(maximo<pesos[i]){
                maximo=pesos[i];
            }

    }
    return maximo;
}
//IMPRIME O RANKING DA CONSULTA
void Ranking::ImprimeRanking(vector<string>nomeArquivo){
    double maximo;
    int k=1;
    int j=0;
    int unsigned contador=1;
    vector<double>aux=similaridade_;
    maximo=RetornavalorMaior(aux);
    cout<<"-------Ranking------"<<endl;
    cout<<"Posicao ---"<<"Documentos"<<endl;
    while(contador < nomeArquivo.size()){
            cout<<"   "<<k;
            k++;
            for( unsigned int i=0;i<similaridade_.size();i++){
                if(aux[i]==maximo){
                    if(j==0){
                        cout<<"            "<<nomeArquivo[i];
                        aux[i]=-1;
                        j++;
                    }
                    else{
                        cout<<" e "<<nomeArquivo[i];
                        aux[i]=-1;
                    }
                }


            }
            maximo=RetornavalorMaior(aux);
            if(maximo==-1){
                exit(3);
            }
            cout<<endl;
            j=0;
            contador++;
    }



}

