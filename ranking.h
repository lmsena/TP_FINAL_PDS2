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

    //calcula o idf de cada palavra
    double idf(string wordIDF);

    // coordenadas de um vetor correspondente a um documento
    // da base de dados (indicie 'W')
    double coordenadas_W_doc(string wordW, vector < list<string> > pal_dos_doc, int k, );





   friend class Leitura;
};


#endif // RANKING_H_INCLUDED

