#include "ranking.h"

double Ranking::coordenadas_W(string wordW, vector< list<string> >palavras_no_doc, int posicao_doc )
{
    double W = termFrequency(wordW, vector< list<string> >palavras_no_doc, int posicao_doc ) * idf(wordW);
    return W;
}

