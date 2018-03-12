#include <Ontologias.h>

using namespace std;

/* Comprueba si una palabra está en el conjunto o no */
pair <bool, const_iterator> Ontologias::Esta(const string & o){
  set<string>::const_iterator sit; // Iterador del conjunto
  ArbolGeneral<pair<set<string>, int>>::const_iter_preorder ait = ab.cbegin(); // Iterador del arbol
  pair<bool, const_iterator> aux;  // Pair a devolver
  bool esta = false;

  /* SI HAY QUE RECORRER TODO EL ARBOL */
  while(ait != ab.cend() && !esta){
  	sit = (*ait).first.find(o); // El iterador del set apunta a la palabra a buscar

  	if(sit != ab.first.end())	  // Si está
  		esta = true; 						  // Ponemos esta a true para salir del while	
  	else												// Si NO está
  		++ait;										// bajamos un nivel en el arbol
  }

  if(esta) {										   // Si la palabra esta
  	//aux = make_pair(true, ait);  // creamos un pair con true y el iterador apuntando al conjunto
  	return make_pair(true, ait);
  }
  else {													 // si no esta
  	ait = ab.end();					     // el iterador apunta al final
  	//aux = make_pair(false, ait); // creamos un pair con false y el iterador apuntando al final
  	// Directamente podemos hacer
  	return make_pair(false, ait);
  }
}

/* Elimina todas las ontologias */
void Ontologias::clear(){
	ab.first.clear(); // Borramos las ontologias del conjunto
	map.clear();		  // Borramos los significados de las ontologias
	n_palabras = 0;   // El numero de palabras queda a 0
}

/* Devuelve el significado asociado a los sinonimos de una palabra y los 
	 sinonimos en si, junto a la palabra */
map <string, set <string>> Ontologias::GetSinonimos(const string & palabra) const{
	pair<bool, const_iterator> aux = Esta(palabra);
	map<string, set <string> m; 
	ArbolGeneral<pair<set<string>, int>>::const_iter_preorder ait;
	set <string>::iterator sit;
	int ref;

	if(aux.first == true){ 				 // Si es true, la palabra está en el conjunto
		ait = aux.second;  	 				 // El iterador apunta al conjunto
		sit = (*ait).first.begin();  // El iterador del set apunta al set
		ref = (*ait).second; 				 // El numero de referencia del significado

		// Buscamos el significado en el mapa de significados
		string significado = significados.find(ref);
		m.first = significado;  // Meto el significado en el map

		// el pair tiene un end?
		while(sit != (*ait).first.end()){ // Recorremos el conjunto
			m.second.push(*sit); 					  // Meto la palabra en el conjunto del mapa
			++sit;						    
		}
	}
	return m;
}

/* Devuelve todas las tematicas hasta la raiz de una palabra con significado
   concreto */
list <set<string>> Ontologias::GetSuperPalabra(const string & palabra, const string & signifi) const{
	list <set<string>> l;		// lista a devolver 
	ArbolGeneral<pair<set<string>, int>>::const_iter_preorder ait;
	pair <bool, const_iterator> aux1 = Esta(palabra);
	pair <set<string>,int> aux2;

	if(aux.first == true){	// Si es true, la palabra está en el conjunto
		ait = aux1.second;     // El iterador apunta al conjunto

		while(ait.padre() != 0 && ait != ab.cbegin()){
			aux2 = ab.parent(*ait).etiqueta(); // Busco el padre del nodo actual y obtengo su etiqueta
			l.push_back(aux2.first) // Inserto el set en la lista
			ait = ait.padre();			// El iterador apunta a su padre
		}
	}
	return l;
}

/* Obtiene el significado de una posicion determinada */
string Ontologias::GetDefinicion(int pos){
	map<int, string>::iterator mit = significados.begin();
	advance(mit, pos); // Avanza mit hasta la posicion pos

	return (*mit).second;
}

/* Lectura de los significados de un fichero */
bool Ontologias::lee_significados(const char * fich_sig) {
	bool leido = true;
	int val, pos;
	string def, lectura;

	ifstream fi(fich_sig); // Abrimos el flujo de lectura del fichero

	if (!fi) // Si no podemos leer el fichero
		leido = false; 

	// Lo normal es que si podamos leerlo
	// Como el fichero está formado por VALOR DEFINICION, buscamos el primer espacio
	// para separar valor y definicion y crear nuestro mapa de significados
 	while(getline(fi, lectura)){
  		pos = lectura.find(" ");      // Buscamos el primer espacio
  		val = lectura.substr(0, pos); // Obtenemos el valor que corresponde
  		def = lectura.substr(pos+1, lectura.size()); // Obtenemos el significado

  		significados.insert(make_pair(val, def));  // Lo insertamos en el mapa de significados
  	}

  	return leido;
}

/* Lee las ontologias y los significados de los ficheros dados */
bool Ontologias::Lee(const char * fich_jerarquia, const char * fic_significados) {
	bool leido = true;

	// Creamos los flujos de entrada
	// No hace falta crear un flujo para los significados porque
	// ya tenemos un método que hace toda esa mierda
	ifstream fi_jerarq(fich_jerarquia),

	// Primero los significados que es más fácil(?)
	// Aquí es muy fácil ya que tenemos el método que lo hace, lol
	// pasamos el fichero y hace todo el solo
	leido = lee_significados(fic_significados); // Leido vale true si se pudo hacer
																							// y sino valdrá false

	// Ahora falta hacerlo para el arbol que es lo mierda

	// Realizamos la comprobación,
	// Si no podemos crear alguno de los ficheros significará
	// que no se pueden leer y por tanto leido = false.
	// Lo normal es que si podamos
	if(!fi_jerarq)
		leido = false;

	// Pasamos el flujo de entrada y el nodo raiz para leer el arbol
	// y leemos el arbol
	// ab.lee_arbol(fi_jerarq, ab.raiz());

	// Tras esto ya tenemos completos el arbol y el diccionario

	return leido;
}

/* Escribe las ontologias y los significados en los ficheros dados */
bool Ontologias::Escribe(const char * fich_jerarquia, const char * fic_significados) {
	bool escrito = true;

	// Definimos iterador para movernos por el mapa de significados
	map<int, string>::const_iterator mit;

	// Creamos los dos flujos de salida
	ofstream fo_jerarq(fich_jerarquia),
					 fo_signif(fic_significados);

	// Realizamos la comprobación,
	// Si no podemos crear alguno de los ficheros significará
	// que no se pueden escribir y por tanto escrito = false.
	// Lo normal es que si podamos
	if(!fo_jerarq || !fo_signif)
		escrito = false;
	
	// Primero los significados que es más fácil(?)
	for(mit = significados.cbegin(); mit != significados.cend(); ++mit)
		fo_signif; << (*mit).first << " " << (*mit).second << endl;
	
	// Ahora rellenamos el fichero de jerarquias



	return escrito;
}



























