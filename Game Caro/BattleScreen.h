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
		char PriorityChessMan;
		int ColorX;
		int ColorO;
		string UtilityKey;
	private:
		void PrintTime();
		void changeTurn();
		void SaveGame();
		void getControlFromPlayer();
		void checkCurrentState(int, int);
		void AskPlayer();
	public:
		void LoadGame(string&);
	    bool Loop;
		BattleScreen(int, string, char, int ,int);
		string getUtilityKey() { return UtilityKey; }
		void drawGUI(string);
		void startBattle(string);
		void finishBattle();
};
