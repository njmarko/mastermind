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

/**
* Number of guesses the user can attempt.
*/
#define num_rows 6

/**
* Defines how many signs can be played in one combination.
*/
#define num_positions 4

/**
* Number of different types of signs that can be played.
*/
#define num_signs 6


/**
* This class represents the game of mastermind.
* It consists of correct combination that has to be guessed,
* Combination that was last guessed,
* All the played combinations and all the possibilities that remain after each guess.
*/
class Game {

public:
	enum Signs {
		/*Enumeration for the types of signs*/
		SMILEY = 0, CLUB, SPADE, HEARTH, DIAMOND, STAR
	};

	Game();
	~Game();

	/**
	* Method that adds a sign to the current guess.
	* @param s reference to a sign that will be added.
	* @returns bool false if the combination contains all the signs or the game has ended
	*/
	bool add_sign(const Signs& s);

	/**
	* Get the number that indicates how many combinations were played so far.
	* @returns int number of the current row.
	*/
	int get_curr_row() const;

	/**
	* Get the number that indicates how many signs were played in a combination.
	* @returns int number of the current sign in the combination.
	*/
	int get_curr_col() const;

	/**
	* Removes all the signs from the current guess.
	*/
	void clear_guess();

	/**
	* Stores the current guess into the list of played combinations,
	* and initializes the new empty current guess.
	*/
	void enter_guess();

	/**
	* Compares the current guess to the correct combination.
	* @returns bool returns true if the guessed combination is correct.
	*/
	bool evaluate_guess();

	/**
	* Get the number of correct signs in the correct places for the current guess.
	* @returns int number of correct signs in the correct places.
	*/
	int get_correct_pos() const;

	/**
	* Get the number of correct signs in the incorrect places for the current guess.
	* @returns int number of correct signs in the incorrect places.
	*/
	int get_incorrect_pos() const;

	/**
	* Returns the finished game.
	* @returns bool true if the game is finished.
	*/
	bool is_finished() const;

	/**
	* Changes the game ended indicator to true.
	*/
	void finish_game();

	/**
	* Updates the remaining possibilities based on the current guess
	* and the number of correct signs in the correct and incorrect places.
	* Combinations that can no longer be the solution are removed from the list of possibilities.
	*/
	void update_possibilities();

	/**
	* Get the number of remaining possibilities that is updated after each guess.
	* @returns unsigned int number of remaining possibilities.
	*/
	unsigned int get_num_possibilities() const;


	/**
	* Get the correct combination.
	* @returns Combination correct combination that has to be guessed.
	*/
	Combination get_correct_comb() const;
private:
	/**
	* Correct combination that has to be guessed.
	*/
	Combination correct_comb;

	/**
	* Combination that was last inputed.
	*/
	Combination guess_comb;

	/**
	* Vector of all the played combinations in the current game.
	*/
	vector<Combination> played_combs;

	/**
	* Indicator for when the game has ended.
	*/
	bool game_ended;

	/**
	* List of all the remaining possibilities that is updated after each guess.
	*/
	Possibilities possibilities;

};