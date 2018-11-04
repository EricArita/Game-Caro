#pragma once
#include "CellofBoard.h"

class ChessBoard {
	private:
		int size;
		int UpperLeftCornerX, UpperLeftCornerY;
		CellofBoard** pBoard;
	public:
		int getSize();
		int getUpperLeftCornerX();
		int getUpperLeftCornerY();
		int getXAt(int, int);
		int getYAt(int, int);
	public:
		ChessBoard(int, int, int);
		~ChessBoard();
		void resetBoard();
		void drawBoard();
		void setStateOfBoard(int, int, int);
};
