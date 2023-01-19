#pragma once
class Grass
{
private:
	char id = ',';
	int x;
	int y;
public:
	Grass(int x, int y);
	Grass();
	~Grass();
	void SaveInBoard(char** myBoard);
	void RemoveFromBoard(char** myBoard);
	int GetX();
	int GetY();
};

