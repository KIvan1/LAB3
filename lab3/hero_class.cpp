#include<iostream>
#include<ncurses.h>
#include"game.h"

hero::hero()
{

}

hero::hero(int x, int y, map& m)
{
    if (m.lab[y][x] != '#')
	{
		this->x = x;
		this->y = y;
		this->prev_x = x;
		this->prev_y = y;
	}
	else
	{
		fprintf(stderr, "obj can't be create\n");
		exit(1);
	}
}

void hero::move_x(int side, map& m)
{
	this->prev_x = this->x;
	this->prev_y = this->y;
	if (m.lab[this->y][this->x + side] != '#')
		this->x += side;
}

void hero::move_y(int side, map& m)
{
	this->prev_x = this->x;
	this->prev_y = this->y;
	if (m.lab[this->y + side][this->x] != '#') 
		this->y += side;
}

void hero::drow_hero()
{
	mvdelch(this->prev_y, this->prev_x);
	mvinsch(this->prev_y, this->prev_x, ' ');
	mvdelch(this->y, this->x);
	mvinsch(this->y, this->x, 'o');
}
