#ifndef COLA_H
#define COLA_H

#include <cassert>

#include "nodo.hpp"
#include "listaEnla.hpp"

template<class TDATO>
class Cola{
	private:
		ListaEnla<TDATO> lista_;
	public:
		Cola();
		Cola(const Cola &);
		int obtTam();
		void encolar(TDATO);
		void sacarSig(void);
		TDATO mostrar(void);
};

template<class TDATO>
Cola<TDATO>::Cola(){}

template<class TDATO>
Cola<TDATO>::Cola(const Cola &cola):
	lista_(cola.lista_)
	{}

template<class TDATO>
void Cola<TDATO>::encolar(TDATO dato){
	Nodo<TDATO> *nuevoNodo = new Nodo<TDATO>(dato);

	lista_.insertNodo(nuevoNodo);
}

template<class TDATO>
void Cola<TDATO>::sacarSig(void){
	assert(lista_.obtTam() > 0);
	Nodo<TDATO> *primCola = lista_.obtCabeza();
	
	delete primCola;
}

template<class TDATO>
TDATO Cola<TDATO>::mostrar(void){
	assert(lista_.obtTam() > 0);
	return lista_.obtCabeza()->obtDato();
}

template<class TDATO>
int Cola<TDATO>::obtTam(void){
	return lista_.obtTam();
}

#endif	// COLA_H
