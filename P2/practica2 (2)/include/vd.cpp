/*************************************************/
/* Implementacion de la plantilla vector dinamico*/
/* Jose Miguel Hernandez Garcia                  */
/* 2C C3                                         */
/*************************************************/

// Funcion para modificar el tamaño del vector
template <class T>
void VD <T>::resize(int nuevotam){
  T * aux = new T[nuevotam];
  int minimo = (n < nuevotam) ? n:nuevotam;

  for(int i = 0; i < minimo; i++)
    aux[i] = datos[i];

  reservados = nuevotam;
  n = minimo;
  delete[] datos;
  datos = aux;
}

// Constructor con parametro tam
template <class T>
VD <T>::VD(int tam){
  datos = new T[tam];
  reservados = tam;
  n = 0;
}

// Constructor de copia
template <class T>
VD <T>::VD(const VD <T> & original){
  reservados = original.reservados;
  n = original.n;

  datos = new T[reservados];

  for(int i = 0; i < n; i++)
    datos[i] = original.datos[i];
}

// Destructor
template <class T>
VD <T>::~VD(){
  if(datos != 0)
    delete[] datos;
}

// Sobrecarga del operador =
template <class T>
VD <T> & VD <T>::operator=(const VD <T> & original){
  if(this != &original){
    if(datos != 0)
      delete[] datos;

    reservados = original.reservados;
    n = original.n;

    if(original.datos != 0)
      datos = new T[reservados];

    for(int i = 0; i < n; i++)
      datos[i] = original.datos[i];
  }
  return * this;
}

// Funcion para insertar un valor en la posicion pos
template <class T>
void VD <T>::insertar(const T & dato, int pos){
  if(n >= reservados)
    resize(2*reservados);

  for(int i = n; i > pos; i--)
    datos[i] = datos[i-1];

  datos[pos] = dato;
  n++;
}

// Funcion para borrar el contenido en la posicion pos
template <class T>
void VD <T>::borrar(int pos){
  for(int i = pos; i < n-1; i++)
    datos[i] = datos[i+1];

  n--;

  if(n < reservados / 4)
    resize(reservados / 2);
}
