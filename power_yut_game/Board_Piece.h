#pragma once
#pragma warning(disable: 4819)
#include "Mal.h"
#include <iostream>

class Board_Piece {
private:
	bool isMove;
	Mal *mal;

public:

	bool getIsMove();
	Mal* getMalPoint();

	void setMal(Mal* tmp);
	void setIsMove(bool input);

	int linkedPoint(Mal* m);
	void connectPoint(Mal* tmp, Mal* m);
	void disConnectPoint(Mal* m);
	

	Board_Piece();
	~Board_Piece();
};