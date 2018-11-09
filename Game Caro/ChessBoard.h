#pragma once
#include "CellofBoard.h"

class ChessBoard {
	private:
		int size;
		int UpperLeftCornerX, UpperLeftCornerY;
		int AmountChessMan;
		CellofBoard** pBoard;
 	public:
		int getSize() { return size; }
		int getUpperLeftCornerX() { return UpperLeftCornerX; }
		int getUpperLeftCornerY() { return UpperLeftCornerY; }
		int getXAtCell(int i, int j) { return pBoard[i][j].getX(); }
		int getYAtCell(int i, int j) { return pBoard[i][j].getY(); }
		int getAmountChessMan() { return AmountChessMan; }
		char getChessManAtCell(int i, int j) { return pBoard[i][j].getChessMan(); }
	public:
		ChessBoard(int, int, int);
		~ChessBoard();
		void resetBoard();
		void drawBoard();
		bool setStateOfBoard(int, int, char);
};
