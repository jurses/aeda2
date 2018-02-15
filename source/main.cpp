#include <cstdlib>
#include <cstdio>

#include "../header/nodo.hpp"
#include "../header/listaEnla.hpp"
#include "../header/vector.hpp"
#include "../header/cola.hpp"
#include "../header/pila.hpp"

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

	Pila<int> p1;
	Cola<int> c1;

	for(int i = 0; i < NUM; i++){
		p1.apilar(v1[i]);
		c1.encolar(v1[i]);
	}

	printf("Sacando elmentos de la pila: ");
	for(int i = 0; i < 5; i++){
		printf("%d ", p1.mostrar());
		p1.desapilar();
	}

	Pila<int> p2(p1);

	printf("\n Tam p2: %d \t, Tam p1: %d", p2.obtTam(), p1.obtTam());
}
