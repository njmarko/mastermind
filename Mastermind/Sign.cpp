//============================================================================
// Name        : Sign.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Implementation of the Sign class
//============================================================================


#include "Sign.h"

Sign::Sign():id(-1),name("Unknown")
{
}

Sign::Sign(int id): id(id), name(determine_name(id))
{
}

Sign::Sign(const Sign & other):id(other.id), name(other.name)
{
}

Sign::~Sign()
{
}

bool Sign::operator==(const Sign & other)
{
	return id==other.id;
}

int Sign::get_id() const
{
	return id;
}

string Sign::determine_name(int id)
{
	switch (id)
	{
	case 0:
		return "Skocko";
		break;
	case 1:
		return "Tref";
		break;
	case 2:
		return "Pik";
		break;
	case 3:
		return "Herc";
		break;
	case 4:
		return "Karo";
		break;
	case 5:
		return "Zvezda";
		break;
	default:
		return "Unknown";
		break;
	}
}
