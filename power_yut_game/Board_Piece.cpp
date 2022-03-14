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
	tmp->setPos(-1,-1); // ���� �ڸ��� �ǵ����� 
	if (tmp->getPointChild() != NULL) { // �ڽ��� �ִٸ�
		disConnectPoint(tmp->getPointChild()); // �� �ڽ��� �ִٸ�
		tmp->setChild(NULL); // �ڽľ���
		tmp->setIsChild(false); // ��� �ڽľ������� ó��
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
int Board_Piece::linkedPoint(Mal * input_mal){ // ����� ���� ������ 1�� ��ȯ, �ƴϸ� 0�� ��ȯ

	if (mal != NULL) { // �ش���ġ�� mal (��)�� ������.

		if (mal->getTeam() == input_mal-> getTeam()) { // ���� ���϶�

			if (mal->getPointChild() == NULL) { // �ڽ��� ���� �ڸ��� ��������

				mal->setChild(input_mal);
				input_mal->setIsChild(true);
				mal->getPointChild()->setPos(mal->getY(),mal->getX());
			}
			else {
				connectPoint(mal->getPointChild(), input_mal);
			}

			return 0;
		}
		else { // �ٸ� ���϶�
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