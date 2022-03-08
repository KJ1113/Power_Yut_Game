#include "Player.h"

void Player::setTeam(int input){
	team = input;
}

void Player::setScore(int input){
	score += input;
}

int Player::getTeam(){
	return team;
}

int Player::getScore(){
	return score;
}

Mal &Player::getMal(int index){
	return mal[index];
}

Player::Player(){

}

Player::~Player(){
}
