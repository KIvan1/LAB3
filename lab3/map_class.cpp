#include"game.h"
#include<ncurses.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>

map::map()
{
    this->f_x = -1;
    this->f_y = -1;
}

void map::draw_map()
{
	for (int i = 0; i < this->lab.size(); i++)
	{
        mvinsstr(i, 0, lab[i]);
        if (i == this->f_y)
        {
            mvdelch(this->f_y, this->f_x);
            mvinsch(this->f_y, this->f_x, 'F');
        }
	}
}

bool map::load_map(std::string fname)
{
	std::ifstream f(fname);
    if (!f.is_open())
    {
        fprintf(stderr, "File not found!\n");
        return 1;
    }
	std::string line;
	while (std::getline(f, line))
	{
		char* cur_line = new char[256];
		int i;
		for (i = 0; i < line.length(); i++)
		{
			cur_line[i] = line[i];
		}
		i++;
		this->w = i;
		cur_line[i] = '\0';
		this->lab.push_back(cur_line);
	}
	this->h = this->lab.size();
    f.close();
    return 0;
}

bool map::finish(int x, int y)
{
    if (x <= 0 || y <= 0)
    {
        fprintf(stderr, "finish can't be create\n");
        return 1;
    }

    if (x % 2 != 0)
    {
        fprintf(stderr, "finish can't be create\n");
        return 1;
    }

    if (x >= this->w || y >= this->h)
    {
        fprintf(stderr, "finish can't be create\n");
        return 1;
    }

    if (this->lab[y][x] == '#')
    {
        fprintf(stderr, "finish can't be create\n");
        return 1;
    }

    this->f_x = x;
    this->f_y = y;
    return 0;
}

bool map::clear()
{
    for (int i = 0; i < this->lab.size(); i++)
    {
        free(lab[i]);
    }
    return 0;
}

void map::get_map(std::vector<std::string>& lab)
{
    for (int i = 0; i < this->h; i++)
    {
        lab.push_back(this->lab[i]);
    }
}

int map::get_f_x(){return this->f_x;}

int map::get_f_y(){return this->f_y;}
