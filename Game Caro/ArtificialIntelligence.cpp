#include "ArtificialIntelligence.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

int AI::AttackScore_VerticalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TempScore = 0;
	int TotalScore = 0;
	int AmountX = 0; // human is X chessman
	int AmountO = 0; // computer is O chessman

	// browse from current cell in the downward direction
	// browse 5 consecutive cell     
	for (int i = 1; i <= 5 && currRow + i < SizeofBoard; i++)
	{
		if (pBoard[currRow + i][currCol].getChessMan() == 'O') 
			 AmountO++;
		else if (pBoard[currRow + i][currCol].getChessMan() == 'X') 
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else 
			break;
	}

	// browse from current cell in the upward direction                   
	for (int i = 1; i <= 5 && currRow - i >= 0; i++)
	{
		if (pBoard[currRow - i][currCol].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow - i][currCol].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// if be prevented in 2 heads, the move doesn't have value
	if (AmountX == 2)
		return 0;

	// the maximum of AmountX can only be 1

	// decrease Total Score based on AmountX
	TotalScore -= DefenceScoreArray[AmountX];
	
	//increase Total Score based on AmountO
	TotalScore += AttackScoreArray[AmountO];	
	TotalScore += TempScore;

	return TotalScore;
}

int AI::AttackScore_HorizontalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TempScore = 0;
	int TotalScore = 0;
	int AmountX = 0; // human is X chessman
	int AmountO = 0; // computer is O chessman

	// browse from current cell in the rightward direction
	// browse 5 consecutive cell     
	for (int i = 1; i <= 5 && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow][currCol + i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// browse from current cell in the leftward direction                   
	for (int i = 1; i <= 5 && currCol - i >= 0; i++)
	{
		if (pBoard[currRow][currCol - i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// if be prevented in 2 heads, the move doesn't have value
	if (AmountX == 2)
		return 0;

	// the maximum of AmountX can only be 1

	// decrease Total Score based on AmountX
	TotalScore -= DefenceScoreArray[AmountX];

	//increase Total Score based on AmountO
	TotalScore += AttackScoreArray[AmountO];
	TotalScore += TempScore;

	return TotalScore;
}

int AI::AttackScore_MainDiagonalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TempScore = 0;
	int TotalScore = 0;
	int AmountX = 0; // human is X chessman
	int AmountO = 0; // computer is O chessman

	// browse from current cell in the rightdownward direction
	// browse 5 consecutive cell     
	for (int i = 1; i <= 5 && currRow + i < SizeofBoard && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow + i][currCol + i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow + i][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// browse from current cell in the leftupward direction                   
	for (int i = 1; i <= 5 && currRow - i >= 0 && currCol - i >= 0; i++)
	{
		if (pBoard[currRow - i][currCol - i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow - i][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// if be prevented in 2 heads, the move doesn't have value
	if (AmountX == 2)
		return 0;

	// the maximum of AmountX can only be 1

	// decrease Total Score based on AmountX
	TotalScore -= DefenceScoreArray[AmountX];

	//increase Total Score based on AmountO
	TotalScore += AttackScoreArray[AmountO];
	TotalScore += TempScore;

	return TotalScore;
}

int AI::AttackScore_ExtraDiagonalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TempScore = 0;
	int TotalScore = 0;
	int AmountX = 0; // human is X chessman
	int AmountO = 0; // computer is O chessman

	// browse from current cell in the rightupdownward direction
	// browse 5 consecutive cell     
	for (int i = 1; i <= 5 && currRow - i >= 0 && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow - i][currCol + i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow - i][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// browse from current cell in the leftdownward direction                   
	for (int i = 1; i <= 5 && currRow + i < SizeofBoard && currCol - i >= 0; i++)
	{
		if (pBoard[currRow + i][currCol - i].getChessMan() == 'O')
			AmountO++;
		else if (pBoard[currRow + i][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
			TempScore -= 9;
			break;
		}
		else
			break;
	}

	// if be prevented in 2 heads, the move doesn't have value
	if (AmountX == 2)
		return 0;

	// the maximum of AmountX can only be 1

	// decrease Total Score based on AmountX
	TotalScore -= DefenceScoreArray[AmountX];

	//increase Total Score based on AmountO
	TotalScore += AttackScoreArray[AmountO];
	TotalScore += TempScore;

	return TotalScore;
}

int AI::DefenceScore_VerticalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TotalScore = 0;
	int AmountX = 0;
	int AmountO = 0;
           
	for (int i = 1; i <= 5 && currRow + i < SizeofBoard; i++)
	{
		if (pBoard[currRow + i][currCol].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow + i][currCol].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}
                   
	for (int i = 1; i <= 5 && currRow - i >= 0; i++)
	{
		if (pBoard[currRow - i][currCol].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow - i][currCol].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	if (AmountO == 2)
		return 0;

	TotalScore += DefenceScoreArray[AmountX];

	if (AmountX > 0)
		TotalScore -= AttackScoreArray[AmountO] * 2;

	return TotalScore;
}

int AI::DefenceScore_HorizontalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TotalScore = 0;
	int AmountX = 0;
	int AmountO = 0;

	for (int i = 1; i <= 5 && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow][currCol + i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	for (int i = 1; i <= 5 && currCol - i >= 0; i++)
	{
		if (pBoard[currRow][currCol - i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	if (AmountO == 2)
		return 0;

	TotalScore += DefenceScoreArray[AmountX];

	if (AmountX > 0)
		TotalScore -= AttackScoreArray[AmountO] * 2;

	return TotalScore;
}

int AI::DefenceScore_MainDiagonalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TotalScore = 0;
	int AmountX = 0;
	int AmountO = 0;

	for (int i = 1; i <= 5 && currRow + i < SizeofBoard && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow + i][currCol + i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow + i][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	for (int i = 1; i <= 5 && currRow - i >= 0 && currCol - i >= 0; i++)
	{
		if (pBoard[currRow - i][currCol - i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow - i][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	if (AmountO == 2)
		return 0;

	TotalScore += DefenceScoreArray[AmountX];

	if (AmountX > 0)
		TotalScore -= AttackScoreArray[AmountO] * 2;

	return TotalScore;
}

int AI::DefenceScore_ExtraDiagonalBrowse(CellofBoard** pBoard, int SizeofBoard, int currRow, int currCol) {
	int TotalScore = 0;
	int AmountX = 0;
	int AmountO = 0;

	for (int i = 1; i <= 5 && currRow - i >= 0 && currCol + i < SizeofBoard; i++)
	{
		if (pBoard[currRow - i][currCol + i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow - i][currCol + i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	for (int i = 1; i <= 5 && currRow + i < SizeofBoard && currCol - i >= 0; i++)
	{
		if (pBoard[currRow + i][currCol - i].getChessMan() == 'O')
		{
			AmountO++;
			break;
		}
		else if (pBoard[currRow + i][currCol - i].getChessMan() == 'X')
		{
			AmountX++;
		}
		else
			break;
	}

	if (AmountO == 2)
		return 0;

	TotalScore += DefenceScoreArray[AmountX];

	if (AmountX > 0)
		TotalScore -= AttackScoreArray[AmountO] * 2;

	return TotalScore;
}

void AI::findBestMove(CellofBoard** pBoard, int SizeofBoard) {
	int MaxScore = 0;

	for (int i = 0; i < SizeofBoard; i++)
	{
		for (int j = 0; j < SizeofBoard; j++)
		{
			// browse cells which are empty
			// find the Attack Score and the Defence Score
			if (pBoard[i][j].getChessMan() == ' ')
			{
				int AttackScore = AttackScore_VerticalBrowse(pBoard, SizeofBoard, i, j) + AttackScore_HorizontalBrowse(pBoard, SizeofBoard, i, j) + AttackScore_MainDiagonalBrowse(pBoard, SizeofBoard, i, j) + AttackScore_ExtraDiagonalBrowse(pBoard, SizeofBoard, i, j);
				int DefenceScore = DefenceScore_VerticalBrowse(pBoard, SizeofBoard, i, j) + DefenceScore_HorizontalBrowse(pBoard, SizeofBoard, i, j) + DefenceScore_MainDiagonalBrowse(pBoard, SizeofBoard, i, j) + DefenceScore_ExtraDiagonalBrowse(pBoard, SizeofBoard, i, j);
				
				// get temporary score by comparing Attack Score and Defence Score
				int TempScore = AttackScore > DefenceScore ? AttackScore : DefenceScore;
				
				// get Max Score
				if (TempScore > MaxScore)
				{
					MaxScore = TempScore;
					this->BestRow = i;
					this->BestCol = j;
				}
			}
		}
	}
}

void AI::Go(CellofBoard** &pBoard, int& NumberOfChessManO, int NumberOfChessManX, int ColorO) {
	if (NumberOfChessManX== 0) {
		Graphics::gotoXY(pBoard[11][11].getX() + 2, pBoard[11][11].getY() + 1);
		pBoard[11][11].setChessMan('O');
	}
	else {
		Graphics::gotoXY(pBoard[BestRow][BestCol].getX() + 2, pBoard[BestRow][BestCol].getY() + 1);
		pBoard[BestRow][BestCol].setChessMan('O');
	}

	Graphics::SetColor(ColorO);
	printf_s("O");
	
	NumberOfChessManO++;
	Graphics::gotoXY(Graphics::ConsoleScreenColumns - 14, 21);
	cout << NumberOfChessManO << "  ";
}