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
#include <FL\Fl_Menu_Bar.H>
#include <FL\Fl_Menu_Button.H>
#include <FL\Fl_Menu_Item.H>
#include <string>


/* Width of the main window.*/
#define WINDOW_W	550
/* Height of the main window.*/
#define WINDOW_H	625
/* Width offset for all the elements. [unused]*/
#define W_OFFSET	20
/* Height offset for all the elements. [unused]*/
#define H_OFFSET	20

/* Point that represents the midle point of the screen where the window should be placed.*/
const Point scr_middle_placement(Fl::x() + (Fl::w() - WINDOW_W) / 2, Fl::y() + (Fl::h() - WINDOW_H) / 2);

/* Width of the button.*/
#define BUTTON_W	75
/* Height of the button.*/
#define BUTTON_H	50
/* Y axis starting position for the buttons.*/
#define BUTTON_ROW	500
/* X axis starting position for the buttons.*/
#define BUTTON_COL  47


/* Y axis starting position for the guesses.*/
#define SIGN_ROW_START	50
/* X axis starting position for the guesses.*/
#define SIGN_COL_START	2
/* Y axis starting position for the text that diplays the number of remaining combinations.*/
#define TXT_ROW_START 50
/* X axis starting position for the text that diplays the number of remaining combinations.*/
#define TXT_COL_START 5


/* Y axis starting position for the correctness indicators.*/
#define IND_ROW_START 50
/* X axis starting position for the correctness indicators.*/
#define IND_COL_START 300

/* Y axis starting position for the controll buttons.*/
#define CTRL_BTN_ROW_START 500
/* X axis starting position for the controll buttons.*/
#define CTRL_BTN_COL_START 317
/* Width of the controll buttons.*/
#define CTRL_BTN_W 100
/* Height of the controll buttons.*/
#define CTRL_BTN_H 50

/* Y axis position for the correct combination.*/
#define SIGN_CORRECT_ROW_START 400 

/* Y axis position for the number of points.*/
#define TXT_POINTS_COL 450

/* X axis position for the number of points.*/
#define TXT_POINTS_ROW 400

/*Size of the square box for the gui elements. Used for heigh and width.*/
#define BOX_SIZE 64

/*Spacing between the elements.*/
#define SPACING	50

using namespace std;
using namespace Graph_lib;

/**
* Basic window that will display all the elements needed to play the game.
* Notes about implementation:
*	Redraw individual elements whenever possible instead of redrawing the whole screen to reduce flickering.
*	Add dynamically allocated elements to the apropriate container so they can be deleted when clearing the screen.
*/
class MyWindow:public Window
{
public:

	/**
	* Constructor with screen dimensions and the title.
	* @param xy Point that represents the coordinates where the window will be displayed.
	* @param width of the window.
	* @param height of the window.
	* @param title that will be displayed at the top of the window
	*/
	MyWindow(Point xy, int width, int height, const string& title);

	/**
	* Destructor that deletes the dynamically allocated elements that were created at the start of the program;
	* It also calls clear screen function that deletes all the dynamically allocated elements that were created
	* during the execution of the program.
	*/
	~MyWindow();

	/**
	* Function that shows the window and runs the current application.
	*/
	bool wait_for_button();


	/**
	* Clears the dynamically allocated elements such as signs and indicators that were used in the previous game,
	* and creates the new game instance that can be played in the now clean window.
	*/
	void start_new_game();

private:

	/*Game that does all the calculations.*/
	Game game;

	/*If Shapes from GraphLib are used, they should be placed here for easier cleanup.*/
	vector<Shape*> shapes;

	/*Elements that are dynamically created during the game.*/
	vector<Fl_Widget*> elements;


	//sign buttons.
	Fl_Button* btn_smiley;
	Fl_Button* btn_club;
	Fl_Button* btn_spade;
	Fl_Button* btn_hearth;
	Fl_Button* btn_diamond;
	Fl_Button* btn_star;
	
	//controll buttons.
	Fl_Button* btn_clear;
	Fl_Button* btn_enter;
	Fl_Button* btn_new_game;

	//images for the signs.
	Fl_PNG_Image* png_smiley;
	Fl_PNG_Image* png_club;
	Fl_PNG_Image* png_spade;
	Fl_PNG_Image* png_hearth;
	Fl_PNG_Image* png_diamond;
	Fl_PNG_Image* png_star;

	//indicators for the correctness of the guess.
	Fl_PNG_Image* png_correct;
	Fl_PNG_Image* png_incorrect;
	
	//number of points that can be won
	Fl_Box* txt_points;

	//one guess remaining indicator for when the guess is guaranteed.
	Fl_Box* box_guess_guaranteed;

	//menu bar that will have buttons with basic options listed
	Fl_Menu_Bar* menu_bar;

	//callback functions for the buttons
	static void cb_add_sign(Fl_Widget* w, void* p);
	static void cb_clear_guess(Fl_Widget* w, void* p);
	static void cb_new_game(Fl_Widget* w, void* p);
	static void cb_enter_guess(Fl_Widget* w, void* p);

	/**
	* Callback function for quitting
	*/
	static void cb_quit(Fl_Widget*, void *);



	/**
	* Value that determines if nubmer of remaining combinations 
	* will be shown after each guess.
	*/
	bool num_comb_displayed;

	/**
	* Value that determines if the points will be shown.
	*/
	bool points_displayed;

	/**
	* Value that determines if the "guess guaranteed" indicator will be shown.
	*/
	bool guess_guaranteed_displayed;



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

