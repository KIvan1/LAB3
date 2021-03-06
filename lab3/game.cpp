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
    if(m.load_map("maps/map.txt"))
        return 0;
    if (m.finish(38, 19))
    {
        m.clear();
        return 0;
    }
    hero h;
    if(h.init(2, 1, m))
    {
        m.clear();
        return 0;
    }
	vector<enemy> e;
    enemy cur_e;
    if(cur_e.init(4, 3, 10, m))
    {
        m.clear();
        return 0;
    }
    e.push_back(cur_e);
    enemy cur_e1;
    if(cur_e1.init(20, 5, 7, m))
    {
        m.clear();
        return 0;
    }
    e.push_back(cur_e1);

    if (!(initscr()))
    {
        fprintf(stderr, "Error");
        exit(1);
    }

    m.draw_map();
	for (int i = 0; i < e.size(); i ++)
	{
        e[i].draw_enemy(h);
	}
    h.draw_hero();
	refresh();
	while (k)
	{
        k = get_comm(h, m);
        h.draw_hero();
		for (int i = 0; i < e.size(); i ++)
		{
            if(e[i].move_enemy(m))
                return 0;
            if (h.collision(e[i], m))
            {
                k = false;
                break;
            }
            e[i].draw_enemy(h);
        }
		refresh();
	}
    endwin();

    m.clear();

	return 0;
}
