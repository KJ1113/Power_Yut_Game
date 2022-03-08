#pragma once
#include <iostream>
#include <windows.h>
#include "Board.h"
#include "Player.h"
using namespace std;

class IOhandler {

public :
	// Input
	int StartMenu();
	int selectMal(Player& p);
	int selectMove(Mal &mal, Board& board ,pair<int, int> move_point);
	int selectAIMal(Player& p , int num);
	int selectAIMove(Mal& mal, Board& board, pair<int, int> move_point);

	// Output
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

	void textcolor(int foreground, int background);
};
