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
		string ModePlay;
		string UtilityKey;
	private:
		void startCLock();
		void changeTurn();
		void SaveGame();
		void getControlFromPlayer();
		//void getControlFromComputer(); // update later
		void checkCurrentState(int, int);
		void AskPlayer();
	public:
		void LoadGame(string&);
	    bool Loop;
		BattleScreen(int, string);
		string getUtilityKey() { return UtilityKey; }
		void drawGUI(string);
		void startBattle(string);
		void finishBattle();
};
