#include "Piece.h"

int Piece::moveV(int steps,int X,int Y)
{
	int leagal=0;
	if (getType() != EMPTY)
	{
		if (Y == getY())
		{
			if (X - getX() <= steps)
			{
				for (int i = getX() + 1; i <= X; i++)
				{
					if (_board->_PieceBoard[Y][i]->getType() != EMPTY)
					{
						if (_board->_PieceBoard[Y][i]->getTeam() == _team)
						{
							leagal = PLAYER_IN_DEST;
							break;
						}
						else if (i != X - getX())//not the wanted place
						{
							leagal = ILEAGAL_MOVE;
						}
					}
				}
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}
		}
		else
		{
			leagal = ILEAGAL_MOVE;
		}
	}
	else
	{
		leagal = NO_PLAYER_SOURCE;
	}
	return leagal;
}
int Piece::moveO(int steps, int X, int Y)
{
	int leagal = 0;
	if (getType() != EMPTY)
	{
		if (getX() == X)
		{
			if (Y - getY() <= steps)
			{
				for (int i = getY() + 1; i <= Y; i++)
				{
					if (_board->_PieceBoard[i][X]->getType() != EMPTY)
					{
						if (_board->_PieceBoard[i][X]->getTeam() == _team)
						{
							leagal = PLAYER_IN_DEST;
							break;
						}
						else if (i != Y - getY())//not the wanted place
						{
							leagal = ILEAGAL_MOVE;
						}
					}
				}
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}
		}
		else
		{
			leagal = ILEAGAL_MOVE;
		}
		
	}
	else
	{
		leagal = NO_PLAYER_SOURCE;
	}
	return leagal;
}
int Piece::getY()
{
	return (_index / BOARD_LENGTH);
}

int Piece::getX()
{
	return (_index%BOARD_LENGTH);
}

int Piece::getTeam()
{
	return _team;
}

char Piece::getType()
{
	return _type;
}

Piece::Piece(Board *board, char type, int index)
{
	_board =board;

	_type = type;
	_index = index;
	if (type != EMPTY)
	{
		if (type < 'a')
		{
			_team = WHITE;
		}
		else
		{
			_team = BLACK;
		}
	}
	else
	{
		_team = NO_TEAM;
	}
}

void Piece::setBoard(Board *board)
{
	_board = board;
}

int Piece::moveD(int steps, int X, int Y)
{
	int leagal = 0;
	if (getType() != EMPTY)
	{
		if (X != getX() && Y != getY())
		{
			if (X - getX() == Y - getY())
			{
				if (Y - getY() <= steps)
				{
					int j = getY() + 1;
					for (int i = getX() + 1; i <= X && j <= Y; i++, j++)
					{

						if (_board->_PieceBoard[j][i]->getType() != EMPTY)
						{
							if (_board->_PieceBoard[j][i]->getTeam() == _team)
							{
								leagal = PLAYER_IN_DEST;
								break;
							}
							else if (i != X - getX())//not the wanted place
							{
								leagal = ILEAGAL_MOVE;
								break;
							}
						}
					}
				}
				else
				{
					leagal = ILEAGAL_MOVE;
				}
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}

		}
		else //no move
		{
			if (X == getX() && Y == getY())
			{
				leagal = SAME_PLACE;
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}
		}
	}
	else
	{
		leagal = NO_PLAYER_SOURCE;
	}

	return leagal;
}





int Piece::moveND(int steps, int X, int Y)
{
	int leagal = 0;
	if (getType() != EMPTY)
	{
		if (X != getX() && Y != getY())
		{
			if (getX() - X == Y - getY())
			{
				if (Y - getY() <= steps)
				{
					int j = getY() + 1;
					for (int i = getX() - 1; i >= X && j <= Y; i--, j++)
					{

						if (_board->_PieceBoard[j][i]->getType() != EMPTY)
						{
							if (_board->_PieceBoard[j][i]->getTeam() == _team)
							{
								leagal = PLAYER_IN_DEST;
								break;
							}
							else if (i != X - getX())//not the wanted place
							{
								leagal = ILEAGAL_MOVE;
								break;
							}
						}
					}
				}
				else
				{
					leagal = ILEAGAL_MOVE;
				}
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}

		}
		else //no move
		{
			if (X == getX() && Y == getY())
			{
				leagal = SAME_PLACE;
			}
			else
			{
				leagal = ILEAGAL_MOVE;
			}
		}
	}
	else
	{
		leagal = NO_PLAYER_SOURCE;
	}
	return leagal;
 }

void Piece::move(int x, int y)
{
	Piece* t = new Piece(_board, EMPTY, _index);
	delete _board->_PieceBoard[y][x];
	_board->_PieceBoard[y][x] = this;
	_board->_PieceBoard[getY()][getX()]=t;
	_index = y*BOARD_LENGTH + x;
}
