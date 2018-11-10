#include "GameCaro.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "Graphics.h"

GameCaro::GameCaro(){
	Graphics::InitializeComponent();

	this->PriorityChessMan = 'X';

	while (true) {
		MainScreen* scMain = new MainScreen();
		scMain->PrintTitle();
		int typeSubMenu = scMain->MenuProcessing();

		if (typeSubMenu == 0) { //New Game
			BattleScreen* scrBattle = new BattleScreen(20); //Size of chessboard is 20x20

			while (scrBattle->Loop)
			{
				system("cls");
				scrBattle->drawGUI();
				scrBattle->startGame();
				scrBattle->finishGame();
			}		
		}
		else if (typeSubMenu == 5) { //Exit
			return;
		}
	}
}