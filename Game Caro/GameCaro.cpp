#include "GameCaro.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "Graphics.h"

GameCaro::GameCaro(){
	Graphics::InitializeComponent();

	this->PriorityChessMan = 'O';

	MainScreen* scMain = new MainScreen();
	scMain->PrintTitle();
	int typeSubMenu = scMain->MenuProcessing();

	if (typeSubMenu == 0) { //New Game
		BattleScreen* scrBattle = new BattleScreen(20); //Size of chessboard is 20x20
		scrBattle->drawGUI();
		scrBattle->startGame();
	}
	else if (typeSubMenu == 5) { //Exit
		return;
	}
}