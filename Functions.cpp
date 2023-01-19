#include "Functions.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "BadInput.h"
using namespace std;

void makeBoard(int &height, int &width)
{
	cout << "Podaj wymiary planszy, wysokosc i szerokosc" << endl;
	cin >> height >> width;
	if (height == 0 || width == 0)
	{
		throw BadInput();
	}
	
}

void clearBoard(const int & height, const int &width, char** myBoard)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			*(*(myBoard + i) + j) = ' ';
}

void showBoard(char** myBoard, int width, int height)
{
	char x = 'A';
	int y = 1;

	for (int i = 0; i < width ; i++)
	{
		if (i == 0) cout << "   ";
		cout << " " << x << " ";
		x++;
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0) {
				if (y > 9) cout << y << " ";
				else
				cout << " " << y << " ";
				y++;
			}
			
			cout << " " << *(*(myBoard + i) + j) << " ";
		}
		cout << endl;
	}
}

int howMuchGrass(int width, int height)
{
	cout << "Wybierz ilosc trawy:" << endl;
	cout << "A: 20% planszy" << endl;
	cout << "B: 30% planszy" << endl;
	cout << "C: 50% planszy" << endl;
	char choice;
	int f = 1;
	cin >> choice;
	while (f)
	{
		switch (choice)
		{
		case 'A' | 'a':
		{
			f = 0;
			return 0.2 * width * height;
			break;
		}
		case 'B' | 'b':
		{
			f = 0;
			return 0.3 * width * height;
			break;
		}
		case 'C' | 'c':
		{
			f = 0;
			return 0.5 * width * height;
			break;
		}
		default:
		{
			cout << "Podano zla opcje, wpisz od nowa" << endl;
			cin >> choice;
		}
		}
	}
}

int howManyAnimals(int width, int height, int grassAmount)
{
	cout << "Od ilu zwierzat chcesz zaczac?" << endl;
	int animalAmount;
	cin >> animalAmount;
	if (animalAmount <= 0 || animalAmount + grassAmount > width * height)
	{
		throw BadInput();		
	}
	
	return animalAmount;
}

bool wasAlreadyDrawn(int iNumber, int* tab, int n)
{
	if (n <= 0)
		return false;

	int i = 0;
	do
	{
		if (*(tab+i) == iNumber)
			return true;

		i++;
	} while (i < n);

	return false;
}

int draw(int height, int width)
{
	
	return (rand() % (height*width-1));
}

int chooseYourFighter()
{
	cout << "Wybierz jakim zwierzatkiem chcesz grac:" << endl;
	cout << "Lama - L - porusza sie o 3 pola w danym kierunku" << endl;
	cout << "Owca - O - porusza sie o 2 pola w danym kierunku" << endl;
	cout << "Krowa - K - porusza sie o 1 pole w danym kierunku" << endl;
	char choice;
	int f = 1;
	cin >> choice;
	while (f) {
		switch (choice)
		{
		case 'L' | 'l':
			f = 0;
			cout << "Wybrales lamy, nie ma lepszego wyboru niz lamy ;)" << endl;
			return 3;
			break;
		case 'O' | 'o':
			f = 0;
			cout << "Wybrales owce, one sa takie mieciutkie ;)" << endl;
			return 2;
			break;
		case 'K' | 'k':
			f = 0;
			cout << "Wybrales krowy, zachowawczo ;)" << endl;
			return 1;
			break;

		default:
			cout << "Zla opcja, wybierz jeszcze raz" << endl;
			cout << "Lama - L - porusza sie o 3 pola w danym kierunku" << endl;
			cout << "Owca - O - porusza sie o 2 pola w danym kierunku" << endl;
			cout << "Krowa - K - porusza sie o 1 pole w danym kierunku" << endl;
			cin >> choice;
		}
	}
}

bool CorrectMove(char key)
{
	if (key == 'a' || key == 'A' ||
		key == 'w' || key == 'W' ||
		key == 's' || key == 'S' ||
		key == 'd' || key == 'D')
		return true;
	else
		return false;
}

bool Move(char key, int i, vector <Animal> & array_animal, int width, int height, char** myBoard)
{
	if (key == 'a' || key == 'A')
	{
		return array_animal[i].GoLeft(width, myBoard, array_animal[i].GetMoveValue());
	}
	else if (key == 'd' || key == 'D')
	{
		return array_animal[i].GoRight(width, myBoard, array_animal[i].GetMoveValue());
	}
	else if (key == 'w' || key == 'W')
	{
		return array_animal[i].GoUp(height, myBoard, array_animal[i].GetMoveValue());
	}
	else if (key == 's' || key == 'S')
	{
		return array_animal[i].GoDown(height, myBoard, array_animal[i].GetMoveValue());
	}
	else return false;
}

int What_previous_pos_x(char key, int i, vector<Animal> &array_animal)
{
	if (key == 'a' || key == 'A')
	{
		return array_animal[i].GetX() + array_animal[i].GetMoveValue();
	}
	else if (key == 'd' || key == 'D')
	{
		return array_animal[i].GetX() - array_animal[i].GetMoveValue();
	}
	else if (key == 'w' || key == 'W')
	{
		return array_animal[i].GetX();
	}
	else if (key == 's' || key == 'S')
	{
		return array_animal[i].GetX();
	}
}
int What_previous_pos_y(char key, int i, vector<Animal> &array_animal)
{
	if (key == 'a' || key == 'A')
	{
		return array_animal[i].GetY();
	}
	else if (key == 'd' || key == 'D')
	{
		return array_animal[i].GetY();
	}
	else if (key == 'w' || key == 'W')
	{
		return array_animal[i].GetY() + array_animal[i].GetMoveValue();
	}
	else if (key == 's' || key == 'S')
	{
		return array_animal[i].GetY() - array_animal[i].GetMoveValue();
	}
}

char win(int animalAmount)
{
	cout << "Wygrales i masz " << animalAmount << " zwierzat" << endl;
	return 'q';
}

char loose()
{
	cout << "Przegrales, nie masz juz zwierzat" << endl;
	return 'q';
}
