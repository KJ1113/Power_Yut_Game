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
	tmp->setIsChild(false); // ��� �ڽľ������� ó��
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

	if (mal != NULL) { // �ش���ġ�� mal (��)�� ������.
		if (mal->getTeam() == child-> getTeam()) { // ���� ���϶�
			if (mal->getPointChild() == NULL) {
				mal->setChild(child);
				child->setIsChild(true);
				mal->getPointChild()->setPos(mal->getY(),mal->getX());
			}
			else {
				connectPoint(mal->getPointChild(), child);
			}
		}
		else { // �ٸ� ���϶�
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