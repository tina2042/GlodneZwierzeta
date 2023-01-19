#pragma once
#include "Grass.h"
#include <iostream>
#include <vector>
using namespace std;
class Animal
{
private:
	int x;
	int y;
	char id;
	int move_value;
public:
	Animal();
	Animal(int x, int y);
	Animal(int x, int y, char id, int move_value);
	friend ostream& operator<<(ostream& os, Animal& anim); //przeciezenie operatora do wypisania
	
 ~Animal();
	int GetX();
	int GetY();
	char GetId();
	int GetMoveValue();
	void SaveInBoard(char** myBoard);
	void RemoveFromBoard(char** myBoard);
	bool GoUp(int height, char** myBoard, const int move_value);
	bool GoDown(int height, char** myBoard, const int move_value);
	bool GoLeft(int width, char **myBoard, const int move_value);
	bool GoRight(int width, char** myBoard, const int move_value);
	int Collision(std::vector<Animal> &table, int size, int j);
	int EatGrass(std::vector<Grass> &table, int grass_amount);
	Animal operator++(int);

};

