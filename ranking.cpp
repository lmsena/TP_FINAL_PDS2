#include "ranking.h"


double Ranking::idf(string wordIDF)
{
   list<string>x;
   x = palavras[wordIDF];
  // x = palavras.at(wordIDF).second;
  // idf = log2(quantidadeArquivos / this->palavras->second.size());
   idf = log2(quantidadeArquivos / x.second);

    return idf;
}
