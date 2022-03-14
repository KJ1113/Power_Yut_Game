#include "Mal.h"

int Mal::getChild_Cnt(){
	if (child_point == NULL) {
		return 0;
	}
	return 1 + child_point->getChild_Cnt();
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
	return child_point;
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
	 this->child_point =input;
}

void Mal::setNum(int input){
	number = input;
}

Mal::Mal() {
	isChild = false; //자식여부
	life = true; // 생존여부
	child_point = NULL;
}

Mal::~Mal() {
	delete child_point;
}
