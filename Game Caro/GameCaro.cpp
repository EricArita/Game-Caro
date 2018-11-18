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
		scrMain->SetFeatures(0, this->ModePlay);
		int TypeMenu = scrMain->getTypeMenu();

		if (TypeMenu == 1) { //New Game
			BattleScreen* scrBattle = new BattleScreen(20); //Size of chessboard is 20x20
			system("cls");

			while (scrBattle->Loop)
			{
				scrBattle->drawGUI();
				scrBattle->startBattle(this->ModePlay);

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
		else if (TypeMenu == 5) { //Exit
			return;
		}

		delete scrMain;
	}
}