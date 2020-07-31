//============================================================================
// Name        : Possibilities.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Class that represents all possibilities consisting of combinations of signs
//============================================================================

#pragma once

#include <list>
#include "Combination.h"
#include "Counter.h"

using std::list;

/**
* Class that models the possibilities in the game.
* Possibilities are a list of combinations that can still be correct at some point in the game.
* With each guess the number of possibilities is reduced, untill only one possible combination is left.
* When one combination is left, that means that the correct solution can be deduced.
*/
class Possibilities {

public:
	Possibilities(unsigned int num_signs, unsigned int num_positions);
	~Possibilities();

	/**
	* Compares the current guess with every remaining possibility.
	* If the comparison doesn't return the same number of correct signs in correct and incorrect positions,
	* then that combination is removed from the list of possibilities.
	* @param guess current guess that will be compared to the list of remaining possibilities.
	* @param correct_pos number of correct signs in the correct possitions.
	* @param correct_pos number of correct signs in the incorrect possitions.
	*/
	void update_possibilities(const Combination& guess, unsigned int correct_pos, unsigned int incorrect_pos);

	/**
	* Getter for the number of remaining possibilities.
	* @returns unsigned int number of possibilities.
	*/
	unsigned int get_num_possibilities() const;
private:
	/**
	* List of all the possible combinations at some point in the game.
	*/
	list<Combination> all_possibilites;

};