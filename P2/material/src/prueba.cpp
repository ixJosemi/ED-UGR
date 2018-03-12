
//Este fichero te permite probar el modulo matriz dispersa.

#include "matriz_dispersa.h"
#include <cstring>
int main(){

 
 Matriz_Dispersa<char> P;
 int r,c;
 r=2;c=2;
 //La Ponemos horizontal
 const char * cad="hola";
 for (unsigned int i=0;i<strlen(cad);i++,c++)
     P.Set(r,c,cad[i]);
 r=2;c=2;
 
 for (unsigned int i=0;i<strlen(cad);i++,r++)
     P.Set(r,c,cad[i]);
 cout<<P<<endl;
 
}     