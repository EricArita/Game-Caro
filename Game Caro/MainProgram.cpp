// Game Caro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "windows.h"
#include "Graphics.h"
#include "MainScreen.h"
#include "ChessBoard.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
	
	Graphics::InitializeComponent();
	
	//MainScreen* scMain = new MainScreen();
	//scMain->PrintTitle();
	//scMain->MenuProcessing();

	/*ChessBoard* board = new ChessBoard(10, 60, 10);
	board->drawBoard();
	board->resetBoard();
	
	Graphics::gotoXY(70, 15);
	board->setStateOfBoard(70, 15, 1);*/

	return 0;
	
}

