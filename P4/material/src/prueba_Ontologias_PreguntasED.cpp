#include <iostream>
#include <fstream>
#include "Ontologias.h"
#include "PreguntasED.h"
using namespace std;


int main(int argc, char * argv[]){
 if (argc!=3){
    cout<<"Dime el fichero con la estructura jerarquica de las palabras"<<endl;//Arbol_Ontologias.txt
    cout<<"Dime el fichero con los significados"<<endl; //significados.txt
    return 0;
 }
 //Seccion 1: probando el arbol 
  ifstream f (argv[1]);
 ArbolGeneral<pair<set<string>,int> > ab;
 f>>ab;
  ArbolGeneral<pair<set<string>,int> >::iter_preorden it;
 for (it=ab.begin();it!=ab.end();++it){
   if (it.getlevel()<3){
     for (int i=0;i<=it.getlevel();i++)
       cout<<"----";
     cout<<it.getlevel()<<".-";
    pair<set<string>,int> aux= *it;
    set<string>::iterator sit=aux.first.begin();
    while (sit!=aux.first.end()){
        cout<<*sit<<", ";++sit;
    }   
    cout<<endl;
    
   }
 }  
 //Seccion 2: probando Ontologias
 Ontologias Ot;
 //Lee la estructura jerarquica de las palabras y sus 
 //significados.
 Ot.Lee(argv[1],argv[2]);
 
 //comprobar que es correcta la lectura escribiendo ontologias.
 string test_salida1=argv[1]+"back";
 string test_salida2=argv[2]+"back";
 Ot.Escribe(test_salida1.c_str(),test_salida2.c_str());
 
 int level;
 cout<<"Dime un nivel de tematica (1),(2),(3)"<<endl;
 cin>>level;
 
 cout<< "Las temáticas posibles a nivel"<<level<<" son:"<<endl;
 Ontologias::iterator_level itl;
 int cnt=1;
 for (itl=Ot.beginl(level);itl!=Ot.endl(); ++itl){
   pair<set<string>,int> aux= *itl;
   set<string>::iterator sit=aux.first.begin();
   cout<<"Temática "<<cnt;
   cnt++;
   while (sit!=aux.first.end()){
        cout<<*sit<<", ";
        ++sit;
   }
   cout<<endl;
 }
 cin.get();
 cin.get();
 
 //Seccion 3: probando preguntasED
 
 cout<<"Test PreguntasED************************************"<<endl;
 
 PreguntasED Ask(Ot);
 Ask.MuestraTematicas();
 
 cout<<"Escoge una de las tematicas posibles:";
 int ntema;
 cin>>ntema;
 Ask.SetTematica(ntema);
 Ask.IniciaConceptosTemaEscogido();
 cout<<"**************************************"<<endl;
 cin.get();
 Ask.BarajarPreguntas();
 int i=0;
 while (i<Ask.num_preguntas()){
     pair<set<string>,string> p= Ask.SacaPregunta();
     cout<<p.second<<"?";
     string con;
     getline(cin,con);
     if (p.first.find(con)!=p.first.end()){
       cout<<"Correcta"<<endl;
     }
     else
        cout<<"NO es correcta la contestacion es cualquiera de las palabras: "<<p.first<<endl;
     ++i;
 }     
 
  
}  
