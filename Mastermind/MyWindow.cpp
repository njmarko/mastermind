//============================================================================
// Name        : MyWindow.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.21.2020
// Copyright   : GPLv3
// Description : Implementation of MyWindow class
//============================================================================
#pragma once

#include "MyWindow.h"


void MyWindow::add_sign(Fl_Widget * w, void * p)
{

	MyWindow &win = reference_to<MyWindow>(w->parent());

	if (win.game.add_sign(Game::Signs((int)p)))
	{

		Text* txt = new Text(Point(50 + 100 * win.game.get_curr_col(), 50 + 100*win.game.get_curr_row()), to_string((int)p));
		txt->set_color(Color::black);
		reference_to<MyWindow>(w->parent()).attach(*txt);
		win.shapes.push_back(txt);
		w->parent()->redraw();
	}

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
	skocko = new Fl_Button(100,650,100,50,"Skocko");
	tref = new Fl_Button(200, 650, 100, 50, "Tref");
	pik = new Fl_Button(300, 650, 100, 50, "Pik");
	herc = new Fl_Button(100, 700, 100, 50, "Herc");
	karo = new Fl_Button(200, 700, 100, 50, "Karo");
	zvezda = new Fl_Button(300, 700, 100, 50, "Zvezda");
	
	//callback functions for signs
	skocko->callback(add_sign, (void*)Game::SKOCKO);
	tref->callback(add_sign, (void*)Game::TREF);
	pik->callback(add_sign, (void*)Game::PIK);
	herc->callback(add_sign, (void*)Game::HERC);
	karo->callback(add_sign, (void*)Game::KARO);
	zvezda->callback(add_sign, (void*)Game::ZVEZDA);
	
	clear = new Fl_Button(500, 700, 100, 50, "Clear");
	enter = new Fl_Button(500, 650, 100, 50, "Enter");
	new_game = new Fl_Button(700, 650, 100, 100, "New Game");

	clear->callback(cb_clear_guess);
	enter->callback(cb_enter_guess);
	new_game->callback(cb_new_game);

	end();
}

MyWindow::MyWindow(Point xy, int width, int height, const string & title) :
	Window(xy, width, height, title),
	game(),
	skocko(nullptr),
	tref(nullptr),
	pik(nullptr),
	herc(nullptr),
	karo(nullptr),
	zvezda(nullptr),
	clear(nullptr),
	enter(nullptr),
	new_game(nullptr)
{
	create_fltk_elements();
}


MyWindow::~MyWindow()
{

	delete skocko;
	delete tref;
	delete pik;
	delete herc;
	delete karo;
	delete zvezda;

	delete clear;
	delete enter;
	delete new_game;

	clear_all_shapes();
}

bool MyWindow::wait_for_button()
{
	show();
	Fl::run();
	return true;
}

void MyWindow::start_new_game()
{
	clear_all_shapes();
	game = Game();
}

void MyWindow::clear_all_shapes()
{
	for (int i = 0; i < shapes.size();++i) {
		detach(*shapes[i]);
		delete shapes[i];
	}
	shapes.clear();
	redraw();
}

void MyWindow::clear_curr_guess()
{
	for (int i = 0; i < game.get_curr_col(); i++)
	{
		detach(*shapes[shapes.size()- 1]);
		Shape * s = shapes[shapes.size() - 1];
		shapes.pop_back();
		delete s;
	}
	game.clear_guess();
	
	redraw();
}

void MyWindow::enter_curr_guess()
{
	if (game.is_finished() || game.get_curr_col() < num_positions) {
		return;
	}
	if (game.evaluate_guess()) {
		add_remaining_num();
		add_guess_indicators();
		game.enter_guess();
		game.finish_game();
		
	}
	else {
		add_remaining_num();
		add_guess_indicators();
		game.enter_guess();
		if (game.get_curr_row() >= num_rows) {
			game.finish_game();
		}
	}

}

void MyWindow::add_guess_indicators()
{
	for (int i = 0; i < game.get_correct_pos(); ++i){

		Text* txt = new Text(Point(500 + 100 * i, 50 + 100 * game.get_curr_row()-1), "Tacan");
		txt->set_color(Color::black);
		attach(*txt);
		shapes.push_back(txt);
		redraw();
	}

	for (int i = game.get_correct_pos(); i < game.get_incorrect_pos() + game.get_correct_pos();++i) {
		Text* txt = new Text(Point(500 + 100 * i, 50 + 100 * game.get_curr_row()),"Pogresan"s);
		txt->set_color(Color::black);
		attach(*txt);
		shapes.push_back(txt);
		redraw();
	}
}

void MyWindow::add_remaining_num()
{
	game.update_possibilities();
	unsigned int remaining = game.get_num_possibilities();
	Text* txt = new Text(Point(20, 50 + 100 * game.get_curr_row() - 1), to_string(remaining));
	txt->set_color(Color::black);
	attach(*txt);
	shapes.push_back(txt);
	redraw();
}
