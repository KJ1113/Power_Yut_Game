#include "IOhandler.h"
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

const int MAX_SIZE = 11;
int IOhandler::StartMenu(){
	int num = 0;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "l  #      #  #     #  ######      #####   #            #       #      #   l" << endl;
	cout << "l   #   #    #     #    #         #    #  #           # #       #   #     l" << endl;
	cout << "l     #      #     #    #         #####   #          #   #        #       l" << endl;
	cout << "l     #       #   #     #         #       #         #######       #       l" << endl;
	cout << "l     #        ###      #         #       #######  #       #      #       l" << endl;
	cout << "---------------------------------------------------------------------------" << endl;

	cout << "               ------------------------------------------                   " << endl;
	cout << "               |             1. 싱글 플레이             |                   " << endl;
	cout << "               |             2. 멀티 플레이             |                   " << endl;
	cout << "               |             3.   AI 플레이             |                   " << endl;
	cout << "               |             4.    종료                 |                   " << endl;
	cout << "               ------------------------------------------                   " << endl;
	cout << " 숫자로 입력해주세요 : ";
	cin >> num;
	return num;
}

void IOhandler::showYutUI(int team, int yut_num){
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	cout << "\n\n\n\n\n\n" << endl;
	if (team == 0) {
		textcolor(LIGHTRED, BLACK);
		cout << "                               RED";
		textcolor(WHITE, BLACK);
	}
	else {
		textcolor(BLUE, BLACK);
		cout << "                               BLUE";
		textcolor(WHITE, BLACK);
	}
	cout << " 팀의 차례 입니다. Enter Key로 윷을 던지세요!" << endl;
	cout << "\n";

	cout << "                                        ┌──┐  ┌──┐  ┌──┐  ┌──┐" << endl;

	if (yut_num == 0) {
		cout << "                                        │  │  │ X│  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │ X│  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │ X│  │ X│  │ X│" << endl;
	}
	else if (yut_num == 1) {
		cout << "                                        │  │  │  │  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │ X│  │ X│" << endl;
	}
	else if (yut_num == 2) {
		cout << "                                        │  │  │  │  │  │  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │ X│" << endl;
	}
	else if (yut_num == 3) {
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
	}
	else if (yut_num == 4) {
		cout << "                                        │ X│  │ X│  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │ X│  │ X│  │ X│  │ X│" << endl;
		cout << "                                        │  │  │  │  │  │  │  │" << endl;
		cout << "                                        │ X│  │ X│  │ X│  │ X│" << endl;
	}
	else {

	}
	cout << "                                        └──┘  └──┘  └──┘  └──┘" << endl;
	cout << endl;

}
void IOhandler::showSelectPossible(Player& p) {
	cout << "선택 가능한 말 ( ";
	for (int i = 0; i < 3; i++) {
		Mal* point_mal = &p.getMal(i);
		if (point_mal->getlife() && point_mal->getIsChild() == false) {
			cout << i + 1 << " ";
		}
	}
	cout << ")" << endl;
}
int IOhandler::selectMal(Player& p){
	int output = 0 ;
	showSelectPossible(p);

	while (true) {
		cout << "이동시킬 말을 선택해주세요 (숫자로):";
		cin >> output;
		if (output < 0 || p.getMal(output - 1).getlife() == false || p.getMal(output - 1).getIsChild() == true) {
			cout << "잘못 입력하셨습니다." << endl;
		}
		else {
			return (output - 1);
		}
	}
	return output;
}
int IOhandler::selectAIMal(Player& p, int num) {
	int output = num;
	cout << "이동시킬 말을 선택해주세요 (숫자로):";
	return output-1;
}




void IOhandler::showBoard(Board& board, int turn, int yut) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = true; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (board.getBoardPiece(i, j).getIsMove()) {
				Mal* mal_point = board.getBoardPiece(i, j).getMalPoint();
				if (mal_point != NULL && mal_point->getlife()) {
					if (mal_point->getTeam() == 1) {
						textcolor(LIGHTRED, BLACK);
						showMal(mal_point);
						textcolor(WHITE, BLACK);
					}
					else {
						textcolor(BLUE, BLACK);
						showMal(mal_point);
						textcolor(WHITE, BLACK);
					}
				}
				else {
					showBoardPiece(i,j);
				}
			}
			else {
				cout << " \t";
			}
		}
		showYutOnBoard(turn,i,yut);
	}
}

int IOhandler::selectMove(Mal& mal , Board& board ,pair<int, int> move_point){

	showMovePos(mal, board,  move_point);
	while (true) {
		int input;
		cout << "이동하시겠습니까 ? . (뒤로가기 : 0, 이동하기 : 1) : ";
		cin >> input;
		if (input == 0) { 
			return 0;
		}
		else if (input == 1) {
			return 1;
		}
		else {
			cout << "다시 입력해주세요."<<endl;
		}
	}
	return 0;
}


int IOhandler::selectAIMove(Mal& mal, Board& board, pair<int, int> move_point){

	showMovePos(mal, board, move_point);
	int time = 0;
	cout << "AI가 선택중입니다.." <<endl;
	while (true) {
		Sleep(700);
		if (time == 3) break;
		time++;
	}
	return 1;
}

int IOhandler::selectServer(){
	int input = 0 ;
	cout << "방장은 0, 참여자는 1 를 입력해주세요. (종료 : -1) : ";
	cin >> input;

	while (true) {
		if (input == 0) {
			return 0;
		}
		else if (input == 1) {
			return 1;
		}
		else if (input == -1) {
			return -1;
		}
		else {
			cout << "잘못 입력하셨습니다. " << endl;
		}
	}
}

void IOhandler::showTurn(int turn){
	if (turn == 0) {
		textcolor(LIGHTRED, BLACK);
		cout << "RED";
		textcolor(WHITE, BLACK);
	}
	else {
		textcolor(BLUE, BLACK);
		cout << "BLUE";
		textcolor(WHITE, BLACK);
	}
	cout << " 팀의 턴 입니다." << endl;
}

void IOhandler::showMalList(Player& p){
	int filedOnCnt = 0;
	cout << "┌───────────────────────────────┐" << endl;
	cout << "│\t" ;
	for (int i = 0; i < 3 ; i++) {
		//cout << p.getMal(i).getY() << endl;
		if (p.getMal(i).getlife() == true && (p.getMal(i).getY() == -1 && p.getMal(i).getX() == -1)) {
			if (p.getMal(i).getNum() == 1)cout << "①\t";
			if (p.getMal(i).getNum() == 2)cout << "②\t";
			if (p.getMal(i).getNum() == 3)cout << "③\t";
		}
		else {
			cout << "\t";
		}
	}
	cout << "│ <- 말판에 올라가지 않은 말" << endl;
	cout << "└───────────────────────────────┘"<< endl;
}

void IOhandler::showYut(int num){
	cout << "윷 결과: ";
	if (num == 0) {
		cout << "도 입니다." << endl;
	}
	else if (num == 1) {
		cout << "개 입니다." << endl;
	}
	else if (num == 2) {
		cout << "걸 입니다." << endl;
	}
	else if (num == 3) {
		cout << "윷 입니다." << endl;
	}
	else if (num == 4) {
		cout << "모 입니다." << endl;
	}
	else {
		cout << "???." << endl;
	}
}
void IOhandler::showMal(Mal* mal_point) {
	int childCnt = mal_point->getChild_Cnt();
	if (mal_point->getNum() == 1) {
		if (childCnt == 0) {
			cout << "①\t";
		}
		else {
			cout << "①+" << childCnt << "\t";
		}
	}
	else if (mal_point->getNum() == 2) {
		if (childCnt == 0) {
			cout << "②\t";
		}
		else {
			cout << "②+" << childCnt << "\t";
		}
	}
	else if (mal_point->getNum() == 3) {
		if (childCnt == 0) {
			cout << "③\t";
		}
		else {
			cout << "③+" << childCnt << "\t";
		}
	}
}
void IOhandler::showMovePos(Mal& mal, Board& board, pair<int, int> move_point){

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (board.getBoardPiece(i, j).getIsMove()) {
				if (move_point.first == i && move_point.second == j) {
					textcolor(YELLOW, BLACK);
					cout << "★\t";
					textcolor(WHITE, BLACK);
				}
				else {
					showBoardPiece(i, j);
				}
			}
			else {
				cout << " \t";
			}
		}
		cout << endl;
		cout << endl;
	}
	cout << mal.getNum() << " 번 말을 선택하였습니다. 이동위치는 ★ 로 표시됩니다." << endl;
}
void IOhandler::showBoardPiece(int i, int j) {

	if (i == 0 && j == 0) {
		cout << "◎\t";
	}
	else if (i == 0 && j == 10) {
		cout << "◎\t";
	}
	else if (i == 10 && j == 0) {
		cout << "◎\t";
	}
	else if (i == 10 && j == 10) {
		cout << "◎\t";
	}
	else if (i == 5 && j == 5) {
		cout << "◎\t";
	}
	else {
		cout << "o\t";
	}
}
void IOhandler::showScore(int num1, int num2){
	cout << "                                RED: " << num1 <<  "    BLUE: " << num2 << endl;
}

void IOhandler::showYutOnBoard(int team , int line , int yut){

	//┌', '─', '┐', '└', '─', '┘', '│'를 선택해서 복사
	if (line == 2) {
		cout << "  "; showTurn(team);
		cout << endl;
		cout << endl;
	}
	else if (line == 3) {
		cout << "┌──┐  ┌──┐  ┌──┐  ┌──┐" << endl;
		if (yut == 0)     cout << "                                                                                        │  │  │ X│  │ X│  │ X│" << endl;
		else if (yut == 1)cout << "                                                                                        │  │  │  │  │ X│  │ X│" << endl;
		else if (yut == 2)cout << "                                                                                        │  │  │  │  │  │  │ X│" << endl;
		else if (yut == 3)cout << "                                                                                        │  │  │  │  │  │  │  │" << endl;
		else if (yut == 4)cout << "                                                                                        │ X│  │ X│  │ X│  │ X│" << endl;

	}
	else if (line == 4) {
		cout << "│  │  │  │  │  │  │  │" << endl;
		if (yut == 0)     cout << "                                                                                        │  │  │ X│  │ X│  │ X│" << endl;
		else if (yut == 1)cout << "                                                                                        │  │  │  │  │ X│  │ X│" << endl;
		else if (yut == 2)cout << "                                                                                        │  │  │  │  │  │  │ X│" << endl;
		else if (yut == 3)cout << "                                                                                        │  │  │  │  │  │  │  │" << endl;
		else if (yut == 4)cout << "                                                                                        │ X│  │ X│  │ X│  │ X│" << endl;
	}
	else if (line == 5) {
		cout << "│  │  │  │  │  │  │  │" << endl;
		if (yut == 0)     cout << "                                                                                        │  │  │ X│  │ X│  │ X│" << endl;
		else if (yut == 1)cout << "                                                                                        │  │  │  │  │ X│  │ X│" << endl;
		else if (yut == 2)cout << "                                                                                        │  │  │  │  │  │  │ X│" << endl;
		else if (yut == 3)cout << "                                                                                        │  │  │  │  │  │  │  │" << endl;
		else if (yut == 4)cout << "                                                                                        │ X│  │ X│  │ X│  │ X│" << endl;
	}
	else if (line == 6) {
		cout << "│  │  │  │  │  │  │  │" << endl;
		if (yut == 0)     cout << "                                                                                        │  │  │ X│  │ X│  │ X│" << endl;
		else if (yut == 1)cout << "                                                                                        │  │  │  │  │ X│  │ X│" << endl;
		else if (yut == 2)cout << "                                                                                        │  │  │  │  │  │  │ X│" << endl;
		else if (yut == 3)cout << "                                                                                        │  │  │  │  │  │  │  │" << endl;
		else if (yut == 4)cout << "                                                                                        │ X│  │ X│  │ X│  │ X│" << endl;
	}
	else if (line == 7) {
		cout << "└──┘  └──┘  └──┘  └──┘" << endl;
		cout << endl;
	}
	else if (line == 8) {
		cout << "  "; showYut(yut);
	}
	else {
		cout << endl;
		cout << endl;
	}
}

void IOhandler::textcolor(int foreground, int background){
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
