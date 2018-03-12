#ifndef __ONTOLOGIAS__H
#define __ONTOLOGIAS__H
#include "ArbolGeneral.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <list>
using namespace std;
/** 
 * @file Ontologias.h: TDA Ontologias
 * 
 */

/**
   @brief T.D.A.Ontologias
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Ontologias es una colección de ontologias.
   Una ontologia  es una colección de palabras (finales) (palabras finales) que son sinónimas y se asociación con otras palabras (superpalabras), de forma jerárquica, que definen conjuntos 
   a las que pertenecen. Una palabra final se componen de una serie de palabras que tienen el mismo siginificado y se encuentran
   en el mismo conjunto de superpalabras. Un ejemplo de Ontología es el siguiente:
  
   spanish capital,capital of spain,madrid,;national capital,;capital,;seat,;eye,heart,middle,centre,center,;country,area,;region,;location,;physical object,object,;physical entity,;entity,;

   Así madrid y capital de españa son sinónimos. El siguiente nivel son superpalabras como es "national capital". En el siguiente nivel
   "capital", en el siguiente "seat", etc.
   <tt>\#include Ontologias.h</tt>
   
   
   @author 
   @date Enero 2018
*/

class Ontologias{
  /**
  * @page repOntologias Rep del TDA Ontologias
  *
  * @section invOntologias Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faOntologias Función de abstracción
  *
  * Añadir la función de abstracción
  */

private:
  ArbolGeneral<pair<set<string>,int> >ab; //almacena la estructura de palabras por tematica
                                          //el entero contiene la clave de significados
                                          //de la palabra final o -1 en caso de 
                                          //que no sea palabra final.
  map<int, string> significados; //almacena un codigo de significado de una palabra y
                                 //su significado
  int n_palabras; //numero de palabras finales 
    
public:
  /**
   * @brief Constructor por defecto. 
   **/
  Ontologias(){ 
     n_palabras=0;
  }
    
  /** @brief devuelve el numero de palabras finales.
   */
  int size()const{ return n_palabras;}
 
  //declaración adelanta de los iteradores
  class iterator; 
  class const_iterator;
  /**************/
    
  /** 
   * @brief Devuelve si una palabra  esta en el conjunto. Si esta devuelve un iterador a el
   * @param o: palabra a buscar
   * @return una pareja que contiene si la palabra esta y en caso afirmativo un iterador a el
   *         en otro caso devuelve end y false
  */
  pair<bool, const_iterator> Esta(const string &o)const;
  
  /** 
   * @brief Elimina todos las ontologias
   */
  void clear();
 
  /**
   * @brief Devuelve los significado asociado a todos los sinonimos a una palabra y la misma palabra 
   * @param palabra: palabra a buscar 
   * @return una coleccion de   pares significados y palabras sinonimas a la palabra introducida
   * por el usuario y la misma palabra que tiene ese significado clave
  */
  map<string,set<string> > GetSinonimos(const string & palabra)const;
  
  /**
   * @brief Devuelve  todas las tematícas (con sus sinonimos) hasta la temática raiz de una palabra con un significado concreto.
   * @param palabra: palabra a buscar 
   * @param signi: significado de la palabra 
   * @return una lista con todas las temáticas a las que pertenece  una palabras con un significado
   * @example:  Preguntamos por la palabra  madrid con significado spanish capital. El método devuelve:
    national capital,;capital,;seat,;eye,heart,middle,centre,center,;country,area,;region,;location,;physical object,object,;physical entity,;entity,;
    Si la jerarquía de madrid con ese significado era :
    spanish capital,capital of spain,madrid,;national capital,;capital,;seat,;eye,heart,middle,centre,center,;country,area,;region,;location,;physical object,object,;physical entity,;entity,;
    @exception: devuvelve una lista vacía sin no tiene es una palabra que existe en la ontologias o palabra no tiene ninguna superpalabra.
  */
  list<set<string> > GetSuperPalabra(const string & palabra,const string & signifi)const;
  
  /**
   * @brief Obtiene el significado de una posición determinada
   */
  string GetDefinicion(int pos);
       
  /**
  @brief Lectura de los Significados de un fichero
  @param fich_sig: nombre del fichero con los signficados
  El fichero contiene por cada linea indice y significado. El indice
  se corresponde con el índice del significado de una palabra final.
  */
  bool lee_significados(const char * fich_sig);
  
  /**
   * @brief Lee el las palabras descritas en forma jerarquica en temáticas y sus significados.
   * @param fich_jerarquia: nombre del fichero que almacena las palabras dispuestas en forma jerarquica
   * @param fich_significados: nombre del fichero con los significados.
   * @return true si el proceso de lectura es correcto. False en caso contrario
  */
  bool Lee(const char * fich_jerarquia,cons char * fic_significados);
    
  /**
   * @brief Escribe las ontologias en disco
   * @param fich_jerarquia: nombre del fichero donde se almacenará las palabras en forma jerarquica
   * @param fich_significados: nombre del fichero que almacenará  los significados.
  */
  bool Escribe(const char * fich_jerarquia,cons char * fic_significados);
    
  /**
   * @brief Numero de palabras finales.
   */
  int Numero_Nodos()const{ 
    return ab.size();
  }
    
  /****************************************/
  /**
   * @brief iterator_level es un iterador que itera por las temáticas o palabras finales
   * de un determinado nivel 
   */
  class iterator_level{
  private:
    ArbolGeneral<pair<set<string>,int> >::iter_preorden it;
    int level;
  public:
    /**
      * @brief constructor
      */
    iterator_level(){ level=-1;}

    /**
     * @brief  Consulta/modificador la información del iterador
     * @note el primer elemento del par es el conjunto de palabras sinonimas en dicho nodo 
     * y el segundo elemento del par es el índice del significado
     * Para acceder al significado desde este indice se puede usar GetDefinicion
     */
    pair<set<string>,int> & operator *(){
      return *it;
    }
    
    /**
     * @brief Ver si dos interadores de nivel son iguales.
     */
    bool operator==(const iterator_level &i)const {
      return i.it==it;
    }
    
    /**
     * @brief Ver si dos interadores de nivel son diferentes.
     */
    bool operator!=(const iterator_level &i)const{
      return !(i.it==it);
    }

    /**
     *@brief avanza a la  siguiente temática o palabra final del mismo nivel
     *@return un iterador a la siguiente temática o palabra final.
    */
    iterator_level &operator ++(){
      do{ 
        ++it;
        if (it.getlevel()==-1)
          return *this; 
        else if (it.getlevel()==level-1 && !it.Hoja())
          return *this;
      }while (it.getlevel()!=-1 );
      return *this;
    }
    
   friend class Ontologias;
   friend class const_iterator_level;
   friend class iterator;
  };
  
  //versión constante 
  class const_iterator_level{
  private:
    ArbolGeneral<pair<set<string>,int> >::const_iter_preorden it;
    int level;
  public:
    const_iterator_level(){level=-1;}
    const_iterator_level(const iterator_level  &i):it(i.it){}

    const pair<set<string>,int> & operator *(){
      return *it;
    }
    
    bool operator==(const const_iterator_level &i)const{
      return i.it==it;
    }

    bool operator!=(const const_iterator_level &i)const{
      return !(i.it==it);
    }
    
    const_iterator_level &operator ++(){
      do{ 
        ++it;
        if (it.getlevel()==-1)
          return *this;
        else if (it.getlevel()==level-1 && !it.Hoja())
          return *this;
      }while (it.getlevel()!=-1 );
     return *this;
    }

    friend class Ontologias;  
  };	  
    
  
  /****************************************/
  /**
   * @brief Itera por las palabras finales.
   */
  class iterator{
  private:
    ArbolGeneral<pair<set<string>,int> >::iter_preorden it;
    
  public:
    /**
     * @brief Constructor
     */
    iterator(){}

    /**
     * @brief Constructor a partir de un iterador por niveles.
     */
    iterator(iterator_level & i){
      it=i.it;
      if (!it.Hoja()) ++(*this);
    }

    /**
     * @brief Consulta/Modificador del elemento que apunta el iterador
     */
    pair<set<string>,int> & operator *(){
      return *it;
    }
  
    /**
     * @brief Obtiene las temáticas a las que pertenece la palabra final que apunta
     * el iterador 
     * @return una lista conteniendo todas las temáticas (con sus sinonimos). Asi
     * cada elemento de la lista contiene una temática. Esta tematica se almacena
     * en un conjunto (set<string>) donde se mantiene todos los sinónimos de esa temática incluida ella misma
     */
    list<set<string> >  GetJerarquia(){
      list<set<string> > laux;
      ArbolGeneral<pair<set<string>,int> >::iter_preorden auxit=it;
      do {
        laux.push_front((*auxit).first);
        auxit=auxit.padre();  
      }while (!auxit.Nulo());
      return laux;
    }
    
    /**
     * @brief Obtiene la temáticas justo en el nivel superior (la mas especializada).
     * @return un conjunto con los sinonimos a la temática a la que pertenece la palabra
     * final apuntada por el iterador (temática más especializada).
     */
    set<string> GetSuperPalabra(){
      ArbolGeneral<pair<set<string>,int> >::iter_preorden aux= it.padre();
      if (!aux.Nulo()){
        return (*aux).first;
      }
      else return set<string>();
 
    }
    /**
     * @brief Dos iterador son iguales
     */
    bool operator==(const iterator &i)const {
      return i.it==it;
    }

    /**
     * @brief Dos iterador son diferentes
     */
    bool operator!=(const iterator &i)const{
      return !(i.it==it);
    }

    /**
    * @brief Avanza a la siguiente palabra final
    * */
    iterator &operator ++(){
      do{ 
        ++it;
        if (it.getlevel()==-1) {
          return *this;
        } 
      }while (it.getlevel()!=-1 && !it.Hoja());
      return *this;
    }

    friend class Ontologias;
    friend class const_iterator;
  };
    
  //version constante
  class const_iterator{
  private:
    ArbolGeneral<pair<set<string>,int> >::const_iter_preorden it;
    int level;
  public:
    const_iterator(){}
    const_iterator(const iterator  &i):it(i.it){}

    const pair<set<string>,int> & operator *(){
      return *it;
    }
    
    list<set<string> >  GetJerarquia(){
      list<set<string> > laux;
      ArbolGeneral<pair<set<string>,int> >::const_iter_preorden auxit=it;
      do {
        laux.push_front((*auxit).first);
        auxit=auxit.padre(); 
      }while (!auxit.Nulo());
      return laux;
    }
    
    set<string> GetSuperPalabra(){
      ArbolGeneral<pair<set<string>,int> >::const_iter_preorden aux= it.padre();
      if (!aux.Nulo())
        return (*aux).first;
      else 
        return set<string>();
    }
    
    bool operator==(const const_iterator &i)const{
      return i.it==it;
    }

    bool operator!=(const const_iterator &i)const{
      return !(i.it==it);
    }
    
    const_iterator &operator ++(){
      do{ 
        ++it;
        if (it.getlevel()==-1) 
          return *this;
      }while (it.getlevel()!=-1 && !it.Hoja());
      return *this;
    }

    friend class Ontologias;
  };	  
    
  /***************BEGIN y END*************/
  
  /**
   * @brief Inicia un iterador a la primera palabra final.
   * */
  iterator begin(){
    iterator i;
    i.it = ab.begin();
    ++i;
    return i;
  }  
  /**
   @brief Inicia un iterador al final de las palabras finales (no apunta
   a una palabra valida).
   */
  iterator end(){
    iterator i;
    i.it = ab.end();
    return i;
  }  
  // versiones constantes      
  const_iterator begin()const{
    const_iterator i;
    i.it = ab.begin();      
    ++i;
    return i;
  }  
  
  const_iterator end()const{
    const_iterator i;
    i.it = ab.end(); 
    return i;
  }     
    
  /*
   * @brief Inicia un iterador por niveles a un determiando nivel
   */
  iterator_level beginl(int l){
    iterator_level i;
    i.it = ab.begin();
    i.level= l;
    ++i;
    return i;
  }  
  /*
   * @brief Inicia un iterador por niveles al final de un nivel de tematicas
   *  La posicion ya no es valida
   */
  
  iterator_level endl(){
    iterator_level i;
    i.it = ab.end();
    
    return i;
  }  
  /* versiones constantes
   */
    
  const_iterator_level cbeginl(int l)const{
    const_iterator_level i;
    i.it = ab.begin();      
    i.level= l;
    ++i;
    return i;
  }  
  
  const_iterator_level cendl()const{
    const_iterator_level i;
    
    i.it = ab.end(); 
    return i;
  }     
};

#endif