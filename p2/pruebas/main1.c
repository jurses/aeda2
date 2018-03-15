#include <curses.h>
#include <stdio.h>
#include <string.h>

#define CENTROY(Y1, Y2) (Y1 - Y2)/2
#define CENTROX(X1, X2) (X1 - X2)/2

struct WSize{
	int h;
	int w;
};

enum num_options{
	walk,
	swin,
	run,
	fly,
	all
};

const char *options_c[all] = {"walk", "swin", "run", "fly" };

int getMaxStrlen(const char **, int);

void menu(WINDOW *);

int main(void){
	initscr();
	int x, y;
	getmaxyx(stdscr, x, y);
	cbreak();	// las señales de interrupción son tratadas como calquier otro carácter en la terminal
	  		// al contrario que raw()
	noecho();

	struct WSize ws1;
	ws1.w = getMaxStrlen(options_c, all) + 4;
	ws1.h = all + 2;
	//if (ws1.w < 60 || ws1.h < 10){
	//	ws1.w = getmaxx(stdscr);
	//	ws1.h = getmaxy(stdscr);
	//}
	
	WINDOW *win1 = newwin(ws1.h, ws1.w, CENTROY(getmaxy(stdscr), ws1.h), CENTROX(getmaxx(stdscr), ws1.w));
	box(win1, 0, 0);
	refresh();
	wrefresh(win1);
	menu(win1);
	endwin();
}

void menu(WINDOW *win){
	keypad(win, true);
	int option;
	int highlight = 0;
	curs_set(0);
	do{
		for (int i = 0; i < all; i++){
			if (i == highlight)
				wattron(win, A_REVERSE);
			mvwprintw(win, i + 1, 2, options_c[i]);
			wattroff(win, A_REVERSE);
		}
		option = wgetch(win);
		switch (option){
			case KEY_UP:
				if (highlight > 0)
					highlight--;
			break;
			case KEY_DOWN:
				if (highlight < all - 1)
					highlight++;
			break;
			default:
			break;
		}
	} while (option != 'q');
}

int getMaxStrlen(const char **cad, int args){
	int max = strlen(cad[0]);
	for (int i = 1; i < args; i++)
		if (max < strlen(cad[i]))
			max = strlen(cad[i]);
	return max;
}
