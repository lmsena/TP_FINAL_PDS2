double Ranking::idf()
{
    idf = log2(quantidadeArquivos / this->palavras->second.size());
    return idf;
}
