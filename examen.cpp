#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Partidos{
  int eq1, eq2, goles_eq1, goles_eq2;

  friend ostream & operator<<(ostream & os, const Partidos & p){
    os << "Equipo 1: " << p.eq1;
    os << " Equipo 2: " << p.eq2;
    os << " Goles equipo 1: " << p.goles_eq1;
    os << " Goles equipo 2: " << p.goles_eq2;
    os << endl;
  }
};

struct Total{
  int eq, total_goles = 0;

  friend ostream & operator<<(ostream & os, const Total & t){
    os << "Equipo: " << t.eq;
    os << " Total de goles del equipo: " << t.total_goles;
    os << endl;
  }
};

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimir
 */
template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;

  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numeros aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
 */
void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero entero positivo aleatorio en el rango [min,max]
 */
int generaEntero(int min, int max){
    int tam = max-min+1;
    return ((rand()%tam)+min);
}

int main(){

  Partidos partido;
  list<Partidos> l;

  InicializarSemilla();

  for(int i = 0; i < 10; i++){
    partido.eq1 = generaEntero(1, 9);
    partido.eq2 = generaEntero(1, 9);

    while(partido.eq1 == partido.eq2)
      partido.eq2 = generaEntero(1, 9);

    partido.goles_eq1 = generaEntero(1, 10);
    partido.goles_eq2 = generaEntero(1, 10);

    l.push_back(partido);
  }

  Total total;
  list<Total> resultados;
  list<Partidos>::iterator it = l.begin();


  for(int i = 1; i < 10; i++){
    total.eq = i;

    while (it != l.end()){
      if(i == (*it).eq1)
        total.total_goles += (*it).goles_eq1;
      else if(i == (*it).eq2)
        total.total_goles += (*it).goles_eq2;

      ++it;
    }

    resultados.push_back(total);
  }

  cout<<endl<<l<<endl;
  cout << resultados << endl;
}
