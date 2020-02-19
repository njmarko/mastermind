//============================================================================
// Name        : MyWindow.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.19.2020
// Copyright   : GPLv3
// Description : Class that inherits Window like Simple_window does
//============================================================================
#pragma once

#include "GUI.h"
#include "Graph.h"


#define WINDOW_W	1000
#define WINDOW_H	800
#define W_OFFSET	20
#define H_OFFSET	20
#define BUTTON_W	150
#define BUTTON_H	20
#define INPUT_W		150
#define INPUT_H		20
#define ROW_START	200
#define COL_START	200
#define TXT_W		200
#define TXT_H		20
#define CIRCLE_R	10
#define RECT_W		20
#define RECT_H		20
#define SPACING		50

using namespace std;
using namespace Graph_lib;

class MyWindow:Window
{
private:

	void create_fltk_elements();


public:

	MyWindow(Point xy, int width, int height, const string& title);
	~MyWindow();

	bool wait_for_button();


	/**
	*Detaches all dynamically added elements from the gui and frees the memory
	*/
	void clear_shapes();

};

