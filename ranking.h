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



class Ranking()
{
public:

    Ranking();
    ~Ranking();

     // coordenadas de um vetor correspondente a um documento
    // da base de dados (indicie 'W')
   double coordenadas_W(string wordW, vector< list<string> >palavras_no_doc, int posicao_doc );



   friend class Indice;
   friend class Leitura;
};


#endif // RANKING_H_INCLUDED

