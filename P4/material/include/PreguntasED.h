#ifndef __PREGUNTAS_ED_H
#define __PREGUNTAS_ED_H
#include "Ontologias.h"
#include <vector>

/** 
 * @file Ontologias.h: TDA PreguntasED
 * 
*/

/**
   @brief T.D.A. PreguntasED
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto PreguntasED es una colección de preguntas sobre palabras,
   en una temática, a partir de su definición o significado. 
   <tt>\#include PreguntasED.h</tt>
     
   @author 
   @date
*/

class PreguntasED{
/**
  * @page repPreguntasED Rep del TDA PreguntasED
  *
  * @section invPreguntasED Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faPreguntasED Función de abstracción
  *
  * Añadir la función de abstracción
  */
private:
  int tema_level;//nivel de la tematica escogida
  Ontologias Ot; //conjunto de ontologias
  set<int>preguntas_hechas; //de entre las preguntas escogidas las realizadas
  int tematica_escogida; //tematica escogida entre todas del mismo nivel.
  vector<Ontologias::iterator_level>temas; // los temas en dicho nivel
  vector<Ontologias::iterator> preguntas_tema; //preguntas asociadas a la tematica escogida.
  int next_pregunta=-1; // la siguiente pregunta a realizar
  
  
  /**
   * @brief Obtiene todas las tematicas de un nivel fijado
   * @note Este metodo inicia el miembro temas con iteradores apuntando a dichas tematicas
   * Ver iterator_level de 
   */
  
  void CreaTematica();
       
    
public:
  /**
   * @brief Constructor
   * @param O: conjunto de ontologias para establecer las preguntas
   * @param tl: nivel de tematica sobre la que construir las preguntas
   */
  PreguntasED(const Ontologias &O, int tl=4);
  
  /**
   * @brief Muestra todas las tematicas en el nivel 
   *
   * */
  void MuestraTematicas();
    
  /**
   @brief Modifica la tematica escogida a un valor 
   @param i: valor de tematica escogida
   */
  void SetTematica(int i) ;
  
  /**
   *@brief Obtiene el titulo de la tematica (el nombre)
   * @return el nombre de la tematica
   */
  string GetTitleTematica();
    
  /**
   *@brief Almacena todos las definiciones de las tematica escogida
   *@post tras la ejecución el miembro preguntas_tema tiene  las preguntas (significados de las palabras finales)
   *de la temática escogida. Además next_pregunta a 0 tienen un valor 0
   * 
   */
  void IniciaConceptosTemaEscogido();
  
  /**
   *@brief Baraja todas las preguntas de forma aleatoria.
   * 
   **/
  void BarajarPreguntas();
  
  /**
   *@brief Devuelve la siguiente pregunta a realizar 
   *@post next_pregunta se modifica a la siguiente pregunta.
   */
  pair<set<string>,string> SacaPregunta();
  
  /**
   * @brief Devuelve el numero de preguntas en la tematica
   */
  int num_preguntas()const{ return preguntas_tema.size();}      
 
  /**
   *@brief Obtiene una pregutna
   *@param i: indice de la pregunta a devolver
   *@return un para con con el conjunto de palabras sinonimos que responden a esa pregunta y la definición.
   */
  pair<set<string>,string> GetPregunta(int i);	  
	
};    
#endif      
    
   
