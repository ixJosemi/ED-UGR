/**
  * @file vd.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  *
  */

#ifndef _VD
#define _VD

/**
  * @brief T.D.A. Vector dinamico
  *
  * Una instancia @v del tipo de datos abstracto @c Vector Dinamico es un objeto
  * del tipo vector, con sus metodos correspondientes de insercion, borrado y consulta.
  *
  * @author Jose Miguel Hernandez Garcia
  * @date Noviembre 2017
  */

template <class T>
class VD{
private:

/**
  * @page repVD Rep del TDA Vector dinamico
  *
  * @section invVectorDinamico Invariante de la representacion
  *
  * El numero de elementos utilizados n debe ser menor o igual al numero de
  * elementos reservados
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA Vector Dinamico representa un conjunto de datos
  *
  */

  T * datos; /**< puntero al vector */
  int n; /**< numero elementos almacenados */
  int reservados; /**< la memoria reservada en datos */

/**
  * @brief Funcion para cambiar el tamaño del vector
  * @param nuevotam Nuevo tamaño del vector
  */
  void resize(int nuevotam);

public:

/**
  * @brief Constructor por defecto de la clase. Crea un vector de tamaño tam
  * @param tam Tamaño del vector por defecto.
  */
  VD(int tam = 10);

/**
  * @brief Constructor de copias de la clase
  * @param original Vector original del que queremos realizar la copia
  */
  VD(const VD <T> & original);

/**
  * @brief Destructor de la clase
  */
  ~VD();

/**
  * @brief Funcion para obtener el numero de elementos del vector
  * @return Devuelve el numero de elementos almacenados en el vector
  */
  int size() const {
    return n;
  }

/**
  * @brief Sobrecarga del operador []
  * @param i posicion del elemento a buscar en el vector
  * @return Devuelve el elemento que se encuentra en la posicion i
  */
  T & operator[](int i){
    return datos[i];
  }

/**
  * @brief Sobrecarga del operador [] constante
  * @param i posicion del elemento a buscar en el vector
  * @return Devuelve el elemento que se encuentra en la posicion i
  */
  const T & operator[](int i) const {
    return datos[i];
  }

/**
  * @brief Sobrecarga del operador =
  * @param original Vector al que queremos igualar el vector de la clase
  * @return Devuelve un objeto de la clase VD igual al que se pasa por parametro
  * @pre original debe ser distinto de *this
  */
  VD <T> & operator=(const VD <T> & original);

/**
  * @brief Insertar un valor
  * @param dato Dato a insertar
  * @param pos Posicion en la que se desea insertar el dato
  * @return Inserta un valor en la posicion pos del vector
  */
  void insertar(const T & dato, int pos);

/**
  * @brief Eliminar un valor
  * @param pos Posicion en el vector del valor a borrar
  * @return Elimina el valor situado en la posicion pos del vector
  */
  void borrar(int pos);
};

#include "vd.cpp"

#endif
