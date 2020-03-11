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

class Combination {

public:
	Combination();
	Combination(const Combination& other);
	Combination(vector<Sign> signs);
	~Combination();
	void add_sign(int id);
	bool compare_combinations(const Combination& other);
	int get_size() const;
	void clear_comb();
	int get_correct_pos() const;
	int get_incorrect_pos() const;
	vector<Sign> get_signs() const;

private:
	vector<Sign> signs;
	int correct_pos;
	int incorrect_pos;

	vector<int> make_histogram() const;
	void evaluate_positions(const Combination& other);
};