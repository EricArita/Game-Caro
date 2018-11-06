#pragma once
#include "CellofBoard.h"

class ChessBoard {
	private:
		int size;
		int UpperLeftCornerX, UpperLeftCornerY;
		CellofBoard** pBoard;
	public:
		int getSize() { return size; };
		int getUpperLeftCornerX() { return UpperLeftCornerX; };
		int getUpperLeftCornerY() { return UpperLeftCornerY; };
	public:
		ChessBoard(int, int, int);
		~ChessBoard();
		void resetBoard();
		void drawBoard();
		void setStateOfBoard(int, int, int);
};
