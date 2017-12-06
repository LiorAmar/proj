#include "Board.h"
#include "Piece.h"

int main()
{
	Board t("k###################k######K############################################");
	int f = t._PieceBoard[0][0]->moveV(5, 5, 0);
	if (f == 0) t._PieceBoard[0][0]->move(5, 0);
	std::cout << t._PieceBoard[0][0]->moveV(5, 5, 0) << std::endl;
	std::cout << t._PieceBoard[0][0]->moveO(5, 0, 5) << std::endl;
	std::cout << t._PieceBoard[0][0]->moveD(5, 3, 3) << std::endl;
	std::cout << t._PieceBoard[2][5]->moveND(5, 4, 4) << std::endl;



	return 0;
}