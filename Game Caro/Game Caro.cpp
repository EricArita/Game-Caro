// Game Caro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "windows.h"
#include "Graphics.h"
#include "MainScreen.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
	//for (int i = 0; i < 255; i++)
		//printf_s("%d  %c \n\n", i, i);
	
	//draw
	//int m = 6;
	//int n = 6;
	//int x = 10;
	//int y = 4;

	/*gotoXY(x, y);

	printf_s("%c", 218);
	for (int i = 0; i < n - 1; i++) 
		printf_s("%c%c%c%c", 196, 196, 196, 194);
	printf_s("%c%c%c%c\n", 196, 196, 196, 191);

	for (int i = 0; i < m; i++) {
		gotoXY(x, y + 2*i + 1);

		for (int j = 0; j <= n; j++)
			printf_s("%c   ", 179);
		
		if (i != m - 1) {
			gotoXY(x, y + 2*i + 2);
			printf_s("%c", 195);

			for (int j = 0; j < n - 1; j++)
				printf_s("%c%c%c%c", 196, 196, 196, 197);

			printf_s("%c%c%c%c", 196, 196, 196, 180);
		}
	}

	gotoXY(x, y + 2 * m);
	printf_s("%c", 192);
	for(int i = 0; i < n - 1; i++)
		printf_s("%c%c%c%c", 196, 196, 196, 193);
	printf_s("%c%c%c%c", 196, 196, 196, 217);

	gotoXY(12, 5);
	cout << "X";*/

	
	Graphics::InitializeComponent();
	//Graphics::SetColor(7);
	MainScreen* scMain = new MainScreen();
	scMain->PrintTitle();
	
	_getch();
	
	return 0;
	
}

