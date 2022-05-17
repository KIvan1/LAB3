#include<iostream>
#include"game.h"


bool get_comm(hero& h, map& m) 
{
	char comm;
	comm = std::getchar();
	switch(comm)
	{
		case 'w':
			h.move_y(-1, m);
			break;
		case 's':
			h.move_y(1, m);
			break;
		case 'a':
			h.move_x(-1, m);
			break;
		case 'd':
			h.move_x(1, m);
			break;
		case 'q':
			return false;
	}
	return true; 
}
