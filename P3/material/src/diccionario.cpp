#include "diccionario.h"
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

// Comprueba que la clave que se pasa esta dentro del mapa
bool Diccionario::esta_clave(const string & p, typename multimap<string, string>::iterator & it){
  it = palabras.find(p);       // Busco la clave en el diccionario
  return it != palabras.end(); // devuelve si la clave está o no
}

// Inserta un nuevo par clave-definicion
void Diccionario::insertar(const string & clave, const string & valor){
  typename multimap<string, string>::iterator it;

  // Si la clave no esta en el diccionario, inserto un nuevo par clave-definicion
  if(!esta_clave(clave, it)){
    pair<string, string> par;
    par.first = clave;
    par.second = valor;

    palabras.insert(it, par);
  }
  else{ // Si si esta, pero no existe el valor que pasamos, introducimos un nuevo par clave-definicion
    typename multimap<string, string>::iterator it2 = palabras.find(clave);;

    if((*it2).second != valor){
      pair<string, string> par;
      par.first = clave;
      par.second = valor;

      palabras.insert(it, par);
    }
  }
}

// Devuelve la definicion correspondiente con la clave que le pasamos
string Diccionario::getdefinicion(const string & clave){
  typename multimap<string, string>::iterator it;

  assert(esta_clave(clave, it));
  return (*it).second;
}

// Devuelve las palabras que contienen un determinado tema
Diccionario Diccionario::ObtainPalabrasconDeficionContiene(string t){
  Diccionario d;
  multimap<string, string>::iterator it;
  string def;

  for(it = palabras.begin(); it != palabras.end(); ++it){
    def = (*it).second;

      if(def.find(t) != string::npos){
        d.insertar((*it).first, (*it).second);
      }
  }
  return d;
}

// Sobrecarga del operador de entrada de flujo
istream & operator>>(istream & fi, Diccionario & d){
  string lectura;
  string palabra;
  string definicion;
  int pos;

  while(getline(fi, lectura)){
    pos = lectura.find(";");
    palabra = lectura.substr(0, pos);
    definicion = lectura.substr(pos+1, lectura.size());

    d.insertar(palabra, definicion);
  }

  return fi;
}

// Sobrecarga del operador de salida de flujo
ostream & operator<<(ostream & fo, const Diccionario & d){
  typename multimap<string,string>::const_iterator it;

  for(it = d.palabras.begin(); it != d.palabras.end(); ++it)
    fo << (*it).first << "; " << (*it).second << endl;

  return fo;
}
