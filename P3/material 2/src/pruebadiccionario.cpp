#include "diccionario.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ostream & operator<<(ostream & os, const pair<string,string> & p){
  os<<p.first<<";"<<p.second<<endl;
  return os;
}  
void ImprimirDiccionario(Diccionario &D){
  Diccionario::iterator it;
  for (it=D.begin(); it!=D.end();++it){
    cout<<*it<<endl;
  }
}  
int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario T;
   f>>T; //Cargamos en memoria el diccionario
   cout<<T;
   string a;
   
   
   cout<<"********Dime un tema:";
   getline(cin,a);
   cout<<endl<<endl<<"************Palabras con ese tema:"<<endl;
   Diccionario Dtema = T.ObtainPalabrasconDeficionContiene(a);
   
   
   ImprimirDiccionario(Dtema);
      
}