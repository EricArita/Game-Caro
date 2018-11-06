#pragma once
#include "ChessBoard.h"

class BattleScreen {
	private:
		ChessBoard* board;
		int ScreenColumns;
		int ScreenRows;
		bool Stop;
		int Result;
		int Turn;
	private:
		void startCLock();
		bool checkCurrentState();
	public:
		BattleScreen(int);
		void drawGUI();
		void startGame();		
};
