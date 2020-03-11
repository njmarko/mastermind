//============================================================================
// Name        : Game.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 03.11.2020
// Copyright   : GPLv3
// Description : Class that represents a main game
//============================================================================
#pragma once

#include <vector>
#include "Combination.h"
#include <random>
#include <ctime>
#include "Possibilities.h"

using std::vector;

#define num_rows 6
#define num_positions 4
#define num_signs 6


class Game {

public:
	enum Signs {
		/*Enumeration for the types of signs*/
		SMILEY = 0, CLUB, SPADE, HEARTH, DIAMOND, STAR
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
	void update_possibilities();
	unsigned int get_num_possibilities() const;
	Combination get_correct_comb() const;
private:
	Combination correct_comb;
	Combination guess_comb;
	vector<Combination> played_combs;
	bool game_ended;
	Possibilities possibilities;

};