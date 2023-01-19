#include "Animal.h"
#include <vector>
Animal::Animal()
{
	this->x = 1;
	this->y = 1;
	this->id = '/';
	this->move_value = 0;
}

Animal::Animal(int x, int y)
{
	this->x = x;
	this->y = y;
}

Animal::Animal(int x, int y, char id, int move_value)
{
	this->x = x;
	this->y = y;
	this->id = id;
	this->move_value = move_value;
}

Animal::~Animal()
{
	;
}

int Animal::GetX()
{
	return this->x;
}

int Animal::GetY()
{
	return this->y;
}

char Animal::GetId()
{
	return this->id;
}

int Animal::GetMoveValue()
{
	return this->move_value;
}

void Animal::SaveInBoard(char** myBoard)
{
	*(*(myBoard + this->y) + this->x) = id;
}

void Animal::RemoveFromBoard(char** myBoard)
{	
	*(*(myBoard + this->y) + this->x) = ' ';
}

bool Animal::GoUp(int height, char** myBoard, const int move_value)
{	
	int check = this->y - move_value;
	if (check >= 0)
	{
		RemoveFromBoard(myBoard);
		this->y-=move_value;
		return true;
	}
	else return false;
}

bool Animal::GoDown(int height, char** myBoard, const int move_value)
{
	int check = this->y + move_value;
	if (check < height)
	{
		RemoveFromBoard(myBoard);
		this->y+=move_value;
		return true;
	}
	else return false;
}

bool Animal::GoLeft(int width, char **myBoard, const int move_value)
{
	int check = this->x - move_value;
	if (check >= 0)
	{	
		RemoveFromBoard(myBoard);
		this->x-=move_value;
		return true;
	}
	return false;
}

bool Animal::GoRight(int width, char** myBoard, const int move_value)
{
	int check = this->x + move_value;
	if (check < width)
	{
		RemoveFromBoard(myBoard);
		this->x+=move_value;
		return true;
	}
	return false;
}

int Animal::Collision(std::vector<Animal> &table, int size, int j)
{
	for (int i = 0; i < size; i++)
	{
		if (i == j) ;
		else if (table[i].x == this->x && table[i].y == this->y)
		{
			//wypisz zabite zwierze
			//table.erase(table.begin() + i, table.begin() + i + 1);
			
			return i;
		}
	}
	return -1;
}

int Animal::EatGrass(std::vector<Grass> &table, int grass_amount )
{
	for (int i = 0; i < grass_amount; i++)
	{
		if (this->x == table[i].GetX() && this->y == table[i].GetY())
		{
			table.erase(table.begin() + i, table.begin() + i + 1);
			return i;
		}
	}
	return -1;
}

ostream& operator<<(ostream& os, Animal& anim)
{
	os << "x: " << anim.x << " " << "y: " << anim.y << endl;
	return os;
}
Animal Animal::operator++(int) //funkcja do postinkrementacji
{
	Animal newA((this->x)++, (this->y)++);
	return newA;
}
