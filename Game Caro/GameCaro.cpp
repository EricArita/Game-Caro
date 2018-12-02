#include "GameCaro.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "Graphics.h"
#include "conio.h"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;

void GameCaro::InfoOfAuthor() {
	system("cls");
	string info[9];

	info[0] = "1> FULL NAME: Bui Phan Tho (Eric Arita)";
	info[1] = "2> STUDENT ID: 1712169";
	info[2] = "3> CLASS: 17CTT2";
	info[3] = "4> UNIVERSITY: Ho Chi Minh University of Science(HCMUS)";
	info[4] = "5> EMAIL: buiphantho@gmail.com";
	info[5] = "6> FACEBOOK: Facebook.com/Eric.Arita.619";
	info[6] = "7> GITHUB: github.com/EricArita";
	info[7] = "    This game is my OOP project in the end of term. You can contact me via Email, Facebook link above. For more information about source code of this game, please access my github link.";
	info[8] = "---> Press Backspace to return MainMenu...";

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < info[i].size(); j++) {
			cout << info[i][j];
			Sleep(20);
		}
		cout << "\n";
	}

	cout << "\n" << info[8];

	while (true)
	{
		for (int i = 0; i < 3; i++) {
			Graphics::gotoXY(40 + i, 10);
			cout << ".";

			if (GetAsyncKeyState(VK_BACK))
				break;

			Sleep(300);
		}

		Graphics::gotoXY(40, 10);
		cout << "    ";

		if (GetAsyncKeyState(VK_BACK))
			break;
	}
}

GameCaro::GameCaro(){
	Graphics::SetFullConsoleScreen();
	this->PriorityChessMan = 'X';
	this->ColorOfX = 10; //Default color for X is Light Green
	this->ColorOfO = 12; //Default color for O is Light Red
	this->ModePlay = " ";

	MainScreen* scrMain = new MainScreen();
	int TypeMenu = -1;

	while (true) {
		scrMain->PrintTitle();
		scrMain->SetFeatures(0, this->ModePlay, this->PriorityChessMan, this->ColorOfX, this->ColorOfO);
		TypeMenu = scrMain->getTypeMenu();

		if (TypeMenu == 1) { //New Game
			if (this->ModePlay == " ") { //Back
				system("cls");
				continue;
			}

			BattleScreen* scrBattle = new BattleScreen(20, this->ModePlay, this->PriorityChessMan, this->ColorOfX, this->ColorOfO); //Size of chessboard is 20x20
			system("cls");

			while (scrBattle->Loop)
			{
				scrBattle->drawGUI("New game");
				scrBattle->startBattle("New game");

				if (!scrBattle->Loop) {
					if (scrBattle->getUtilityKey() == "esc")
						return;

					if (scrBattle->getUtilityKey() == "backspace")
						break;
				}
				
				while(scrBattle->getUtilityKey() == "Restart") {
					scrBattle->drawGUI("Restart");
					scrBattle->startBattle("New game");
				}

				if (!scrBattle->Loop) {
					if (scrBattle->getUtilityKey() == "esc")
						return;

					if (scrBattle->getUtilityKey() == "backspace")
						break;
				}

				scrBattle->finishBattle();
			}	

			delete scrBattle;
			system("cls");		
			continue;
		}

		if (TypeMenu == 2) { //Load game
			BattleScreen* scrBattle = new BattleScreen(20, " ", this->PriorityChessMan, this->ColorOfX, this->ColorOfO);
			scrBattle->LoadGame(this->ModePlay);

			if (this->ModePlay == " ") { // user presses back to return main menu instead of selecting and loading game	
				system("cls");
				continue;
			}

			system("cls");
			int cntLoop = -1;

			while (scrBattle->Loop)
			{
				cntLoop++;
				if (cntLoop == 0) {
					scrBattle->drawGUI("Load game");
					scrBattle->startBattle("Load game");
				}
				else {
					scrBattle->drawGUI("New game");
					scrBattle->startBattle("New game");				
				}
				

				if (!scrBattle->Loop) {
					if (scrBattle->getUtilityKey() == "esc") {
						delete scrMain;
						return;
					}

					if (scrBattle->getUtilityKey() == "backspace")
						break;
				}

				while (scrBattle->getUtilityKey() == "Restart") {
					scrBattle->drawGUI("Restart");
					scrBattle->startBattle("New game");
				}

				if (!scrBattle->Loop) {
					if (scrBattle->getUtilityKey() == "esc") {
						delete scrMain;
						return;
					}

					if (scrBattle->getUtilityKey() == "backspace")
						break;
				}

				scrBattle->finishBattle();
			}

			delete scrBattle;
			system("cls");
			Sleep(20);
			continue;
		}

		if (TypeMenu == 5) {
			InfoOfAuthor();
			system("cls");
		}

		if (TypeMenu == 6) { //Exit
			delete scrMain;
			return;
		}

		
	}
}