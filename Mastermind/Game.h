//============================================================================
// Name        : Game.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.19.2020
// Copyright   : GPLv3
// Description : Class that represents a main game
//============================================================================
#pragma once

#include <vector>
#include "Combination.h"

using std::vector;

class Game {

public:


private:
	Combination correct_comb;
	Combination guess_comb;
	vector<Combination> played_combs;
	int end_counter;

};