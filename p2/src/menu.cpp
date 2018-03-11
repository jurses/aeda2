#include "menu.hpp"
namespace MENU{
	void ventEmergente(const char *cad, const char *tit){
		curs_set(0);
		WINDOW *vent = newwin(5, strlen(cad) + 2, CENTROY(getmaxy(stdscr), 5), CENTROX(getmaxx(stdscr), strlen(cad) + 2));
		keypad(vent, true);
		refresh();
		wrefresh(menuVent);

		mvwprintw(vent, 2, 2, cad);
		if (tit)
			mvwprintw(vent, 0, 2, tit);

		wgetch(vent);
		curs_set(1);
	}
	int mostrarMenu(const **char opciones_c, int args, int y, int x){
		curs_set(0);
		int maxSize = 0;
		for (int i = 0; i < args; i++)
			if (maxSize < strlen(opciones_c[i]))
				maxSize = strlen(opciones_c[i]);
		
		WINDOW *menuVent;
		if (y == 0 && x == 0)
			//menuVent = newwin(args, maxSize, (getmaxy(stdscr) - args) / 2, (getmaxx(stdscr) - maxSize)/2 );
			menuVent = newwin(args, maxSize, CENTROY(args), CENTROX(maxSize));
		else
			menuVent = newwin(args, maxSize, y, x);

		keypad(menuVent, true);

		refresh();
		wrefresh(menuVent);
		box(menuVent, 0, 0);

		int sobresaltado = 0;
		int eleccion = 0;
		do {
			for (int i = 0; i < args; i++){
				if (i == sobresaltado)
					wattron(menuVent, A_REVERSE);
				mvwprintw(menuVent, i+1, 1, opciones_c[i]);
				wattroff(menuVent, A_REVERSE);
			}

			eleccion = wgetch(menuVent);

			switch (eleccion){
				case KEY_UP:
					if (sobresaltado > 0)
						sobresaltado--;
				break;
				case KEY_DOWN:
					if (sobresaltado < args - 1)
						sobresaltado++;
				break;
				case KEY_RIGHT:
					return eleccion;
				break:
				default:
				break;
			}
		} while (eleccion == 'q');
	}
	curs_set(1);
}
