#include"game.h"
#include<ncurses.h>
#include<iostream>
#include<ctime>

enemy::enemy()
{

}

bool enemy::init(int x, int y, int way_len, const map& m)
{
    if (x <= 0 || y <= 0)
    {
        fprintf(stderr, "enemy obj can't be init\n");
        return 1;
    }

    if (x % 2 != 0)
    {
        fprintf(stderr, "enemy obj can't be init\n");
        return 1;
    }

    if (x >= m.w || y >= m.h)
    {
        fprintf(stderr, "enemy obj can't be init\n");
        return 1;
    }

    if (way_len <= 0)
    {
        fprintf(stderr, "enemy obj can't be init\n");
        return 1;
    }

	if (m.lab[y][x] != '#')
	{
		this->x = x;
		this->y = y;
		this->prev_x = x;
		this->prev_y = y;
        this->way_len = way_len;
		for (int i = 0; i < this->way_len; i ++)
		{
			this->way.push_back(0);
		}
		this->side = 1;
		this->it = 0;
        return 0;
	}
	else
	{
        fprintf(stderr, "enemy obj can't be init\n");
        return 1;
	}
	
}

void enemy::move_enemy(const map& m)
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
                this->x-=2;
				break;
			case 3:
                this->y++;
				break;
			case 4:
                this->x+=2;
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
                    if (m.lab[this->y][this->x - 2] != '#')
					{
						this->way[this->it] = cur_side;
                        this->x-=2;
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
                    if (m.lab[this->y][this->x + 2] != '#')
					{
						this->way[this->it] = cur_side;
                        this->x+=2;
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

void enemy::drow_enemy(const hero& h)
{
    if (this->prev_x != h.x || this->prev_y != h.y)
    {
        mvdelch(this->prev_y, this->prev_x);
        mvinsch(this->prev_y, this->prev_x, ' ');
    }
    mvdelch(this->y, this->x);
    mvinsch(this->y, this->x, '@');
}

int enemy::get_x(){return this->x;}
int enemy::get_y(){return this->y;}
int enemy::get_prev_x(){return this->prev_x;}
int enemy::get_prev_y(){return this->prev_y;}
int enemy::get_way_len(){return this->way_len;}
void enemy::get_way(std::vector<int>& way){way = this->way;}
