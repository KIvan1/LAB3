#include<iostream>
#include<ncurses.h>
#include"game.h"

hero::hero()
{

}

bool hero::init(int x, int y, const map& m)
{
    if (x <= 0 || y <= 0)
    {
        fprintf(stderr, "hero obj can't be init\n");
        return 1;
    }

    if (x % 2 != 0)
    {
        fprintf(stderr, "hero obj can't be init\n");
        return 1;
    }

    if (x >= m.w || y >= m.h)
    {
        fprintf(stderr, "hero obj can't be init\n");
        return 1;
    }

    if (m.lab[y][x] != '#')
	{
		this->x = x;
		this->y = y;
		this->prev_x = x;
		this->prev_y = y;
        return 0;
	}
	else
	{
        fprintf(stderr, "hero obj can't be init\n");
        return 1;
	}
}

void hero::move_x(int side, const map& m)
{
	this->prev_x = this->x;
	this->prev_y = this->y;
    if (m.lab[this->y][this->x + side * 2] != '#')
        this->x += side * 2;
}

void hero::move_y(int side, const map& m)
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

bool hero::collision(const enemy& e, const map& m)
{
    if (e.x == this->x && e.y == this->y)
    {
        return 1;
    }
    if (m.f_x == this->x && m.f_y == this->y)
    {
        return 1;
    }
    return 0;
}
