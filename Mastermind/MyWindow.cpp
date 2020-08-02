//============================================================================
// Name        : MyWindow.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 03.11.2020
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

void MyWindow::create_fltk_elements()
{
	begin();
	//signs
	btn_smiley = new Fl_Button(BUTTON_COL, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_club = new Fl_Button(BUTTON_COL + BUTTON_W, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_spade = new Fl_Button(BUTTON_COL + BUTTON_W * 2, BUTTON_ROW, BUTTON_W, BUTTON_H);
	btn_hearth = new Fl_Button(BUTTON_COL, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);
	btn_diamon = new Fl_Button(BUTTON_COL + BUTTON_W, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);
	btn_star = new Fl_Button(BUTTON_COL + BUTTON_W * 2, BUTTON_ROW + BUTTON_H, BUTTON_W, BUTTON_H);

	//removes borders from the sign buttons
	btn_smiley->box(FL_NO_BOX);
	btn_club->box(FL_NO_BOX);
	btn_spade->box(FL_NO_BOX);
	btn_hearth->box(FL_NO_BOX);
	btn_diamon->box(FL_NO_BOX);
	btn_star->box(FL_NO_BOX);

	//callback functions for signs
	btn_smiley->callback(cb_add_sign, (void*)Game::SMILEY);
	btn_club->callback(cb_add_sign, (void*)Game::CLUB);
	btn_spade->callback(cb_add_sign, (void*)Game::SPADE);
	btn_hearth->callback(cb_add_sign, (void*)Game::HEARTH);
	btn_diamon->callback(cb_add_sign, (void*)Game::DIAMOND);
	btn_star->callback(cb_add_sign, (void*)Game::STAR);
	
	//sets images for the sign buttons
	btn_star->image(png_star);
	btn_club->image(png_club);
	btn_diamon->image(png_diamond);
	btn_hearth->image(png_hearth);
	btn_spade->image(png_spade);
	btn_smiley->image(png_smiley);

	//adds the keyboard shortcuts for the sign buttons
	btn_smiley->shortcut('q');
	btn_club->shortcut('w');
	btn_spade->shortcut('e');
	btn_hearth->shortcut('a');
	btn_diamon->shortcut('s');
	btn_star->shortcut('d');
	
	btn_enter = new Fl_Button(400, 500, 100, 50, "Enter");
	btn_clear = new Fl_Button(400, 550, 100, 50, "Clear");
	btn_new_game = new Fl_Button(500, 500, 100, 100, "New Game");

	//adds the keyboard shortcuts for the rest of the buttons
	btn_enter->shortcut(FL_KEYBOARD | FL_Enter);
	btn_clear->shortcut(FL_KEYBOARD | FL_BackSpace);
	btn_new_game->shortcut('n');

	btn_clear->callback(cb_clear_guess);
	btn_enter->callback(cb_enter_guess);
	btn_new_game->callback(cb_new_game);

	end();
}

MyWindow::MyWindow(Point xy, int width, int height, const string & title) :
	Window(xy, width, height, title),
	game(),
	btn_smiley(nullptr),
	btn_club(nullptr),
	btn_spade(nullptr),
	btn_hearth(nullptr),
	btn_diamon(nullptr),
	btn_star(nullptr),
	btn_clear(nullptr),
	btn_enter(nullptr),
	btn_new_game(nullptr),
	png_club(new Fl_PNG_Image("../resources/club.png")),
	png_diamond(new Fl_PNG_Image("../resources/diamond.png")),
	png_hearth(new Fl_PNG_Image("../resources/hearth.png")),
	png_smiley(new Fl_PNG_Image("../resources/smiley.png")),
	png_spade(new Fl_PNG_Image("../resources/spade.png")),
	png_star(new Fl_PNG_Image("../resources/star.png")),
	png_correct(new Fl_PNG_Image("../resources/ind_correct_s.png")),
	png_incorrect(new Fl_PNG_Image("../resources/ind_incorrect_s.png"))
{
	create_fltk_elements();

}


MyWindow::~MyWindow()
{

	delete btn_smiley;
	delete btn_club;
	delete btn_spade;
	delete btn_hearth;
	delete btn_diamon;
	delete btn_star;

	delete btn_clear;
	delete btn_enter;
	delete btn_new_game;

	delete png_smiley;
	delete png_club;
	delete png_spade;
	delete png_hearth;
	delete png_diamond;
	delete png_star;
	
	delete png_correct;
	delete png_incorrect;

	clear_screen();
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
	clear_screen();
	game = Game();
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

	elements.clear();
	shapes.clear();
	redraw();
}

void MyWindow::clear_curr_guess()
{
	for (int i = 0; i < game.get_curr_col(); i++)
	{
		Fl::delete_widget(elements[elements.size() - 1]);
		elements.pop_back();
	}	
	game.clear_guess();
}

void MyWindow::enter_curr_guess()
{
	if (game.is_finished() || game.get_curr_col() < NUM_POSITIONS) {
		return;
	}
	if (game.evaluate_guess()) {
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
		end();

	}

	for (int i = game.get_correct_pos(); i < game.get_incorrect_pos() + game.get_correct_pos();++i) {

		begin();
		Fl_Box* b2 = new Fl_Box(IND_COL_START + SPACING * i, IND_ROW_START + SPACING * game.get_curr_row(), BOX_SIZE, BOX_SIZE);
		b2->image(png_incorrect);
		elements.push_back(b2);
		end();

	}
}

void MyWindow::add_remaining_num()
{
	game.update_possibilities();
	unsigned int remaining = game.get_num_possibilities();

	Text* txt = new Text(Point(TXT_COL_START, TXT_ROW_START + SPACING * game.get_curr_row() - 1), to_string(remaining));
	txt->set_color(Color::black);
	attach(*txt);
	shapes.push_back(txt);
	redraw();
	
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
			box1->image(png_smiley);
			elements.push_back(box1);
			redraw();
			break;
		case Game::CLUB:
			box1->image(png_club);
			elements.push_back(box1);
			redraw();
			break;
		case Game::SPADE:
			box1->image(png_spade);
			elements.push_back(box1);
			redraw();
			break;
		case Game::HEARTH:
			box1->image(png_hearth);
			elements.push_back(box1);
			redraw();
			break;
		case Game::DIAMOND:
			box1->image(png_diamond);
			elements.push_back(box1);
			redraw();
			break;
		case Game::STAR:
			box1->image(png_star);
			elements.push_back(box1);
			redraw();
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
		Fl_Box* box1 = new Fl_Box(SIGN_COL_START + SPACING * (i+1), SIGN_CORRECT_START, BOX_SIZE, BOX_SIZE);
		end();
		Sign s = game.get_correct_comb().get_signs()[i];

		switch (Game::Signs(s.get_id()))
		{
		case Game::SMILEY:
			box1->image(png_smiley);
			elements.push_back(box1);
			redraw();
			break;
		case Game::CLUB:
			box1->image(png_club);
			elements.push_back(box1);
			redraw();
			break;
		case Game::SPADE:
			box1->image(png_spade);
			elements.push_back(box1);
			redraw();
			break;
		case Game::HEARTH:
			box1->image(png_hearth);
			elements.push_back(box1);
			redraw();
			break;
		case Game::DIAMOND:
			box1->image(png_diamond);
			elements.push_back(box1);
			redraw();
			break;
		case Game::STAR:
			box1->image(png_star);
			elements.push_back(box1);
			redraw();
			break;
		default:
			delete box1;
			break;
		}
	}
}
