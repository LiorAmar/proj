#pragma once
#include "Piece.h"

class Rook:public Piece
{
public:
	Rook(Board *board, char type, int index);
	int NumOfSteps(int funcIndex,int x,int y);
protected:

private:

};