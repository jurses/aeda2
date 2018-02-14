#ifndef PILA_H
#define PILA_H

#include "listaEnla.hpp"

template<class TDATO>
class Pila{
	private:
		ListaEnla<TDATO> lista_;
	public:
		Pila();
		int obtTam();
		void apilar(TDATO);
		void desapilar(void);
		TDATO mostrar(void);		
};

template<class TDATO>
Pila<TDATO>::Pila(){}

template<class TDATO>
void Pila<TDATO>::apilar(TDATO dato){
	Nodo<TDATO> *nuevoNodo = new Nodo<TDATO>(dato);

	lista_.insertNodo(nuevoNodo);
}

template<class TDATO>
void Pila<TDATO>::desapilar(void){
	Nodo<TDATO> *ultNodo = lista_.obtUltimo();
	delete ultNodo;
}

template<class TDATO>
TDATO Pila<TDATO>::mostrar(void){
	return lista_->obtUltimo();
}

#endif	// PILA_H
