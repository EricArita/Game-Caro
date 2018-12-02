#include "MainScreen.h"
#include "Windows.h"
#include "Graphics.h"
#include "BattleScreen.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;

MainScreen::MainScreen() {
	system("cls");
	Graphics::getConsoleScreenSize();
	ScreenColumns = Graphics::ConsoleScreenColumns;
	ScreenRows = Graphics::ConsoleScreenRows;
	Graphics::VisibleCursor(false);
}

void MainScreen::PrintTitle(){
	int initX = (ScreenColumns - 74) / 2 + 8; //coordinate X to start printing title
	int initY = 6; //coordinate Y to start printing title
	Graphics::SetColor(10);
	Graphics::VisibleCursor(false);

	/*
		print 'C'
	*/
	Sleep(700);

	Graphics::gotoXY(initX, initY);
	printf_s("CCCCCCCCCCCCC");

	Graphics::gotoXY(initX - 3, initY + 1);
	printf_s("CCC::::::::::::C");

	Graphics::gotoXY(initX - 5, initY + 2);
	printf_s("CC:::::::::::::::C");

	Graphics::gotoXY(initX - 6, initY + 3);
	printf_s("C:::::CCCCCCCC::::C");


	Graphics::gotoXY(initX - 7, initY + 4);
	printf_s("C:::::C       CCCCCC");

	for (int i = 1; i <= 6; i++) {
		Graphics::gotoXY(initX - 8, initY + 4 + i);
		printf_s("C:::::C");
	}

	Graphics::gotoXY(initX - 7, initY + 11);
	printf_s("C:::::C       CCCCCC");

	Graphics::gotoXY(initX - 6, initY + 12);
	printf_s("C:::::CCCCCCCC::::C");

	Graphics::gotoXY(initX - 5, initY + 13);
	printf_s("CC:::::::::::::::C");

	Graphics::gotoXY(initX - 3, initY + 14);
	printf_s("CCC::::::::::::C");

	Graphics::gotoXY(initX, initY + 15);
	printf_s("CCCCCCCCCCCCC");

	Sleep(600);

	/*
		print 'A'
	*/
	initX += 15;
	initY += 4;

	Graphics::gotoXY(initX, initY);
	printf_s("aaaaaaaaaaaaa");

	Graphics::gotoXY(initX, initY + 1);
	printf_s("a::::::::::::a");

	Graphics::gotoXY(initX, initY + 2);
	printf_s("aaaaaaaaa:::::a");

	Graphics::gotoXY(initX + 9, initY + 3);
	printf_s("a::::a");

	Graphics::gotoXY(initX + 2, initY + 4);
	printf_s("aaaaaaa:::::a");

	Graphics::gotoXY(initX, initY + 5);
	printf_s("aa::::::::::::a");

	Graphics::gotoXY(initX - 1, initY + 6);
	printf_s("a::::aaaa::::::a");

	for (int i = 1; i <= 2; i++) {
		Graphics::gotoXY(initX - 2, initY + 6 + i);
		printf_s("a::::a    a:::::a");
	}

	Graphics::gotoXY(initX - 2, initY + 9);
	printf_s("a:::::aaaa::::::a");

	Graphics::gotoXY(initX -1, initY + 10);
	printf_s("a::::::::::aa:::a");

	Graphics::gotoXY(initX, initY + 11);
	printf_s("aaaaaaaaaa  aaaa");

	Sleep(600);

	/*
		print 'R'
	*/
	initX += 15;

	Graphics::gotoXY(initX, initY);
	printf_s("rrrrrrrrrrrrrrrrr");

	Graphics::gotoXY(initX, initY + 1);
	printf_s("r::::rrr:::::::::r");

	Graphics::gotoXY(initX, initY + 2);
	printf_s("r:::::::::::::::::r");

	Graphics::gotoXY(initX, initY + 3);
	printf_s("rr::::::rrrrr::::::r");

	Graphics::gotoXY(initX + 1, initY + 4);
	printf_s("r:::::r     r:::::r");

	Graphics::gotoXY(initX + 1, initY + 5);
	printf_s("r:::::r     rrrrrrr");

	for (int i = 1; i <= 5; i++) {
		Graphics::gotoXY(initX + 1, initY + 5 + i);
		printf_s("r:::::r");
	}

	Graphics::gotoXY(initX + 1, initY + 11);
	printf_s("rrrrrrr");

	Sleep(600);

	/*
		print 'O'
	*/
	initX += 23;

	Graphics::gotoXY(initX, initY);
	printf_s("ooooooooooo");

	Graphics::gotoXY(initX - 2, initY + 1);
	printf_s("oo:::::::::::oo");

	Graphics::gotoXY(initX - 3, initY + 2);
	printf_s("o:::::::::::::::o");

	Graphics::gotoXY(initX - 3, initY + 3);
	printf_s("o:::::ooooo:::::o");

	for (int i = 1; i <= 4; i++) {
		Graphics::gotoXY(initX - 3, initY + 3 + i);
		printf_s("o::::o     o::::o");
	}

	Graphics::gotoXY(initX - 3, initY + 8);
	printf_s("o:::::ooooo:::::o");

	Graphics::gotoXY(initX - 3, initY + 9);
	printf_s("o:::::::::::::::o");

	Graphics::gotoXY(initX - 2, initY + 10);
	printf_s("oo:::::::::::oo");

	Graphics::gotoXY(initX, initY + 11);
	printf_s("ooooooooooo");
}

bool MainScreen::HandleOptionMenu(int currSubmenu, char &PriorityChessMan, int &ColorX, int &ColorO) {
	int initX = ScreenColumns / 2;
	int initY = ScreenRows / 2;

	switch (currSubmenu) {
		case 0:
			Graphics::gotoXY(initX + 19, initY + 4);
			Graphics::SetColor(15);
			cout << PriorityChessMan;
			break;
		case 1:
			Graphics::gotoXY(initX + 12, initY + 6);
			Graphics::SetColor(15);
			cout << ColorX;
			break;
		case 2:
			Graphics::gotoXY(initX + 12, initY + 8);
			Graphics::SetColor(15);
			cout << ColorO;
			break;
		case 3:
			return true;
	}

	while (true) {
			_getch();

			if (_kbhit()) {
				if (GetAsyncKeyState(VK_DOWN)) {
					if (currSubmenu == 0) {
						Graphics::gotoXY(initX + 19, initY + 4);

						if (PriorityChessMan == 'X') {
							printf_s("O");
							PriorityChessMan = 'O';
						}
						else {
							printf_s("X");
							PriorityChessMan = 'X';
						}

						Sleep(200);
						continue;
					}

					if(currSubmenu == 1) {
						Graphics::gotoXY(initX + 12, initY + 6);
						if (ColorX - 1 >= 0)
							ColorX--;
						else
							ColorX = 15;

						cout << ColorX << " ";

						Sleep(200);
						continue;
					}

					if (currSubmenu == 2) {
						Graphics::gotoXY(initX + 12, initY + 8);
						if (ColorO - 1 >= 0)
							ColorO--;
						else
							ColorO = 15;

						cout << ColorO << " ";

						Sleep(200);
						continue;
					}
				}

				if (GetAsyncKeyState(VK_UP)) {
					if (currSubmenu == 0) {
						Graphics::gotoXY(initX + 19, initY + 4);

						if (PriorityChessMan == 'X') {
							printf_s("O");
							PriorityChessMan = 'O';
						}
						else {
							printf_s("X");
							PriorityChessMan = 'X';
						}

						Sleep(200);
						continue;
					}

					if (currSubmenu == 1) {
						Graphics::gotoXY(initX + 12, initY + 6);
						if (ColorX + 1 <= 15)
							ColorX++;
						else
							ColorX = 0;

						cout << ColorX << " ";

						Sleep(200);
						continue;
					}

					if (currSubmenu == 2) {
						Graphics::gotoXY(initX + 12, initY + 8);
						if (ColorO + 1 <= 15)
							ColorO++;
						else
							ColorO = 0;

						cout << ColorO << " ";

						Sleep(200);
						continue;
					}
				
				}

				if (GetAsyncKeyState(VK_RETURN)) {
					switch (currSubmenu) {
						case 0:
							Graphics::gotoXY(initX + 19, initY + 4);
							Graphics::SetColor(8);
							cout << PriorityChessMan;
							break;
						case 1:
							Graphics::gotoXY(initX + 12, initY + 6);
							Graphics::SetColor(8);
							cout << ColorX;
							break;
						case 2:
							Graphics::gotoXY(initX + 12, initY + 8);
							Graphics::SetColor(8);
							cout << ColorO;
							break;
					}

					return false;
				}
			}
	}
}

void MainScreen::PrintMenu(int BoldAt, char PriorityChessMan, int ColorX, int ColorO) {
	string submenu[6];

	switch (this->TypeMenu)	
	{
		case 0: //MainMenu
			submenu[0] = "New Game                 ";
			submenu[1] = "Load Game                ";
			submenu[2] = "Options                  ";
			submenu[3] = "Help                     ";
			submenu[4] = "About                    ";
			submenu[5] = "Exit                     ";
			break;
		case 1: 
			submenu[0] = "Human vs Human";
			submenu[1] = "Human vs Computer";
			submenu[2] = "Back    ";
			submenu[3] = "    ";
			submenu[4] = "     ";
			submenu[5] = "    ";
			break;
		case 3:
			submenu[0] = "Priority chessman: ";
			submenu[1] = "Color of X: ";
			submenu[2] = "Color of O: ";
			submenu[3] = "Back    ";
			submenu[4] = "     ";
			submenu[5] = "    ";
			break;
	}
	
	int initX = ScreenColumns / 2;
	int initY = ScreenRows / 2;

	for (int i = 0; i < 6; i++) {
		Graphics::gotoXY(initX, initY + 4 + 2 * i);

		if (BoldAt == i)
			Graphics::SetColor(12);
		else
			Graphics::SetColor(14);

		cout << submenu[i];

		if (TypeMenu == 3) {
			Graphics::SetColor(8);
			string s(1, PriorityChessMan);
			switch (i)
			{
				case 0:
					cout << s;
					break;
				case 1:
					cout << to_string(ColorX);
					break;
				case 2:
					cout << to_string(ColorO);
					break;
			}
		}
	}
}

void MainScreen::SetFeatures(int TypeMenu, string &ModePlay, char &PriorityChessMan, int &ColorX, int &ColorO){
	this->TypeMenu = TypeMenu;
	this->PrintMenu(0, PriorityChessMan, ColorX, ColorO);

	int currSubmenu = 0;

	while (true) {
		_getch();

		if (_kbhit()) {
			if (GetAsyncKeyState(VK_DOWN)){
				currSubmenu++;
				if (currSubmenu == SizeofMenu[TypeMenu])
					currSubmenu = 0;
				this->PrintMenu(currSubmenu, PriorityChessMan, ColorX, ColorO);
				Sleep(200);
				continue;
			}
			
			if (GetAsyncKeyState(VK_UP)) {
				currSubmenu--;
				if (currSubmenu == -1)
					currSubmenu = SizeofMenu[TypeMenu] - 1;
				this->PrintMenu(currSubmenu, PriorityChessMan, ColorX, ColorO);
				Sleep(200);
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN)) {
				if (TypeMenu == 0) {
					if (currSubmenu == 0) { //New game

						SetFeatures(1, ModePlay, PriorityChessMan, ColorX, ColorO);

						if (ModePlay != " ")
							return;

						this->TypeMenu = TypeMenu;
						this->PrintMenu(0, PriorityChessMan, ColorX, ColorO);
						continue;
					}

					if (currSubmenu == 1) { //Load game
						this->TypeMenu = 2;
						return;
					}

					if (currSubmenu == 2) {
						SetFeatures(3, ModePlay, PriorityChessMan, ColorX, ColorO);
						this->TypeMenu = TypeMenu;
						this->PrintMenu(currSubmenu, PriorityChessMan, ColorX, ColorO);
						continue;
					}

					if (currSubmenu == 4) {
						this->TypeMenu = 5;
						return;
					}

					if (currSubmenu == 5) { //Exit
						system("cls");
						this->TypeMenu = 6;
						return;
					}
				}

				if (TypeMenu == 1) { //mode play
					if (currSubmenu == 0)
						ModePlay = "Player vs Player";
					else if (currSubmenu == 1)
						ModePlay = "Player vs Laptop";
					else
						ModePlay = " "; // back

					return;
				}

				if (TypeMenu == 3) {
					if (HandleOptionMenu(currSubmenu, PriorityChessMan, ColorX, ColorO))
						return;
				}
			}
		}
		
	}
}