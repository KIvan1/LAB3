#include"game.h"
#include<ncurses.h>
#include<iostream>
#include<ctime>

enemy::enemy()
{

}

enemy::enemy(int x, int y, map& m)
{
	if (m.lab[y][x] != '#')
	{
		this->x = x;
		this->y = y;
		this->prev_x = x;
		this->prev_y = y;
		this->way_len = 6;
		for (int i = 0; i < this->way_len; i ++)
		{
			this->way.push_back(0);
		}
		this->side = 1;
		this->it = 0;
	}
	else
	{
		fprintf(stderr, "obj can't be create\n");
		exit(1);
	}
	
}

void enemy::move_enemy(map& m)
{
	std::srand(std::time(NULL));
	this->prev_y = this->y;
	this->prev_x = this->x;

	if (this->way[this->it] != 0)
	{
		switch (this->way[this->it])
		{
			case 1:
				this->y--;
				break;
			case 2:
				this->x--;
				break;
			case 3:
				this->y++;
				break;
			case 4:
				this->x++;
				break;
		}
	} 
	else 
	{
		while(true)
		{
			int cur_side = rand() % 4 + 1;
			switch (cur_side)
			{
				case 1:
					if (m.lab[this->y - 1][this->x] != '#')
					{
						this->way[this->it] = cur_side;
						this->y--; 
					}
					break;
				case 2:
					if (m.lab[this->y][this->x - 1] != '#')
					{
						this->way[this->it] = cur_side;
						this->x--; 
					}
					break;
				case 3:
					if (m.lab[this->y + 1][this->x] != '#')
					{
						this->way[this->it] = cur_side;
						this->y++; 
					}
					break;
				case 4:
					if (m.lab[this->y][this->x + 1] != '#')
					{
						this->way[this->it] = cur_side;
						this->x++; 
					}
					break;
			}
			if (this->way[this->it] != 0)
				break;
		}
	}


	if (this->it + this->side >= 0 && this->it + this->side < this->way_len)
	{
		this->it += this->side;
	}
	else
	{
		this->side *= -1;
		for (int i = 0; i < this->way_len; i++)
		{
			switch(this->way[i])
			{
				case 1:
					this->way[i] = 3;
					break;
				case 2:
					this->way[i] = 4;
					break;
				case 3:
					this->way[i] = 1;
					break;
				case 4:
					this->way[i] = 2;
					break;
			}
		}
	}

}

void enemy::drow_enemy()
{
	mvdelch(this->prev_y, this->prev_x);
	mvinsch(this->prev_y, this->prev_x, ' ');
	mvdelch(this->y, this->x);
	mvinsch(this->y, this->x, '@');
}
