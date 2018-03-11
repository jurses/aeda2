#include "maquina.hpp"
#include "menu.hpp"
#include <curses.h>
#include <fstream>
#include <iostream>


enum opciones_num{
	partDefecto,
	crearRejilla,
	crearHormiga,
	empezarPartida,
	TOTAL
};

int main(int argc, char **argv){
	// inicialización de [n]curses
	initscr();	// inicialización
	raw();	// las señales no son tratadas como carácteres
	noecho();	// no se muestran los carácter [[^ o de ese tipo

	printf("Inserte las dimensiones iniciales: ");
	int alt, anc;
	scanf("%d, %d", &alt, &anch);
	AEDA::Maquina m1(alt, anc);
	const char *opciones1_c[TOTAL] =	{
										"Partida por defecto",
										"Crear rejilla",
										"Crear hormiga",
										"Empezar Partida"
										};
	do{
		int opcion = MENU::mostrarMenu(opciones1_c, TOTAL, 0, 0);
		bool rej = false;
		switch (opcion){
			case partDefecto:
			break;
			case crearRejilla:
				if (!rej)
					m1.cargarColores();
				else

				// crear la rejilla x1
			break;
			case crearHormiga:
				// crear la hormiga x(inf)
			break;
			default:
			break;
		}
	} while (opcion != 0 || opcion != 3);


	endwin();
}
