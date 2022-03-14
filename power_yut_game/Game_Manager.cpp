#include "Game_Manager.h"
void Game_Manager::runPlay() {
	while (true) {
		system("cls");
		int num = iohandler.startMenu();
		bool stop = false;

		switch (num) {
		case 1:
			system("cls");
			singlePlay();
			break;
		case 2:
			system("cls");
			multiPlay();
			break;
		case 3:
			system("cls");
			AIPlay();
			break;
		case 4:
			system("cls");
			iohandler.ouputMessage("������ �����մϴ�.");
			stop = true;
			break;
		default:
			iohandler.ouputMessage("�߸� �Է��Ͽ����ϴ�.");
		}

		if (stop) break;
	}
}

void Game_Manager::multiPlay() {
	system("cls");
	init_Network();

	while (true) {
		system("cls");
		if (team == server_or_client) {
			playProcess(false);
			if (endGame_Check()) break; // �¸� ���� �˻�
			iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // ���ͷ� ������
			nextTeam();

			// ����
			tcp_net.send_message(team,yut_num, select_Mal_Idx);
		}
		else {
			// string �ް� ������� ó��
			provide_GameUI();

			string recv_message = tcp_net.recv_message();
			yut_num = recv_message[1] - '0';
			select_Mal_Idx = recv_message[2] - '0';
			move_Mal(team, select_Mal_Idx, true);
			team = recv_message[0] - '0';

			provide_GameUI();
			Sleep(1500);
			if (endGame_Check()) break;
		}
	}

	tcp_net.disConnect(); // ���� ����
}


void Game_Manager::singlePlay() {
	while (true) {
		system("cls");
		playProcess(false);
		if (endGame_Check()) break; // �¸� ���� �˻�
		iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // ���ͷ� ������
		nextTeam();
	}
}

void Game_Manager::AIPlay() {
	while (true) {
		system("cls");
		int mal_num;
		if (team == 0) { // RED ���̸� ����� ����
			playProcess(false);
		}
		else { // BLUE ���̸� AI�� ����
			yut_num = select_Yut(true);
			while (true) {
				mal_num = ai.getSelectMal(player[1], board, yut_num);
				Sleep(1500);
				select_Mal_Idx = select_Mal_AI(team, mal_num);
				Sleep(250);
				move_possible = move_Mal(team, select_Mal_Idx, true); // �� �̵�
				Sleep(250);
				if (move_possible) break;
			}
		}

		if (endGame_Check()) break; // �¸� ���� �˻�
		iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // ���ͷ� ������
		nextTeam();
	}
}

int Game_Manager::select_Yut(bool AImode) {
	int time = 0;
	while (true) {
		system("cls");
		int yut_num = do_Gae_Girl_Yut_Mo();
		iohandler.showYutUI(team, yut_num);
		Sleep(200);

		if (AImode) {
			if (time == 3) return do_Gae_Girl_Yut_Mo();
			else time++;
		}
		else {
			if (_kbhit()) {
				int iChar = _getch();
				if (iChar == '\r') return do_Gae_Girl_Yut_Mo();
			}
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
		iohandler.ouputMessage("�̵����Դϴ�..");
		Sleep(500);
		return true; // �̵� ������ �˷���
	}
}


bool Game_Manager::endGame_Check() {
	redTeamScore = getScore(0);
	blueTeamScore = getScore(1);

	if (redTeamScore == 3 || blueTeamScore == 3) { // �¸� ���� �˻�
		if (redTeamScore == 3) {
			iohandler.ouputMessage("Red ���� �¸� �Դϴ�!!");
		}
		else {
			iohandler.ouputMessage("Blue ���� �¸� �Դϴ�!!");
		} 

		return true;
	}

	return false;
}

void Game_Manager::provide_GameUI(){
	system("cls");
	iohandler.showScore(redTeamScore, blueTeamScore);
	iohandler.showBoard(board, team, yut_num);
}

void Game_Manager::init_Network(){
	server_or_client = iohandler.selectServer();
	if (server_or_client == 0) {
		tcp_net.serverModeOn();
	}
	else {
		iohandler.ouputMessage("���� IP �ּҸ� �Է����ּ���");
		string IP = iohandler.inputMessage();
		tcp_net.setIP(IP);
		tcp_net.clientModeOn();
	}
	iohandler.ouputMessage("���Ἲ��.. ������� ���۵˴ϴ�.");
	Sleep(1500);
}

int Game_Manager::select_Mal(int team) {
	provide_GameUI();
	iohandler.showMalList(player[team]);
	return iohandler.selectMal(player[team]); // �̵��ϰ���� �� ����
}

int Game_Manager::select_Mal_AI(int team, int mal_num) {
	provide_GameUI();
	iohandler.showMalList(player[team]);
	return iohandler.selectAIMal(player[team], mal_num);
}

void Game_Manager::playProcess(bool AImode){
	yut_num = select_Yut(AImode);
	while (true) { // �� ���� -> �� �̵� ���μ���
		select_Mal_Idx = select_Mal(team); // �� ����
		move_possible = move_Mal(team, select_Mal_Idx, AImode); // �� �̵�
		if (move_possible) break;
	}
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

void Game_Manager::nextTeam() {
	if (yut_num == 4 || yut_num == 3) {

		iohandler.ouputMessage("�� �Ǵ� ���� ���ͼ� �ѹ��� !!");
		team = team;
		Sleep(1000);
	}
	else {
		team = (team + 1) % 2;
	}
}

Game_Manager::Game_Manager() {
	team = 0;
	select_Mal_Idx = -1;
	move_possible = false;
	playerInit(3);
}

Game_Manager::~Game_Manager() {

}