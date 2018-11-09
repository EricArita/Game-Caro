#include "BattleScreen.h"
#include "Graphics.h"
#include "Windows.h"
#include <conio.h>
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

void BattleScreen::getControlFromPlayer() {
	while (true)
	{
		if (GetAsyncKeyState(VK_UP)){
			if (CurrCursorY - 2 > board->getUpperLeftCornerY()) {
				CurrCursorY -= 2;
				Graphics::gotoXY(CurrCursorX, CurrCursorY);
			}
			Sleep(350);
			continue;
		}

		if (GetAsyncKeyState(VK_DOWN)){
			if (CurrCursorY + 2 < board->getUpperLeftCornerY() + board->getSize() * 2) {
				CurrCursorY += 2;
				Graphics::gotoXY(CurrCursorX, CurrCursorY);
			}
			Sleep(350);
			continue;
		}

		if (GetAsyncKeyState(VK_LEFT)) {
			if (CurrCursorX - 4 > board->getUpperLeftCornerX()) {
				CurrCursorX -= 4;
				Graphics::gotoXY(CurrCursorX, CurrCursorY);
			}
			Sleep(350);
			continue;
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			if (CurrCursorX + 4 < board->getUpperLeftCornerX() + board->getSize() * 4) {
				CurrCursorX += 4;
				Graphics::gotoXY(CurrCursorX, CurrCursorY);
			}
			Sleep(350);
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			if (board->setStateOfBoard(CurrCursorX, CurrCursorY, Turn)) return;
			Sleep(500);
		}
	}
}

void BattleScreen::checkCurrentState(){
	if (board->getAmountChessMan() == 20 * 20) {
		this->Result = 'Draw';
		return;
	}

	int n = board->getSize();
	int currRow = -1, currColumn = -1;
	int i, j;
	int AmountX, AmountO;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int x = board->getXAtCell(i, j) + 2;
			int y = board->getYAtCell(i, j) + 1;
			if (x == this->CurrCursorX && y == this->CurrCursorY) {
				currRow = i;
				currColumn = j;
				break;
			}
		}

		if (currRow != -1)
			break;
	}

	/*	
		check horizontal line on chessboard
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (j + 4 > n - 1) j--;

	board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i, j + 1) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i, j + 2) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i, j + 3) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i, j + 4) == 'X' ? AmountX++ : AmountO++;

	while (j >= 0 && j >= currColumn - 4) {
		if (j != currColumn) {
			board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
			board->getChessManAtCell(i, j + 5) == 'X' ? AmountX-- : AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			this->Stop = true;
			
			if (AmountX == 5)
				this->Result = 'Win';
			else
				this->Result = 'Lose';

			return;
		}

		j--;
	}

	/*
		check vertical line on chessboard
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1) i--;

	board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i - 1, j) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i - 2, j) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i - 3, j) == 'X' ? AmountX++ : AmountO++;
	board->getChessManAtCell(i - 4, j) == 'X' ? AmountX++ : AmountO++;

	while (i >= 0 && i >= currRow - 4) {
		if (i != currRow) {
			board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
			board->getChessManAtCell(i + 5, j) == 'X' ? AmountX-- : AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			this->Stop = true;

			if (AmountX == 5)
				this->Result = 'Win';
			else
				this->Result = 'Lose';

			return;
		}

		i--;
	}

	/*
		check diagonal lines is parallel to main diagonal line
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1 || j + 4 > n - 1) {
		i--;
		j--;
	}

	if (i >= 0 && j >= 0) {
		board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i + 1, j + 1) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i + 2, j + 2) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i + 3, j + 3) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i + 4, j + 4) == 'X' ? AmountX++ : AmountO++;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j >= currColumn - 4) {
			if ( i != currRow && j != currColumn) {
				board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
				board->getChessManAtCell(i + 5, j + 5) == 'X' ? AmountX-- : AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {
				this->Stop = true;

				if (AmountX == 5)
					this->Result = 'Win';
				else
					this->Result = 'Lose';

				return;
			}

			i--;
			j--;
		}
	}

	/*
		check diagonal lines is parallel to extra diagonal line
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1 || j - 4 < 0) {
		i--;
		j++;
	}

	if (i >= 0 && j >= 0) {
		board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i - 1, j + 1) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i - 2, j + 2) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i - 3, j + 3) == 'X' ? AmountX++ : AmountO++;
		board->getChessManAtCell(i - 4, j + 4) == 'X' ? AmountX++ : AmountO++;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j <= currColumn + 4) {
			if (i != currRow && j != currColumn) {
				board->getChessManAtCell(i, j) == 'X' ? AmountX++ : AmountO++;
				board->getChessManAtCell(i + 5, j - 5) == 'X' ? AmountX-- : AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {
				this->Stop = true;

				if (AmountX == 5)
					this->Result = 'Win';
				else
					this->Result = 'Lose';

				return;
			}

			i--;
			j++;
		}
	}
}

void BattleScreen::changeTurn() {
	Graphics::gotoXY((ScreenColumns - 41) / 2 - 9, 4);
	Graphics::SetColor(12);
	
	if (Turn == 'X') {
		cout << "O";
		Turn = 'O';
	}
	else {
		cout << "X";
		Turn = 'X';
	}
	Graphics::gotoXY(CurrCursorX, CurrCursorY);
}

void BattleScreen::startGame() {
	/*
		Ready for starting
	*/

	while (true) { //Blinking effect
		if (GetAsyncKeyState(VK_SPACE)) 
				break;
		else 
			Graphics::Blink((ScreenColumns - 41) / 2 - 24, 3, "NHAN PHIM SPACE DE BAT DAU");
	}
	
	/*
		Starts
	*/

	/*
		--> This feature is being developped
		thread thrClock = new thread(startClock());
	*/

	this->Stop = false;
	this->Result = 'N';
	this->Turn = 'X';

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
	Graphics::SetColor(13);
	cout << "        Den luot quan co      ";

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 12, 4);
	Graphics::SetColor(15);
	cout << "--";
	Graphics::SetColor(12);
	Turn == 'X' ? cout << " X " : cout << " O ";
	Graphics::SetColor(15);
	cout << "--";


	board->resetBoard();
	CurrCursorX = board->getXAtCell(10, 10) + 2;
	CurrCursorY = board->getYAtCell(10, 10) + 1;
	Graphics::gotoXY(CurrCursorX, CurrCursorY);

	while (!this->Stop) //Loop until finishing the match
	{
		this->getControlFromPlayer();
		//this->checkCurrentState();
		this->changeTurn();
	}
	
	return;
}

void BattleScreen::finishGame() {
	Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
	for(int i = 1; i <= 30; i++)
		printf_s(" ");

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 12, 4);
	for (int i = 1; i <= 7; i++)
		printf_s(" ");

	if (this->Result == 'Win')
		Graphics::Blink((ScreenColumns - 41) / 2 - 24, 3, "BAN THANG");
	else if (this->Result == 'Draw')
		Graphics::Blink((ScreenColumns - 41) / 2 - 24, 3, "HOA");
	else if (this->Result == 'Lose') 
		Graphics::Blink((ScreenColumns - 41) / 2 - 24, 3, "MAY THANG");
}