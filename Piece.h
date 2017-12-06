#pragma once

#include <vector>
#include "Board.h"

#define CHESS_WIN 1
#define NO_PLAYER_SOURCE 2
#define PLAYER_IN_DEST 3
#define CHESS_LOOSE 4
#define WRONG_INDEX 5
#define ILEAGAL_MOVE 6
#define SAME_PLACE 7
#define EMPTY '#'
#define WHITE 0
#define BLACK 1
#define NO_TEAM 2
#define BOARD_LENGTH 8

#define X_AXIS 0
#define Y_AXIS 1
#define DIAGONAL 2
#define NEG_DIAGONAL 3

class Board;
class Piece
{
public:
	Piece(Board *board, char type, int index);
	int getTeam();
	char getType();
	//protected
	virtual int moveV(int steps, int X, int Y);//x axis
	virtual int moveO(int steps, int X, int Y);//Y axis
	virtual int moveD(int steps, int X, int Y);//DIAGONAL
	virtual int moveND(int steps, int X, int Y);//the oposite DIAGONAL
	void move(int x, int y);
	void setBoard(Board *board);
	//~Piece();
protected:
	

	int getY();
	int getX();


private:
	int _team;
	char _type;
	int _index;
	Board * _board;

};