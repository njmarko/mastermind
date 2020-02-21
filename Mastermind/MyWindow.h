//============================================================================
// Name        : MyWindow.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Class that inherits Window like Simple_window does
//============================================================================
#pragma once

#include "GUI.h"
#include "Graph.h"
#include <FL\Fl_Button.H>
#include "Game.h"

#include <iostream>

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
public:

	MyWindow(Point xy, int width, int height, const string& title);
	~MyWindow();

	bool wait_for_button();

	void start_new_game();

private:

	/*Game that does all the calculations*/
	Game game;

	/*Elements that are displayed like signs and correct position indicators*/
	vector<Shape*> shapes;

	//sign buttons
	Fl_Button* skocko;
	Fl_Button* tref;
	Fl_Button* pik;
	Fl_Button* herc;
	Fl_Button* karo;
	Fl_Button* zvezda;
	
	Fl_Button* clear;
	Fl_Button* enter;
	Fl_Button* new_game;

	static void add_sign(Fl_Widget* w, void* p);
	static void cb_clear_guess(Fl_Widget* w, void* p);
	static void cb_new_game(Fl_Widget* w, void* p);
	static void cb_enter_guess(Fl_Widget* w, void* p);

	void create_fltk_elements();

	/**
	*Detaches all dynamically added elements from the gui and frees the memory
	*/
	void clear_all_shapes();

	void clear_curr_guess();

	void enter_curr_guess();

	void add_guess_indicators();

	void add_remaining_num();
};

