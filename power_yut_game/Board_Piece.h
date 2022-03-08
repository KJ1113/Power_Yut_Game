#pragma once
#include "Mal.h"
#include <iostream>

class Board_Piece {
private:
	bool isMove;
	Mal *mal;

public:

	bool getIsMove();
	Mal* getMalPoint();

	void connectPoint(Mal* tmp, Mal* m);
	void linkedPoint(Mal* m);
	void disConnectPoint(Mal* m);
	void setMal(Mal* tmp);
	void setIsMove(bool input);

	Board_Piece();
	~Board_Piece();
};