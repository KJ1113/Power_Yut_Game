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
			iohandler.ouputMessage("게임을 종료합니다.");
			stop = true;
			break;
		default:
			iohandler.ouputMessage("잘못 입력하였습니다.");
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
			if (endGame_Check()) break; // 승리 조건 검사
			iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // 엔터로 다음턴
			nextTeam();

			// 전송
			tcp_net.send_message(team,yut_num, select_Mal_Idx);
		}
		else {
			// string 받고 순서대로 처리
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

	tcp_net.disConnect(); // 연결 해제
}


void Game_Manager::singlePlay() {
	while (true) {
		system("cls");
		playProcess(false);
		if (endGame_Check()) break; // 승리 조건 검사
		iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // 엔터로 다음턴
		nextTeam();
	}
}

void Game_Manager::AIPlay() {
	while (true) {
		system("cls");
		int mal_num;
		if (team == 0) { // RED 팀이면 사람이 선택
			playProcess(false);
		}
		else { // BLUE 팀이면 AI가 선택
			yut_num = select_Yut(true);
			while (true) {
				mal_num = ai.getSelectMal(player[1], board, yut_num);
				Sleep(1500);
				select_Mal_Idx = select_Mal_AI(team, mal_num);
				Sleep(250);
				move_possible = move_Mal(team, select_Mal_Idx, true); // 말 이동
				Sleep(250);
				if (move_possible) break;
			}
		}

		if (endGame_Check()) break; // 승리 조건 검사
		iohandler.nextTurn(redTeamScore, blueTeamScore, board, team, yut_num); // 엔터로 다음턴
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


	if (move_possible == 0) { // 다시 선택
		return false;
	}
	else { // 말 선택완료. 이동.
		int nY = move_point.first;
		int nX = move_point.second;
		Mal* point_mal = NULL;

		if (cY == -1 && cX == -1) { // 보드 밖에 있을때
			point_mal = &player[team].getMal(select_Mal_Idx);
		}
		else { // 보드위에 있는 말
			point_mal = board.getBoardPiece(cY, cX).getMalPoint();
			board.getBoardPiece(cY, cX).setMal(NULL);
		}

		point_mal->setPos(nY, nX);
		board.getBoardPiece(nY, nX).linkedPoint(point_mal);

		if (nY == 10 && nX == 10) board.lastPiece_check(&player[team].getMal(select_Mal_Idx)); // 종료위치에 도달한다면?
		iohandler.ouputMessage("이동중입니다..");
		Sleep(500);
		return true; // 이동 성공을 알려줌
	}
}


bool Game_Manager::endGame_Check() {
	redTeamScore = getScore(0);
	blueTeamScore = getScore(1);

	if (redTeamScore == 3 || blueTeamScore == 3) { // 승리 조건 검사
		if (redTeamScore == 3) {
			iohandler.ouputMessage("Red 팀의 승리 입니다!!");
		}
		else {
			iohandler.ouputMessage("Blue 팀의 승리 입니다!!");
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
		iohandler.ouputMessage("서버 IP 주소를 입력해주세요");
		string IP = iohandler.inputMessage();
		tcp_net.setIP(IP);
		tcp_net.clientModeOn();
	}
	iohandler.ouputMessage("연결성공.. 곧게임이 시작됩니다.");
	Sleep(1500);
}

int Game_Manager::select_Mal(int team) {
	provide_GameUI();
	iohandler.showMalList(player[team]);
	return iohandler.selectMal(player[team]); // 이동하고싶은 말 선택
}

int Game_Manager::select_Mal_AI(int team, int mal_num) {
	provide_GameUI();
	iohandler.showMalList(player[team]);
	return iohandler.selectAIMal(player[team], mal_num);
}

void Game_Manager::playProcess(bool AImode){
	yut_num = select_Yut(AImode);
	while (true) { // 말 선택 -> 말 이동 프로세스
		select_Mal_Idx = select_Mal(team); // 말 선택
		move_possible = move_Mal(team, select_Mal_Idx, AImode); // 말 이동
		if (move_possible) break;
	}
}

int Game_Manager::do_Gae_Girl_Yut_Mo() {
	srand((unsigned int)time(NULL)); // seed 값으로 현재값 부여
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

	for (int i = 0; i < size; i++) { // 플레이어 말들을 초기화
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

		iohandler.ouputMessage("모 또는 윷이 나와서 한번더 !!");
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