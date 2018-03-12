
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Paises{
	string nombre;
	float poblacion, superficie;


	friend ostream & operator<<(ostream & os, const Paises & p){
		os << p.nombre;
		os << " tiene " << p.poblacion << " habitantes";
		os << " y una superficie de " << p.superficie << " km2";
		os << endl;
	}

	bool operator < (const Paises & p){
		return poblacion < p.poblacion;
	}
};

struct Densidad{
	string nombre;
	float densidad;
	
	friend ostream & operator<<(ostream & os, const Densidad & d){
		os << d.nombre;
		os << " tiene una densidad de: " << d.densidad << " habs/km2";
		os << endl;
	}

	bool operator < (const Densidad & d){
		return densidad < d.densidad;
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
  
  list<Paises> l;
	vector <string> paises = {"Peru", "Spain", "Chile", "Chipre", "Japon", "Corea", "Fiji", "Brasil", "Francia", "Congo"};
  
  InicializarSemilla();
  
	// Rellenamos la lista inicial

  for (int i=0;i<10;i++){
    Paises pais;
		pais.nombre = paises[i];
		pais.poblacion = generaEntero(1,10000);
		pais.superficie = generaEntero(1,10000);
		l.push_back(pais);
	}

	// Ordeno la lista por poblacion
	l.sort();
    
  cout<<endl<<l<<endl;

	// Calculo de densidades

	list<Densidad> densidades;
	list<Paises>::iterator it;

	for(it = l.begin(); it != l.end(); ++it){
		Densidad d;

		d.nombre = (*it).nombre;
		d.densidad = ((*it).poblacion / (*it).superficie);

		densidades.push_back(d);
	}

	// Mostramos la lista de paises ordenados por densidad, de menor a mayor
	densidades.sort();
	cout << densidades << endl;

	// Mostramos los dos paises mas densos

	cout << "Los dos paises con mayor densidad son: " << endl;

	for(int i = 0; i < 2; i++){
		cout << densidades.back().nombre << endl;
		densidades.pop_back();
	}

	cout << endl;

	// Mostramos los dos paises menos densos
	cout << "Los dos paises con menor densidad son: " << endl;

	for(int i = 0; i < 2; i++){
		cout << densidades.front().nombre << endl;
		densidades.pop_front();
	}
	
	cout << endl;

	return 0;
}  
  
  
  
  
  
  
  
  
