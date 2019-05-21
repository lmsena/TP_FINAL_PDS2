#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include "leitura.h"
using namespace std;

// tira caracteres de uma string
void tiraCaracter(string&word){
    for(unsigned int i=0;i<word.size();i++){
        if(word[i]=='.'||word[i]=='?'||word[i]=='/'||word[i]==';'||word[i]==']'||word[i]=='['||word[i]=='-'||word[i]==')'||word[i]=='('||word[i]==','||word[i]==':'){
            word.erase(word.begin()+i);
            i=i-1;
        }



    }

}

string Tudominusculo(string &word){

    for(unsigned int i=0;i<word.size();i++){
        word[i]=tolower(word[i]);

    }
    tiraCaracter(word);
    //cout<<word<<"aqui"<<endl;
    return word;
}
int main () {
  //string word;
  //ifstream arquivo;
  //arquivo.open("teste.txt");
  //while(!arquivo.eof()){
  //  arquivo>>word;
    //cout<<word<<endl;
    //cout<<"here"<<endl;
 //   Tudominusculo(word);
   // cout<<word<<endl;

  //}
  Leitura(1);

  return 0;
}
