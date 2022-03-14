#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Board.h"
#include "Player.h"
using namespace std;

class IOhandler {

public :
	// Input
	string inputMessage();
	int StartMenu();
	int selectMal(Player& p);
	int selectMove(Mal &mal, Board& board ,pair<int, int> move_point);
	int selectAIMal(Player& p , int num);
	int selectAIMove(Mal& mal, Board& board, pair<int, int> move_point);
	int selectServer();
	void nextTurn(int redTeamScore, int blueTeamScore, Board& board, int team, int yut_num);

	// Output
	void ouputMessage(string output);
	void showBoard(Board& board, int turn, int yut);
	void showTurn(int turn);
	void showMalList(Player &p);
	void showYut(int num);
	void showScore(int num1 , int num2);
	void showYutOnBoard(int team , int line ,int yut);
	void showYutUI(int team ,int num);
	void showMal(Mal *mal_point);
	void showMovePos(Mal& mal, Board& board, pair<int, int> move_point);
	void showBoardPiece(int i , int j);
	void showSelectPossible(Player& p);

	// Color
	void textColorInit(int foreground, int background);
};
