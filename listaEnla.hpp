#ifndef LISTAENLA_H
#define LISTAENLA_H

#include <cassert>

#include "nodo.hpp"

template<class TDATO>
class ListaEnla{
	private:
		Nodo<TDATO> *cabeza_;
	public:
		ListaEnla();
		int obtTam(void);
		void insertNodo(Nodo<TDATO>*);
		Nodo<TDATO>* extracNodo(TDATO);
		Nodo<TDATO>* obtUltimo(void);
		Nodo<TDATO>* obtCabeza(void);
};

template<class TDATO>
ListaEnla<TDATO>::ListaEnla():
	cabeza_(nullptr)
{
}

template<class TDATO>
void ListaEnla<TDATO>::insertNodo(Nodo<TDATO> *nuevoNodo){
	Nodo<TDATO> *aux = cabeza_;
	if(aux){
		while(aux->obtSig())	// buscar el último nodo
			aux = aux->obtSig();
		aux->obtSig() = nuevoNodo;	// incorporarle al último nodo colgante el 'nuevoNodo'
	}else
		cabeza_ = nuevoNodo;

}

template<class TDATO>
Nodo<TDATO>* ListaEnla<TDATO>::obtCabeza(){
	return cabeza_;
}

template<class TDATO>
int ListaEnla<TDATO>::obtTam(void){
	Nodo<TDATO> *aux = cabeza_;
	int tam = 0;
	while(aux){
		aux = aux->obtSig();
		tam++;
	}
	
	return tam;
}

template<class TDATO>
Nodo<TDATO>* ListaEnla<TDATO>::obtUltimo(void){
	assert(this->obtTam() > 0);
	Nodo<TDATO> *aux = cabeza_;
	while(aux->obtSig())
		aux = aux->obtSig();
	return aux;
}

template<class TDATO>
Nodo<TDATO>* ListaEnla<TDATO>::extracNodo(TDATO dato){
	assert(this->obtTam() > 0);
	Nodo<TDATO> *aux = cabeza_;
	// En caso de que sea el nodo cabeza
	if(aux->obtDato() == dato){
		cabeza_ = aux->obtSig();	// la cabeza pasa a ser el nodo siguiente
		return aux;
	}
	// Si es un nodo que no es el nodo cabeza... 
	while(aux->obtSig()){
		if(aux->obtSig()->obtDato() == dato){
			Nodo<TDATO> *temp = aux->obtSig();
			aux->obtSig() = aux->obtSig()->obtSig();
			return temp;
		}
		aux = aux->obtSig();
	}
	
	return nullptr;
}

#endif	// LISTAENLA_H
