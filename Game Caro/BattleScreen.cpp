#define _CRT_SECURE_NO_WARNINGS
#include "BattleScreen.h"
#include "Graphics.h"
#include "ArtificialIntelligence.h"
#include "Windows.h"
#include "CellofBoard.h"
#include "Time.h"
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

BattleScreen::BattleScreen(int ChessBoardSize, string ModePlay, char PriorityChessMan, int ColorX, int ColorO) {
	Graphics::getConsoleScreenSize();
	ScreenColumns = Graphics::ConsoleScreenColumns;
	ScreenRows = Graphics::ConsoleScreenRows;

	int x = (ScreenColumns - 41) / 2 - (4 * ChessBoardSize + 1) / 2 - 6;
	board = new ChessBoard(ChessBoardSize, x, 6);	
	this->ModePlay = ModePlay;
	this->PriorityChessMan = PriorityChessMan;
	this->ColorX = ColorX;
	this->ColorO = ColorO;
	this->Loop = true;
	this->Stop = false;
}

void BattleScreen::drawGUI(string StartMode) {
	Graphics::SetColor(14);

	if ((StartMode == "New game" && this->NumberOfWinsOfPlayer + this->NumberOfWinsOfComputer == 0) || (StartMode == "Load game")) {
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
		Graphics::SetColor(this->ColorX);
		cout << this->NumberOfWinsOfPlayer;
		Graphics::SetColor(15);
		cout << "    :     ";
		Graphics::SetColor(this->ColorO);
		cout << this->NumberOfWinsOfComputer;

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

	if (StartMode == "New game")
		this->NumberOfChessManX = this->NumberOfChessManO = 0;

	Graphics::gotoXY(ScreenColumns - 25, 19);
	Graphics::SetColor(13);
	cout << "So nuoc di";

	Graphics::SetColor(15);
	Graphics::gotoXY(ScreenColumns - 28, 21);
	cout << "X - ";

	Graphics::SetColor(this->ColorX);
	cout << this->NumberOfChessManX;

	Graphics::SetColor(15);
	this->NumberOfChessManX > 9 ? cout << " :  O - " : cout << "  :  O - ";

	Graphics::SetColor(this->ColorO);
	cout << this->NumberOfChessManO << "  ";
	
	board->drawBoard();
}

void BattleScreen::getControlFromPlayer() {
	while (true)
	{			
			PrintTime();

			Graphics::VisibleCursor(true);
			Graphics::gotoXY(CurrCursorX, CurrCursorY);
			Sleep(100);

			if (GetAsyncKeyState(0x57)) { // press W 
				if (CurrCursorY - 2 > board->getUpperLeftCornerY()) {
					CurrCursorY -= 2;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				Sleep(100);
				continue;
			}

			if (GetAsyncKeyState(0x53)) { // press S
				if (CurrCursorY + 2 < board->getUpperLeftCornerY() + board->getSize() * 2) {
					CurrCursorY += 2;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				Sleep(100);
				continue;
			}

			if (GetAsyncKeyState(0x41)) { // press A
				if (CurrCursorX - 4 > board->getUpperLeftCornerX()) {
					CurrCursorX -= 4;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				Sleep(100);
				continue;
			}

			if (GetAsyncKeyState(0x44)) { // press D
				if (CurrCursorX + 4 < board->getUpperLeftCornerX() + board->getSize() * 4) {
					CurrCursorX += 4;
					Graphics::gotoXY(CurrCursorX, CurrCursorY);
				}
				Sleep(100);
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) { //press Enter
				if (board->setStateOfBoard(CurrCursorX, CurrCursorY, Turn, this->ColorX, this->ColorO)) {
					Graphics::VisibleCursor(false);

					if (Turn == 'X') {
						this->NumberOfChessManX++;
						Graphics::gotoXY(ScreenColumns - 24, 21);
						Graphics::SetColor(this->ColorX);
						cout << this->NumberOfChessManX;
					}
					else {
						this->NumberOfChessManO++;
						Graphics::gotoXY(ScreenColumns - 14, 21);
						Graphics::SetColor(this->ColorO);
						cout << this->NumberOfChessManO;
					}

					Sleep(200);
					return;
				}
			}

			/*
				Utility Key
			*/
			if (GetAsyncKeyState(VK_ESCAPE)) {
				system("cls");
				this->UtilityKey = "esc";
				this->Loop = false;
				return;
			}

			if (GetAsyncKeyState(VK_BACK)) {
				this->UtilityKey = "backspace";
				this->Loop = false;
				return;
			}

			if (GetAsyncKeyState(0x31)) { // key 1
				this->UtilityKey = "Restart";
				this->NumberOfChessManX = this->NumberOfChessManO = 0;
				return;
			}

			if (GetAsyncKeyState(0x32)) { // key 2
				SaveGame();
				Sleep(100);
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
	Graphics::gotoXY((ScreenColumns - 41) / 2 - 8, 4);
	Graphics::SetColor(12);
	
	if (Turn == 'X') {
		Graphics::SetColor(this->ColorO);
		cout << "O";
		Turn = 'O';
	}
	else {
		Graphics::SetColor(this->ColorX);
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

			/*
				Utility Key
			*/
			if (GetAsyncKeyState(VK_ESCAPE)) {
				system("cls");
				this->UtilityKey = "esc";
				this->Loop = false;
				return;
			}

			if (GetAsyncKeyState(VK_BACK)) {
				this->UtilityKey = "backspace";
				this->Loop = false;
				return;
			}
		}
	}
}

void BattleScreen::SaveGame() {
	ofstream fwriter1, fwriter2;
	fwriter1.open("SaveGameState.txt", ios::app);
	fwriter2.open("SaveDateOfGame.txt", ios::app);

	time_t t = time(0);
	tm* currTime = localtime(&t);
	
	fwriter2 << currTime->tm_mday << "/" << currTime->tm_mon + 1 << "/" << currTime->tm_year + 1900 << " ";
	if (currTime->tm_hour <= 9)
		fwriter2 << "0" << currTime->tm_hour << ":";
	else
		fwriter2 << currTime->tm_hour << ":";

	if (currTime->tm_min <= 9)
		fwriter2 << "0" << currTime->tm_min << "\n";
	else
		fwriter2 << currTime->tm_min << "\n";

	fwriter1 << this->Turn << " " << this->NumberOfChessManX << " " << this->NumberOfChessManO << " " << this->NumberOfWinsOfPlayer << " " << this->NumberOfWinsOfComputer << " " << this->ModePlay << endl;
	
	CellofBoard** pBoard = this->board->getpBoard();
	int n = this->board->getSize();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			fwriter1 << pBoard[i][j].getChessMan();

		fwriter1 << endl;
	}

	fwriter1.close();
	fwriter2.close();
}

void BattleScreen::LoadGame(string &ModePlay) {
	ifstream freader1, freader2;
	freader1.open("SaveDateOfGame.txt", ios::in);
	freader2.open("SaveGameState.txt", ios::in);

	vector<string> date;
	string s;

	while (getline(freader1, s))
	{
		date.push_back(s);
	}
	freader1.close();

	system("cls");
	
	for (int i = 0; i < date.size(); i++) {
		if (i == 0)
			Graphics::SetColor(12);
		else
			Graphics::SetColor(14);

		Graphics::gotoXY(ScreenColumns / 2, ScreenRows / 2 + i - 5);

		cout << ">> " << date[i];
	}

	int CurrPositionData = 0;
	int SizeOfData = date.size();

	while (true)
	{
		_getch();

		if (_kbhit()) {
			if (GetAsyncKeyState(VK_DOWN)) {
				CurrPositionData++;
				if (CurrPositionData == SizeOfData)
					CurrPositionData = 0;

				for (int i = 0; i < date.size(); i++) {
					Graphics::gotoXY(ScreenColumns / 2, ScreenRows / 2 + i - 5);

					if (i == CurrPositionData)
						Graphics::SetColor(12);
					else
						Graphics::SetColor(14);

					cout << ">> " << date[i];
				}
				Sleep(200);
				continue;
			}

			if (GetAsyncKeyState(VK_UP)) {
				CurrPositionData--;
				if (CurrPositionData == -1)
					CurrPositionData = SizeOfData - 1;

				for (int i = 0; i < date.size(); i++) {
					Graphics::gotoXY(ScreenColumns / 2, ScreenRows / 2 + i - 5);

					if (i == CurrPositionData)
						Graphics::SetColor(12);
					else
						Graphics::SetColor(14);

					cout << ">> " << date[i];
				}
				Sleep(200);
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) {
				freader2.seekg(430 * CurrPositionData, ios::beg);

				freader2 >> this->Turn >> this->NumberOfChessManX >> this->NumberOfChessManO >> this->NumberOfWinsOfPlayer >> this->NumberOfWinsOfComputer;
				freader2.ignore();
				getline(freader2, ModePlay);
				this->ModePlay = ModePlay;

				CellofBoard** pBoard = board->getpBoard();
				int n = board->getSize();

				string s;
				for (int i = 0; i < n; i++) {
					getline(freader2, s);

					for (int j = 0; j < n; j++)
						pBoard[i][j].setChessMan(s[j]);
				}

				freader2.close();
				return;
			}
		}
	}

}

void BattleScreen::PrintTime() {
	Time* t = new Time();
	t->PrintTime(ScreenColumns-25, 2);
	delete t;
}

void BattleScreen::startBattle(string StartMode) {
	/*
		Ready for starting
	*/

	if (StartMode == "New game") {
		board->resetBoard("New game", this->ColorX, this->ColorO);
		this->Turn = this->PriorityChessMan;
	}
	else if (StartMode == "Load game")
		board->resetBoard("Load game", this->ColorX, this->ColorO);

	Graphics::Blink((ScreenColumns - 41) / 2 - 12, 4, "                    ");
	while (true) { //Blinking effect
		 Graphics::VisibleCursor(false);
		 Graphics::Blink((ScreenColumns - 41) / 2 - 25, 3, "     NHAN PHIM SPACE DE BAT DAU            ");

		 PrintTime();

         if (GetAsyncKeyState(VK_SPACE)) 
				break;
		 
		 if (GetAsyncKeyState(VK_ESCAPE)) {
			 system("cls");
			 this->UtilityKey = "esc";
			 this->Loop = false;
			 return;
		 }

		 if (GetAsyncKeyState(VK_BACK)) {
			 this->UtilityKey = "backspace";
			 this->Loop = false;
			 return;
		 }

		 if (GetAsyncKeyState(0x32)) { // key 2
			   SaveGame();
		 }
 		
	}
	
	/*
		Starts
	*/

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 24, 3);
	Graphics::SetColor(13);
	cout << "        Den luot quan co      ";

	Graphics::gotoXY((ScreenColumns - 41) / 2 - 12, 4);
	Graphics::SetColor(15);
	cout << "--- ";

	if (Turn == 'X') {
		Graphics::SetColor(this->ColorX);
		cout << "X";
	}
	else {
		Graphics::SetColor(this->ColorO);
		cout << "O";
	}

	Graphics::SetColor(15);
	cout << " ---";

	CurrCursorX = board->getXAtCell(9, 9) + 2;
	CurrCursorY = board->getYAtCell(9, 9) + 1;
	Graphics::gotoXY(CurrCursorX, CurrCursorY);

	this->Result = 'N';
	this->Loop = true;
	this->Stop = false;
	this->UtilityKey = " ";

	if (ModePlay == "Player vs Player") {
		while (!this->Stop) //Loop until finishing the match
		{
			this->getControlFromPlayer();

			if (this->UtilityKey == "esc" || this->UtilityKey == "backspace" || this->UtilityKey == "Restart")
				return;

			this->checkCurrentState(-1, -1);
			this->changeTurn();
		}
	}
	else if (ModePlay == "Player vs Laptop") {
		AI* computer = new AI();

		while (!this->Stop) //Loop until finishing the match
		{
			Graphics::VisibleCursor(true);
			if (Turn == 'X') {
				this->getControlFromPlayer();

				if (this->UtilityKey == "esc" || this->UtilityKey == "backspace" || this->UtilityKey == "Restart")
					return;

				this->checkCurrentState(-1, -1);
			}
			else {
				computer->findBestMove(board->getpBoard(), board->getSize());

				int BestRow, BestCol;

				if (this->NumberOfChessManX == 0) {
					BestRow = 11;
					BestCol = 11;
				}
				else {
				    BestRow = computer->getBestRow();
					BestCol = computer->getBestCol();
				}

				computer->Go(board->getpBoard(), this->NumberOfChessManO, this->NumberOfChessManX, this->ColorO);
				this->CurrCursorX = board->getXAtCell(BestRow, BestCol) + 2;
				this->CurrCursorY = board->getYAtCell(BestRow, BestCol) + 1;

				board->setAmountChessMan(board->getAmountChessMan() + 1);

				this->checkCurrentState(BestRow, BestCol);			
			}

			this->changeTurn();
			Sleep(30);
		}

		delete computer;
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
		Graphics::SetColor(this->ColorX);
		cout << this->NumberOfWinsOfPlayer;
	}
	else {
		if (this->Result == 'L') {
			Graphics::gotoXY(ScreenColumns - 16, 15);
			this->NumberOfWinsOfComputer++;
			Graphics::SetColor(this->ColorO);
			cout << this->NumberOfWinsOfComputer;
		}
		else if (this->Result == 'D') {
			Graphics::gotoXY(ScreenColumns - 27, 15);
			this->NumberOfWinsOfPlayer++;
			Graphics::SetColor(this->ColorX);
			cout << this->NumberOfWinsOfPlayer;

			Graphics::gotoXY(ScreenColumns - 16, 15);
			this->NumberOfWinsOfComputer++;
			Graphics::SetColor(this->ColorO);
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
		if (this->UtilityKey == "esc" || this->UtilityKey == "backspace")
			return;

		Graphics::VisibleCursor(false);
		PrintTime();

		if (this->Result == 'W') {
			Graphics::Blink((ScreenColumns - 41) / 2 - 21, 3, "YOU WIN!");
			Sleep(15);
			Graphics::Blink((ScreenColumns - 41) / 2 - 11, 3, "YOU WIN!");
			Sleep(15);
			Graphics::Blink((ScreenColumns - 41) / 2 - 1, 3, "YOU WIN!");
			Sleep(15);
		}
		else if (this->Result == 'D'){
			Graphics::Blink((ScreenColumns - 41) / 2 - 23, 3, "DRAW!");
			Sleep(15);
			Graphics::Blink((ScreenColumns - 41) / 2 - 14, 3, "DRAW!");
			Sleep(15);
			Graphics::Blink((ScreenColumns - 41) / 2 - 5, 3, "DRAW!");
			Sleep(15);
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
