#pragma once
#include<vector>
#include<string>

struct map;
struct enemy;
struct hero;
void set_way(enemy& e);
void draw();

struct hero
{
    friend struct enemy;

	hero();
    bool init(int x, int y, const map& m);
    void move_x(int side, const map& m);
    void move_y(int side, const map& m);
    void draw_hero();
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
    void draw_map();
    bool load_map(std::string fname);
    bool finish(int x, int y);
    bool clear();
    void get_map(std::vector<std::string>& lab);
    int get_f_x();
    int get_f_y();
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
    friend void set_way(enemy& e);

	enemy();
    bool init(int x, int y, int way_len, const map& m);
    bool move_enemy(const map& m);
    void draw_enemy(const hero& h);
    int get_x();
    int get_y();
    int get_prev_x();
    int get_prev_y();
    int get_way_len();
    void get_way(std::vector<int>& way);
    int get_side();
    int get_it();
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
