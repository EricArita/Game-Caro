#include "ArtificialIntelligence.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

int AI::getEvaluatedScore(CellofBoard** pBoard, int movei, int movej, int AmountChessMan) {
	if (AmountChessMan == 20 * 20) 
		return 0;

	int n = 20;
	int i, j;
	int currRow = movei;
	int currColumn = movej;
	int AmountX, AmountO;
	char c1, c2, c3, c4, c5;
	int t, k;

	/*
		check horizontal line on chessboard
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (j + 4 > n - 1) j--;

	c1 = pBoard[i][j].getChessMan();
	c2 = pBoard[i][j + 1].getChessMan();
	c3 = pBoard[i][j + 2].getChessMan();
	c4 = pBoard[i][j + 3].getChessMan();
	c5 = pBoard[i][j + 4].getChessMan();

	if (c1 == 'X')
		AmountX++;
	else if (c1 == 'O')
		AmountO++;

	if (c2 == 'X')
		AmountX++;
	else if (c2 == 'O')
		AmountO++;

	if (c3 == 'X')
		AmountX++;
	else if (c3 == 'O')
		AmountO++;

	if (c4 == 'X')
		AmountX++;
	else if (c4 == 'O')
		AmountO++;

	if (c5 == 'X')
		AmountX++;
	else if (c5 == 'O')
		AmountO++;

	t = j;

	while (j >= 0 && j >= currColumn - 4) {
		if (j != t) {
			char p = pBoard[i][j].getChessMan();
			char q = pBoard[i][j+5].getChessMan();

			if (p == 'X')
				AmountX++;
			else if (p == 'O')
				AmountO++;

			if (q == 'X')
				AmountX--;
			else if (q == 'O')
				AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			if (AmountX == 5)
				return -100;
			else
				return 100;
		}

		j--;
	}

	/*
		check vertical line on chessboard
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1) i--;

	c1 = pBoard[i][j].getChessMan();
	c2 = pBoard[i + 1][j].getChessMan();
	c3 = pBoard[i + 2][j].getChessMan();
	c4 = pBoard[i + 3][j].getChessMan();
	c5 = pBoard[i + 4][j].getChessMan();

	if (c1 == 'X')
		AmountX++;
	else if (c1 == 'O')
		AmountO++;

	if (c2 == 'X')
		AmountX++;
	else if (c2 == 'O')
		AmountO++;

	if (c3 == 'X')
		AmountX++;
	else if (c3 == 'O')
		AmountO++;

	if (c4 == 'X')
		AmountX++;
	else if (c4 == 'O')
		AmountO++;

	if (c5 == 'X')
		AmountX++;
	else if (c5 == 'O')
		AmountO++;

	t = i;

	while (i >= 0 && i >= currRow - 4) {
		if (i != t) {
			char p = pBoard[i][j].getChessMan();
			char q = pBoard[i+5][j].getChessMan();

			if (p == 'X')
				AmountX++;
			else if (p == 'O')
				AmountO++;

			if (q == 'X')
				AmountX--;
			else if (q == 'O')
				AmountO--;
		}

		if (AmountX == 5 || AmountO == 5) {
			if (AmountX == 5)
				return -100;
			else
				return 100;
		}

		i--;
	}

	/*
		check diagonal lines is parallel to main diagonal line
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1 || j + 4 > n - 1) {
		i--;
		j--;
	}

	if (i >= 0 && j >= 0) {
		c1 = pBoard[i][j].getChessMan();
		c2 = pBoard[i + 1][j + 1].getChessMan();
		c3 = pBoard[i + 2][j + 2].getChessMan();
		c4 = pBoard[i + 3][j + 3].getChessMan();
		c5 = pBoard[i + 4][j + 4].getChessMan();

		if (c1 == 'X')
			AmountX++;
		else if (c1 == 'O')
			AmountO++;

		if (c2 == 'X')
			AmountX++;
		else if (c2 == 'O')
			AmountO++;

		if (c3 == 'X')
			AmountX++;
		else if (c3 == 'O')
			AmountO++;

		if (c4 == 'X')
			AmountX++;
		else if (c4 == 'O')
			AmountO++;

		if (c5 == 'X')
			AmountX++;
		else if (c5 == 'O')
			AmountO++;

		t = i;
		k = j;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j >= currColumn - 4) {
			if (i != t && j != k) {
				char p = pBoard[i][j].getChessMan();
				char q = pBoard[i + 5][j + 5].getChessMan();

				if (p == 'X')
					AmountX++;
				else if (p == 'O')
					AmountO++;

				if (q == 'X')
					AmountX--;
				else if (q == 'O')
					AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {	
				if (AmountX == 5)
					return -100;
				else
					return 100;
			}

			i--;
			j--;
		}
	}

	/*
		check diagonal lines is parallel to extra diagonal line
	*/
	i = currRow;
	j = currColumn;
	AmountO = AmountX = 0;

	while (i + 4 > n - 1 || j - 4 < 0) {
		i--;
		j++;
	}

	if (i >= 0 && j >= 0) {
		c1 = pBoard[i][j].getChessMan();
		c2 = pBoard[i + 1][j - 1].getChessMan();
		c3 = pBoard[i + 2][j - 2].getChessMan();
		c4 = pBoard[i + 3][j - 3].getChessMan();
		c5 = pBoard[i + 4][j - 4].getChessMan();

		if (c1 == 'X')
			AmountX++;
		else if (c1 == 'O')
			AmountO++;

		if (c2 == 'X')
			AmountX++;
		else if (c2 == 'O')
			AmountO++;

		if (c3 == 'X')
			AmountX++;
		else if (c3 == 'O')
			AmountO++;

		if (c4 == 'X')
			AmountX++;
		else if (c4 == 'O')
			AmountO++;

		if (c5 == 'X')
			AmountX++;
		else if (c5 == 'O')
			AmountO++;

		t = i;
		k = j;

		while (i >= 0 && j >= 0 && i >= currRow - 4 && j <= currColumn + 4) {
			if (i != t && j != k) {
				char p = pBoard[i][j].getChessMan();
				char q = pBoard[i + 5][j - 5].getChessMan();

				if (p == 'X')
					AmountX++;
				else if (p == 'O')
					AmountO++;

				if (q == 'X')
					AmountX--;
				else if (q == 'O')
					AmountO--;
			}

			if (AmountX == 5 || AmountO == 5) {
				if (AmountX == 5)
					return -100;
				else
					return 100;
			}

			i--;
			j++;
		}
	}
}

int AI::minimax(CellofBoard** pBoard, int depth, char chessman, int AmountChessMan, int movei, int movej, int alpha, int beta) {
	int score = -1e9;
	score = getEvaluatedScore(pBoard, movei, movej, AmountChessMan);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == -100 || score == 0 || score == 100)
		return score;
	
	// If this maximizer's move 
	if (chessman == 'O')
	{
		int best = -1e9;

		// Traverse all cells 
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++)
			{
				// Check if cell is empty 
				if (pBoard[i][j].getChessMan() == ' ')
				{
					// Make the move 
					pBoard[i][j].setChessMan('X');

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best, minimax(pBoard, depth + 1, 'O', AmountChessMan + 1, i, j, alpha, beta));
					alpha = max(alpha, best);
				
					// Undo the move 
					pBoard[i][j].setChessMan(' ');

					// Alpha Beta Pruning 
					if (beta <= alpha)
						break;
				}

			}

			if (beta <= alpha)
				break;
		}

		return best;
	}	
	else{ // If this minimizer's move
		int best = 1e9;

		// Traverse all cells 
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				// Check if cell is empty 
				if (pBoard[i][j].getChessMan() == ' ')
				{
					// Make the move 
					pBoard[i][j].setChessMan('O');

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best, minimax(pBoard, depth + 1, 'X', AmountChessMan + 1, i, j, alpha, beta));
					beta = min(beta, best);

					// Undo the move 
					pBoard[i][j].setChessMan(' ');

					if (beta <= alpha)
						break;
				}
			}

			if (beta <= alpha)
				break;
		}

		return best;
	}
}

void AI::findBestMove(CellofBoard** pBoard, int AmountChessMan) {
	int bestVal = -1e9;
	this->BestRow = -1;
	this->BestCol = -1;

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			// Check if cell is empty 
			if (pBoard[i][j].getChessMan() == ' ')
			{
				// Make the move 
				pBoard[i][j].setChessMan('O');

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(pBoard, 0, 'X', AmountChessMan + 1, i, j, MIN, MAX);

				// Undo the move 
				pBoard[i][j].setChessMan(' ');

				// If the value of the current move is 
				// more than the best value, then update 
				// best/ 
				if (moveVal > bestVal)
				{
					this->BestRow = i;
					this->BestCol = j;
					bestVal = moveVal;
				}
			}
		}
}

void AI::Go(CellofBoard** &pBoard) {
	Graphics::gotoXY(pBoard[BestRow][BestCol].getX() + 2, pBoard[BestRow][BestCol].getY() + 1);
	Graphics::SetColor(12);
	printf_s("O");
	pBoard[BestRow][BestCol].setChessMan('O');
}