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
			BattleScreen* scrBattle = new BattleScreen(20, this->ModePlay); //Size of chessboard is 20x20
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

				scrBattle->finishBattle();
			}	

			delete scrBattle;
			delete scrMain;
			system("cls");		
			continue;
		}

		if (TypeMenu == 2) { //Load game
			BattleScreen* scrBattle = new BattleScreen(20, " ");
			scrBattle->LoadGame(this->ModePlay);
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
					if (scrBattle->getUtilityKey() == "esc")
						return;

					if (scrBattle->getUtilityKey() == "backspace")
						break;
				}

				scrBattle->finishBattle();
			}

			delete scrBattle;
			delete scrMain;
			system("cls");
			continue;
		}

		if (TypeMenu == 5) { //Exit
			return;
		}

		
	}
}