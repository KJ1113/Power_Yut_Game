#include "Game_Manager.h"


void Game_Manager::runPlay() {
	while (true) {
		int num = iohandler.StartMenu();
		bool stop = false;

		switch (num) {
		case 1:
			system("cls");
			singlePlay();
			break;

		case 2:
			system("cls");
			cout << "���� �ȸ�������~!! Enter key �� ������ ���� ȭ������ ���ư��ϴ�." << endl;
			break;
		case 3:
			system("cls");
			AIPlay();
			break;
		case 4:
			system("cls");
			cout << "������ �����մϴ�." << endl;
			stop = true;
			break;
		default:
			cout << "�߸� �Է��Ͽ����ϴ�." << endl;
		}
		if (stop) break;
	}
}

void Game_Manager::singlePlay() {
	team = 0; // �� & �� 
	while (true) {
		system("cls");
		yut_num = select_Yut(false);

		while (true) { // �� ���� -> �� �̵� ���μ���
			int select_Mal_Idx = select_Mal(team); // �� ����
			bool move_possible = move_Mal(team, select_Mal_Idx,false); // �� �̵�
			if (move_possible) break;
		}

		if (endGame_Check()) break; // �¸� ���� �˻�

		
		while (true){
			char iChar;
			system("cls");
			iohandler.showScore(redTeamScore, blueTeamScore);
			iohandler.showBoard(board, team, yut_num);
			cout << "Enter key�� ������ �������� ����˴ϴ�.." << endl;
			if (_kbhit()) {
				iChar = _getch();
				if (iChar == '\r') break;
			}
			Sleep(1000);
		}

		if (yut_num == 4 || yut_num == 3) {
			cout << "�� �Ǵ� ���� ���ͼ� �ѹ��� !!" << endl;
			team = team;
			Sleep(1000);
		}
		else {
			team = (team + 1) % 2;
		}
	}
}

void Game_Manager::AIPlay() {
	team = 0; // �� & �� 
	while (true) {
		system("cls");
		
		int mal_num;
		int select_Mal_Idx;
		bool move_possible;

		if (team == 0) { // RED ���̸� ����� ����
			yut_num = select_Yut(false);
			while (true) { // �� ���� -> �� �̵� ���μ���
				select_Mal_Idx = select_Mal(team); // �� ����
				move_possible = move_Mal(team, select_Mal_Idx, false); // �� �̵�
				if (move_possible) break;
			}
		}
		else { // BLUE ���̸� AI�� ����
			yut_num = select_Yut(true);

			while (true) {
				mal_num = ai.getSelectMal(player[1], board, yut_num);
				Sleep(2000);
				select_Mal_Idx = select_Mal_AI(team, mal_num);

				Sleep(250);
				move_possible = move_Mal(team, select_Mal_Idx, true); // �� �̵�
				Sleep(500);
				if (move_possible) break;
			}
		}

		if (endGame_Check()) break; // �¸� ���� �˻�

		while (true) {
			char iChar;
			system("cls");
			iohandler.showScore(redTeamScore, blueTeamScore);
			iohandler.showBoard(board, team, yut_num);
			cout << "Enter key�� ������ �������� ����˴ϴ�.." << endl;
			if (_kbhit()) {
				iChar = _getch();
				if (iChar == '\r') break;
			}
			Sleep(1000);
		}


		if (yut_num == 4 || yut_num == 3) {
			cout << "�� �Ǵ� ���� ���ͼ� �ѹ��� !!" << endl;
			team = team;
			Sleep(1000);
		}
		else {
			team = (team + 1) % 2;
		}
	}
}

int Game_Manager::select_Mal(int team) {
	system("cls");
	iohandler.showScore(redTeamScore, blueTeamScore);
	iohandler.showBoard(board, team, yut_num);
	iohandler.showMalList(player[team]);
	return iohandler.selectMal(player[team]); // �̵��ϰ���� �� ����
}

int Game_Manager::select_Mal_AI(int team , int mal_num) {
	system("cls");
	iohandler.showScore(redTeamScore, blueTeamScore);
	iohandler.showBoard(board, team, yut_num);
	iohandler.showMalList(player[team]);
	return iohandler.selectAIMal(player[team], mal_num);
}



int Game_Manager::select_Yut(bool AImode) {

	if (AImode) {
		int time = 0;
		while (true) {
			system("cls");
			int iChar;
			int yut_num = do_Gae_Girl_Yut_Mo();
			iohandler.showYutUI(team, yut_num);
			Sleep(250);

			if (time == 3) return do_Gae_Girl_Yut_Mo();
			else time++; 
		}
	}
	else {
		while (true) {
			system("cls");
			int iChar;
			int yut_num = do_Gae_Girl_Yut_Mo();
			iohandler.showYutUI(team, yut_num);

			if (_kbhit()) {
				iChar = _getch();
				if (iChar == '\r') return do_Gae_Girl_Yut_Mo();
			}
			Sleep(200);
		}
	}
}

bool Game_Manager::move_Mal(int team, int select_Mal_Idx , bool AImode) {
	system("cls");
	int cY = player[team].getMal(select_Mal_Idx).getY();
	int cX = player[team].getMal(select_Mal_Idx).getX();
	int move_possible = 0;
	pair<int, int> move_point = board.getMovePoint(cY, cX, yut_num);
	
	if (AImode) move_possible = iohandler.selectAIMove(player[team].getMal(select_Mal_Idx), board, move_point);
	else move_possible = iohandler.selectMove(player[team].getMal(select_Mal_Idx), board, move_point);


	if (move_possible == 0) { // �ٽ� ����
		return false;
	}
	else { // �� ���ÿϷ�. �̵�.
		int nY = move_point.first;
		int nX = move_point.second;
		Mal* point_mal = NULL;

		if (cY == -1 && cX == -1) { // ���� �ۿ� ������
			point_mal = &player[team].getMal(select_Mal_Idx);
		}
		else { // �������� �ִ� ��
			point_mal = board.getBoardPiece(cY, cX).getMalPoint();
			board.getBoardPiece(cY, cX).setMal(NULL);
		}

		point_mal->setPos(nY, nX);
		board.getBoardPiece(nY, nX).linkedPoint(point_mal);

		if (nY == 10 && nX == 10) board.lastPiece_check(&player[team].getMal(select_Mal_Idx)); // ������ġ�� �����Ѵٸ�?
		cout << "�̵����Դϴ�.." << endl;
		Sleep(500);
		return true;
	}
}


bool Game_Manager::endGame_Check() {
	redTeamScore = getScore(0);
	blueTeamScore = getScore(1);

	if (redTeamScore == 3 || blueTeamScore == 3) { // �¸� ���� �˻�
		if (redTeamScore == 3) {
			cout << "Red ���� �¸� �Դϴ�!!" << endl;
		}
		else {
			cout << "Blue ���� �¸� �Դϴ�!!" << endl;
		}
		return true;
	}
	return false;
}


int Game_Manager::do_Gae_Girl_Yut_Mo() {
	srand((unsigned int)time(NULL)); // seed ������ ���簪 �ο�
	return rand() % 5;
}

int Game_Manager::getScore(int team) {
	int score = 0;
	for (int i = 0; i < 3; i++) {
		if (player[team].getMal(i).getlife() == false) {
			score++;
		}
	}
	return score;
}

void Game_Manager::playerInit(int size) {
	redTeamScore = 0;
	blueTeamScore = 0;

	player[0].setTeam(1);
	player[1].setTeam(2);

	for (int i = 0; i < size; i++) { // �÷��̾� ������ �ʱ�ȭ
		player[0].getMal(i).setPos(-1, -1);
		player[0].getMal(i).setNum(i + 1);
		player[0].getMal(i).setTeam(1);

		player[1].getMal(i).setPos(-1, -1);
		player[1].getMal(i).setNum(i + 1);
		player[1].getMal(i).setTeam(2);
	}
}

Game_Manager::Game_Manager() {
	playerInit(3);
}

Game_Manager::~Game_Manager() {

}