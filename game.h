#pragma once
#include<iostream>

struct hero
{
	hero();
	hero(int x, int y);
	void move_x(int side);
	void move_y(int side);
	void drow_hero();
private:
	int x;
	int y;
	int prev_x;
	int prev_y;
};

struct map
{
	map();
	void drow_map();
private:
	int h = 10;
	int w = 10;
};

bool get_comm(hero& h); 