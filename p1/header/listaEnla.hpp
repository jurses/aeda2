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
		void extracUltimo(void);
		void extracCabeza(void);
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
void ListaEnla<TDATO>::extracCabeza(void){
	assert(this->obtTam() > 0);
	Nodo<TDATO> *aux = cabeza_;
	cabeza_ = cabeza_->obtSig();
	delete aux;
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
void ListaEnla<TDATO>::extracUltimo(void){
	assert(this->obtTam() > 0);
	Nodo<TDATO> *aux = cabeza_;
	if(aux->obtSig())
		aux = aux->obtSig();
	else{
		cabeza_ = nullptr;
		delete aux;
	}
	do{
		Nodo<TDATO> *anterior = aux;
		aux = aux->obtSig();
		if(aux->obtSig() == nullptr){
			delete aux;
			anterior = nullptr;
		}
	}while(aux->obtSig());
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

template<class TDATO>
Nodo<TDATO>* ListaEnla<TDATO>::obtUltimo(void){
	Nodo<TDATO> *aux = cabeza_;
	while(aux->obtSig())
		aux = aux->obtSig();

	return aux;
}

#endif	// LISTAENLA_H
