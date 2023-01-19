#include <iostream>
#include <algorithm>
#include <vector>
#include "Grass.h"
#include "Functions.h"
#include "Animal.h"
#include "BadInput.h"
#include <exception>
using namespace std;

int main()
{
	int height=0, width=0;
	while (!height || !width)
	{
		try 
		{ 
			makeBoard(height, width); 
		}
		catch (BadInput& ex)
		{
			cout << ex.what() << endl;
		}
	}
	
		char** myBoard = new char* [height];
		for (int i = 0; i < height; i++)
		{
			myBoard[i] = new char[width];
		}

	clearBoard(height, width, myBoard);
	int animalAmount=0;
	int grassAmount = howMuchGrass(width, height);
	while (!animalAmount)
	{
		try
		{
			animalAmount = howManyAnimals(width, height, grassAmount);
		}
		catch (BadInput& ex)
		{
			cout << ex.what() << endl;
		}
	}
	int objectsAmount = grassAmount + animalAmount;

	int *drawn_numbers=new int[objectsAmount];

	int nDrawn = 0;
	
	srand(time(NULL));
	do
	{
		int number = draw(height, width);
		if (wasAlreadyDrawn(number, drawn_numbers, nDrawn) == false)
		{
			drawn_numbers[nDrawn] = number;
			nDrawn++;
		} 
	} while (nDrawn < objectsAmount);	

	vector<Grass> array_grass;
	array_grass.reserve(grassAmount);
	
	int i;
	for (i = 0; i < grassAmount; i++)
	{
		Grass grass((drawn_numbers[i] % width), (drawn_numbers[i] / width));
		array_grass.emplace_back(grass);
	}

	for (int j = 0; j < grassAmount; j++)
	{
		array_grass[j].SaveInBoard(myBoard);
	}

	int choice=chooseYourFighter();
	char id;
	if (choice == 3) id = 'L';
	else if (choice == 2) id = 'O';
	else id = 'K';

	vector<Animal> array_animal;
	array_animal.reserve(objectsAmount);
	for (i; i < objectsAmount; i++)
	{
		Animal animal((drawn_numbers[i] % width), (drawn_numbers[i] / width), id, choice);
		array_animal.emplace_back(animal);
	} 
	for (int i = 0; i < animalAmount; i++)
	{
		array_animal[i].SaveInBoard(myBoard);
	}

	
	char a;
	char key='x';
	system("PAUSE");
	
	system("cls");
	while (key != 'q' && key!='Q')
	{	
		
		showBoard(myBoard, width, height);
		cout << "Podaj ruch (awsd)" << endl;
		cin >> key;
		system("cls");
		int newAnimalAmount = 0;
		if (CorrectMove(key))
		{
			for (int i = 0; i < animalAmount; i++)
			{
					bool direction = Move(key, i, array_animal, width, height, myBoard);
					if (direction)
					{
						int id_collision_animal = array_animal[i].Collision(array_animal, animalAmount+newAnimalAmount, i);
						if (id_collision_animal == -1)
						{
							int id_eaten_grass = array_animal[i].EatGrass(array_grass, grassAmount);
							if (id_eaten_grass != -1)
							{
								grassAmount--;
								int previous_pos_x = What_previous_pos_x(key, i, array_animal);
								int previous_pos_y = What_previous_pos_y(key, i, array_animal);
								Animal newAnimal(previous_pos_x, previous_pos_y, array_animal[i].GetId(), array_animal[i].GetMoveValue());
								array_animal.emplace_back(newAnimal);
								newAnimalAmount++;
							}
						}
						else //zwierzeta sie zderzyly
						{
								//wypisz zabite zwierze
								cout << "Doszlo do kolizji" << endl;
								array_animal[i]++;
								cout << "Zwierzeta zderzyly sie w polu o wspolrzednych: " << array_animal[i] << endl;
								array_animal.erase(array_animal.begin() + i, array_animal.begin() + i + 1); //usuwa zwierze ktore wykonuje ruch
								if (i > id_collision_animal) {
									i--;
									array_animal.erase(array_animal.begin() + id_collision_animal, (array_animal.begin() + (id_collision_animal + 1)));
								}
								else
									array_animal.erase(array_animal.begin() + id_collision_animal - 1, (array_animal.begin() + (id_collision_animal)));
								i--;
							
							animalAmount -= 2;;
							
						}
					}
					
					
			}
			
			animalAmount += newAnimalAmount;
			clearBoard(height, width, myBoard);
			if (grassAmount == 0)
			{
				for (int i = 0; i < animalAmount; i++)
					array_animal[i].SaveInBoard(myBoard);
				for (int i = 0; i < grassAmount; i++)
					array_grass[i].SaveInBoard(myBoard);

				showBoard(myBoard, width, height);
				key=win(animalAmount);
			}
			else if (animalAmount == 0)
			{
				key=loose();
			}
			else {
				for (int i = 0; i < animalAmount; i++)
					array_animal[i].SaveInBoard(myBoard);
				for (int i = 0; i < grassAmount; i++)
					array_grass[i].SaveInBoard(myBoard);			
			}
		}
		else if(key == 'q' || key=='Q')
		{

			cout << "Dzieki za gre" << endl;
			cout << "Zostalo ci " << animalAmount << " zwierzat i " <<grassAmount<<" niezjedzonej trawy."<< endl;
			cout << "Wykonala Justyna Brzozowska" << endl;
		}
		else
		{
			cout << "Zly ruch" << endl;
		}
	}
	//sprzatanie
	array_animal.clear();
	array_grass.clear();
	delete[]drawn_numbers;
		for (int i = 0; i < height; i++)
			delete[] myBoard[i];
		delete[]myBoard;
  
}
