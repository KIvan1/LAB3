#include"game.h"
#include<ncurses.h>

void draw()
{
    map m;
    m.load_map("maps/map.txt");
    enemy e;
    e.init(2, 1, 4, m);
    hero h;
    h.init(8, 1, m);
    initscr();
    m.draw_map();
    h.draw_hero();
    e.draw_enemy(h);
    refresh();
    endwin();
}
