#pragma once
#pragma warning(disable: 4819)
#include "Board_Piece.h"

class Board
{
private:
	Board_Piece bp[11][11];
public:
	Board_Piece &getBoardPiece(int y , int x);
	pair<int, int> getMovePoint(int y ,int x, int yut_num);

	void init_Piece();
	void endPoint_Init(Mal* point_mal); // (첫번째&마지막 말판 초기화)

	Board();
	~Board();
};
