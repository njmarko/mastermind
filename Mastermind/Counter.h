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

/**
* Class that is used for counting all the possibilities based on the
* number of types of signs used and the total number of places where those signs
* can be placed.
*/
class Counter {
public:
	Counter(unsigned int base,unsigned int length);
	Counter(const Counter& other);
	~Counter();

	/**
	* Postfix increment operator.
	* @returns copy of the incremented counter.
	*/
	Counter operator++(int);

	/**
	* Prefix increment operator.
	* @returns reference to the incremented counter.
	*/
	Counter& operator++();

	/**
	* Function that check if the maximum value of the counter is reached.
	* @returns bool true if the counter has reached the max value.
	*/
	bool is_finished() const;

	/**
	* Getter for the current state of every number in the counter.
	* @returns vector with all the numbers at each position.
	*/
	vector<int>& get_numbers();
private:
	/**
	* Determines the number of times each position can be incremented without affecting other positions.
	*/
	unsigned int base;

	/**
	* Number of positions in the counter.
	*/
	unsigned int length;

	/**
	* Indicator for the finished state of the counter.
	*/
	bool finished;

	/**
	* All numbers in the apropriate position in the counter.
	*/
	vector<int> numbers;
};

