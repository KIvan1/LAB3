#include<iostream>
#include"game.h"


bool get_comm(hero& h, const map& m)
{
    bool k = true;
    while (k)
    {
        char comm;
        comm = std::getchar();
        switch(comm)
        {
            case 'w':
                h.move_y(-1, m);
                k = false;
                break;
            case 's':
                h.move_y(1, m);
                k = false;
                break;
            case 'a':
                h.move_x(-1, m);
                k = false;
                break;
            case 'd':
                h.move_x(1, m);
                k = false;
                break;
            case 'q':
                return false;
        }
    }
	return true; 
}
