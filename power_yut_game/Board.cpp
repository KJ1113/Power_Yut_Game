#include "Board.h"

Board_Piece &Board::getBoardPiece(int y, int x){
	return bp[y][x];
}
pair<int, int> Board::getMovePoint(int y, int x, int yut_num){
	pair<int, int> output;
	if (y == -1 && x == -1) {
		if (yut_num == 0) output.first = 8, output.second = 10 ;
		else if (yut_num == 1) output.first = 6, output.second = 10;
		else if (yut_num == 2) output.first = 4, output.second = 10;
		else if (yut_num == 3) output.first = 2, output.second = 10;
		else if (yut_num == 4) output.first = 0, output.second = 10;
		else;
	}
	else if (y == 10 && x == 10) {
		if (yut_num == 0) output.first = 8, output.second = 10;
		else if (yut_num == 1) output.first = 6, output.second = 10;
		else if (yut_num == 2) output.first = 4, output.second = 10;
		else if (yut_num == 3) output.first = 2, output.second = 10;
		else if (yut_num == 4) output.first = 0, output.second = 10;
		else;
	}
	else if (y == 8 && x == 10) {
		if (yut_num == 0) output.first = 6, output.second = 10;
		else if (yut_num == 1) output.first = 4, output.second = 10;
		else if (yut_num == 2) output.first = 2, output.second = 10;
		else if (yut_num == 3) output.first = 0, output.second = 10;
		else if (yut_num == 4) output.first = 0, output.second = 8;
		else;
	}
	else if (y == 6 && x == 10) {
		if (yut_num == 0) output.first = 4, output.second = 10;
		else if (yut_num == 1) output.first = 2, output.second = 10;
		else if (yut_num == 2) output.first = 0, output.second = 10;
		else if (yut_num == 3) output.first = 0, output.second = 8;
		else if (yut_num == 4) output.first = 0, output.second = 6;
		else;
	}
	else if (y == 4 && x == 10) {
		if (yut_num == 0) output.first = 2, output.second = 10;
		else if (yut_num == 1) output.first = 0, output.second = 10;
		else if (yut_num == 2) output.first = 0, output.second = 8;
		else if (yut_num == 3) output.first = 0, output.second = 6;
		else if (yut_num == 4) output.first = 0, output.second = 4;
		else;
	}
	else if (y == 2 && x == 10) {
		if (yut_num == 0) output.first = 0, output.second = 10;
		else if (yut_num == 1) output.first = 0, output.second = 8;
		else if (yut_num == 2) output.first = 0, output.second = 6;
		else if (yut_num == 3) output.first = 0, output.second = 4;
		else if (yut_num == 4) output.first = 0, output.second = 2;
		else;
	}
	else if (y == 0 && x == 10) {
		if (yut_num == 0) output.first = 2, output.second = 8;
		else if (yut_num == 1) output.first = 4, output.second = 6;
		else if (yut_num == 2) output.first = 5, output.second = 5;
		else if (yut_num == 3) output.first = 6, output.second = 4;
		else if (yut_num == 4) output.first = 8, output.second = 2;
		else;
	} // 
	else if (y == 0 && x == 8) {
		if (yut_num == 0) output.first = 0, output.second = 6;
		else if (yut_num == 1) output.first = 0, output.second = 4;
		else if (yut_num == 2) output.first = 0, output.second = 2;
		else if (yut_num == 3) output.first = 0, output.second = 0;
		else if (yut_num == 4) output.first = 2, output.second = 0;
		else;
	}
	else if (y == 0 && x == 6) {
		if (yut_num == 0) output.first = 0, output.second = 4;
		else if (yut_num == 1) output.first = 0, output.second = 2;
		else if (yut_num == 2) output.first = 0, output.second = 0;
		else if (yut_num == 3) output.first = 2, output.second = 0;
		else if (yut_num == 4) output.first = 4, output.second = 0;
		else;
	}
	else if (y == 0 && x == 4) {
		if (yut_num == 0) output.first = 0, output.second = 2;
		else if (yut_num == 1) output.first = 0, output.second = 0;
		else if (yut_num == 2) output.first = 2, output.second = 0;
		else if (yut_num == 3) output.first = 4, output.second = 0;
		else if (yut_num == 4) output.first = 6, output.second = 0;
		else;
	}
	else if (y == 0 && x == 2) {
		if (yut_num == 0) output.first = 0, output.second = 0;
		else if (yut_num == 1) output.first = 2, output.second = 0;
		else if (yut_num == 2) output.first = 4, output.second = 0;
		else if (yut_num == 3) output.first = 6, output.second = 0;
		else if (yut_num == 4) output.first = 8, output.second = 0;
		else;
	}
	else if (y == 0 && x == 0) {
		if (yut_num == 0) output.first = 2, output.second = 2;
		else if (yut_num == 1) output.first = 4, output.second = 4;
		else if (yut_num == 2) output.first = 5, output.second = 5;
		else if (yut_num == 3) output.first = 6, output.second = 6;
		else if (yut_num == 4) output.first = 8, output.second = 8;
		else;
	}
	else if (y == 2 && x == 0) {
		if (yut_num == 0) output.first = 4, output.second = 0;
		else if (yut_num == 1) output.first = 6, output.second = 0;
		else if (yut_num == 2) output.first = 8, output.second = 0;
		else if (yut_num == 3) output.first = 10, output.second = 0;
		else if (yut_num == 4) output.first = 10, output.second = 2;
		else;
	}
	else if (y == 4 && x == 0) {
		if (yut_num == 0) output.first = 6, output.second = 0;
		else if (yut_num == 1) output.first = 8, output.second = 0;
		else if (yut_num == 2) output.first = 10, output.second = 0;
		else if (yut_num == 3) output.first = 10, output.second = 2;
		else if (yut_num == 4) output.first = 10, output.second = 4;
		else;
	}
	else if (y == 6 && x == 0) {
		if (yut_num == 0) output.first = 8, output.second = 0;
		else if (yut_num == 1) output.first = 10, output.second = 0;
		else if (yut_num == 2) output.first = 10, output.second = 2;
		else if (yut_num == 3) output.first = 10, output.second = 4;
		else if (yut_num == 4) output.first = 10, output.second = 6;
		else;
	}
	else if (y == 8 && x == 0) {
		if (yut_num == 0) output.first = 10, output.second = 0;
		else if (yut_num == 1) output.first = 10, output.second = 2;
		else if (yut_num == 2) output.first = 10, output.second = 4;
		else if (yut_num == 3) output.first = 10, output.second = 6;
		else if (yut_num == 4) output.first = 10, output.second = 8;
		else;
	}
	else if (y == 10 && x == 0) {
		if (yut_num == 0) output.first = 10, output.second = 2;
		else if (yut_num == 1) output.first = 10, output.second = 4;
		else if (yut_num == 2) output.first = 10, output.second = 6;
		else if (yut_num == 3) output.first = 10, output.second = 8;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 10 && x == 2) {
		if (yut_num == 0) output.first = 10, output.second = 4;
		else if (yut_num == 1) output.first = 10, output.second = 6;
		else if (yut_num == 2) output.first = 10, output.second = 8;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 10 && x == 4) {
		if (yut_num == 0) output.first = 10, output.second = 6;
		else if (yut_num == 1) output.first = 10, output.second = 8;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 10 && x == 6) {
		if (yut_num == 0) output.first = 10, output.second = 8;
		else if (yut_num == 1) output.first = 10, output.second = 10;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 10 && x == 8) {
		if (yut_num == 0) output.first = 10, output.second = 10;
		else if (yut_num == 1) output.first = 10, output.second = 10;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 2 && x == 2) {
		if (yut_num == 0) output.first = 4, output.second = 4;
		else if (yut_num == 1) output.first = 5, output.second = 5;
		else if (yut_num == 2) output.first = 6, output.second = 6;
		else if (yut_num == 3) output.first = 8, output.second = 8;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 4 && x == 4) {
		if (yut_num == 0) output.first = 5, output.second = 5;
		else if (yut_num == 1) output.first = 6, output.second = 6;
		else if (yut_num == 2) output.first = 8, output.second = 8;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 5 && x == 5) {
		if (yut_num == 0) output.first = 6, output.second = 6;
		else if (yut_num == 1) output.first = 8, output.second = 8;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 6 && x == 6) {
		if (yut_num == 0) output.first = 8, output.second = 8;
		else if (yut_num == 1) output.first = 10, output.second = 10;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}
	else if (y == 8 && x == 8) {
		if (yut_num == 0) output.first = 10, output.second = 10;
		else if (yut_num == 1) output.first = 10, output.second = 10;
		else if (yut_num == 2) output.first = 10, output.second = 10;
		else if (yut_num == 3) output.first = 10, output.second = 10;
		else if (yut_num == 4) output.first = 10, output.second = 10;
		else;
	}

	else if (y == 2 && x == 8) {
		if (yut_num == 0) output.first = 4, output.second = 6;
		else if (yut_num == 1) output.first = 5, output.second = 5;
		else if (yut_num == 2) output.first = 6, output.second = 4;
		else if (yut_num == 3) output.first = 8, output.second = 2;
		else if (yut_num == 4) output.first = 10, output.second = 0;
		else;
	}
	else if (y == 4 && x == 6) {//
		if (yut_num == 0) output.first = 5, output.second = 5;
		else if (yut_num == 1) output.first = 6, output.second = 4;
		else if (yut_num == 2) output.first = 8, output.second = 2;
		else if (yut_num == 3) output.first = 10, output.second = 0;
		else if (yut_num == 4) output.first = 10, output.second = 2;
		else;
	}
	else if (y == 5 && x == 5) {//
		if (yut_num == 0) output.first = 6, output.second = 4;
		else if (yut_num == 1) output.first = 8, output.second = 2;
		else if (yut_num == 2) output.first = 10, output.second = 0;
		else if (yut_num == 3) output.first = 10, output.second = 2;
		else if (yut_num == 4) output.first = 10, output.second = 4;
		else;
	}
	else if (y == 6 && x == 4) {//
		if (yut_num == 0) output.first = 8, output.second = 2;
		else if (yut_num == 1) output.first = 10, output.second = 0;
		else if (yut_num == 2) output.first = 10, output.second = 2;
		else if (yut_num == 3) output.first = 10, output.second = 4;
		else if (yut_num == 4) output.first = 10, output.second = 6;
		else;
	}
	else if (y == 8 && x == 2) {//
		if (yut_num == 0) output.first = 10, output.second = 0;
		else if (yut_num == 1) output.first = 10, output.second = 2;
		else if (yut_num == 2) output.first = 10, output.second = 4;
		else if (yut_num == 3) output.first = 10, output.second = 6;
		else if (yut_num == 4) output.first = 10, output.second = 8;
		else;
	}

	return output;
}

void Board::pieceInit(){
	for (int i = 0; i < 11;i ++) {
		for (int j = 0; j < 11 ;j++) {
			if (i == 0 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 0 && j == 2) bp[i][j].setIsMove(true);
			else if (i == 0 && j == 4) bp[i][j].setIsMove(true);
			else if (i == 0 && j == 6) bp[i][j].setIsMove(true);
			else if (i == 0 && j == 8) bp[i][j].setIsMove(true);
			else if (i == 0 && j == 10) bp[i][j].setIsMove(true);

			else if (i == 2 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 2 && j == 2) bp[i][j].setIsMove(true);
			else if (i == 2 && j == 8) bp[i][j].setIsMove(true);
			else if (i == 2 && j == 10) bp[i][j].setIsMove(true);

			else if (i == 4 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 4 && j == 4) bp[i][j].setIsMove(true);
			else if (i == 4 && j == 6) bp[i][j].setIsMove(true);
			else if (i == 4 && j == 10) bp[i][j].setIsMove(true);

			else if (i == 5 && j == 5) bp[i][j].setIsMove(true);

			else if (i == 6 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 6 && j == 4) bp[i][j].setIsMove(true);
			else if (i == 6 && j == 6) bp[i][j].setIsMove(true);
			else if (i == 6 && j == 10) bp[i][j].setIsMove(true);

			else if (i == 8 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 8 && j == 2) bp[i][j].setIsMove(true);
			else if (i == 8 && j == 8) bp[i][j].setIsMove(true);
			else if (i == 8 && j == 10) bp[i][j].setIsMove(true);

			else if (i == 10 && j == 0) bp[i][j].setIsMove(true);
			else if (i == 10 && j == 2) bp[i][j].setIsMove(true);
			else if (i == 10 && j == 4) bp[i][j].setIsMove(true);
			else if (i == 10 && j == 6) bp[i][j].setIsMove(true);
			else if (i == 10 && j == 8) bp[i][j].setIsMove(true);
			else if (i == 10 && j == 10) bp[i][j].setIsMove(true);

			else bp[i][j].setIsMove(false);
		}
	}
}

void Board::endPoint_Init(Mal* point_mal){
	if (point_mal != NULL) {
		point_mal->setLife(false); // life false Ã³¸®·Î ¸Ê¹ÛÀ¸·Î º¸³¿
		endPoint_Init(point_mal->getPointChild());
		this->getBoardPiece(point_mal->getX(), point_mal->getX()).disConnectPoint(point_mal);
	}
}

Board::Board(){
	pieceInit();
}

Board::~Board(){

}
