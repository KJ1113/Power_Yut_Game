#pragma once
#pragma warning(disable: 4819)
#include <iostream>
using namespace std;

class Mal
{
private:
	int team; // 팀
	int number; //번호
	int y, x; // y x 말판에서 좌표
	bool isChild; //본인이 자식인지 아닌지
	bool life; // 생존여부
	Mal *child; // 자식

public:

	int getNum();
	int getTeam();
	int getY();
	int getX();
	int getChild_Cnt();

	void setTeam(int input);
	void setPos(int inputY, int inputX);
	void setIsChild(bool input);
	void setLife(bool input);
	void setChild(Mal *input);
	void setNum(int input);


	bool getIsChild();
	bool getlife();
	Mal *getPointChild();

	Mal();
	~Mal();
};