#pragma once
#include <iostream>
using namespace std;

class GameCaro {
	private:
		//All game settings attributes
		string ModePlay;
		char PriorityChessMan;
		int ColorOfX;
		int ColorOfO;
	private:
		void InfoOfAuthor();
	public:
		GameCaro();
};
