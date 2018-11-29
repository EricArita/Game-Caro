#pragma once
#include "CellofBoard.h"
#include <string>

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
		void setAmountChessMan(int value) { AmountChessMan = value; }
		CellofBoard**& getpBoard() { return pBoard; }
		char getChessManAtCell(int i, int j) { return pBoard[i][j].getChessMan(); }
	public:
		ChessBoard(int, int, int);
		~ChessBoard();
		void resetBoard(std::string, int, int);
		void drawBoard();
		bool setStateOfBoard(int, int, char, int, int);
};
