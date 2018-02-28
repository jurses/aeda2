#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

template<class TDATO>
class Vector{
	private:
		TDATO *datos_;
		int tam_;
		void limpiar(void);
	public:
		Vector();
		Vector(int);
		~Vector();
		void redimensionar(int);
		void pasarAtras(TDATO);
		TDATO& operator[](int);
		int obtTam(void){ return tam_; }
};

template<class TDATO>
Vector<TDATO>::Vector():
	tam_(0),
	datos_(nullptr)
{}

template<class TDATO>
Vector<TDATO>::Vector(int tam):
	tam_(tam)
{
	datos_ = new TDATO[tam];
}

template<class TDATO>
Vector<TDATO>::~Vector(){
	limpiar();
}

template<class TDATO>
void Vector<TDATO>::limpiar(void){
	redimensionar(0);
	datos_ = nullptr;
}

template<class TDATO>
void Vector<TDATO>::redimensionar(int tam){
	TDATO *nDatos = new TDATO[tam];
	for(int i = 0; i < (tam < tam_ ? tam : tam_); i++)
		nDatos[i] = datos_[i];

	datos_ = nDatos;
	delete[] nDatos;
	tam_ = tam;
}

template<class TDATO>
void Vector<TDATO>::pasarAtras(TDATO item){
	redimensionar(tam_ + 1);
	datos_[tam_ - 1] = item;
}

template<class TDATO>
TDATO& Vector<TDATO>::operator[](int i){
	assert(i >= 0 && i < tam_);
	return datos_[i];
}

#endif	// VECTOR_H
