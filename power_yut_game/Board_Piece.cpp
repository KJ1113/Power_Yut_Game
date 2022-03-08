#include "Board_Piece.h"

bool Board_Piece::getIsMove(){
	return this->isMove;
}
Mal* Board_Piece::getMalPoint(){
	return mal;
}
void Board_Piece::setIsMove(bool input) {
	this->isMove = input;
}
void Board_Piece::setMal(Mal* tmp){
	this->mal = tmp;
}

void Board_Piece::disConnectPoint(Mal* tmp){
	tmp->setPos(-1,-1);
	if (tmp->getPointChild() != NULL) {
		disConnectPoint(tmp->getPointChild());
	}
	tmp->setChild(NULL);
	tmp->setIsChild(false); // 모두 자식없음으로 처리
}

void Board_Piece::connectPoint(Mal* tmp , Mal *child) {
	if (tmp->getPointChild() == NULL) {
		tmp->setChild(child);
		child->setIsChild(true);
		child->setPos(tmp->getY(), tmp->getX());
	}
	else {
		connectPoint(tmp->getPointChild(), child);
	}
}
void Board_Piece::linkedPoint(Mal * child){

	if (mal != NULL) { // 해당위치에 mal (말)이 있을때.
		if (mal->getTeam() == child-> getTeam()) { // 같은 팀일때
			if (mal->getPointChild() == NULL) {
				mal->setChild(child);
				child->setIsChild(true);
				mal->getPointChild()->setPos(mal->getY(),mal->getX());
			}
			else {
				connectPoint(mal->getPointChild(), child);
			}
		}
		else { // 다른 팀일때
			Mal* tmp_point = this->mal;
			mal = child;
			disConnectPoint(tmp_point);
		}
	}
	else {
		mal = child;
	}
}
Board_Piece::Board_Piece() {
	mal = NULL;
}

Board_Piece::~Board_Piece(){

}