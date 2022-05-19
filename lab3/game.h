#pragma once
#include<vector>
#include<string>

struct map;
struct enemy;
struct hero;

struct hero
{
    friend struct enemy;

	hero();
    bool init(int x, int y, const map& m);
    void move_x(int side, const map& m);
    void move_y(int side, const map& m);
	void drow_hero();
    bool collision(const enemy& e, const map& m);
    int get_x();
    int get_y();
    int get_prev_x();
    int get_prev_y();
private:
	int x;
	int y;
	int prev_x;
	int prev_y;
};

struct map
{
	friend struct hero;
	friend struct enemy;

	map();
	void drow_map();
    bool load_map(std::string fname);
    bool finish(int x, int y);
    bool clear();
    void get_map(std::vector<std::string>& lab);
private:
	std::vector<char*> lab;
	int h;
	int w;
    int f_x;
    int f_y;
};

struct enemy
{
    friend struct hero;

	enemy();
    bool init(int x, int y, const map& m);
    void move_enemy(const map& m);
    void drow_enemy(const hero& h);
private:
	int x;
	int y;
	int prev_x;
	int prev_y;
	int way_len;
	std::vector<int> way;
	int it;
	int side;
};

bool get_comm(hero& h, const map& m);
