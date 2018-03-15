#include <curses.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void crearVent(const char *, const char *, int, ...);

int main(void){
	initscr();
	cbreak();
	int anio, peso, altura;
	crearVent("Datos", "Año, peso, altura", 3, &anio, &peso, &altura);
	printw("Año: %d, peso: %d, altura %d.\n", anio, peso, altura);
	getch();
	endwin();
}


void crearVent(const char *titulo, const char *cadena, int arg, ...){
	WINDOW *win = newwin(15, 29, 6, 2);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	mvwprintw(win, 0, 3, "%s", titulo);
	mvwprintw(win, 2, 3, "%s", cadena);
	va_list vl;
	va_start(vl, arg);
	wmove(win, 3, 3);

	char cadI[256];
	wscanw(win, "%[^\n]", cadI);

	int *p;
	if (arg > 1){
		char aux[256];
		for (int i = 0; i < arg - 1; i++){
			sscanf(cadI, "%[^,]", aux);
			p = va_arg(vl, int *);
			*p = atoi(aux);
		}
	}
	
	p = va_arg(vl, int *);
	*p = atoi(cadI);
	
	mvwprintw(win, 4, 3, "Terminé");
	wgetch(win);
	delwin(win);
}
