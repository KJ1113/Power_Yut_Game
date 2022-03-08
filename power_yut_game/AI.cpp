#include "AI.h"

int AI::getSelectMal(Player &player, Board &board ,int yut_num){
	vector <Mal*> list;
	vector <pair<int,int>> val_list;


	for (int i = 0; i < 3; i++) { // ���ð����� ��
		Mal* point_mal = &player.getMal(i);
		if (point_mal->getlife() && point_mal->getIsChild() == false) { // ���� ����ְ�, �ڽ��� ���ٸ�
			

			list.push_back(point_mal);
			val_list.push_back({ point_mal->getNum(),0});

		}
		// ����ġ�� ��� �ٰ��ΰ�....? 
		// ���� �����ϸ� �̵��� �������
	}


	int max_num = 1;
	int max_val = 0;
	for (int idx = 0; idx < list.size(); idx++) {
		int move_val = getMoveValue( list[idx], board, yut_num); // �̵����̿� ���� ����ġ
		int child_val = getChildValue(list[idx]);
		int team_val = getTeamValue(list[idx], board, yut_num);

		val_list[idx].second += move_val;
		val_list[idx].second += child_val;
		val_list[idx].second += team_val;



		if (max_val <= val_list[idx].second) {
			max_val = val_list[idx].second;
			max_num = val_list[idx].first;
		}
	}
	return max_num;
}



int AI::getMoveValue(Mal *mal, Board& board,int yut_num) {
	pair<int,int> p = board.getMovePoint(mal->getY(), mal->getX(), yut_num);

	int i = p.first;
	int j = p.second;

	if (i == 0 && j == 0) return 20;
	else if (i == 0 && j == 2) return 9;
	else if (i == 0 && j == 4) return 8;
	else if (i == 0 && j == 6) return 7;
	else if (i == 0 && j == 8) return 6;
	else if (i == 0 && j == 10) return 20;

	else if (i == 2 && j == 0) return 11;
	else if (i == 2 && j == 2) return 16;
	else if (i == 2 && j == 8) return 16;
	else if (i == 2 && j == 10) return 4;

	else if (i == 4 && j == 0) return 12;
	else if (i == 4 && j == 4) return 17;
	else if (i == 4 && j == 6) return 17;
	else if (i == 4 && j == 10) return 3;

	else if (i == 5 && j == 5) return 20;

	else if (i == 6 && j == 0) return 13;
	else if (i == 6 && j == 4) return 16;
	else if (i == 6 && j == 6) return 18;
	else if (i == 6 && j == 10) return 2;

	else if (i == 8 && j == 0) return 14;
	else if (i == 8 && j == 2) return 16;
	else if (i == 8 && j == 8) return 19;
	else if (i == 8 && j == 10) return 1;

	else if (i == 10 && j == 0) return 20;
	else if (i == 10 && j == 2) return 16;
	else if (i == 10 && j == 4) return 17;
	else if (i == 10 && j == 6) return 18;
	else if (i == 10 && j == 8) return 19;
	else if (i == 10 && j == 10) return 20;

	else return 0;
}

int AI::getChildValue(Mal* mal){

	if (mal->getChild_Cnt() == 0) {
		return 0;
	}
	else {
		return 5 * mal->getChild_Cnt();
	}
}

int AI::getTeamValue(Mal* mal, Board& board, int yut_num){
	pair<int, int> p = board.getMovePoint(mal->getY(), mal->getX(), yut_num);

	int i = p.first;
	int j = p.second;

	Board_Piece bp = board.getBoardPiece(i, j);

	if (bp.getMalPoint() != NULL) {
		if (mal->getTeam() != bp.getMalPoint()->getTeam()) { // �ٸ� �� ���� �ִٸ�
			cout << "����� ���� ��� ���� ����" << endl;
			return 20;
		}
		else { // ���� �� ���� �ִٸ�
			cout << "���� �� ���� ��ġ�� ���� ����" << endl;
			return 10;
		}
	}
	else {
		return 0;
	}
}

