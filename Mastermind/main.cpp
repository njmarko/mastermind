//============================================================================
// Name        : main.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.19.2020
// Copyright   : GPLv3
// Description : Main file where the execution of the program begins
//============================================================================


#include "MyWindow.h"
using namespace std;

void main(int argc, char* argv[])
{


	MyWindow simple(Point(100,100),WINDOW_W,WINDOW_H,"Mastermind");

	simple.wait_for_button();
}
