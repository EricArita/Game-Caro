#include "ArtificialIntelligence.h"
#include <algorithm>
using namespace std;

int AI::minimax(CellofBoard** pBoard, int depth, char chessman, int AmountChessMan, int alpha, int beta) {
	int score = evaluate(board);

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 100)
		return score;

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -100)
		return score;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (AmountChessMan == 20*20)
		return 0;

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
					pBoard[i][j].setChessMan('O');

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best, minimax(pBoard, depth + 1, 'X', AmountChessMan + 1, alpha, beta));
					alpha = max(alpha, best);

					// Alpha Beta Pruning 
					if (beta <= alpha)
						break;

					// Undo the move 
					pBoard[i][j].setChessMan(' ');
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
					pBoard[i][j].setChessMan('X');

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best, minimax(pBoard, depth + 1, 'O', AmountChessMan + 1, alpha, beta));
					beta = min(beta, best);

					if (beta <= alpha)
						break;

					// Undo the move 
					pBoard[i][j].setChessMan(' ');
				}
			}
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
				int moveVal = minimax(pBoard, 0, 'X', AmountChessMan + 1, MIN, MAX);

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