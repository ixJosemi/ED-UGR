/*************************************************/
/* Implementacion del modulo de Matriz Dispersa  */
/* Jose Miguel Hernandez Garcia                  */
/* 2C C3                                         */
/*************************************************/

#include "matrizdispersa.h"
#include <iostream>

using namespace std;

// Contructor por defecto de la clase
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa(){
  valor_defecto = 0;
}

// Constructor con parametro val_defecto
template <class T>
Matriz_Dispersa<T>::Matriz_Dispersa(T val_defecto){
  valor_defecto = val_defecto;
}

// Funcion que obtiene el elemento en la posicion (f, c)
template <class T>
T Matriz_Dispersa<T>::elemento(int f, int c) const{
  T valor = 0;
  bool encontrado = false;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end() && !encontrado; ++it)
    if((*it).fila == f && (*it).col == c){
      valor = (*it).d;
      encontrado = true;
    }

  return valor;
}

// Funcion que devuelve la fila menor
template <class T>
int Matriz_Dispersa<T>::fmenor() const{
  int min = l.front().fila;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it)
    if((*it).fila < min)
      min = (*it).fila;

  return min;
}

//Funcion que devuelve la fila mayor
template <class T>
int Matriz_Dispersa<T>::fmayor() const{
  int max = l.front().fila;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it)
    if((*it).fila > max)
      max = (*it).fila;

  return max;
}

// Funcion que devuelve la columna menor
template <class T>
int Matriz_Dispersa<T>::cmenor() const{
  int min = l.front().col;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it)
    if((*it).col < min)
      min = (*it).col;

  return min;
}

// Funcion que devuelve la columna mayor
template <class T>
int Matriz_Dispersa<T>::cmayor() const{
  int max = l.front().col;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it)
    if((*it).col > max)
      max = (*it).col;

  return max;
}

// Funcion que devuelve el numero de casillas con valor distinto a valor por defecto
template <class T>
int Matriz_Dispersa<T>::casillasinicializadas(){
  int cont = 0;
  typename list<tripleta<T>>::const_iterator it;

  for(it = l.begin(); it != l.end(); ++it)
    if((*it).d != valor_defecto)
      cont++;

  return cont;
}

// Funcion que devuelve el numero total de filas
template <class T>
int Matriz_Dispersa<T>::numfilas() const{
  return fmayor() - fmenor() + 1;
}

// Funcion que devuelve el numero total de columnas
template <class T>
int Matriz_Dispersa<T>::numcols() const{
  return cmayor() - cmenor() + 1;
}

// Funcion para modificar o insertar un valor en la posicion (f, c)
template <class T>
void Matriz_Dispersa<T>::set(int f, int c, T valor){
  bool encontrado = false;
  typename list<tripleta<T>>::iterator it;

  if(valor == valor_defecto){
    for(it = l.begin(); it != l.end() && !encontrado; ++it){
      if((*it).fila == f && (*it).col == c){
        encontrado = true;
        it = l.erase(it); // Borramos el elemento en esa posicion si valor == valor_defecto
      }
    }
  }
  else{
    for(it = l.begin(); it != l.end() && !encontrado; ++it){
      if((*it).fila == f && (*it).col == c){
        encontrado = true;
        (*it).d = valor; // Modifica el valor
      }
    }
  }

  // Si no lo encontramos, lo insertamos como un nuevo valor
  if(!encontrado){
    tripleta<T> t;
    t.fila = f;
    t.col = c;
    t.d = valor;

    l.push_back(t); // Lo insertamos al final
    l.sort();       // Ordenamos la matriz dispersa
  }
}
