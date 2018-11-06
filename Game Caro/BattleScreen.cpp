#include "BattleScreen.h"
#include "Graphics.h"
#include "Windows.h"
#include <stdio.h>
#include <iostream>
using namespace std;

BattleScreen::BattleScreen(int ChessBoardSize) {
	Graphics::getConsoleScreenSize();
	ScreenColumns = Graphics::ConsoleScreenColumns;
	ScreenRows = Graphics::ConsoleScreenRows;

	int x = (ScreenColumns - 41) / 2 - (4 * ChessBoardSize + 1) / 2 - 8;
	board = new ChessBoard(ChessBoardSize, x, 6);
	
}

void BattleScreen::drawGUI() {
	Graphics::SetColor(14);

	for (int i = 0; i < ScreenColumns; i++) {
		if (i == 0)
			printf_s("%c", 201);
		else if (i == ScreenColumns - 1)
			printf_s("%c", 187);
		else if (i == ScreenColumns - 40)
			printf_s("%c", 203);
		else
			printf_s("%c", 205);
		Sleep(4);
	}

	for (int i = ScreenColumns - 2; i >= 0; i--) {
		Graphics::gotoXY(i, ScreenRows - 1);
		if (i == 0)
			printf_s("%c", 200);
		else if (i == ScreenColumns - 40)
			printf_s("%c", 202);
		else
			printf_s("%c", 205);
		Sleep(4);
	}

	for (int i = 1; i < ScreenRows; i++) {
		Graphics::gotoXY(ScreenColumns - 1, i);
		if (i == ScreenRows - 1)
			printf_s("%c", 188);
		else if (i == 10)
			printf_s("%c", 185);
		else
			printf_s("%c", 186);
		Sleep(4);
	}

	for (int i = ScreenRows - 2; i > 0; i--) {
		Graphics::gotoXY(0, i);
		printf_s("%c", 186);
		Sleep(4);
	}

	for (int i = 1; i < ScreenRows - 1; i++) {
		Graphics::gotoXY(ScreenColumns - 40, i);
		if (i == 10)
			printf_s("%c", 204);
		else
			printf_s("%c", 186);
		Sleep(5);
	}

	for (int i = ScreenColumns - 39; i < ScreenColumns - 1; i++) {
		Graphics::gotoXY(i, 10);
		printf_s("%c", 205);
		Sleep(5);
	}

	Graphics::gotoXY(ScreenColumns - 23, 12);
	Graphics::SetColor(13);
	cout << "Ti so";
	Graphics::SetColor(15);
	Graphics::gotoXY(ScreenColumns - 27, 14);
	cout << "P1         P2"; // 9 blank space
	Graphics::gotoXY(ScreenColumns - 27, 15);
	cout << "0     :    0";

	Graphics::gotoXY(ScreenColumns - 25, 19);
	Graphics::SetColor(13);
	cout << "So nuoc di";
	Graphics::SetColor(15);
	Graphics::gotoXY(ScreenColumns - 28, 21);
	cout << "X - 0  :  O - 0";

	board->drawBoard();
}

void BattleScreen::startGame() {
	while (true) { //Blinking effect
		if (GetAsyncKeyState(VK_SPACE)) {
			Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
			for (int i = 1; i <= 30; i++)
				cout << " ";
			break;
		}
		else {
			Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
			Graphics::SetColor(10);
			cout << "NHAN SPACE DE BAT DAU TRAN DAU";
			Sleep(200);

			Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
			Graphics::SetColor(12);
			cout << "NHAN SPACE DE BAT DAU TRAN DAU";
			Sleep(200);

			Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
			Graphics::SetColor(13);
			cout << "NHAN SPACE DE BAT DAU TRAN DAU";
			Sleep(200);

			Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
			Graphics::SetColor(14);
			cout << "NHAN SPACE DE BAT DAU TRAN DAU";
			Sleep(200);
		}
	}
	
	/*
		--> This feature is being developped
		thread thrClock = new thread(startClock());
	*/

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 16, 3);
	Graphics::SetColor(13);
	cout << "Den luot quan co";
	Graphics::gotoXY((ScreenColumns - 41) / 2 - 12, 4);
	Graphics::SetColor(15);
	cout << "--";
	Graphics::SetColor(12);
	cout << " X ";
	Graphics::SetColor(15);
	cout << "--";

	Stop = false;
	Result = -2; 

	while (!Stop) //Loop until finishing the match
	{
		
	}
}