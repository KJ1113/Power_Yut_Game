#pragma once
#pragma warning(disable: 4819)
#include "TCP_Network.h"
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
	int team = 0; // 현재 진행중인 팀, 턴
	
	int redTeamScore;
	int blueTeamScore;
	int server_or_client; // 네트워크 연결시 0 (서버) 또는 1 (클라이언트) 로 설정됨
	int select_Mal_Idx = -1;

	int yut_num; // 윷
	int yut_ratio_arr[15] = { 0,0,1,1,1,1,2,2,2,2,3,3,3,4 };

	bool killed_possible = false; // 매턴 말을 잡았는지 아닌지 체크
	bool move_possible = false; // 이동 가능한지 체크
	

	AI ai; // 킹공지능
	string IP; // IP 주소
	Board board; // 말판
	Player player[2]; // 플레이어
	TCP_Network tcp_net; // 네트워크 접속
	IOhandler iohandler; // 입출력 매니저

public:

	void start_Game(); // 메인화면 실행
	int getScore(int team); // 말 이동후 점수 계산
	int get_Do_Gae_Girl_Yut_Mo(); // 도개걸윷모 랜덤생성
	
	void play_Single_Mode(bool AImode); // 싱글플레이 & AI 모드 실행
	void play_Multi_Mode(); // 멀티플레이 실행
	void play_AIvsAI_Mode(); // 이스터에그. AI 끼리 붙음

	void run_Game_Process(bool AImode); // 공통된 게임 진행 코드
	void run_Next_Team(); // 다음팀으로 변경, 윷 또는 모로 나오면 안넘어감
	void run_Move_Mal(int team, int select_Mal_Idx, bool AImode); // 이동위치가 결정후, 말들을 움직임.
	
	void init_Game();
	void init_Network();
	void init_Player(int size); // 최초 실행시 플레이어 말 번호 초기화

	int select_Mal(int team); // 이동하고 싶은 말선택, int 로 말 번호를 반환함
	int select_Yut(bool AImode); // 말선택 UI, 입력 기능 , 파라미터로 ai 유무검사

	bool check_End_Game();// 게임 종료 체크
	void provide_BoardUI(); // 보드 상황, 점수 UI 제공
	 

	Game_Manager();
	~Game_Manager();
};