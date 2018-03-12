
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <class Tbase>
void ArbolGeneral <Tbase>::destruir (nodo * n){
  if (n!=0){
    destruir (n->izqda);
    destruir (n->drcha);  
    delete n;
  }      
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo * & dest, nodo * orig){
  if (orig!=0){
    dest = new nodo;
    dest->padre=0;
    dest->izqda=0;
    dest->drcha=0;
    dest->etiqueta=orig->etiqueta;
    copiar(dest->izqda,orig->izqda);
    copiar(dest->drcha,orig->drcha);
    
    if (dest->izqda!=0){
      dest->izqda->padre=dest;
      for (nodo *aux = dest->izqda->drcha;aux!=0; aux = aux->drcha)
        aux->padre=dest;
    } 
  }
  else 
    dest=0;
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
  if (n==0) 
    return 0;
  else 
    return 1+contar(n->izqda)+contar(n->drcha);
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1,const nodo * n2) const{
  if (n1==0 && n2==0) 
    return true;
  else if (n1==0 || n2==0) 
    return false;
    
  if (n1->etiqueta !=n2->etiqueta) 
    return false;
  else 
    return soniguales (n1->izqda,n2->izqda) && soniguales (n1->drcha,n2->drcha);
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo * & nod){
  char c;
  if (in.get(c)){
    switch (c){
      case 'x':
        nod=0;
        break;
      case 'n':
        Tbase et;
        in>>et;
        // cout<<"Leida "<<et<<endl; cin.get();
        nod=new nodo;
        nod->etiqueta=et;
        nod->padre=0;
        nod->izqda=0;
        nod->drcha=0;
        lee_arbol(in,nod->izqda);     
        lee_arbol(in,nod->drcha);
      
        if (nod->izqda!=0){
          nod->izqda->padre=nod;
          if (nod->izqda->drcha!=0) {
   	        nodo * aux = nod->izqda;
          
            while (aux->drcha!=0){
              aux->drcha->padre=nod->izqda->padre; 
              aux = aux->drcha;
            }    
          }
        } 
        break;
    }
	}      
	else
	  return;
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
  if (nod==0) 
    out.put('x');
  else{
    out<<'n'<<nod->etiqueta;
    escribe_arbol(out,nod->izqda);
    escribe_arbol(out,nod->drcha);
  }     
}

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
  laraiz=0;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
  laraiz = new nodo;
  laraiz->padre=laraiz->izqda=laraiz->drcha=0;
  laraiz->etiqueta = e;   
}
    
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){
  copiar(laraiz,v.laraiz);
}
    
template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
  destruir(laraiz);
}
    
template <class Tbase>
ArbolGeneral<Tbase>& 
ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){
  if (this!=&v){
	  destruir(laraiz);
	  copiar(laraiz,v.laraiz);
	}
	return *this;
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
  if (laraiz==0){
    laraiz = new nodo;
    laraiz->etiqueta=e;
    laraiz->padre=laraiz->izqda=laraiz->drcha=0;
  }
	else{
	  destruir(laraiz->izqda);
	  destruir(laraiz->drcha);
	  laraiz->etiqueta=e;
	  laraiz->padre=laraiz->izqda=laraiz->drcha=0;
	}    
}
    
template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
	return laraiz;
}
    
template <class Tbase>
typename ArbolGeneral<Tbase>::
Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
  return n->izqda;
}
    
template <class Tbase>
typename ArbolGeneral<Tbase>::
Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const{
  return n->drcha;
}
    
template <class Tbase>
typename ArbolGeneral<Tbase>::
Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const{
  return n->padre;
}
    
template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n){
  return n->etiqueta;
}
    
template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const{
  return n->etiqueta;     
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::
asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
  if (laraiz!=0){
	  destruir(laraiz);
	  copiar(laraiz,nod);
  }
  else 
    copiar(laraiz,nod);
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::
podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
  dest.laraiz= n->izqda;
	n->izqda->padre=0;
	n->izqda=0;
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::
podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
  dest.laraiz= n->drcha;
	n->drcha->padre=0;
	n->drcha=0; 
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::
insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
  if (rama.laraiz!=0){
    rama.laraiz->drcha=n->izqda;
    rama.laraiz->padre=n;
    n->izqda=rama.laraiz;
    rama.laraiz=0;
  }          
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::
insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
  if (rama.laraiz!=0){
    rama.laraiz->drcha=n->drcha;
    rama.laraiz->padre=n->padre;
    n->drcha=rama.laraiz;
    rama.laraiz=0;
  }
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
  destruir(laraiz);
  laraiz=0;
}
    
template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
  return contar(laraiz);
}
    
template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
  return laraiz==0;
}
    
template <class Tbase>
bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const{
  return soniguales (laraiz,v.laraiz); 
}
    
template <class Tbase>
bool ArbolGeneral<Tbase>::operator != (const ArbolGeneral<Tbase>& v) const{
  return !soniguales(laraiz,v.laraiz);
}
    
template<class T> 
istream& operator >> (istream& in, ArbolGeneral<T>& v){
	v.destruir(v.laraiz);
	v.laraiz=0;
  v.lee_arbol(in,v.laraiz);
  return in;	  
}
    
template<class T>
ostream& operator << (ostream& out, const ArbolGeneral<T>& v){
  v.escribe_arbol(out,v.laraiz);
	return out;
}
