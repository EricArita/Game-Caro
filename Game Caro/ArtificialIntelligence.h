#pragma once
#include "CellofBoard.h"

class AI {
	private:
		int BestRow;
		int BestCol;
		const int MAX = 1e9;
		const int MIN = -1e9;
	private:
		int minimax(CellofBoard**, int , char , int , int, int);
	public:
		int getBestRow() { return BestRow; }
		int getBestCol() { return BestCol; }
	public:
		void findBestMove(CellofBoard**, int);
};
