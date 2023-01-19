#include "Grass.h"
#include <iostream>
using namespace std;
Grass::Grass(int x, int y)
{
	this->x = x;
	this->y = y;
}

Grass::Grass()
{
	this->x = 0;
	this->y = 0;
}

Grass::~Grass()
{
	;
}

void Grass::SaveInBoard(char** myBoard)
{
	*(*(myBoard + this->y) + this->x) = id;
}

void Grass::RemoveFromBoard(char** myBoard)
{
	*(*(myBoard + this->y) + this->x) = ' ';
}

int Grass::GetX()
{
	return this->x;
}

int Grass::GetY()
{
	return this->y;
}
