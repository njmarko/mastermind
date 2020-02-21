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

class Sign {

public:
	Sign();
	Sign(int id);
	Sign(const Sign& other);
	~Sign();

	bool operator==(const Sign& other);
	int get_id() const;

private:
	int id;
	string name;
	string determine_name(int id);
};


