#include "AI.h"

int AI::getSelectMal(Player &player, Board &board ,int yut_num){
	vector <Mal*> list;
	for (int i = 0; i < 3; i++) { // 선택가능한 말
		Mal* point_mal = &player.getMal(i);
		if (point_mal->getlife() && point_mal->getIsChild() == false) { // 말이 살아있고, 자식이 없다면
			

			list.push_back(point_mal);

		}
		// 가중치를 어떻게 줄것인가....? 
		// 말만 선택하면 이동은 상관없음
	}


	int max_num = 1;
	int max_val = 0;
	for (int idx = 0; idx < list.size(); idx++) {
		int val = getMoveValue( list[idx], board, yut_num);

		if (max_val <= val) {
			max_val = val;
			max_num = list[idx]->getNum();
		}
	}
	return max_num;
}

int AI::getMoveValue(Mal *mal, Board& board,int yut_num) {
	pair<int,int> p = board.getMovePoint(mal->getY(), mal->getX(), yut_num);


	int i = p.first;
	int j = p.second;


	if (i == 0 && j == 0) return 10;
	else if (i == 0 && j == 2) return 9;
	else if (i == 0 && j == 4) return 8;
	else if (i == 0 && j == 6) return 7;
	else if (i == 0 && j == 8) return 6;
	else if (i == 0 && j == 10) return 5;

	else if (i == 2 && j == 0) return 11;
	else if (i == 2 && j == 2) return 16;
	else if (i == 2 && j == 8) return 16;
	else if (i == 2 && j == 10) return 4;

	else if (i == 4 && j == 0) return 12;
	else if (i == 4 && j == 4) return 17;
	else if (i == 4 && j == 6) return 17;
	else if (i == 4 && j == 10) return 3;

	else if (i == 5 && j == 5) return 18;

	else if (i == 6 && j == 0) return 13;
	else if (i == 6 && j == 4) return 16;
	else if (i == 6 && j == 6) return 18;
	else if (i == 6 && j == 10) return 2;

	else if (i == 8 && j == 0) return 14;
	else if (i == 8 && j == 2) return 16;
	else if (i == 8 && j == 8) return 19;
	else if (i == 8 && j == 10) return 1;

	else if (i == 10 && j == 0) return 15;
	else if (i == 10 && j == 2) return 16;
	else if (i == 10 && j == 4) return 17;
	else if (i == 10 && j == 6) return 18;
	else if (i == 10 && j == 8) return 19;
	else if (i == 10 && j == 10) return 20;

	else return 0;


	return 0;
}
