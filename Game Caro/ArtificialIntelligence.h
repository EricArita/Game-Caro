#pragma once
#include "CellofBoard.h"

class AI {
	private:
		int BestRow;
		int BestCol;
		const int MAX = 1e9;
		const int MIN = -1e9;
	private:
		int getEvaluatedScore(CellofBoard**, int, int, int);
		int minimax(CellofBoard**, int , char , int , int, int, int, int);
	public:
		int getBestRow() { return BestRow; }
		int getBestCol() { return BestCol; }
		void findBestMove(CellofBoard**, int);
		void Go(CellofBoard** &);
};
