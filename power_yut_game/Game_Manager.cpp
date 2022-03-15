#include "Game_Manager.h"
void Game_Manager::start_Game() {
	while (true) {
		system("cls");
		int num = iohandler.selectMode();
		bool stop = false;


		switch (num) {

		case 1:
			system("cls");
			play_Single_Mode(false);
			break;

		case 2:
			system("cls");
			play_Multi_Mode();
			break;

		case 3:
			system("cls");
			play_Single_Mode(true);
			break;

		case 4:
			system("cls");
			iohandler.ouputMessage("������ �����մϴ�.");
			stop = true;
			break;

		default:
			iohandler.ouputMessage("�߸� �Է��Ͽ����ϴ�.");
		}

		init_Player(3);
		this->board.init_Piece();

		if (stop) break;
	}
}



void Game_Manager::play_Single_Mode(bool AImode) {
	while (true) {

		system("cls");

		if (!AImode) { // AI ��� �ƴ϶��
			run_Game_Process(false);
		}
		else {
			if (team == 0) {
				run_Game_Process(false);
			}
			else {
				run_Game_Process(true);
			}
		}

		if (check_End_Game()) {
			Sleep(1000);
			break; // �¸� ���� �˻�
		}

		iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // ���ͷ� ������
		run_Next_Team();
	}
}

void Game_Manager::run_Game_Process(bool AImode) {
	yut_num = select_Yut(AImode);
	while (true) { // �� ���� -> �� �̵� ���μ���

		if (!AImode) {
			select_Mal_Idx = select_Mal(team); // �� ����
		}
		else {
			Sleep(250);
			select_Mal_Idx = ai.getSelectMal(player[1], board, yut_num) - 1;
			Sleep(250);
		}

		run_Move_Mal(team, select_Mal_Idx, AImode);
		if (move_possible) break;
	}
}

int Game_Manager::select_Yut(bool AImode) {
	int time = 0;
	while (true) {
		system("cls");
		iohandler.showYutUI(team, time);
		Sleep(500);

		if (AImode) {
			if (time == 4) return get_Do_Gae_Girl_Yut_Mo();
		}
		else {
			if (_kbhit()) {
				if (_getch() == '\r') return get_Do_Gae_Girl_Yut_Mo();
			}
		}
		time++;
		if (time == 5) time = 0;
	}
}

void Game_Manager::play_Multi_Mode() {
	system("cls");

	while (true) {
		init_Network();
		if (server_or_client == 1 || server_or_client == 0) {
			iohandler.ouputMessage("���Ἲ��.. ������� ���۵˴ϴ�.");
			Sleep(500);
			break;
		}
		else if (server_or_client == -1) {
			iohandler.ouputMessage("���� ����..");
			Sleep(500);
			break;
		}
		else {
			continue;
		}
	}

	while (true) {
		system("cls");
		if (team == server_or_client) {
			run_Game_Process(false);

			if (check_End_Game()) {
				Sleep(1000);
				break; // �¸� ���� �˻�
			}

			iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // ���ͷ� ������
			run_Next_Team();
			tcp_net.send_message(team, yut_num, select_Mal_Idx);
		}
		else {
			// string message �ް� ������� ó��
			provide_BoardUI();

			tcp_net.recv_message();
			yut_num = tcp_net.getYutNumMessage();
			select_Mal_Idx = tcp_net.getMalIdxMessage();

			run_Move_Mal(team, select_Mal_Idx, true); // ai ��忡�� �̿��ߴ� �Լ��� ����

			if (check_End_Game()) {
				Sleep(1000);
				break; // �¸� ���� �˻�
			}
			team = tcp_net.getNextTeamMessage(); // ������(��) ����
		}
	}
	tcp_net.disConnect(); // ���� ����
}

void Game_Manager::run_Move_Mal(int team, int select_Mal_Idx , bool AImode) {
	system("cls");

	int cY = player[team].getMal(select_Mal_Idx).getY();
	int cX = player[team].getMal(select_Mal_Idx).getX();
	
	pair<int, int> move_point = board.getMovePoint(cY, cX, yut_num);
	
	if (!AImode) {
		this->move_possible = iohandler.selectMove(player[team].getMal(select_Mal_Idx), board, move_point);
	} 
	else {
		this->move_possible = iohandler.selectAIMove(player[team].getMal(select_Mal_Idx), board, move_point);
	} 


	if (this->move_possible) { // �ٽ� ����

		Mal* point_mal = NULL;
		int nY = move_point.first;
		int nX = move_point.second;

		if (cY == -1 && cX == -1) { // ���� �ۿ� ������
			point_mal = &player[team].getMal(select_Mal_Idx);
		}
		else { // �������� �ִ� ��
			point_mal = board.getBoardPiece(cY, cX).getMalPoint();
			board.getBoardPiece(cY, cX).setMal(NULL);
		}

		point_mal->setPos(nY, nX);
		this-> killed_possible = board.getBoardPiece(nY, nX).linkedPoint(point_mal);

		if (nY == 10 && nX == 10) {
			board.endPoint_Init(&player[team].getMal(select_Mal_Idx)); // ������ġ�� �����Ѵٸ�?
			iohandler.ouputMessage("�̵����Դϴ�..");
		}
		Sleep(800);
	}
}


bool Game_Manager::check_End_Game() {
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

void Game_Manager::provide_BoardUI(){
	system("cls");
	iohandler.showScore(redTeamScore, blueTeamScore);
	iohandler.showBoard(board, team, yut_num);
}

void Game_Manager::init_Network(){
	server_or_client = iohandler.selectServer();
	if (server_or_client == 0) {
		tcp_net.serverModeOn();
	}
	else if(server_or_client == 1){
		iohandler.ouputMessage("���� IP �ּҸ� �Է����ּ���");
		tcp_net.setIP(iohandler.inputMessage());
		tcp_net.clientModeOn();
	}
	else if (server_or_client == -1) {
		iohandler.ouputMessage("���� �մϴ�.");
	}
	else {
		iohandler.ouputMessage("�߸� �Է��ϼ̽��ϴ�.");
	}
}

int Game_Manager::select_Mal(int team) {
	provide_BoardUI();
	iohandler.showMalList(player[team]);
	return iohandler.selectMal(player[team]); // �̵��ϰ���� �� ����
}

int Game_Manager::get_Do_Gae_Girl_Yut_Mo() {
	srand((unsigned int)time(NULL)); // seed ������ ���簪 �ο�
	return yut_ratio_arr[rand() % 15];
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

void Game_Manager::init_Player(int size) {
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

void Game_Manager::run_Next_Team() {
	if (yut_num == 4 || yut_num == 3 || killed_possible == true) {
		if (killed_possible == true) {
			iohandler.ouputMessage("������ϱ� �ѹ��� !!");
		} 
		else {
			iohandler.ouputMessage("�� �Ǵ� ���� ���ͼ� �ѹ��� !!");
		}
		Sleep(1000);
	}
	else {
		team = (team + 1) % 2;
	}
}

Game_Manager::Game_Manager() {
	init_Player(3);
}

Game_Manager::~Game_Manager() {

}