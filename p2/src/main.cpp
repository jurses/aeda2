#include "maquina.hpp"
#include "hormiga.hpp"
#include <fstream>
#include <iostream>

int main(void){
	/*
	AEDA::Maquina m1(20, 20);
	std::ifstream fHorConf;
	std::ifstream fColorConf;
	fHorConf.open("./conf/h1.conf", std::ifstream::in);
	fColorConf.open("./conf/colores.conf", std::ifstream::in);
	m1.ponHormiga(fHorConf);
	m1.cargarColores(fColorConf);
	do{
		m1.sigGen();
		std::cout << m1.devHormiguero() << std::endl;
	}while (getchar() != 'q');
	fHorConf.close();
	fColorConf.close();
	*/

	AEDA::Hormiga *h1, *h2;	// Declaración de puntero a hormiga
	AEDA::MaquinaV2 m1(20, 20);

	std::ifstream fColorConf;
	fColorConf.open("./conf/colores.conf", std::ifstream::in);
	m1.cargarColores(fColorConf);

	h1 = new AEDA::DDII(13, 6);	// nueva hormiga
	h2 = new AEDA::DDII(5, 8);	// nueva hormiga
	
	m1.cargarHormiga(h1);
	m1.cargarHormiga(h2);

	do{
		m1.sigGen();
		std::cout << m1.devHormiguero() << std::endl;
	}while (getchar() != 'q');


	fColorConf.close();
	delete h1;
}
