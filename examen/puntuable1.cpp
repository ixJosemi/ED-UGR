
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

struct contenido{
  float aparicion;
  char letra;

  friend ostream & operator<<(ostream & os, const contenido & st){
    os << "Letra: " << st.letra << endl;
    os << "Aparicion: " << st.aparicion << endl;

    return os;
  }
};


/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;

  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

int main(){

  list<contenido> l;
  contenido cont;

  InicializarSemilla();

  for(char i = 'A'; i <= 'Z'; i
    cont.aparicion = generaEntero(1, 100);
    cont.letra = i;

    l.push_back(cont);
  }

  cout << endl << l;

  //list<int> l;

  // InicializarSemilla();

  // for (int i=0;i<10;i++)
  //  l.push_back(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  // cout<<endl<<l;
}
