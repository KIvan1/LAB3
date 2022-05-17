#include<iostream>
#include<ncurses.h>
#include"game.h"

hero::hero()
{

}

hero::hero(int x, int y)
{
	this->x = x;
	this->y = y;
	this->prev_x = x;
	this->prev_y = y;
}

void hero::move_x(int side)
{
	this->prev_x = this->x;
	this->prev_y = this->y;
	this->x += side;
}

void hero::move_y(int side)
{
	this->prev_x = this->x;
	this->prev_y = this->y;
	this->y += side;
}

void hero::drow_hero()
{
	mvdelch(this->prev_y, this->prev_x);
	mvinsch(this->prev_y, this->prev_x, ' ');
	mvdelch(this->y, this->x);
	mvinsch(this->y, this->x, 'o');
}