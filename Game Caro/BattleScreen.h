#pragma once
#include "ChessBoard.h"
#include <string>
using namespace std;

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
		string UtilityKey;
	private:
		void startCLock();
		void changeTurn();
		void getControlFromPlayer();
		//void getControlFromComputer(); // update later
		void checkCurrentState(int, int);
		void AskPlayer();
		void handleUtilityKey();
	public:
	    bool Loop;
		BattleScreen(int);
		string getUtilityKey() { return UtilityKey; }
		void drawGUI();
		void startBattle(string);
		void finishBattle();
};
