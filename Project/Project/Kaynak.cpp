#include <iostream>
#include <Windows.h>

using namespace std;


struct shipCell
{
	int x;
	int y;

	char character;
};

struct enemy
{
	int x;
	int y;

	char character;
};

const int width = 100;
const int height = 25;

char scene[width][height];
char keys[256];

shipCell ship[7];

void createEnemy()//
{

}

void createShip() 
{
	int xilkDeger = 2;
	int yilkDeger = 12;
	for (int i = 0; i < 7; i++)
	{
		if (i < 6)
		{
			ship[i].x = xilkDeger;
			ship[i].y = yilkDeger;
			ship[i].character = char(219);
			yilkDeger++;
			if (i == 2)
			{
				xilkDeger++;
				yilkDeger = 12;
			}
		}
		else
		{
			ship[i].x = 4;
			ship[i].y = 13;
			ship[i].character = char(205);
		}
	}
}
void drawShip()
{
	for (int i = 0; i < 7; i++)
	{
		int x = ship[i].x;
		int y = ship[i].y;

		scene[x][y] = ship[i].character;
	}
}
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
void readKey(char keys[])//function for detecting and saving pressed key(klavyede basilan tusun bilgilerini diziye atayan fonksiyon)
{
	for (int i = 0; i < 256; i++)
		keys[i] = (char)(GetAsyncKeyState(i) >> 8);
}

void controls() 
{
	readKey(keys);
	if (keys['W'] != 0 && ship[0].y!=1)
	{
		for (int i = 0; i < 7; i++)
		{
			ship[i].y--;
		}
	}
	else if (keys['S'] != 0 && ship[2].y != 23)
	{
		for (int i = 0; i < 7; i++)
		{
			ship[i].y++;
		}
	}
	else if (keys[' '] != 0)//
	{
		
	}
}



int main()
{
	hideCurssor();
	createBorder();
	scene[5][5] = char(250);
	drawScene();
	createShip();

	while (true)
	{
		clearScene();
		createBorder();
		controls();

		drawShip();
		coordinatesXY(0, 0);
		
		drawScene();
		Sleep(50);
	}
	system("pause");
	return 0;
}