/*************************************************/
/* Programa principal de la sopa de letras       */
/* Jose Miguel Hernandez Garcia                  */
/* 2C C3                                         */
/*************************************************/

#include "diccionario.h"
#include "sopaletras.h"
#include "colormod.h"
#include <iostream>
#include <chrono>
#include <random>
#include <set>

using namespace std;
using namespace std::chrono;

// Genera una direccion aleatoria
string randomdir(){
  int val = (rand() % 6)+1;
  string dir;

  if(val == 1)
    dir = "vu";
  else if(val == 2)
    dir = "vd";
  else if(val == 3)
    dir = "hi";
  else if(val == 4)
    dir = "hd";
  else if(val == 5)
    dir = "dd";
  else if(val == 6)
    dir = "di";

  return dir;
}

ostream & operator<<(ostream & os, const pair<string,string> & p){
  os<<p.first<<";"<<p.second<<endl;
  return os;
}

void ImprimirDiccionario(Diccionario &D){
  for (Diccionario::iterator it=D.begin(); it!=D.end();++it){
    cout<<*it<<endl;
  }
}

int main(int argc, char ** argv){

  typedef duration<float,ratio<1,1>> seconds_f;

  if (argc!=4){
      cout<<"ERROR: Numero de parametros incorrecto"<<endl;
      return 0;
  }

  ifstream fi (argv[1]);
  if (!fi){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  Diccionario T;
  fi>>T; //Cargamos en memoria el diccionario

  string a = argv[2];    // Leemos el tema
  int n = atoi(argv[3]); // Leemos el numero de palabras que queremos en nuestro diccionario

  // Obtenemos todas las palabras con el tema
  Diccionario Dtema = T.ObtainPalabrasconDeficionContiene(a);

  srand(time(NULL)); // Iniciamos la semilla

  Diccionario Dfinal; // Creamos el diccionario que contendrá n palabras;
  Diccionario::iterator it = Dtema.begin(); // Inicializamos el iterador al principio del diccionario

  set<int> s;

  // Rellenamos el set de valores aleatorios
  while(s.size() < n){
    int val = rand() % (Dtema.size());
    s.insert(val);
  }

  // Si el num de palabras que queremos es menor al tamaño del diccionario
  // Generamos nuestras n palabras aleatorias
  if(n < Dtema.size())
    for(set<int>::iterator its = s.begin(); its != s.end(); ++its){
      it.avanzar((*its)); // Avanzamos el iterador del diccionario
      Dfinal.insertar((*it).first, (*it).second);
      it = Dtema.begin(); // Reiniciamos la posicion del iterador
    }
  else
    Dfinal = Dtema;

  // Una vez tenemos nuestro diccionario final, generamos la sopa de letras
  Sopa_Letras sl;

  int f, c;      // Fila y columna
  string p, dir; // Palabra y direccion

  // Ponemos titulo a nuestra sopa de letras
  sl.settitulo(a);

  // Colocamos las diferentes palabras en la sopa de letras
  for(Diccionario::iterator it2 = Dfinal.begin(); it2 != Dfinal.end(); ++it2){
    do{
      p = (*it2).first;        // Buscamos la palabra
      f = rand() % (11);       // Generamos una fila aleatoria
      c = rand() % (11);       // Generamos una columna aleatoria

      if(p.length() > 1)
        dir = randomdir();     // Generamos una direccion aleatoria
      else
        dir = "vd";            // Si la palabra SOLO tiene 1 letra, la direccion siempre sera vd
    }while(!sl.esposiblecolocar(p, f, c, dir));
    sl.colocarpalabra(p, f, c, dir);
  }

  // Iniciamos el cronometro
  time_point<steady_clock> instante1 = steady_clock::now() ;

  //El usuario ahora tiene que ir descubriendo las palabras
  //en la sopa de letras
  while (sl.nodescubiertas() != 0){
    // Creamos una lista que almacene las palabras ocultas
    list <string> ocultas = sl.getpalabrasocultas();

    cout << endl;

    // Iteramos sobre la lista de palabras ocultas para mostrar sus definiciones
    for(list<string>::iterator locultas = ocultas.begin(); locultas != ocultas.end(); ++locultas)
      cout << BOLD(FCYN("Definicion --> ")) << Dfinal.getdefinicion((*locultas)) << endl;
    
    cout<<sl<<endl;
    cout<<"Dime una palabra: ";
    string word;
    cin>>word;
    cout<<"Dime la fila :";
    int row;
    cin>>row;
    cout<<"Dime la columna :";
    int col;
    cin>>col;

    cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";
    string direccion;
    cin>>direccion;

    if (!sl.Comprobar_Palabra(word,row,col,direccion))//Esta?
      cout<<BOLD(FRED("La palabra "))<< word << BOLD(FRED(" no esta"))<<endl;
    else
      //La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
      sl.Poner_Acertada(word,row,col,direccion);
  }

  cout<<sl<<endl;

  // Calculamos el tiempo total de ejecucion de la sopa
  time_point<steady_clock> instante2 = steady_clock::now();
  steady_clock::duration duracion = instante2 - instante1;

  cout << "\n\nHAS COMPLETADO LA SOPA DE LETRAS. FIN." << endl << endl;
  cout << "\nHas tardado " << seconds_f(duracion).count() << " segundos."
       << endl;
}
