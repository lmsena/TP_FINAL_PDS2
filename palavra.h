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
    string word;
    set<string> documentosTxt;
    double indicieInvertido;

public:
    double indicie_invertido();


};


#endif // PALAVRA_H_INCLUDED
