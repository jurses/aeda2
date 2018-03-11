#ifndef MENU_H
#define MENU_H

#define CENTROY(Y1, Y2) (Y1 - Y2)/2
#define CENTROX(X1, X2) (X1 - X2)/2

#include <curses.h>
#include <string.h>
#include <cstdarg.h>

namespace MENU{
	int mostrarMenu(const char *, const **char, int, int, int);
	void ventEmergente(const char, const char *);

	// ventana que recoge numeros enteros
	void ventanaRecNumE(const char *, const char *, int, ...);
}

#endif	// MENU_H
