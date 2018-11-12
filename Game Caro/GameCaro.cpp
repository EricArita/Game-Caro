#include "GameCaro.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "Graphics.h"

GameCaro::GameCaro(){
	Graphics::InitializeComponent();

	this->PriorityChessMan = 'X';

	while (true) {
		MainScreen* scrMain = new MainScreen();
		scrMain->PrintTitle();
		int typeSubMenu = scrMain->MenuProcessing();

		if (typeSubMenu == 0) { //New Game
			BattleScreen* scrBattle = new BattleScreen(20); //Size of chessboard is 20x20

			while (scrBattle->Loop)
			{
				system("cls");
				scrBattle->drawGUI();
				scrBattle->startBattle();
				scrBattle->finishBattle();
			}	

			delete scrBattle;
		}
		else if (typeSubMenu == 5) { //Exit
			return;
		}

		delete scrMain;
	}
}