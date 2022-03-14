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
	tmp->setPos(-1,-1); // 원래 자리로 되돌리고 
	if (tmp->getPointChild() != NULL) { // 자식이 있다면
		disConnectPoint(tmp->getPointChild()); // 또 자식이 있다면
		tmp->setChild(NULL); // 자식없음
		tmp->setIsChild(false); // 모두 자식없음으로 처리
	}
	this->setMal(NULL);
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
int Board_Piece::linkedPoint(Mal * input_mal){ // 상대편 말을 잡으면 1을 반환, 아니면 0을 반환

	if (mal != NULL) { // 해당위치에 mal (말)이 있을때.

		if (mal->getTeam() == input_mal-> getTeam()) { // 같은 팀일때

			if (mal->getPointChild() == NULL) { // 자식이 없는 자리로 들어왔을때

				mal->setChild(input_mal);
				input_mal->setIsChild(true);
				mal->getPointChild()->setPos(mal->getY(),mal->getX());
			}
			else {
				connectPoint(mal->getPointChild(), input_mal);
			}

			return 0;
		}
		else { // 다른 팀일때
			Mal* tmp_point = this->mal;
			disConnectPoint(tmp_point);
			this->mal = input_mal;

			return 1;
		}
	}
	else {
		mal = input_mal;
		return 0;
	}
}
Board_Piece::Board_Piece() {
	mal = NULL;
}

Board_Piece::~Board_Piece(){

}