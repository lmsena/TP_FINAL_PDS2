#include <iostream>
#include "palavra.h"
#include "leitura.h"


double Palavra::indicie_invertido()
{
    indicieInvertido = log2(quantidadeArquivos / ocorrencia(this->wordP, documentoTxt));
    return indicieInvertido;
}


Palavra::Palavra(string p, list<string> docTxt)
{   
    wordP = p;
    documentosTxt = docTxt;
    
}
