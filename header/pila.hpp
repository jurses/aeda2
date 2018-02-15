#ifndef PILA_H
#define PILA_H

#include "listaEnla.hpp"

template<class TDATO>
class Pila{
	private:
		ListaEnla<TDATO> lista_;
	public:
		Pila();
		Pila(const Pila &);
		int obtTam();
		void apilar(TDATO);
		void desapilar(void);
		TDATO mostrar(void);		
};

template<class TDATO>
Pila<TDATO>::Pila(){}

template<class TDATO>
Pila<TDATO>::Pila(const Pila &pila):
	lista_(pila.lista_)
	{}

template<class TDATO>
void Pila<TDATO>::apilar(TDATO dato){
	Nodo<TDATO> *nuevoNodo = new Nodo<TDATO>(dato);

	lista_.insertNodo(nuevoNodo);
}

template<class TDATO>
void Pila<TDATO>::desapilar(void){
	lista_.extracUltimo();
}

template<class TDATO>
TDATO Pila<TDATO>::mostrar(void){
	return lista_.obtUltimo()->obtDato();
}

template<class TDATO>
int Pila<TDATO>::obtTam(void){
	return lista_.obtTam();
}

#endif	// PILA_H
