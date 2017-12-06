#pragma once
#include "Piece.h"
#include <iostream>
#define BOARD_LENGTH 8
class Piece;
class Board
{
public:
	Board(std::string board);
	Piece* _PieceBoard[BOARD_LENGTH][BOARD_LENGTH];
private:
	Piece* CreatePiece(char type, int x, int y);

};