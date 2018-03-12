/**
  * @file Diccionario.h
  * @brief Fichero de cabecera del TDA Diccionario
  *
  */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <map>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia @e m del tipo de datos abstracto Diccionario contiene
  * una serie de palabras ordenadas en orden alfabético con su correspondiente
  * definición. De una misma palabra podemos encontrar distintas definiciones
  *
  * @author Jose Miguel Hernandez Garcia
  * @date Diciembre 2017
  */
class Diccionario{
private:

  /**
    * @page repDiccionario Rep del TDA Diccionario
    *
    * @section invConjunto Invariable de la representacion
    *
    * Cada palabra debe contener una definición válida, además el formato debe ser:
    * palabra;definición
    *
    * @section faConjunto Funcion de abstraccion
    *
    * Un objeto valido @e rep del TDA Diccionario representa un conjunto 
    * de palabras junto a su definición de forma ordenada, donde cada palabra 
    * puede tener distintas definiciones
    *
    */
  multimap <string, string> palabras; /**< Multimapa que contiene palabra y definicion */
public:

/**
  * @brief Constructor por defecto. Crea un diccionario vacio
  */
  Diccionario(){};

/**
  * @brief Constructor de copia.
  * @param d Diccionario original del que se quiere hacer la copia
  */ 
  Diccionario(const Diccionario & d){
    palabras = d.palabras;
  }

/**
  * @brief Destructor de la clase
  */
  ~Diccionario(){
    this->palabras.erase(palabras.begin(), palabras.end());
  };

/**
  * @brief Sobrecarga del operador = 
  * @param d Diccionario original del que se quiere hacer la copia
  * @return Devuelve un Diccionario igual al que se pasa por parametro
  * @pre d debe ser distinto de this
  */
  Diccionario & operator=(const Diccionario & d){
    if(this != &d)
      palabras = d.palabras;

    return * this;
  };

/**
  * @brief Funcion que comprueba si una clave esta dentro del diccionario
  * @param p Clave a buscar dentro del diccionario
  * @param it Iterador para iterar por el multimapa del diccionario
  * @return Devuelve "true" si la clave p esta en el diccionario y "false"
  * en caso contrario
  */
  bool esta_clave(const string & p, typename multimap<string, string>::iterator & it);

/**
  * @brief Funcion para insertar una palabra y su definición en el diccionario
  * @param clave Palabra a insertar
  * @param valor Definición de la palabra a insertar
  */
  void insertar(const string & clave, const string & valor);

/**
  * @brief Funcion para encontrar la definición correspondiente a una clave
  * @param clave Palabra de la que queremos obtener la definición
  * @return devuelve una definición correspondiente a la palabra que se pasa
  * como parametro
  */
  string getdefinicion(const string & clave);

/**
  * @brief Funcion constante que devuelve el tamaño del diccionario
  * @return Devuelve el tamaño de diccionario
  */
  int size() const{
    return palabras.size();
  }

  /*Borrar todas las palabras del diccionario*/

/**
  * @brief Funcion que elimina todas las palabras del diccionario y lo deja vacio
  */
  void clear(){
    palabras.clear();
  }

/**
  * @brief Funcion para obtener todas las palabras en cuya definición aparece
  * el tema t pasado por parámetro
  * @param t Tema a buscar dentro de las definiciones
  * @return Devuelve un nuevo Diccionario que contiene unicamente las palabras
  * en cuya definición aparece el tema t
  */
  Diccionario ObtainPalabrasconDeficionContiene(string t);

  friend class const_iterator;

  /*clase iterador*/
  class iterator{
  private:
    typename multimap<string, string>::iterator p;
  public:
    iterator(){}

    iterator & operator++(){
      ++p;
      return * this;
    }

    iterator & operator--(){
      --p;
      return * this;
    }

    bool operator==(const iterator & it){
      return it.p == p;
    }

    bool operator!=(const iterator & it){
      return it.p != p;
    }

    const pair<const string,string> & operator *(){
      return * p;
    }

    /* funcion para avanzar el iterador del diccionario*/
    void avanzar(int n){
      advance(p, n);
    }

    friend class Diccionario;
    friend class const_iterator;
  };

  class const_iterator{
  private:
    typename multimap<string, string>::const_iterator p;
  public:
    const_iterator(){}

    const_iterator & operator++(){
      ++p;
      return * this;
    }

    const_iterator & operator--(){
      --p;
      return * this;
    }

    bool operator==(const const_iterator & it){
      return it.p == p;
    }

    bool operator!=(const const_iterator & it){
      return it.p != p;
    }

    const pair<const string,string> & operator *(){
      return * p;
    }

    /* funcion para avanzar el iterador del diccionario*/
    void avanzar(int n){
      advance(p, n);
    }

    friend class Diccionario;
  };

/**
  * @brief Metodo para inicializar el iterator al principio de la matriz;
  */
  iterator begin(){
    iterator it;
    it.p = palabras.begin();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator al final de la matriz;
  */
  iterator end(){
    iterator it;
    it.p = palabras.end();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator constante al principio de la matriz;
  */
  const_iterator begin() const{
    const_iterator it;
    it.p = palabras.begin();

    return it;
  }

/**
  * @brief Metodo para inicializar el iterator constante al final de la matriz;
  */
  const_iterator end() const{
    const_iterator it;
    it.p = palabras.end();

    return it;
  }

/** 
  * @brief Entrada de un Diccionario desde istream
  * @param fi Stream de entrada
  * @param d Diccionario que recibe los valores a leer
  * @return El diccionario leido en d
  * @pre La entrada es de tipo palabra - definicion
  */
  friend istream & operator>>(istream & fi, Diccionario & d);

/**
  * @brief Salida de un Diccionario a istream
  * @param fo Stream de salida
  * @param d Diccionario a escribir
  * @post Pinta en pantalla la palabra y su definición, con el siguiente formato:
  * palabra;definición
  */
  friend ostream & operator<<(ostream & fo, const Diccionario & d);
};

#endif
