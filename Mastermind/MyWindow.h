//============================================================================
// Name        : MyWindow.h
// Author      : Marko Njegomir sw-38-2018
// Date        : 03.11.2020
// Copyright   : GPLv3
// Description : Class that inherits Window like Simple_window does
//============================================================================
#pragma once

//#include <FL\Fl_Shared_Image.H> //allows for rescaling of images. Also keeps the original copy

#include "GUI.h"
#include "Graph.h"
#include <FL\Fl_Button.H>
#include "Game.h"
#include <FL\Fl_PNG_Image.H>
#include <FL\Fl_Image.H>
#include <FL\Fl_Box.H>
#include <FL\Fl_Widget.H>
#include <FL\Fl.H>


#define WINDOW_W	650
#define WINDOW_H	650
#define W_OFFSET	20
#define H_OFFSET	20

#define BUTTON_W	100
#define BUTTON_H	50
#define BUTTON_ROW	500
#define BUTTON_COL  32

#define SIGN_ROW_START	50
#define SIGN_COL_START	32
#define TXT_ROW_START 85
#define TXT_COL_START 50

#define IND_ROW_START 50
#define IND_COL_START 300

#define SIGN_CORRECT_START 400

#define BOX_SIZE 64

#define SPACING	50

using namespace std;
using namespace Graph_lib;

class MyWindow:public Window
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

	vector<Fl_Widget*> elements;


	//sign buttons
	Fl_Button* btn_smiley;
	Fl_Button* btn_club;
	Fl_Button* btn_spade;
	Fl_Button* btn_hearth;
	Fl_Button* btn_diamon;
	Fl_Button* btn_star;
	
	//
	Fl_Button* btn_clear;
	Fl_Button* btn_enter;
	Fl_Button* btn_new_game;

	Fl_PNG_Image* png_smiley;
	Fl_PNG_Image* png_club;
	Fl_PNG_Image* png_spade;
	Fl_PNG_Image* png_hearth;
	Fl_PNG_Image* png_diamond;
	Fl_PNG_Image* png_star;

	Fl_PNG_Image* png_correct;
	Fl_PNG_Image* png_incorrect;
	

	static void cb_add_sign(Fl_Widget* w, void* p);
	static void cb_clear_guess(Fl_Widget* w, void* p);
	static void cb_new_game(Fl_Widget* w, void* p);
	static void cb_enter_guess(Fl_Widget* w, void* p);

	void create_fltk_elements();

	/**
	*Detaches all dynamically added elements from the gui and frees the memory
	*/
	void clear_screen();

	void clear_curr_guess();

	void enter_curr_guess();

	void add_guess_indicators();

	void add_remaining_num();

	void add_sign(Game::Signs type);

	void add_correct_comb();
};

