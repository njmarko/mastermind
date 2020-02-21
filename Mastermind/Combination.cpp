//============================================================================
// Name        : Combination.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Implementation of the Combination class
//============================================================================

#include "Combination.h"

Combination::Combination():correct_pos(0),incorrect_pos(0)
{
}

Combination::Combination(const Combination & other):signs(other.signs), correct_pos(other.correct_pos),incorrect_pos(other.incorrect_pos)
{
}

Combination::Combination(vector<Sign> signs): signs(signs), correct_pos(0),incorrect_pos(0)
{
}



Combination::~Combination()
{
}

void Combination::add_sign(int id)
{
	signs.push_back(Sign(id));
}

bool Combination::compare_combinations(const Combination& other) 
{
	evaluate_positions(other);
	if (correct_pos == get_size()) {
		return true;
	}
	else {
		return false;
	}
}

int Combination::get_size() const
{
	return signs.size();
}

void Combination::clear_comb()
{
	signs.clear();
	correct_pos = 0;
	incorrect_pos = 0;
}

int Combination::get_correct_pos() const
{
	return correct_pos;
}

int Combination::get_incorrect_pos() const
{
	return incorrect_pos;
}

vector<int> Combination::make_histogram() const
{
	vector<int> histogram(6);
	for (int i = 0; i < get_size();++i) {
		histogram[signs[i].get_id()]++;
	}
	return histogram;
}

void Combination::evaluate_positions(const Combination & other)
{
	vector<int> guess_hist = make_histogram();
	vector<int> correct_hist = other.make_histogram();
	correct_pos = 0;
	incorrect_pos = 0;

	for (int i = 0; i < 6;++i) {
		if (guess_hist[i] <= correct_hist[i]) {
			incorrect_pos += guess_hist[i];
		}
		else {
			incorrect_pos += correct_hist[i];
		}
	}

	for (int i = 0; i < get_size(); i++)
	{
		if (signs[i] == other.signs[i]) {
			correct_pos++;
		}
	}
	incorrect_pos = incorrect_pos - correct_pos;
}
