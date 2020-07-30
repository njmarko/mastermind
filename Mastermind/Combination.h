//============================================================================
// Name        : Combination.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 03.11.2020
// Copyright   : GPLv3
// Description : Class that represents a combination consisting of signs
//============================================================================
#pragma once

#include <vector>
#include "Sign.h"
#include "Counter.h"

using std::vector;


/**
* Class that represents one combination in the game. It consists of signs
* that are placed in order inside a vector. These can be any suported signs
* and there is no restriction on how many of them can be used in one combination.
*/
class Combination {

public:
	Combination();
	Combination(const Combination& other);
	Combination(const vector<Sign>& signs);
	~Combination();

	/**
	* Adds a sign based on the id.
	* @param id number that determines what sign will be added.
	*/
	void add_sign(int id);

	/**
	* Compares the signs from two combinations.
	* @param other combination that will be compared to this combination.
	* @returns bool true if the combinations are the same, false otherwise.
	*/
	bool compare_combinations(const Combination& other);

	/**
	* Getter for the number of signs in the combination.
	* @returns int number of signs in the combination.
	*/
	int get_size() const;

	/**
	* Clears the combination.
	*/
	void clear_comb();

	/**
	* Returns the number of correct signs at the correct positions. This value is set 
	* after comparing this combination with the correct combination by evaluate_positions functions.
	* @returns int number of correct signs at the correct possitions.
	*/
	int get_correct_pos() const;

	/**
	* Returns the number of correct signs at the incorrect positions. This value is set
	* after comparing this combination with the correct combination by evaluate_positions functions.
	* @returns int number of correct signs at the incorrect possitions.
	*/
	int get_incorrect_pos() const;

	/**
	* Getter for the signs.
	* @returns vector with signs.
	*/
	vector<Sign> get_signs() const;

private:
	/**
	* Vector that contains the signs that represent the combination.
	*/
	vector<Sign> signs;

	/**
	* Correct signs at the correct positions.
	*/
	int correct_pos;

	/**
	* Correct signs at the incorrect positions.
	*/
	int incorrect_pos;

	/**
	* Creates the histogram that counts each appearance of every signs in the combination.
	* This histogram is used by evaluate_positions function to calculate correct signs
	* that are placed at the incorrect positions.
	* @returns vector where each number represents the number of appearances of the coresponding sign.
	*/
	vector<int> make_histogram() const;

	/**
	* Calculates the correct_pos and icnorrect_pos atributes. These atributes represent
	* correct signs in the right places and correct signs in the incorrect places.
	* @param other combination that is compared to this combination.
	*/
	void evaluate_positions(const Combination& other);
};