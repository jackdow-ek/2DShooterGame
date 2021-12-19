#include <iostream>
#include <Windows.h>

using namespace std;


const int width = 100;
const int height = 25;


char scene[width][height];
char keys[256];

void coordinatesXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCurssor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void drawScene()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << scene[x][y];
		}
		cout << endl;
	}
}

void clearScene()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if(scene[x][y]!=char(178))
				scene[x][y]=' ';
		}
	}
}


void createBorder()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			scene[x][y] = ' ';
			if (x == 0 || x == 1 || x == width - 1 || x == width - 2 || y == 0 || y == height - 1)
				scene[x][y] = char(178);
		}
	}
}

//function for detecting and saveing pressed key(klavyede basilan tusun bilgilerini diziye atayan fonksiyon)
void readKey(char keys[])
{
	for (int i = 0; i < 256; i++)
		keys[i] = (char)(GetAsyncKeyState(i) >> 8);
}


void controls() 
{
	readKey(keys);
}

int main()
{
	hideCurssor();
	createBorder();
	scene[5][5] = char(250);
	drawScene();
	while (true)
	{
		clearScene();
		createBorder();
		controls();


		coordinatesXY(0, 0);
		
		//scene[i][j] = char(250);
		drawScene();
		Sleep(50);
	}
	system("pause");
	return 0;
}