#pragma once
#include "Board.h"
#include "Player.h"
#include "IOhandler.h"
#include "AI.h"
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

class Game_Manager{
private:
	int team; // ���� �������� ��, ��
	int yut_num; // ��
	int redTeamScore;
	int blueTeamScore;


	IOhandler iohandler; // ����� �Ŵ���
	Board board; // ����
	Player player[2]; // �÷��̾�
	AI ai; // ŷ������


public:
	int do_Gae_Girl_Yut_Mo(); // ���������� ��������
	int getScore(int team); // �� �̵��� ���� ���

	
	void playerInit(int size); // ���� ����� �÷��̾� �� ��ȣ �ʱ�ȭ
	void runPlay(); // ����ȭ�� ����
	void singlePlay(); // �̱��÷��� ����
	void AIPlay();

	int select_Mal(int team); // �̵��ϰ� ���� ������, int �� �� ��ȣ�� ��ȯ��
	int select_AIMal(int team, int mal_num);
	int select_Yut(bool AIselect); // ������ UI, �Է� ��� , �Ķ���ͷ� ai �����˻�


	bool move_Mal(int team , int select_Mal_Idx , bool AImode); // �̵���ġ�� �����Ǹ�, �̵������� �Ǻ��Ͽ� �˷���
	bool endGame_Check();

	Game_Manager();
	~Game_Manager();
};