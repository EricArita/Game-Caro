#pragma once
#include "ChessBoard.h"

class BattleScreen {
	private:
		ChessBoard* board;
		int ScreenColumns;
		int ScreenRows;
		int CurrCursorX;
		int CurrCursorY;
		bool Stop;
		char Result;
		char Turn;
		bool FinishThreadAskPlayer;
		int NumberOfWinsOfPlayer;
		int NumberOfWinsOfComputer;
		int NumberOfChessManX;
		int NumberOfChessManO;
	private:
		void startCLock();
		void changeTurn();
		void getControlFromPlayer();
		//void getControlFromComputer(); // update later
		void checkCurrentState();
		void AskPlayer();
	public:
	    bool Loop;
		BattleScreen(int);
		void drawGUI();
		void startBattle();
		void finishBattle();
};
