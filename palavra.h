#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
#include<iostream>
#include <string>
#include <fstream>
#include<list>
#include<vector>
#include<map>
#include<cmath>
using namespace std;


class Palavra
{
private:
    string wordP;
    set<string> documentosTxt; //documentos que word pertence
    double indicieInvertido;

public:
    double indicie_invertido();
    Palavra(string p, list<string> docTxt);
    ~Palavra();


};


#endif // PALAVRA_H_INCLUDED
