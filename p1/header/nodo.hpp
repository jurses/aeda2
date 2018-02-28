#ifndef NODO_H
#define NODO_H

template<class TDATO>
class Nodo{
	private:
		Nodo *nodoSig_;
		TDATO dato_;
	public:
		Nodo();
		Nodo(TDATO);
		// TDATO& operator=(const TDATO&);
		TDATO& obtDato(void);
		Nodo<TDATO>& operator=(const Nodo<TDATO>&);
		Nodo<TDATO>*& obtSig(void);
};

template<class TDATO>
Nodo<TDATO>::Nodo(TDATO dato):
	nodoSig_(nullptr),
	dato_(dato)
{
}

template<class TDATO>
Nodo<TDATO>::Nodo():
	nodoSig_(nullptr)
{
}

/*
template<class TDATO>
TDATO& Nodo<TDATO>::operator=(const TDATO& dato){
	dato_ = dato;
	return dato_;
}
*/

template<class TDATO>
TDATO& Nodo<TDATO>::obtDato(){
	return dato_;
}

template<class TDATO>
Nodo<TDATO>*& Nodo<TDATO>::obtSig(void){
	return nodoSig_;
}

template<class TDATO>
Nodo<TDATO>& Nodo<TDATO>::operator=(const Nodo<TDATO>& nodo){
	nodoSig_ = nodo.nodoSig_;
	dato_ = nodo.dato_;

	return *this;
}

#endif	// NODO_H
