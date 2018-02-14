#include <cstdlib>
#include <cstdio>

#include "nodo.hpp"
#include "listaEnla.hpp"
#include "vector.hpp"

#define NUM 14

int main(void){
	srand(NUM);
	Vector<int> v1(NUM);

	for(int i = 0; i < NUM; i++)
		v1[i] = rand() % 50;
	
	printf("Mostrando el vector: ");
	for(int i = 0; i < NUM; i++)
		printf("%d ", v1[i]);
	printf("\n");

	ListaEnla<int> l1;

	for(int i = 0; i < NUM; i++)
		l1.insertNodo(new Nodo<int>(v1[i]));

	printf("%d\n", l1.obtTam());

	Nodo<int> *n1;
	printf("Mostrando la lista enlazada: ");
	for(int i = 0; i < NUM; i++){
		n1 = l1.extracNodo(v1[NUM - i - 1]);	// yendo por la lista al revés...
		printf("%d ", n1->obtDato());
		delete n1;
	}
	printf("\n");

	printf("%d\n", l1.obtTam());
}
