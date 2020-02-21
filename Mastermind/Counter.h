//============================================================================
// Name        : Counter.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Class that represents a counter used for generating possibilities with any number of signs
//============================================================================
#pragma once
#include <vector>

using std::vector;

class Counter {
public:
	Counter(unsigned int base,unsigned int length);
	Counter(const Counter& other);
	~Counter();
	Counter operator++(int);
	Counter& operator++();
	bool is_finished() const;
	vector<int>& get_numbers();
private:
	unsigned int base;
	unsigned int length;
	bool finished;
	vector<int> numbers;
};

