/*************************************************/
/* Implementacion del modulo de Sopa de Letras   */
/* Jose Miguel Hernandez Garcia                  */
/* 2C C3                                         */
/*************************************************/

#include "Sopa_Letras.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Constructor por defecto
Sopa_Letras::Sopa_Letras(){
  direccion = '0';
}

// Funcion para comprobar que una palabra esta dentro de la sopa de letras
bool Sopa_Letras::Comprobar_Palabra(string p, int f, int c, string direccion){
  bool esta = false;

  for(unsigned i = 0; i < p.length() && !esta; i++){
    char cd = p.at(i);

    if(cd == sp.elemento(f, c)){
      if(direccion == "vu")
        f--;
      else if(direccion == "vd")
        f++;
      else if(direccion == "hi")
        c--;
      else if(direccion == "hd")
        c++;
      else if(direccion == "dd"){
        f++;
        c++;
      }
      else if(direccion == "di"){
        f++;
        c--;
      }
      esta = true;

    }else
      esta = false;
  }

  return esta;
}

// Funcion para comprobar si una palabra p ha sido descubierta o no
bool Sopa_Letras::palabranodescubierta(string p){
  bool nodescubierta = false;

  for(int i = 0; i < ocultas.size() && !nodescubierta; i++)
    if(p == ocultas[i])
      nodescubierta = true;

  return nodescubierta;
}

// Funcion para comprobar si es posible colocar una palabra en la posicion(f, c)
bool Sopa_Letras::esposiblecolocar(string p, int f, int c, string direccion){
  bool es_posible = true;

  for(unsigned i = 0; i < p.length() && es_posible; i++){
    char cd = p.at(i);

    if(cd == sp.elemento(f, c) || sp.elemento(f, c) == sp.valordefecto()){
      if(direccion == "vu")
        f--;
      else if(direccion == "vd")
        f++;
      else if(direccion == "hi")
        c--;
      else if(direccion == "hd")
        c++;
      else if(direccion == "dd"){
        f++;
        c++;
      }
      else if(direccion == "di"){
        f++;
        c--;
      }
    }
    else
      es_posible = false;
  }
  return es_posible;
}

// Funcion para obtener el numero de palabras no descubiertas
int Sopa_Letras::nodescubiertas() const{
  return ocultas.size();
}

// Funcion para obtener el numero de palabras descubiertas
int Sopa_Letras::descubiertas() const{
  return encontradas.size();
}

// Funcion para colocar una palabra p en la posicion(f, c)
void Sopa_Letras::colocarpalabra(string p, int f, int c, string direccion){
  if(esposiblecolocar(p, f, c, direccion)){
    ocultas.insertar(p, ocultas.size());

    for(unsigned i = 0; i < p.length(); i++){
      char cd = p.at(i);
      sp.Set(f, c, cd);

      if(direccion == "vu")
        f--;
      else if(direccion == "vd")
        f++;
      else if(direccion == "hi")
        c--;
      else if(direccion == "hd")
        c++;
      else if(direccion == "dd"){
        f++;
        c++;
      }
      else if(direccion == "di"){
        f++;
        c--;
      }
    }
  }
}

// Funcion para poner una palabra p a acertada
void Sopa_Letras::Poner_Acertada(string p, int f, int c, string direccion){
  if(Comprobar_Palabra(p, f, c, direccion)){
    for(int i = 0; i < ocultas.size(); i++)
      if(ocultas[i] == p){
        encontradas.insertar(p, encontradas.size());
        ocultas.borrar(i);

        for(unsigned j = 0; j < p.length(); j++){
          char cd = p.at(j);
          acertadas.Set(f, c, cd);

          if(direccion == "vu")
            f--;
          else if(direccion == "vd")
            f++;
          else if(direccion == "hi")
            c--;
          else if(direccion == "hd")
            c++;
          else if(direccion == "dd"){
            f++;
            c++;
          }
          else if(direccion == "di"){
            f++;
            c--;
          }
        }
      }
  }
}

// Funciones para poner y quitar la letra en negrita
ostream & bold_on(ostream & fo){
  return fo << "\e[1m";
}

ostream & bold_off(ostream & fo){
  return fo << "\e[0m";
}

// Sobrecarga del operador de salida
ostream & operator<<(ostream & fo, const Sopa_Letras & s){
  srand(time(NULL));
  fo << "\nTITULO: " << s.titulo
     << " Numero de palabras ocultas: " << s.nodescubiertas()
     << ", Numero de palabras descubiertas: " << s.descubiertas() << "\n";

  fo << "**************************\n\t";

  // Pintamos el numero de las columnas
  for(int i = s.sp.cmenor(); i < s.sp.cmayor()+1; i++){
    fo << i << "\t";
  }

  fo << "\n";

  // Hacemos el ciclo desde la fila menor a la mayor+1 para poder pintar todas las palabras
  for(int i = s.sp.fmenor(); i < s.sp.fmayor()+1; i++){
    // Hacemos el ciclo desde columna menor -1 para poder pintar en esa primera columna
    // el numero de filas
    for(int j = s.sp.cmenor()-1; j < s.sp.cmayor()+1; j++){
      if(j == s.sp.cmenor()-1)
        fo << i << "\t"; // pintamos numero de filas
      else{
        if(s.sp.elemento(i, j) == s.sp.valordefecto()){
          // GENERAMOS LETRA ALEATORIA
          int n = rand() % 26; // genera un numero aleatorio entre 0 y 26
          char c = (char)(n+65); // cambia el entero a un caracter en mayuscula aleatorio
          fo << c << "\t";
        }
        else{
          if(s.sp.elemento(i, j) == s.acertadas.elemento(i, j)){
            fo << bold_on << s.sp.elemento(i, j) << bold_off << "\t"; // ponemos a negrita
          }
          else
            fo << s.sp.elemento(i, j) << "\t";
        }
      }
    }
    fo << "\n";
  }

  fo << "\n";

  return fo;
}

// Sobrecarga del operador de lectura
istream & operator>>(istream & fi, Sopa_Letras & s){
  string p, dir;
  int f;
  int c;

  getline(fi, s.titulo);

  while(fi >> f >> c >> dir >> p){
    s.colocarpalabra(p, f, c, dir);
  }

  return fi;
}
