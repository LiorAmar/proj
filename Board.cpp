#include "Board.h"

Board::Board(std::string board)
{
	if (board.length() >= BOARD_LENGTH*BOARD_LENGTH)
	{
		for (int i = 0; i < BOARD_LENGTH; i++)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				_PieceBoard[i][j] = CreatePiece(board[(i*BOARD_LENGTH) + j],i,j);
			}
		}
	}
}
Piece* Board::CreatePiece(char type,int x,int y)
{
	Piece *t=nullptr;
	char type_l= tolower(type);
	switch (type_l)
	{
	case 'k':
		t=new Piece(this, type, (x*BOARD_LENGTH) + y);
		//King() //need to 
		break;
	case 'q':
		//Quinn() //need to 
		break;
	case 'r':
		//King() //need to 
		break;
	case '#':
		t = new Piece(this, type, (x*BOARD_LENGTH) + y);
		break;
	}
	return t;
}

