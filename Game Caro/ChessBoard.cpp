#include "ChessBoard.h"
#include "Graphics.h"
#include<stdio.h>

ChessBoard::ChessBoard(int size, int x, int y) {
	this->size = size;
	this->UpperLeftCornerX = x;
	this->UpperLeftCornerY = y;
	pBoard = new CellofBoard*[size];

	for (int i = 0; i < size; i++)
		pBoard[i] = new CellofBoard[size];
}

ChessBoard::~ChessBoard() {
	for (int i = 0; i < size; i++)
		delete[] pBoard[i];
	delete[] pBoard;
}

void ChessBoard::resetBoard() {
	if (size == 0)
		return;
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			pBoard[i][j].setX(UpperLeftCornerX + 4 * j);
			pBoard[i][j].setY(UpperLeftCornerY + 2 * i);
			pBoard[i][j].setChessMan(' ');
		}
}

void ChessBoard::drawBoard() {
	int x = UpperLeftCornerX;
	int y = UpperLeftCornerY;

	Graphics::gotoXY(x, y);
	printf_s("%c", 218);
	for (int i = 0; i < size - 1; i++)
		printf_s("%c%c%c%c", 196, 196, 196, 194);
	printf_s("%c%c%c%c\n", 196, 196, 196, 191);

	for (int i = 0; i < size; i++) {
		Graphics::gotoXY(x, y + 2 * i + 1);

		for (int j = 0; j <= size; j++)
			printf_s("%c   ", 179);

		if (i != size - 1) {
			Graphics::gotoXY(x, y + 2 * i + 2);
			printf_s("%c", 195);

			for (int j = 0; j < size - 1; j++)
				printf_s("%c%c%c%c", 196, 196, 196, 197);

			printf_s("%c%c%c%c", 196, 196, 196, 180);
		}
	}

	Graphics::gotoXY(x, y + 2 * size);
	printf_s("%c", 192);
	for (int i = 0; i < size - 1; i++)
		printf_s("%c%c%c%c", 196, 196, 196, 193);
	printf_s("%c%c%c%c", 196, 196, 196, 217);
}

void ChessBoard::setStateOfBoard(int CursorX, int CursorY, int turn) {
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			int x1 = pBoard[i][j].getX();
			int y1 = pBoard[i][j].getY();
			int x2 = pBoard[i + 1][j + 1].getX();
			int y2 = pBoard[i + 1][j + 1].getY();
			char ChessMan = pBoard[i][i].getChessMan();

			if (x1 < CursorX && CursorX < x2 && y1 < CursorY && CursorY < y2) {
				if (ChessMan != ' ')
					return;
				if (turn == 1) {
					pBoard[i][j].setChessMan('X');
					printf_s("X");
					return;
				}
				else {
					pBoard[i][j].setChessMan('O');
					printf_s("O");
					return;
				}
			}
		}
}
