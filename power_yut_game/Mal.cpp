#include "Mal.h"


int Mal::getChild_Cnt(){
	if (child == NULL) {
		return 0;
	}
	return 1 + child->getChild_Cnt();
}

int Mal::getNum() {
	return number;
}

int Mal::getTeam() {
	return team;
}

int Mal::getY() {
	return y;
}

int Mal::getX() {
	return x;
}

bool Mal::getIsChild(){
	return isChild;
}

bool Mal::getlife(){
	return life;
}

Mal* Mal::getPointChild(){
	return child;
}

void Mal::setTeam(int input){
	this->team = input;
}

void Mal::setPos(int inputY , int inputX){
	y = inputY;
	x = inputX;
}

void Mal::setIsChild(bool input){
	isChild = input;
}

void Mal::setLife(bool input){
	life = input;
}

void Mal::setChild(Mal *input){
	 this->child =input;
}

void Mal::setNum(int input){
	number = input;
}

Mal::Mal() {
	isChild = false; //�ڽĿ���
	life = true; // ��������
	child = NULL;
}

Mal::~Mal() {
	delete child;
}
