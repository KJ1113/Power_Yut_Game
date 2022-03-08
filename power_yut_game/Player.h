#pragma once
#include "Board.h"
class Player{

private:
	int team;
	int score;
	Mal mal[3];

public:
	void setTeam(int input);
	void setScore(int input);
	int getTeam();
	int getScore();
	Mal &getMal(int index);

	Player();
	~Player();
};

