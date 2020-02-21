//============================================================================
// Name        : Counter.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Implementation of the Counter class
//============================================================================

#include "Counter.h"

Counter::Counter(unsigned int b, unsigned int l) : base(b), length(l), numbers(vector<int>(l)),finished(false)
{
}

Counter::Counter(const Counter & other):base(other.base),length(other.length),numbers(other.numbers),finished(other.finished)
{
}

Counter::~Counter()
{
}

Counter Counter::operator++(int)
{
	Counter ret_val(*this);
	operator++();
	return ret_val;
}

Counter & Counter::operator++()
{
	vector<int>::reverse_iterator rit;
	finished = true;
	for (rit = numbers.rbegin();rit != numbers.rend();++rit) {
		*rit = (*rit + 1) % base;
		if (*rit != 0) {
			finished = false;
			break;
		}
	}
	return *this;
}

bool Counter::is_finished() const
{
	return finished;
}

vector<int>& Counter::get_numbers() 
{
	return numbers;
}


