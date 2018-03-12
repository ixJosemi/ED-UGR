/**
  * @file Matriz_Dispersa.h
  * @brief Fichero de cabecera del TDA Matriz Dispersa
  *
  */

#ifndef _MATRIZ_DISPERSA
#define _MATRIZ_DISPERSA

#include <list>
#include <iostream>

using namespace std;

template <class T>
struct tripleta{
  int fila, col;
  T d;

  tripleta & operator=(const tripleta & t){
    fila = t.fila;
    col = t.col;
    d = t.d;

    return * this;
  }

  bool operator<(const tripleta & t) const{
    return fila < t.fila && col < t.col;
  }
};

/**
  * @brief T.D.A. Matriz dispersa
  *
  * Una instancia @e m del tipo de datos abstracto @c Matriz Dispersa es un objeto
  * almacenado en un TDA Lista de la STL donde cada elemento de la lista contiene
  * una tripleta formada por la fila, la columna y el valor en esa posicion.
  * Ya que una matriz dispersa es aquella donde la mayoria de valores
  * estan inicializados a un valor nulo que en este caso es 0;
  *
  * @author Jose Miguel Hernandez Garcia
  * @date Diciembre 2017
  */

template <class T>
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

  list <tripleta<T>> l; /**< Matriz creada a partir de un TDA Lista de la STL */
  T valor_defecto; /**< Valor por defecto de las casillas */

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
  Matriz_Dispersa(T val_defecto);

/**
  * @brief Obtener el elemento en la posicion (f, c)
  * @param f fila en la que se encuentra el elemento a buscar
  * @param c columna en la que se encuentra el elemento a buscar
  * @return Devuelve el elemento situado en la posicion (f, c)
  */
  T elemento(int f, int c) const;

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
  T valordefecto() const{
    return valor_defecto;
  }

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
  void set(int f, int c, T valor);

/**
  * @brief Salida de una Matriz Dispersa a ostream
  * @param fo Stream de Salida
  * @param m Matriz Dispersa a escribir
  * @post Pinta las tripletas de la forma fila-columna-valor
  */
  friend ostream & operator<<(ostream & fo, const Matriz_Dispersa & m){
    typename list<tripleta<T>>::const_iterator it;

    for(it = m.l.begin(); it != m.l.end(); ++it){
      fo << "\n" << (*it).fila << " " << (*it).col << " "
         << (*it).d;
    }

    fo << endl;

    return fo;
  }

  /*clase iterador*/
  class iterator{
  private:
    typename list<tripleta<T>>::iterator p;
  public:
    iterator(){}

    iterator & operator++(){
      p++;

      return * this;
    }

    iterator & operator--(){
      p--;

      return * this;
    }

    bool operator==(const iterator & it){
      return it.p == p;
    }

    bool operator!=(const iterator & it){
      return it.p != p;
    }

    const tripleta<T> & operator*(){
      return * p;
    }

    friend class Matriz_Dispersa;
    friend class const_iterator;
  };

  /*clase iterador constante*/
  class const_iterator{
  private:
    typename list<tripleta<T>>::const_iterator p;
  public:
    const_iterator(){}

    const_iterator & operator++(){
      p++;

      return * this;
    }

    const_iterator & operator--(){
      p--;

      return * this;
    }

    bool operator==(const const_iterator & it){
      return it.p == p;
    }

    bool operator!=(const const_iterator & it){
      return it.p != p;
    }

    const tripleta<T> & operator*(){
      return * p;
    }

    friend class Matriz_Dispersa;
  };

/**
  * @brief Metodo para inicializar el iterator al principio de la matriz;
  */
  iterator begin(){
    iterator it;
    it.p = l.begin();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator al final de la matriz;
  */
  iterator end(){
    iterator it;
    it.p = l.end();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator constante al principio de la matriz;
  */
  const_iterator begin() const{
    const_iterator it;
    it.p = l.begin();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator constante al final de la matriz;
  */
  const_iterator end() const{
    const_iterator it;
    it.p = l.end();

    return it;
  }
};

#include "matrizdispersa.cpp"

#endif
