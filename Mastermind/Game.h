//============================================================================
// Name        : Game.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.20.2020
// Copyright   : GPLv3
// Description : Class that represents a main game
//============================================================================
#pragma once

#include <vector>
#include "Combination.h"
#include <random>
#include <ctime>

using std::vector;

#define num_rows 6
#define num_signs 4

class Game {

public:
	enum Signs {
		/*Enumeration for the types of signs*/
		SKOCKO = 0, TREF, PIK, HERC, KARO, ZVEZDA
	};

	Game();
	~Game();

	bool add_sign(Signs s);
	int get_curr_row() const;
	int get_curr_col() const;
	void clear_guess();
	void enter_guess();
	bool evaluate_guess();
	int get_correct_pos() const;
	int get_incorrect_pos() const;
	bool is_finished() const;
	void finish_game();

private:
	Combination correct_comb;
	Combination guess_comb;
	vector<Combination> played_combs;
	bool game_ended;


};