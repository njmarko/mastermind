//============================================================================
// Name        : Game.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 11.17.2020
// Copyright   : GPLv3
// Description : Class that represents a main game
//============================================================================
#pragma once

#include <vector>
#include "Combination.h"
#include <random>
#include <ctime>
#include "Possibilities.h"
#include <iostream>

using std::vector;

/**
* Number of guesses the user can attempt.
*/
#define NUM_ROWS 6

/**
* Defines how many signs can be played in one combination.
*/
#define NUM_POSITIONS 4

/**
* Number of different types of signs that can be played.
*/
#define NUM_SIGNS 6

/**
* Number of points at the start of the game.
*/
#define POINTS_START 15

/**
* Number of points that will be deduced from the total number of points
* after each incorrect guess when there is only one possible combination remaining.
*/
#define POINTS_DECREMENT 3

/**
* Starting number of points that will be decremented from the total number of points
* after each incorrect guess when there is only one possible combination remaining.
* Decrement will be reduce for each subsequent wrong guess.
*/
#define POINTS_DECREMENT_V2 5


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
		SMILEY = 0, CLUB, SPADE, HEART, DIAMOND, STAR
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
	* Get the current decrement value.
	* @returns int number that will be decremented after a wrong guess with only one combination remaining.
	*/
	int get_points_decr_v2() const;

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

	/**
	* Updates the points if the number of remaining combinations is 1.
	* Points are deduced based on the POINTS_DECREMENT that is predefined.
	*/
	void update_points();

	/**
	* Getter for the current points the player can win in the game
	* @returns int points that can be won if the combination is guessed
	*/
	int get_points() const;

	/**
	* Updates the points decrement by decreasing its value by 1 in this case
	*/
	void update_points_decrement_v2();
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

	/**
	* Number of points that will be won at the moment the correct guess is submited.
	*/
	int points;

	/**
	* Indicator for when only one possible combination is left.
	*/
	bool one_comb_remaining;

	/**
	* Number of points that will be reduced after each wrong guess when there is only one combination remaining.
	* It changes on successive misstakes and takes the following values: 5,4,3,2,1
	*/
	int points_decr_v2;

};