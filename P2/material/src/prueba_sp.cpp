#include "matriz_dispersa.h"
#include <cstring>
#include <fstream>
#include "sopa_letras.h"
int main(int argc, char * argv[]){
 
    if (argc!=2){
      cout<<"Dime el nombre del fichero con las palabras de la sopa de letras"<<endl;
      return 0;
    }
    ifstream f(argv[1]);
    if (!f){
	cout<<"No puedo abrir "<<argv[1]<<endl;
	return 0;
    }
    Sopa_letras Sl;
    f>>Sl;//Leemos las palabras y construimos la sopa de letras
    //El usuario ahora tiene que ir descubriendo las palabras
    //en la sopa de letras
    while (Sl.NumPalabras()!=0){
       cout<<Sl<<endl;
       cout<<"Dime una palabra: ";
       string word;
       cin>>word;
       cout<<"Dime la fila :";
       int row;
       cin>>row;
       cout<<"Dime la columna :";
       int col;
       cin>>col;
       
       cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";
       dir direccion;
       cin>>direccion;
       if (!Sl.Comprobar_Palabra(word,row,col,direccion)){//Esta?
	 cout<<"La palabra "<<word << " no esta"<<endl;
       }
       else{
	 //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
	  Sl.Poner_Acertada(word,row,col,direccion);
       }
    }
    cout<<Sl<<endl;
       
}     