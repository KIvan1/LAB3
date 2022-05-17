#pragma once
#include<vector>
#include<string>

struct map;
struct enemy;

struct hero
{
	hero();
	hero(int x, int y);
	void move_x(int side, map& m);
	void move_y(int side, map& m);
	void drow_hero();
private:
	int x;
	int y;
	int prev_x;
	int prev_y;
};

struct map
{
	friend struct hero;
	map();
	void drow_map();
	void load_map(std::string fname);
private:
	std::vector<char*> lab;
	int h;
	int w;
};

struct enemy
{

};

bool get_comm(hero& h, map& m); 