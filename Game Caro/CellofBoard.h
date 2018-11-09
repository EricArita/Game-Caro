#pragma once

class CellofBoard {
	private:
		int x, y; //coordinate of upper left corner of each cell in board
		char ChessMan;
	public:
		CellofBoard() {
			x = y = 0;
			ChessMan = ' ';
		}

		CellofBoard(int x, int y) {
			this->x = x;
			this->y = y;
			ChessMan = ' ';
		}

		int getX() { return x; }
		int getY() { return y; }
		char getChessMan() { return ChessMan; }
		void setX(int value) { x = value; }
		void setY(int value) { y = value; }
		void setChessMan(char value) { ChessMan = value; }
};
