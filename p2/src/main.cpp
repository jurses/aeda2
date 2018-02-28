#include "maquina.hpp"
#include <fstream>
#include <iostream>

int main(void){
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
}
