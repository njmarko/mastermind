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
#include <string>

/* Width of the main window.*/
#define WINDOW_W	650
/* Height of the main window.*/
#define WINDOW_H	650
/* Width offset for all the elements. [unused]*/
#define W_OFFSET	20
/* Height offset for all the elements. [unused]*/
#define H_OFFSET	20


/* Width of the button.*/
#define BUTTON_W	100
/* Height of the button.*/
#define BUTTON_H	50
/* Y axis starting position for the buttons.*/
#define BUTTON_ROW	500
/* X axis starting position for the buttons.*/
#define BUTTON_COL  32


/* Y axis starting position for the guesses.*/
#define SIGN_ROW_START	50
/* X axis starting position for the guesses.*/
#define SIGN_COL_START	32
/* Y axis starting position for the text that diplays the number of remaining combinations.*/
#define TXT_ROW_START 85
/* X axis starting position for the text that diplays the number of remaining combinations.*/
#define TXT_COL_START 50


/* Y axis starting position for the correctness indicators.*/
#define IND_ROW_START 50
/* X axis starting position for the correctness indicators.*/
#define IND_COL_START 300


/* Y axis position for the correct combination.*/
#define SIGN_CORRECT_START 400 

/*Size of the square box for the gui elements. Used for heigh and width.*/
#define BOX_SIZE 64

/*Spacing between the elements.*/
#define SPACING	50

using namespace std;
using namespace Graph_lib;

/**
* Basic window that will display all the elements needed to play the game.
*/
class MyWindow:public Window
{
public:

	MyWindow(Point xy, int width, int height, const string& title);
	~MyWindow();

	/*
	* Function that shows the window and runs the current application.
	*/
	bool wait_for_button();


	/*
	* Clears the dynamically allocated elements such as signs and indicators that were used in the previous game,
	* and creates the new game instance that can be played in the now clean window.
	*/
	void start_new_game();

private:

	/*Game that does all the calculations.*/
	Game game;

	/*Elements that are displayed like signs and correct position indicators.*/
	vector<Shape*> shapes;

	/*Elements that are dynamically created during the game.*/
	vector<Fl_Widget*> elements;


	//sign buttons
	Fl_Button* btn_smiley;
	Fl_Button* btn_club;
	Fl_Button* btn_spade;
	Fl_Button* btn_hearth;
	Fl_Button* btn_diamon;
	Fl_Button* btn_star;
	
	//controll buttons
	Fl_Button* btn_clear;
	Fl_Button* btn_enter;
	Fl_Button* btn_new_game;

	//images for the signs
	Fl_PNG_Image* png_smiley;
	Fl_PNG_Image* png_club;
	Fl_PNG_Image* png_spade;
	Fl_PNG_Image* png_hearth;
	Fl_PNG_Image* png_diamond;
	Fl_PNG_Image* png_star;

	//indicators for the correctness of the guess
	Fl_PNG_Image* png_correct;
	Fl_PNG_Image* png_incorrect;
	
	//number of points that can be won
	Text* txt_points;

	//one guess remaining indicator for when the guess is guaranteed
	Fl_Box* box_guess_guaranteed;

	//callback functions for the buttons
	static void cb_add_sign(Fl_Widget* w, void* p);
	static void cb_clear_guess(Fl_Widget* w, void* p);
	static void cb_new_game(Fl_Widget* w, void* p);
	static void cb_enter_guess(Fl_Widget* w, void* p);

	/**
	* Creates all the buttons on the screen.
	*/
	void create_fltk_elements();

	/**
	* Detaches all dynamically added elements from the gui and frees the memory.
	*/
	void clear_screen();

	/**
	* Clears the signs from the screen that belong to the current guess.
	*/
	void clear_curr_guess();

	/**
	* Enters the current signs from the current guess.
	* This doesn't work if the game is in finished state or if the guess is not yet complete.
	* If this action is successfull, the game  can either end if the combination is correct
	* or if the maximum number of guesses were played,
	* or alternatively move to the next guess.
	*/
	void enter_curr_guess();

	/**
	* Creates the indicators on the screen for the correct signs in the correct and incorrect places
	* for the current guess in the game.
	*/
	void add_guess_indicators();

	/**
	* Add the number of remaining combinations after the guess.
	*/
	void add_remaining_num();

	/**
	* Adds a currently played sign to the current guess on the screen.
	* @param type enumeration for the sign that is being added.
	*/
	void add_sign(Game::Signs type);

	/**
	* Adds the signs for the correct combination to the screen.
	*/
	void add_correct_comb();

	/**
	* Updates the number of points the player can win if he guesses the combintation at this point.
	*/
	void refresh_points();

	/**
	* Updates the indicator for when the guess is guaranteed. 
	* If the number of remaining combinations is 1, the guess is guaranteed.
	* Otherwise the user can't be shure what is the correct combinations that has to be played.
	*/
	void refresh_guess_guaranteed();
};

