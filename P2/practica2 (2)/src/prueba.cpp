//Este fichero te permite probar el modulo matriz dispersa.
#include "Matriz_Dispersa.h"
#include <cstring>

using namespace std;

int main(){

  Matriz_Dispersa P;
  int r,c;
  r=2;c=2;

  //La Ponemos horizontal
  const char * cad="hola";
  for (unsigned int i=0;i<strlen(cad);i++,c++)
    P.Set(r,c,cad[i]);

  r=2;c=2;

  for (unsigned int i=0;i<strlen(cad);i++,r++)
    P.Set(r,c,cad[i]);

  cout << P << endl;
}
