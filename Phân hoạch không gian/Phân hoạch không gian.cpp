// Phân hoạch không gian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fstream"
#define GRID_CELL_HEIGHT 460
#define GRID_CELL_WIDTH  520

using namespace std;
void Write(int type, int trend, float x, float y, float w, float h, int id_item, ofstream& outFile);
int main()
{
	
	ifstream inFile("obj2.txt");
	int grid_x, grid_y, type, trend, id_item, nx, ny;
	float x, y, w, h;

	if (inFile)
	{
		ofstream outFile("obj_2.txt");

		while (inFile >> type >> trend >> x >> y >> w >> h >> id_item)
		{
			Write(type, trend, x, y, w, h, id_item, outFile);
		}
		outFile.close();

		inFile.close();
	}

}
void Write(int type, int trend, float x, float y, float w, float h, int id_item, ofstream &outFile)
{
	int top = (int)(y) / GRID_CELL_HEIGHT;
	int bottom = (int)(y + h) / GRID_CELL_HEIGHT;
	int left = (int)(x) / GRID_CELL_WIDTH;
	int right = (int)(x + w) / GRID_CELL_WIDTH;
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			outFile << i << " " << j << " " << type << " " << trend << " " << x << " " << y << " " << w << " " << h << " " << id_item << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
