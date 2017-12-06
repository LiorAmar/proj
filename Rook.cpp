#include "Rook.h"


Rook::Rook(Board *board, char type, int index):Piece(board,type,index)
{
}


int Rook::NumOfSteps(int funcIndex, int x, int y)
{
	int steps = 0;
	switch (funcIndex)
	{
	case X_AXIS:
	{
		steps = x - getX();
	}
	break;
	case Y_AXIS:
	{
		steps = y - getY();
	}
	break;
	case DIAGONAL:
	{
		steps = 0;
	}
	break;
	case NEG_DIAGONAL:
	{
		steps = 0;
	}
	break;
	}
	return abs(steps);
}
