//============================================================================
// Name        : Sign.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Class that represents sign in a combination
//============================================================================
#pragma once

#include <string>
#include "Counter.h"
using std::string;

/**
* Class that represents a sign in the combinations.
*/
class Sign {

public:
	Sign();
	Sign(int id);
	Sign(const Sign& other);
	~Sign();

	/**
	* Operator for comparing the two signs.
	* @param other sign that will be compared to this one.
	* @returns bool true if the signs have the same id.
	*/
	bool operator==(const Sign& other);

	/**
	* Getter for the sign id.
	* @returns int id of the sign.
	*/
	int get_id() const;

private:
	/**
	* Id that determines the type of sign.
	*/
	int id;

	/**
	* Name of the sign.
	*/
	string name;

	/**
	* Function that determines the sign name based on the id.
	* It currently supports six standard sign names.
	* @param id of the sign.
	* @param string name of the sign.
	*/
	string determine_name(int id);
};


