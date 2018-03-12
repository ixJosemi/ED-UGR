/**
  * @file Sop a_Letras.h
  * @brief Fichero cabecera del modulo Sopa de Letras
  *
  */
#ifndef _SOPA_LETRAS
#define _SOPA_LETRAS

#include "matrizdispersa.h"
#include <iostream>
#include <string>
#include <list>
#include <queue>

using namespace std;

/**
  * @brief Modulo Sopa de Letras
  *
  * Una instancia @e sp del modulo @c Sopa de Letras contiene un conjunto
  * de palabras dispuestos en las direcciones verticales, horizontales o diagonal
  * en una matriz dispersa.
  *
  * @author Jose Miguel Hernandez Garcia
  * @date Diciembre 2017
  */

class Sopa_Letras{
private:

/**
  * @page repSopaLetras Rep del modulo Sopa de Letras
  *
  * @section invSopaLetras Invariante de la representacion
  *
  * La direccion debe ser vd(arriba), vu(abajo), hd(derecha), hi(izquierda),
  * dd(diagonal derecha), di(diagonal izquierda)
  *
  * @section faSopaLetras Funcion de abstraccion
  *
  * Un objeto valido @e rep del modulo Sopa de Letras
  * contiene un conjunto de palabras dispuesto en la direcciones
  * verticales, horizontal o diagonal en una matriz dispersa
  *
  */

  Matriz_Dispersa <char> sp; /**< Matriz dispersa que almacena la sopa de letras */
  queue <string> encontradas; /**< Cola que almacena las palabras encontradas */
  list <string> ocultas; /**< Lista que almacena las palabras ocultas */
  string direccion; /**< Direccion en la que va la palabra */
  string titulo; /**< Titulo de la sopa de letras */
  Matriz_Dispersa <char> acertadas; /**< Matriz con valores acertados */

public:

/**
  * @brief Constructor por defecto. Crea una sopa de letras vacia
  */
  Sopa_Letras();

/**
  * @brief Comprobar si una palabra a partir de una posición (fila,columna)
  * y dirección se encuentra en la sopa de letras
  * @param p Palabra a comprobar
  * @param f Fila de la palabra a comprobar
  * @param c Columna de la palabra a comprobar
  * @param direccion Direccion de la palabra a comprobar
  * @return Devuelve si la palabra se encuentra o no en la sopa de letras
  */
  bool Comprobar_Palabra(string p, int f, int c, string direccion);

/**
  * @brief Comprobar si una palabra esta en la lista de palabras no descubiertas
  * @param p Palabra a comprobar
  * @return Devuelve si la palabra se encuentra en la lista de no descubiertas o no
  */
  bool palabranodescubierta(string p);

/**
  * @brief Comprobar si es posible poner una palabra en una posicion (f, c) y direccion.
  * Una palabra puede colocarse si en cada casilla que ocupa tiene el valor por defecto,
  * o si no es así el caracter de la matriz debe coincidir con el caracter  que
  * corresponda  de la palabra
  * @param p Palabra a colocar
  * @param f Fila en la que se desea colocar la palabra
  * @param c Columna en la que se desea colocar la palabra
  * @param direccion Direccion en que la se desea colocar la palabra
  * @return Devuelve si la palabra puede ser insertada o no
  */
  bool esposiblecolocar(string p, int f, int c, string direccion);

/**
  * @brief Obtener el numero de palabras no descubiertas por el usuario
  * @return Devuelve el numero de palabras no descubiertas
  */
  int nodescubiertas() const;

/**
  * @brief Obtener el numero de palabras descubiertas por el usuario
  * @return Devuelve el numero de palabras descubiertas
  */
  int descubiertas() const;

/**
  @brief Establece el titulo de la sopa de letras
  */
  void settitulo(string t){
    titulo = t;
  }

/**
  * @brief Colocar una palabra en una posicion y con una direccion concreta
  * @param p Palabra a colocar
  * @param f Fila en la que se desea colocar la palabra
  * @param c Columna en la que se desea colocar la palabra
  * @param direccion Direccion en la que se desea colocar la palabra
  */
  void colocarpalabra(string p, int f, int c, string direccion);

/**
  * @brief Modificar una palabra en la matriz dispersa como acertada. Quitarla
  * de palabras no descubiertas y moverla a palabras descubiertas
  * @param p Palabra a modificar
  * @param f Fila de la palabra a modificar
  * @param c Columna de la palabra a modificar
  * @param direccion Direccion de la palabra a modificar
  */
  void Poner_Acertada(string p, int f, int c, string direccion);

/**
  * @brief Devuelve una lista de palabras ocultas
  */
  list <string> getpalabrasocultas(){
    return ocultas;
  }

/**
  * @brief Pone a negrita lo que se muestre por el flujo de salida
  * @param os Stream de salida
  * @post Muestra lo que sale por el flujo de salida en negrita
  */
  friend ostream & bold_on(ostream & fo);

/**
  * @brief Quita el negrita de lo que se muestra por el flujo de salida
  * @param os Stream de salida
  * @post Quita el negrita del flujo de salida
  */
  friend ostream & bold_off(ostream & fo);

/**
  * @brief Salida de una Sopa de letras a ostream
  * @param fo Stream de salida
  * @param s Sopa de letras a escribir
  * @post Pinta el titulo de la sopa de letras, el numero de palabras ocultas y
  * acertadas y posteriormente la sopa de letras
  */
  friend ostream & operator<<(ostream & fo, const Sopa_Letras & s);

/**
  * @brief Entrada de una Sopa de letras desde istream
  * @param fi Stream de entrada
  * @param s Sopa de letras que recibe el valor
  * @return La Sopa de letras leida en s
  * @pre La entrada es del tipo: fila columna direccion palabra
  */
  friend istream & operator>>(istream & fi, Sopa_Letras & s);

};

#endif
