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
	int team; // 현재 진행중인 팀, 턴
	int yut_num; // 윷
	int redTeamScore;
	int blueTeamScore;


	IOhandler iohandler; // 입출력 매니저
	Board board; // 말판
	Player player[2]; // 플레이어
	AI ai; // 킹공지능


public:
	
	int getScore(int team); // 말 이동후 점수 계산

	void runPlay(); // 메인화면 실행
	void singlePlay(); // 싱글플레이 실행
	void AIPlay(); // 인공지능 플레이 

	int select_Mal(int team); // 이동하고 싶은 말선택, int 로 말 번호를 반환함
	int select_Mal_AI(int team, int mal_num); //AI 말선택
	int select_Yut(bool AImode); // 말선택 UI, 입력 기능 , 파라미터로 ai 유무검사


	bool move_Mal(int team , int select_Mal_Idx , bool AImode); // 이동위치가 결정되면, 이동유무를 판별하여 알려줌
	bool endGame_Check();

	int do_Gae_Girl_Yut_Mo(); // 도개걸윷모 랜덤생성
	void playerInit(int size); // 최초 실행시 플레이어 말 번호 초기화

	Game_Manager();
	~Game_Manager();
};