#pragma once
#pragma warning(disable: 4819)

#include "Board.h"
#include "Player.h"
#include <vector>

class AI {
public:
	int getSelectMal(Player& player, Board& board, int yut_num);
	int getMoveValue(Mal*mal, Board& board, int yut_num);
	int getChildValue(Mal* mal);
	int getTeamValue(Mal* mal, Board& board, int yut_num);
};