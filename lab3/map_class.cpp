#include"game.h"
#include<ncurses.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>

map::map()
{

}

void map::drow_map()
{
	for (int i = 0; i < this->lab.size(); i++)
	{
		mvinsstr(i, 0, lab[i]);
	}
}

void map::load_map(std::string fname)
{
	std::ifstream f(fname);
    if (!f.is_open())
    {
        fprintf(stderr, "File not found!\n");
        exit(1);
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
}
