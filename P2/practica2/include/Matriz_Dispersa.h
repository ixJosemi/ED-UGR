/**
  * @file Matriz_Dispersa.h
  * @brief Fichero de cabecera del TDA Matriz Dispersa
  *
  */

#ifndef _MATRIZ_DISPERSA
#define _MATRIZ_DISPERSA

#include "vd.h"
#include <iostream>

using namespace std;

struct tripleta{
  int fila, col;
  char d;

  tripleta & operator=(const tripleta & t){
    fila = t.fila;
    col = t.col;
    d = t.d;

    return * this;
  }
};

/**
  * @brief T.D.A. Matriz dispersa
  *
  * Una instancia @e m del tipo de datos abstracto @c Matriz Dispersa es un objeto
  * almacenado en un T.D.A. Vector Dinamico donde cada casilla del vector contiene
  * una tripleta formada por la fila, la columna y el valor en esa posicion.
  * Ya que una matriz dispersa es aquella donde la mayoria de valores
  * estan inicializados a un valor nulo que en este caso es 0;
  *
  * @author Jose Miguel Hernandez Garcia
  * @date Noviembre 2017
  */

class Matriz_Dispersa{
private:

/**
  * @page repMatriz Rep del TDA Matriz dispersa
  *
  * @section invConjunto Invariable de la representacion
  *
  * El valor por defecto debe ser distinto de 0
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA Matriz Dispersa representa una matriz
  * donde la mayoria de valores son nulos y solo unos pocos estan inicializados
  * a un valor distinto al valor por defecto
  *
  */

  VD <tripleta> m; /**< Matriz creada a partir de un TDA Vector Dinamico */
  char valor_defecto; /**< Valor por defecto de las casillas */

public:

/**
  * @brief Constructor por defecto de la clase. Inicializa todo a 0
  */
  Matriz_Dispersa();

/**
  * @brief Constructor con parametros
  * @param val_defecto Valor por defecto al que se inicializan las casillas
  * @return Establece el valor por defecto a val_defecto
  */
  Matriz_Dispersa(char val_defecto);

/**
  * @brief Obtener el elemento en la posicion (f, c)
  * @param f fila en la que se encuentra el elemento a buscar
  * @param c columna en la que se encuentra el elemento a buscar
  * @return Devuelve el elemento situado en la posicion (f, c)
  */
  char elemento(int f, int c) const;

/**
  * @brief Obtener la menor fila de la matriz
  * @return Devuelve la fila menor de la matriz
  */
  int fmenor() const;

/**
  * @brief Obtener la mayor fila de la matriz
  * @return Devuelve la fila mayor de la matriz
  */
  int fmayor() const;

/**
  * @brief Obtener la menor columna de la matriz
  * @return Devuelve la columna menor de la matriz
  */
  int cmenor() const;

/**
  * @brief Obtener la mayor columna de la matriz
  * @return Devuelve la columna mayor de la matriz
  */
  int cmayor() const;

/**
  * @brief Consultar el valor por defecto
  * @return Devuelve el valor por defecto de las casillas
  */
  char valordefecto() const;

/**
  * @brief Indicar el numero de casillas que no tienen valor igual al valor por
  * defecto
  * @return Devuelve el numero de casillas que no tienen un valor igual al valor
  * por defecto
  */
  int casillasinicializadas();

/**
  * @brief Obtener el numero de filas de la matriz
  * @return Devuelve el numero de filas de la matriz
  */
  int numfilas() const;

/**
  * @brief Obtener el numero de columnas de la matriz
  * @return Devuelve el numero de columnas de la matriz
  */
  int numcols() const;

/**
  * @brief Modifica el elemento de la posicion (f, c) al valor valor. Este
  * puede ser el valor por defecto, y en este caso se eliminaria dicha casilla
  * de memoria si existe en la matriz dispersa. Si no existe nada en esa posicion
  * se inserta una nueva tripleta formada por f, c y valor. Ademas ordena la
  * matriz dispersa cada vez que se inserta un nuevo valor
  * @param f Fila en la que se desea insertar el elemento
  * @param c Columna en la que se desea insertar el elemento
  * @param valor Valor que se desea insertar en la posicion (f, c)
  */
  void Set(int f, int c, char valor);

/**
  * @brief Salida de una Matriz Dispersa a ostream
  * @param fo Stream de Salida
  * @param m Matriz Dispersa a escribir
  * @post Pinta las tripletas de la forma fila-columna-valor
  */
  friend ostream & operator<<(ostream & fo, const Matriz_Dispersa & matriz);

/**
  * @brief Metodo para intercambiar dos tripletas de la matriz dispersa
  * @param a Primera tripleta a intercambiar
  * @param b Segunda tripleta a intercambiar
  * @return Intercambia los valores de fila, columna, dato de la tripleta a
  * los de la tripleta b
  */
  void intercambiar(tripleta & a, tripleta & b){
    tripleta aux = a;
    a = b;
    b = aux;
  }

/**
  * @brief Metodo para ordenar tripletas
  * @return Ordena las tripletas de la matriz dispersa mediante el metodo de
  * ordenacion por burbuja
  */
  void ordenar(){
    for(int i = 1; i < m.size(); i++)
      for(int j = 0; j < m.size() - i; j++)
        if(m[j].fila > m[j+1].fila && m[j].col > m[j+1].col)
            intercambiar(m[j], m[j+1]);
  }
};

#endif
