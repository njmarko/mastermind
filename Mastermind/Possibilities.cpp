//============================================================================
// Name        : Possibilities.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Implementation of the Possibilities class
//============================================================================

#include "Possibilities.h"


Possibilities::Possibilities(unsigned int num_signs, unsigned int num_positions)
{
	
	for (Counter i(num_signs, num_positions);!i.is_finished();++i) {
		vector<Sign> signs(num_positions);
		for (int j = 0; j < i.get_numbers().size(); j++)
		{
			signs[j] = (Sign(i.get_numbers()[j]));
		}
		all_possibilites.push_back(Combination(signs));
	}
	
}

Possibilities::~Possibilities()
{
}

void Possibilities::update_possibilities(Combination& guess, unsigned int correct_pos, unsigned int incorrect_pos)
{
	list<Combination>::iterator it = all_possibilites.begin();
	while (it != all_possibilites.end()) {
		list<Combination>::iterator current = it;
		++it;
		(*current).compare_combinations(guess);
		if (correct_pos != (*current).get_correct_pos() || incorrect_pos != (*current).get_incorrect_pos()) {
			all_possibilites.erase(current);
		}

	}
}

unsigned int Possibilities::get_num_possibilities() const
{
	return all_possibilites.size();
}
