// Game Caro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "windows.h"
#include "MainScreen.h"
#include "BattleScreen.h"
#include "GameCaro.h"
#include "Graphics.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
	Graphics::InitializeComponent();
	BattleScreen* s = new BattleScreen(20);
	s->drawGUI();
	s->startGame();
	s->finishGame();
	//GameCaro* readyPlay = new GameCaro();
	_getch();
	return 0;
}

