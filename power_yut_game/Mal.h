#pragma once
#include <iostream>
using namespace std;

class Mal
{
private:
	int team; // ��
	int number; //��ȣ
	int y, x; // y x ���ǿ��� ��ǥ
	bool isChild; //������ �ڽ����� �ƴ���
	bool life; // ��������
	Mal *child; // �ڽ�

public:

	void setTeam(int input);
	void setPos(int inputY, int inputX);
	void setIsChild(bool input);
	void setLife(bool input);
	void setChild(Mal *input);
	void setNum(int input);

	int getNum();
	int getTeam();
	int getY();
	int getX();
	int getChild_Cnt();

	bool getIsChild();
	bool getlife();
	Mal *getPointChild();

	Mal();
	~Mal();
};