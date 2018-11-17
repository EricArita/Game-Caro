#include "BattleScreen.h"
#include "Graphics.h"
#include "ArtificialIntelligence.h"
#include "Windows.h"
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <iostream>
#include <string>
using namespace std;

BattleScreen::BattleScreen(int ChessBoardSize) {
	Graphics::getConsoleScreenSize();
	ScreenColumns = Graphics::ConsoleScreenColumns;
	ScreenRows = Graphics::ConsoleScreenRows;

	int x = (ScreenColumns - 41) / 2 - (4 * ChessBoardSize + 1) / 2 - 6;
	board = new ChessBoard(ChessBoardSize, x, 6);	
	this->Loop = true;
	this->NumberOfWinsOfComputer = this->NumberOfWinsOfPlayer = 0;
}

void BattleScreen::drawGUI() {
	Graphics::SetColor(14);

	if (this->NumberOfWinsOfComputer + this->NumberOfWinsOfPlayer == 0) {
		/*
			Draw frame
		*/
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
			else if (i == 10 || i == 24)
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
			if (i == 10 || i == 24)
				printf_s("%c", 204);
			else
				printf_s("%c", 186);
			Sleep(5);
		}

		for (int i = ScreenColumns - 39; i < ScreenColumns - 1; i++) {
			Graphics::gotoXY(i, 10);
			printf_s("%c", 205);
			Sleep(5);

			Graphics::gotoXY(i, 24);
			printf_s("%c", 205);
			Sleep(5);
		}

		/*
			print score
		*/
		Graphics::gotoXY(ScreenColumns - 23, 12);
		Graphics::SetColor(13);
		cout << "Ti so";
		Graphics::SetColor(15);
		Graphics::gotoXY(ScreenColumns - 27, 14);
		cout << "P1         P2"; // 9 blank space
		Graphics::gotoXY(ScreenColumns - 27, 15);
		cout << "0     :    0";

		/*
			print list of utility keys
		*/

		Graphics::SetColor(2);
		Graphics::gotoXY(ScreenColumns - 37, 26);
		cout << "Press key 1 to restart the match";
		Graphics::gotoXY(ScreenColumns - 37, 28);
		cout << "Press key 2 to Save Game";
		Graphics::gotoXY(ScreenColumns - 37, 30);
		cout << "Press Backspace to return Main Menu";
		Graphics::gotoXY(ScreenColumns - 37, 32);
		cout << "Press ESC to exit game";
	}

	int x = board->getUpperLeftCornerX() + board->getSize() * 4;
	int y = board->getUpperLeftCornerY() + 2 * 5;

	Graphics::gotoXY(x + 6, y);
	Graphics::SetColor(9);
	for(int i = 1; i <= 23; i++)
		printf_s(" ");

	Graphics::gotoXY(x + 9, y + 2);
	Graphics::SetColor(10);
	printf_s("        "); //8 blank space
	Graphics::gotoXY(x + 9, y + 4);
	Graphics::SetColor(8);
	printf_s("        "); //8 blank space 

	Graphics::gotoXY(ScreenColumns - 25, 19);
	Graphics::SetColor(13);
	cout << "So nuoc di";
	Graphics::SetColor(15);
	Graphics::gotoXY(ScreenColumns - 28, 21);
	cout << "X - 0  :  O - 0 ";
	
	board->drawBoard();
}

void BattleScreen::getControlFromPlayer() {
	while (true)
	{
			char key = _getch();

			if (key == 'w' || key == 'W') {
				if (CurrCursorY - 2 > board->getUpperLeftCornerY()) {
					CurrCursorY -= 2;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				continue;
			}

			if (key == 's' || key == 'S') {
				if (CurrCursorY + 2 < board->getUpperLeftCornerY() + board->getSize() * 2) {
					CurrCursorY += 2;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				continue;
			}

			if (key == 'a' || key == 'A') {
				if (CurrCursorX - 4 > board->getUpperLeftCornerX()) {
					CurrCursorX -= 4;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				continue;
			}

			if (key == 'd' || key == 'D') {
				if (CurrCursorX + 4 < board->getUpperLeftCornerX() + board->getSize() * 4) {
					CurrCursorX += 4;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				continue;
			}

			if (key == VK_RETURN) { //press Enter
				if (board->setStateOfBoard(CurrCursorX, CurrCursorY, Turn)) {
					if (Turn == 'X') {
						this->NumberOfChessManX++;
						Graphics::gotoXY(ScreenColumns - 24, 21);
						cout << this->NumberOfChessManX;
					}
					else {
						this->NumberOfChessManO++;
						Graphics::gotoXY(ScreenColumns - 14, 21);
						cout << this->NumberOfChessManO;
					}
									
					return;
				}
			}
	
	}
}

void BattleScreen::checkCurrentState(int currRow, int currColumn){
	if (board->getAmountChessMan() == 20 * 20) {
		this->Result = 'D';
		return;
	}

	int n = board->getSize();
	int i, j;
	int AmountX, AmountO;
	char c1, c2, c3, c4, c5;
	int t, k;
	
	if (currRow == -1) {
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
	}

	/*	
		check horizontal line on chessboard
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (j + 4 > n - 1) j--;

	c1 = board->getChessManAtCell(i, j);
	c2 = board->getChessManAtCell(i, j + 1);
	c3 = board->getChessManAtCell(i, j + 2);
	c4 = board->getChessManAtCell(i, j + 3);
	c5 = board->getChessManAtCell(i, j + 4);

	if (c1 == 'X')
		AmountX++;
	else if (c1 == 'O')
		AmountO++;

	if (c2 == 'X')
		AmountX++;
	else if (c2 == 'O')
		AmountO++;

	if (c3 == 'X')
		AmountX++;
	else if (c3 == 'O')
		AmountO++;

	if (c4 == 'X')
		AmountX++;
	else if (c4 == 'O')
		AmountO++;

	if (c5 == 'X')
		AmountX++;
	else if (c5 == 'O')
		AmountO++;

	t = j;

	while (j >= 0 && j >= currColumn - 4) {
		if (j != t) {
			char p = board->getChessManAtCell(i, j);
			char q = board->getChessManAtCell(i, j + 5);

			if (p == 'X')
				AmountX++;
			else if (p == 'O')
				AmountO++;

			if (q == 'X')
				AmountX--;
			else if (q == 'O')
				AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			this->Stop = true;
			
			if (AmountX == 5)
				this->Result = 'W';
			else
				this->Result = 'L';

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

	c1 = board->getChessManAtCell(i, j);
	c2 = board->getChessManAtCell(i + 1, j);
	c3 = board->getChessManAtCell(i + 2, j);
	c4 = board->getChessManAtCell(i + 3, j);
	c5 = board->getChessManAtCell(i + 4, j);

	if (c1 == 'X')
		AmountX++;
	else if (c1 == 'O')
		AmountO++;

	if (c2 == 'X')
		AmountX++;
	else if (c2 == 'O')
		AmountO++;

	if (c3 == 'X')
		AmountX++;
	else if (c3 == 'O')
		AmountO++;

	if (c4 == 'X')
		AmountX++;
	else if (c4 == 'O')
		AmountO++;

	if (c5 == 'X')
		AmountX++;
	else if (c5 == 'O')
		AmountO++;

	t = i;

	while (i >= 0 && i >= currRow - 4) {
		if (i != t) {
			char p = board->getChessManAtCell(i, j);
			char q = board->getChessManAtCell(i + 5, j);

			if (p == 'X')
				AmountX++;
			else if (p == 'O')
				AmountO++;

			if (q == 'X')
				AmountX--;
			else if (q == 'O')
				AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			this->Stop = true;

			if (AmountX == 5)
				this->Result = 'W';
			else
				this->Result = 'L';

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
		c1 = board->getChessManAtCell(i, j);
		c2 = board->getChessManAtCell(i + 1, j + 1);
		c3 = board->getChessManAtCell(i + 2, j + 2);
		c4 = board->getChessManAtCell(i + 3, j + 3);
		c5 = board->getChessManAtCell(i + 4, j + 4);

		if (c1 == 'X')
			AmountX++;
		else if (c1 == 'O')
			AmountO++;

		if (c2 == 'X')
			AmountX++;
		else if (c2 == 'O')
			AmountO++;

		if (c3 == 'X')
			AmountX++;
		else if (c3 == 'O')
			AmountO++;

		if (c4 == 'X')
			AmountX++;
		else if (c4 == 'O')
			AmountO++;

		if (c5 == 'X')
			AmountX++;
		else if (c5 == 'O')
			AmountO++;

		t = i;
		k = j;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j >= currColumn - 4) {
			if ( i != t && j != k) {
				char p = board->getChessManAtCell(i, j);
				char q = board->getChessManAtCell(i + 5, j + 5);

				if (p == 'X')
					AmountX++;
				else if (p == 'O')
					AmountO++;

				if (q == 'X')
					AmountX--;
				else if (q == 'O')
					AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {
				this->Stop = true;

				if (AmountX == 5)
					this->Result = 'W';
				else
					this->Result = 'L';

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
		c1 = board->getChessManAtCell(i, j);
		c2 = board->getChessManAtCell(i + 1, j - 1);
		c3 = board->getChessManAtCell(i + 2, j - 2);
		c4 = board->getChessManAtCell(i + 3, j - 3);
		c5 = board->getChessManAtCell(i + 4, j - 4);

		if (c1 == 'X')
			AmountX++;
		else if (c1 == 'O')
			AmountO++;

		if (c2 == 'X')
			AmountX++;
		else if (c2 == 'O')
			AmountO++;

		if (c3 == 'X')
			AmountX++;
		else if (c3 == 'O')
			AmountO++;

		if (c4 == 'X')
			AmountX++;
		else if (c4 == 'O')
			AmountO++;

		if (c5 == 'X')
			AmountX++;
		else if (c5 == 'O')
			AmountO++;

		t = i;
		k = j;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j <= currColumn + 4) {
			if (i != t && j != k) {
				char p = board->getChessManAtCell(i, j);
				char q = board->getChessManAtCell(i + 5, j - 5);

				if (p == 'X')
					AmountX++;
				else if (p == 'O')
					AmountO++;

				if (q == 'X')
					AmountX--;
				else if (q == 'O')
					AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {
				this->Stop = true;

				if (AmountX == 5)
					this->Result = 'W';
				else
					this->Result = 'L';

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
		Graphics::SetColor(12);
		cout << "O";
		Turn = 'O';
	}
	else {
		Graphics::SetColor(10);
		cout << "X";
		Turn = 'X';
	}
	Graphics::gotoXY(CurrCursorX, CurrCursorY);
}

void BattleScreen::AskPlayer() {
	int x = board->getUpperLeftCornerX() + board->getSize() * 4 ;
	int y = board->getUpperLeftCornerY() + 2 * 5;

	string MenuAsk[2];
	MenuAsk[0] = "---> YES";
	MenuAsk[1] = "---> NO";

	Graphics::gotoXY(x + 6, y);
	Graphics::SetColor(9);
	printf_s("BAN CO MUON CHOI TIEP ?");
	
	Graphics::gotoXY(x + 9, y + 2);
	Graphics::SetColor(10);
	cout << MenuAsk[0];
	Graphics::gotoXY(x + 9, y + 4);
	Graphics::SetColor(8);
	cout << MenuAsk[1];

	int currMenu = 0;
	while (true)
	{
		_getch();
		if (_kbhit()) {
			if (GetAsyncKeyState(VK_UP)) {
				if (currMenu == 1)
					currMenu = 0;

				for (int i = 0; i < 2; i++) {
					Graphics::gotoXY(x + 9, y + 2 + 2 * i);

					if (i == currMenu)
						Graphics::SetColor(10);
					else
						Graphics::SetColor(8);

					cout << MenuAsk[i];
				}

				Sleep(250);
				continue;
			}

			if (GetAsyncKeyState(VK_DOWN)) {
				if (currMenu == 0)
					currMenu = 1;

				for (int i = 0; i < 2; i++) {
					Graphics::gotoXY(x + 9, y + 2 + 2 * i);

					if (i == currMenu)
						Graphics::SetColor(10);
					else
						Graphics::SetColor(8);

					cout << MenuAsk[i];
				}

				Sleep(250);
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) {
				if (currMenu == 0)
					Loop = true;
				else
					Loop = false;

				this->FinishThreadAskPlayer = true;
				return;
			}
		}
	}
}

void BattleScreen::handleUtilityKey() {
	while (true) {
		if (_kbhit()) {
			char key = _getch();

			if (key = VK_ESCAPE) {
				
			}
		}
	}
}

void BattleScreen::startBattle() {
	/*
		Ready for starting
	*/

	board->resetBoard();

	while (true) { //Blinking effect
         if (GetAsyncKeyState(VK_SPACE)) 
				break;
		else 
 			Graphics::Blink((ScreenColumns - 41) / 2 - 25, 3, "     NHAN PHIM SPACE DE BAT DAU            ");
	}
	
	/*
		Starts
	*/

	this->Stop = false;
	this->Result = 'N';
	this->Turn = 'X';
	this->NumberOfChessManX = this->NumberOfChessManO = 0;

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

	Graphics::VisibleCursor(true);
	CurrCursorX = board->getXAtCell(9, 9) + 2;
	CurrCursorY = board->getYAtCell(9, 9) + 1;
	Graphics::gotoXY(CurrCursorX, CurrCursorY);

	/*
		--> This feature is being developped
		thread thrClock = new thread(startClock());
	*/

	AI* computer = new AI();

	while (!this->Stop) //Loop until finishing the match
	{
		if (Turn == 'X') {
			this->getControlFromPlayer();
			this->checkCurrentState(-1, -1);
		}
		else {
			computer->findBestMove(board->getpBoard(), board->getSize());

			int BestRow = computer->getBestRow();
			int BestCol = computer->getBestCol();

			computer->Go(board->getpBoard(), this->NumberOfChessManO);
			this->CurrCursorX = board->getXAtCell(BestRow, BestCol) + 2;
			this->CurrCursorY = board->getYAtCell(BestRow, BestCol) + 1;

			board->setAmountChessMan(board->getAmountChessMan() + 1);
			
			this->checkCurrentState(BestRow, BestCol);
		}
	
		this->changeTurn();
	}
	
	return;
}

void BattleScreen::finishBattle() {
	/*
		Update score
	*/
	
	if (this->Result == 'W') {
		Graphics::gotoXY(ScreenColumns - 27, 15);
		this->NumberOfWinsOfPlayer++;
		Graphics::SetColor(10);
		cout << this->NumberOfWinsOfPlayer;
	}
	else {
		if (this->Result == 'L') {
			Graphics::gotoXY(ScreenColumns - 16, 15);
			this->NumberOfWinsOfComputer++;
			Graphics::SetColor(12);
			cout << this->NumberOfWinsOfComputer;
		}
		else if (this->Result == 'D') {
			Graphics::gotoXY(ScreenColumns - 27, 15);
			this->NumberOfWinsOfPlayer++;
			Graphics::SetColor(10);
			cout << this->NumberOfWinsOfPlayer;

			Graphics::gotoXY(ScreenColumns - 16, 15);
			this->NumberOfWinsOfComputer++;
			Graphics::SetColor(12);
			cout << this->NumberOfWinsOfComputer;
		}
	}


	/*
		Print result and ask player
	*/
	Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
	for (int i = 1; i <= 30; i++)
		printf_s(" ");

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 12, 4);
	for (int i = 1; i <= 7; i++)
		printf_s(" ");

	Graphics::VisibleCursor(false);

	this->FinishThreadAskPlayer = false;

	thread askPlayer(&BattleScreen::AskPlayer, this);
	askPlayer.detach();
	askPlayer.~thread();
	
	Sleep(10); //The speed of main thread is faster than askPlayer thread so reducing speed
			  //of main thread a bit before continuing for not causing collision

	while (!this->FinishThreadAskPlayer) {
		if (this->Result == 'W') {
			Graphics::Blink((ScreenColumns - 41) / 2 - 21, 3, "YOU WIN!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 - 11, 3, "YOU WIN!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 - 1, 3, "YOU WIN!");
			Sleep(20);
		}
		else if (this->Result == 'D'){
			Graphics::Blink((ScreenColumns - 41) / 2 - 23, 3, "DRAW!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 - 14, 3, "DRAW!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 - 5, 3, "DRAW!");
			Sleep(20);
		}	
		else if (this->Result == 'L') {
			Graphics::Blink((ScreenColumns - 41) / 2 - 25, 3, "COMPUTER WIN!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 - 10, 3, "COMPUTER WIN!");
			Sleep(20);
			Graphics::Blink((ScreenColumns - 41) / 2 + 5, 3, "COMPUTER WIN!");
			Sleep(20);
		}
	}

}
