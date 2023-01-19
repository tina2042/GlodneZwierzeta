#pragma once
#include <vector>
#include "Animal.h"
#include "Grass.h"
using namespace std;
void makeBoard(int &height, int &width);
void clearBoard(const int& height, const int& width, char** myBoard);
void showBoard(char** MyBoard, int width, int height);

int howMuchGrass(int width, int height);
int howManyAnimals(int width, int height, int grassAmount);

bool wasAlreadyDrawn(int iNumber, int* tab, int n);
int draw(int height, int width);

int chooseYourFighter();

bool CorrectMove(char key);
bool Move(char key, int i, vector<Animal> &array_animal, int width, int height, char** myBoard);
int What_previous_pos_x(char key, int i, vector<Animal> &array_animal);
int What_previous_pos_y(char key, int i, vector<Animal> &array_animal);
char win(int animalAmount);
char loose();