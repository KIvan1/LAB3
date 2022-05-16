#include<iostream>
#include<ncurses.h>
#include"game.h"


using namespace std;

int main()
{
	hero f(12,3);
	if (!(initscr()))
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	printw("Hello world!\n");
    getch();
    mvinsch(15,10,'#');
    refresh();
    getch();
    mvinsch(15,10,'&');
    refresh();
    getch();

	endwin();

	return 0;
}