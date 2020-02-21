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

class Possibilities {

public:
	Possibilities(unsigned int num_signs, unsigned int num_positions);
	~Possibilities();

	void update_possibilities(Combination& guess, unsigned int correct_pos, unsigned int incorrect_pos);
	unsigned int get_num_possibilities() const;
private:
	list<Combination> all_possibilites;

};