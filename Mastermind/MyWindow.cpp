//============================================================================
// Name        : MyWindow.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 03.14.2021
// Copyright   : GPLv3
// Description : Implementation of MyWindow class
//============================================================================
#pragma once

#include "MyWindow.h"
 

void MyWindow::cb_add_sign(Fl_Widget * w, void * p)
{
	MyWindow &win = reference_to<MyWindow>(w->parent());
	reference_to<MyWindow>(w->parent()).add_sign(Game::Signs((int)p));
}

void MyWindow::cb_clear_guess(Fl_Widget * w, void * p)
{
	reference_to<MyWindow>(w->parent()).clear_curr_guess();
}

void MyWindow::cb_new_game(Fl_Widget * w, void * p)
{
	reference_to<MyWindow>(w->parent()).start_new_game();
}

void MyWindow::cb_enter_guess(Fl_Widget * w, void * p)
{
	reference_to<MyWindow>(w->parent()).enter_curr_guess();
}

void MyWindow::cb_quit(Fl_Widget *, void *)
{
	exit(0);
}

void MyWindow::cb_remaining_combs(Fl_Widget * w, void *)
{
	reference_to<MyWindow>(w->parent()).toggle_num_combs();
}

void MyWindow::cb_points_displayed(Fl_Widget * w, void *)
{
	reference_to<MyWindow>(w->parent()).toggle_points_displayed();
}

void MyWindow::cb_guess_guaranteed(Fl_Widget * w, void *)
{
	reference_to<MyWindow>(w->parent()).toggle_guess_guaranteed();
}

void MyWindow::cb_game_rules(Fl_Widget *, void *)
{
	fl_message("Goal of the game is to guess the combination of 4 signs that was generated randomly.\
		\nThere are 6 signs that can be placed at any position in the combination and the signs\
		\ncan be repeated.\
		\n\nYou have 6 tries to guess the combination by choosing a 4 sign combination each time.\
		\nAfter you enter the guess red indicators will inform you how many signs are in the right places\
		\nand yellow indicators will tell you how many signs you guessed correctly but are not at the \
		\nright places.\
		\n\nIf there is only one possible combination remaining, green indicator will turn on to signal\
		\nthat you can deduce what the correct combination is with hundred percent certanty.\
		\n\nThe number of points you can win by guessing correctly at any point is displayed on the screen.\
		\nNumber of points you can get starts at 15, and is only reduced if you fail to guess correctly\
		\nwhen there is only one possible combination remaining. Points are reduced by [5,4,3,2] points\
		\n(in that order) for each subsequent wrong guess.\
		");
}

void MyWindow::cb_about(Fl_Widget *, void *)
{
	fl_message("MASTERMIND\
		\n\n� 2021 Marko Njegomir\
		\n\nProject can be found at:\
		\nhttps://github.com/njmarko/mastermind\
		");
}

void MyWindow::create_fltk_elements()
{
	begin();

	//background image
	box_background = new Fl_Box(0, 0, WINDOW_W, WINDOW_H);
	box_background->image(png_background);

	//signs
	btn_smiley = new Fl_Button(BUTTON_COL, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_club = new Fl_Button(BUTTON_COL + BUTTON_W, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_spade = new Fl_Button(BUTTON_COL + BUTTON_W * 2, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_heart = new Fl_Button(BUTTON_COL, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);
	btn_diamond = new Fl_Button(BUTTON_COL + BUTTON_W, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);
	btn_star = new Fl_Button(BUTTON_COL + BUTTON_W * 2, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);

	//removes borders from the sign buttons
	btn_smiley->box(FL_NO_BOX);
	btn_club->box(FL_NO_BOX);
	btn_spade->box(FL_NO_BOX);
	btn_heart->box(FL_NO_BOX);
	btn_diamond->box(FL_NO_BOX);
	btn_star->box(FL_NO_BOX);

	//callback functions for signs
	btn_smiley->callback(cb_add_sign, (void*)Game::SMILEY);
	btn_club->callback(cb_add_sign, (void*)Game::CLUB);
	btn_spade->callback(cb_add_sign, (void*)Game::SPADE);
	btn_heart->callback(cb_add_sign, (void*)Game::HEART);
	btn_diamond->callback(cb_add_sign, (void*)Game::DIAMOND);
	btn_star->callback(cb_add_sign, (void*)Game::STAR);
	
	//sets images for the sign buttons
	btn_star->image(png_star);
	btn_club->image(png_club);
	btn_diamond->image(png_diamond);
	btn_heart->image(png_heart);
	btn_spade->image(png_spade);
	btn_smiley->image(png_smiley);

	//adds the keyboard shortcuts for the sign buttons
	btn_smiley->shortcut('q');
	btn_club->shortcut('w');
	btn_spade->shortcut('e');
	btn_heart->shortcut('a');
	btn_diamond->shortcut('s');
	btn_star->shortcut('d');

	//tooltips that display hotkeys for signs. copy_tooltip is used to copy the string from the temporary object
	btn_smiley->copy_tooltip(fl_shortcut_label(btn_smiley->shortcut()));
	btn_club->copy_tooltip(fl_shortcut_label(btn_club->shortcut()));
	btn_spade->copy_tooltip(fl_shortcut_label(btn_spade->shortcut()));
	btn_heart->copy_tooltip(fl_shortcut_label(btn_heart->shortcut()));
	btn_diamond->copy_tooltip(fl_shortcut_label(btn_diamond->shortcut()));
	btn_star->copy_tooltip(fl_shortcut_label(btn_star->shortcut()));
	
	//adds game controll buttons
	btn_enter = new Fl_Button(CTRL_BTN_COL_START, CTRL_BTN_ROW_START, CTRL_BTN_W, CTRL_BTN_H, "Enter");
	btn_clear = new Fl_Button(CTRL_BTN_COL_START, CTRL_BTN_ROW_START + CTRL_BTN_H, CTRL_BTN_W, CTRL_BTN_H, "Clear");
	btn_new_game = new Fl_Button(CTRL_BTN_COL_START + CTRL_BTN_W, CTRL_BTN_ROW_START, CTRL_BTN_W, CTRL_BTN_H * 2, "New Game");

	//adds the keyboard shortcuts for the game controll buttons
	btn_enter->shortcut(FL_KEYBOARD | FL_Enter);
	btn_clear->shortcut(FL_KEYBOARD | FL_BackSpace);
	btn_new_game->shortcut('n');

	//tooltips that display hotkeys for controll buttons. copy_tooltip is used to copy the string from the temporary object
	btn_enter->copy_tooltip(fl_shortcut_label(btn_enter->shortcut()));
	btn_clear->copy_tooltip(fl_shortcut_label(btn_clear->shortcut()));
	btn_new_game->copy_tooltip(fl_shortcut_label(btn_new_game->shortcut()));

	//adds the callback functions for game controll buttons
	btn_clear->callback(cb_clear_guess);
	btn_enter->callback(cb_enter_guess);
	btn_new_game->callback(cb_new_game);
	//btn_clear->deactivate();

	//btn colors
	btn_clear->color(FL_WHITE);
	btn_enter->color(FL_WHITE);
	btn_new_game->color(FL_WHITE);


	//adds the number of points player can win
	txt_points = new Fl_Box(TXT_POINTS_COL, TXT_POINTS_ROW, BOX_SIZE, BOX_SIZE);
	txt_points->copy_label(to_string(game.get_points()).c_str());
	txt_points->tooltip("Number of points the player can win if they guess correctly.\
 When there is only one combination remaining that can possibly be correct,\
 points will be reduced for each subsequent wrong guess by [5,4,3,2] points (in that order).");
	if (!points_displayed)
	{
		txt_points->hide();
	}

	box_guess_guaranteed = new Fl_Box(IND_COL_START, SIGN_CORRECT_ROW_START, BOX_SIZE, BOX_SIZE);
	box_guess_guaranteed->image(png_remaining_many);
	box_guess_guaranteed->tooltip("This indicator is green if there is only one possible correct combination remaining.\
 It is dark when there are multiple combinations remaining that can possibly be correct.");
	if (!guess_guaranteed_displayed)
	{
		box_guess_guaranteed->hide();
	}

	txt_finished_msg = new Fl_Box(SIGN_COL_START + MSG_FINISHED_OFFSET, TXT_FINISHED_ROW, BOX_FINISHED_SIZE_W, BOX_FINISHED_SIZE_H);
	txt_finished_msg->copy_label(MSG_WIN);
	txt_finished_msg->tooltip("The game is finished. You can start a new game to play again.");
	txt_finished_msg->hide();

	//menu bar
	menu_bar = new Fl_Menu_Bar(MENU_X, MENU_Y, WINDOW_W, MENU_H);
	menu_bar->color(FL_WHITE);
	menu_bar->add("File/New Game", FL_CTRL + 'n', cb_new_game);
	menu_bar->add("File/Quit", FL_CTRL + 'q', cb_quit);
	menu_bar->add("View/Hide Remaining Combinations", FL_CTRL + 's', cb_remaining_combs, (void*)this, FL_MENU_TOGGLE);
	menu_bar->add("View/Hide Guess Guaranteed", FL_CTRL + 'g', cb_guess_guaranteed, (void*)this, FL_MENU_TOGGLE);
	menu_bar->add("View/Hide Points", FL_CTRL + 'p', cb_points_displayed, (void*)this, FL_MENU_TOGGLE);
	menu_bar->add("Help/Game Rules", FL_CTRL + 'r', cb_game_rules);
	menu_bar->add("Help/About", FL_CTRL + 'a', cb_about);

	this->icon(bmp_icon);
	this->default_icon(bmp_icon);
	end();
}

MyWindow::MyWindow(Point xy, int width, int height, const string & title) :
	Window(xy, width, height, title),
	game(),
	btn_smiley(nullptr),
	btn_club(nullptr),
	btn_spade(nullptr),
	btn_heart(nullptr),
	btn_diamond(nullptr),
	btn_star(nullptr),
	btn_clear(nullptr),
	btn_enter(nullptr),
	btn_new_game(nullptr),
	png_club(new Fl_PNG_Image("../resources/club.png")),
	png_diamond(new Fl_PNG_Image("../resources/diamond.png")),
	png_heart(new Fl_PNG_Image("../resources/heart.png")),
	png_smiley(new Fl_PNG_Image("../resources/smiley.png")),
	png_spade(new Fl_PNG_Image("../resources/spade.png")),
	png_star(new Fl_PNG_Image("../resources/star.png")),
	png_correct(new Fl_PNG_Image("../resources/ind_correct_s.png")),
	png_incorrect(new Fl_PNG_Image("../resources/ind_incorrect_s.png")),
	png_background(new Fl_PNG_Image("../resources/background.png")),
	png_remaining_one(new Fl_PNG_Image("../resources/ind_remaining_one.png")),
	png_remaining_many(new Fl_PNG_Image("../resources/ind_remaining_many.png")),
	bmp_icon(new Fl_BMP_Image("../resources/logo.bmp")),
	num_comb_displayed(true),
	points_displayed(true),
	guess_guaranteed_displayed(true),
	menu_bar(nullptr),
	txt_finished_msg(nullptr),
	txt_points(nullptr)
{
	create_fltk_elements();
	resizable(NULL);
	size_range(width, height, width, height, width, height, 0);
}


MyWindow::~MyWindow()
{
	clear_screen();
	delete btn_smiley;
	delete btn_club;
	delete btn_spade;
	delete btn_heart;
	delete btn_diamond;
	delete btn_star;

	delete btn_clear;
	delete btn_enter;
	delete btn_new_game;

	delete png_smiley;
	delete png_club;
	delete png_spade;
	delete png_heart;
	delete png_diamond;
	delete png_star;
	
	delete png_correct;
	delete png_incorrect;

	delete png_background;
	delete png_remaining_many;
	delete png_remaining_one;
	delete bmp_icon;

	delete txt_points;

	delete box_guess_guaranteed;

	delete menu_bar;

	delete txt_finished_msg;

}

bool MyWindow::wait_for_button()
{
	//for the alternatinve handling of the actions, check the Simple_window::wait_for_button() 
	//function implementation in the SimpleWindow.cpp
	show();
	Fl::run();
	return true;
}

void MyWindow::start_new_game()
{
	game = Game();
	clear_screen();
}

void MyWindow::clear_screen()
{
	for (int i = 0; i < elements.size();++i) {
		Fl::delete_widget(elements[i]);
	}

	for (int i = 0; i < shapes.size(); ++i) {
		detach(*shapes[i]);
		delete shapes[i];
	}
	shapes.clear();

	elements.clear();
	// combinations_remaining_numbers can be cleared because all the items contained in it 
	// were also already in elements, and elements Widgets were deleted.
	combinations_remaining_numbers.clear();

	refresh_points();
	refresh_guess_guaranteed();

	// hide the winning message
	displayed_finished_msg(game.is_finished(),false);

	redraw();
}

void MyWindow::clear_curr_guess()
{
	if (!game.is_finished()) {
		for (int i = 0; i < game.get_curr_col(); i++)
		{
			Fl::delete_widget(elements[elements.size() - 1]);
			elements.pop_back();
		}
		game.clear_guess();
	}
}

void MyWindow::enter_curr_guess()
{
	if (game.is_finished() || game.get_curr_col() < NUM_POSITIONS) {
		return;
	}
	bool guessed_correctly = game.evaluate_guess();
	if (guessed_correctly) {
		add_remaining_num();
		add_guess_indicators();
		game.enter_guess();
		add_correct_comb();
	}
	else {
		add_remaining_num();
		add_guess_indicators();
		game.enter_guess();
		if (game.is_finished()) {
			add_correct_comb();
		}
	}
	displayed_finished_msg(game.is_finished(),guessed_correctly);

	refresh_points();
	refresh_guess_guaranteed();
}

void MyWindow::add_guess_indicators()
{
	for (int i = 0; i < game.get_correct_pos(); ++i){

		begin();
		//this is a way to add new images
		//fl_register_images();
		//Fl_PNG_Image* p1 = new Fl_PNG_Image("ind_correct_s.png");
		
		Fl_Box* b1 = new Fl_Box(IND_COL_START + SPACING * i, IND_ROW_START+ SPACING * game.get_curr_row(), BOX_SIZE, BOX_SIZE);
		elements.push_back(b1);
		b1->image(png_correct);
		b1->tooltip("Correct sign at the correct possition.");
		b1->redraw();
		end();

	}

	for (int i = game.get_correct_pos(); i < game.get_incorrect_pos() + game.get_correct_pos();++i) {

		begin();
		Fl_Box* b2 = new Fl_Box(IND_COL_START + SPACING * i, IND_ROW_START + SPACING * game.get_curr_row(), BOX_SIZE, BOX_SIZE);
		b2->image(png_incorrect);
		b2->tooltip("Correct sign at the incorrect possition.");
		elements.push_back(b2);
		b2->redraw();
		end();

	}
}

void MyWindow::add_remaining_num()
{
	game.update_possibilities();
	unsigned int remaining = game.get_num_possibilities();

	/*Alternative way to display the possibilities using the Text shape from graph lib*/
	//Text* txt = new Text(Point(TXT_COL_START, TXT_ROW_START + SPACING * game.get_curr_row() - 1), to_string(remaining));
	//txt->set_color(Color::black);
	//shapes.push_back(txt); //this collection has to be created and has to be empties when clearing the screen for this implmentation to work
	//if (num_comb_displayed) { 
	//	attach(*txt);
	//	redraw();
	//}

	begin();
	Fl_Box* txt = new Fl_Box(TXT_COL_START, TXT_ROW_START + SPACING * game.get_curr_row() - 1, BOX_SIZE, BOX_SIZE);
	txt->copy_label(to_string(remaining).c_str());
	txt->tooltip("Number of combinations remaining that can possibly be correct.");
	elements.push_back(txt);
	combinations_remaining_numbers.push_back(txt);
	if (!num_comb_displayed) {
		txt->hide();
	}
	end();
}

void MyWindow::add_sign(Game::Signs sign_type)
{
	//game class checks if the sign can be added, and if adding is successfull, it should be displayed imediately
	if (game.add_sign(sign_type)) {
		begin();
		Fl_Box* box1 = new Fl_Box(SIGN_COL_START + SPACING * game.get_curr_col(), SIGN_ROW_START + SPACING * game.get_curr_row(), BOX_SIZE, BOX_SIZE);
		end();
		switch (sign_type)
		{
		case Game::SMILEY:
			box1->tooltip("Smiley");
			box1->image(png_smiley);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::CLUB:
			box1->tooltip("Club");
			box1->image(png_club);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::SPADE:
			box1->tooltip("Spade");
			box1->image(png_spade);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::HEART:
			box1->tooltip("Heart");
			box1->image(png_heart);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::DIAMOND:
			box1->tooltip("Diamond");
			box1->image(png_diamond);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::STAR:
			box1->tooltip("Star");
			box1->image(png_star);
			elements.push_back(box1);
			box1->redraw();
			break;
		default:
			delete box1;
			break;
		}
	}
}

void MyWindow::add_correct_comb()
{
	for (int  i = 0; i < game.get_correct_comb().get_size(); i++)
	{
		begin();
		Fl_Box* box1 = new Fl_Box(SIGN_COL_START + SPACING * (i+1), SIGN_CORRECT_ROW_START, BOX_SIZE, BOX_SIZE);
		end();
		Sign s = game.get_correct_comb().get_signs()[i];

		switch (Game::Signs(s.get_id()))
		{
		case Game::SMILEY:
			box1->tooltip("Smiley");
			box1->image(png_smiley);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::CLUB:
			box1->tooltip("Club");
			box1->image(png_club);
			elements.push_back(box1);

			box1->redraw();
			break;
		case Game::SPADE:
			box1->tooltip("Spade");
			box1->image(png_spade);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::HEART:
			box1->tooltip("Heart");
			box1->image(png_heart);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::DIAMOND:
			box1->tooltip("Diamond");
			box1->image(png_diamond);
			elements.push_back(box1);
			box1->redraw();
			break;
		case Game::STAR:
			box1->tooltip("Star");
			box1->image(png_star);
			elements.push_back(box1);
			box1->redraw();
			break;
		default:
			delete box1;
			break;
		}
	}
}

void MyWindow::refresh_points()
{
	txt_points->copy_label(to_string(game.get_points()).c_str());
	txt_points->redraw();
}

void MyWindow::refresh_guess_guaranteed()
{
	if (game.get_num_possibilities() == 1) {
		box_guess_guaranteed->image(png_remaining_one);
	}
	else {
		box_guess_guaranteed->image(png_remaining_many);
	}
	box_guess_guaranteed->redraw();
}

void MyWindow::toggle_num_combs()
{
	num_comb_displayed = !num_comb_displayed;
	for each (Fl_Widget* var in combinations_remaining_numbers)
	{
		if (num_comb_displayed==true)
		{
			var->show();
		}
		else {
			var->hide();
		}	
	}
}

void MyWindow::toggle_points_displayed()
{
	points_displayed = !points_displayed;
	if (points_displayed == true)
	{
		txt_points->show();
	}
	else {
		txt_points->hide();
	}
}

void MyWindow::toggle_guess_guaranteed()
{
	guess_guaranteed_displayed = !guess_guaranteed_displayed;
	if (guess_guaranteed_displayed == true)
	{
		box_guess_guaranteed->show();
	}
	else {
		box_guess_guaranteed->hide();
	}
}

void MyWindow::displayed_finished_msg(bool finished, bool is_won)
{
	if (finished)
	{
		if (is_won)
		{
			txt_finished_msg->copy_label(MSG_WIN);
		}
		else
		{
			txt_finished_msg->copy_label(MSG_LOSS);
		}
		txt_finished_msg->show();
	}
	else {
		txt_finished_msg->hide();
	}
}

