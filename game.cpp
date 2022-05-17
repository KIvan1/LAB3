#include<iostream>
#include<ncurses.h>
#include<unistd.h>
#include"game.h"


using namespace std;

int main()
{
	bool k = true;
	hero h(3, 3);
	map m;

	if (!(initscr()))
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	m.drow_map();
	while (k)
	{
		h.drow_hero();
		refresh();
		k = get_comm(h);
	}

	endwin();

	return 0;
}