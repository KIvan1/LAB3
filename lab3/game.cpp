#include<iostream>
#include<ncurses.h>
#include<unistd.h>
#include<vector>
#include"game.h"


using namespace std;

int main()
{
	bool k = true;
	map m;
    m.load_map("map.txt");
	hero h(1, 1, m);
	vector<enemy> e;
	enemy cur_e(10, 7, m);
	e.push_back(cur_e);

	if (!(initscr()))
	{
		fprintf(stderr, "Error");
		exit(1);
	}

	m.drow_map();
	for (int i = 0; i < e.size(); i ++)
	{
		e[i].drow_enemy();
	}
	h.drow_hero();
	refresh();
	while (k)
	{
		k = get_comm(h, m);
		h.drow_hero();
		for (int i = 0; i < e.size(); i ++)
		{
			e[i].move_enemy(m);
			e[i].drow_enemy();
		}
		refresh();
	}
	endwin();

	return 0;
}
