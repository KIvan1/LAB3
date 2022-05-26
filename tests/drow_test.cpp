#include"game.h"
#include<ncurses.h>

void drow()
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    e.init(2, 1, 4, m);
    hero h;
    h.init(8, 1, m);
    initscr();
    m.drow_map();
    h.drow_hero();
    e.drow_enemy(h);
    refresh();
    endwin();
}
