#pragma once
#include "CellofBoard.h"

class AI {
	private:
		int BestRow;
		int BestCol;
		int AttackScoreArray[7] = { 0, 9, 54, 162, 1458, 13112, 118008 };
		int DefenceScoreArray[7] = { 0, 3, 27, 99, 729, 6561, 59049 };
	private:
		int AttackScore_VerticalBrowse(CellofBoard**, int, int, int);
		int AttackScore_HorizontalBrowse(CellofBoard**, int, int, int);
		int AttackScore_MainDiagonalBrowse(CellofBoard**, int, int, int);
		int AttackScore_ExtraDiagonalBrowse(CellofBoard**, int, int, int);
		int DefenceScore_VerticalBrowse(CellofBoard**, int, int, int);
		int DefenceScore_HorizontalBrowse(CellofBoard**, int, int, int);
		int DefenceScore_MainDiagonalBrowse(CellofBoard**, int, int, int);
		int DefenceScore_ExtraDiagonalBrowse(CellofBoard**, int, int, int);
	public:
		int getBestRow() { return BestRow; }
		int getBestCol() { return BestCol; }
		void findBestMove(CellofBoard**, int);
		void Go(CellofBoard** &, int&, int, int);
};
