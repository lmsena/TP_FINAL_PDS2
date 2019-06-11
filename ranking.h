
#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<set>
#include<map>
#include <iostream>
#include<algorithm>
#include<cmath>
#include"indice.h"
#include"leitura.h"
using namespace std;



class Ranking
{
public:
    //Construtor da classe Ranking
    Ranking();

    //Destrutor para a classe Ranking
    //~Ranking();

    //calcula o idf de cada palavra
    double idf(string wordIDF,Indice indice,int quantidadeArquivos);

    // coordenadas de um vetor correspondente a um documento
    // da base de dados (indicie 'W')
   void coordenadas_W(Indice indice, int posicao_doc,int quantidadeArquivos);

    //Cria as coordenadas referente a busca e armazena no vetor coordenadasBusca
    void coordenadas_Q(Indice indice,int quantidadeArquivos);

    //Calcula A quantidade de vezes que uma palavra aparece na busca
    int TermFrequency_Q(string word,vector<string>palavrasBusca);

    //inicializa uma consulta de Palavras
    void consultaQ(Indice indice);

    //calcula as similaridades
    void Similaridade(vector <vector<double> > coordenadas_docs,vector<double>coordenadasBusca);

    //imprime o Ranking
    void ImprimeRanking(vector<string>nomeArquivo);

    //RETORNA O MAIOR VALOR EM UM VETOR
    double RetornavalorMaior(vector<double>pesos);

    //Vetor que armazena as coordenas de cada documento
    vector <vector<double> > coordenadas_docs;

    //Armazena as palavras da busca em um vetor
    vector<string>palavrasBusca;

    //Armazena as coordenadas da busca
    vector<double>coordenadasBusca;

    //Armazena as similaridades
    vector<double> similaridade_;




   friend class Leitura;
};


#endif // RANKING_H_INCLUDED
