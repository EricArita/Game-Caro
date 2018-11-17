#include "GameCaro.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "Graphics.h"

GameCaro::GameCaro(){
	Graphics::SetFullConsoleScreen();

	this->PriorityChessMan = 'X';

	while (true) {
		MainScreen* scrMain = new MainScreen();
		scrMain->PrintTitle();
		int typeSubMenu = scrMain->MenuProcessing();

		if (typeSubMenu == 0) { //New Game
			BattleScreen* scrBattle = new BattleScreen(20); //Size of chessboard is 20x20
			system("cls");

			while (scrBattle->Loop)
			{
				scrBattle->drawGUI();
				scrBattle->startBattle();

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
		}
		else if (typeSubMenu == 5) { //Exit
			return;
		}

		delete scrMain;
	}
}