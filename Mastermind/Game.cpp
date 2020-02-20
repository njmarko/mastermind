//============================================================================
// Name        : Game.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.20.2020
// Copyright   : GPLv3
// Description : Implementation of the Game class
//============================================================================


#include "Game.h"

Game::Game():game_ended(false)
{
	srand((unsigned)time(0));
	for (int i = 0; i < 4; ++i) {
		correct_comb.add_sign(rand()%6);
	}
}

Game::~Game()
{
}

bool Game::add_sign(Signs s)
{
	if (guess_comb.get_size()<num_signs && !game_ended)
	{
		guess_comb.add_sign(s);
		return true;
	}
	else
	{
		return false;
	}
	
}

int Game::get_curr_row() const
{
	return played_combs.size();
}

int Game::get_curr_col() const
{
	return guess_comb.get_size();
}

void Game::clear_guess()
{
	guess_comb.clear_comb();
	
}

void Game::enter_guess()
{
	played_combs.push_back(guess_comb);
	guess_comb = Combination();
}

bool Game::evaluate_guess()
{
	return guess_comb.compare_combinations(correct_comb);;
}

int Game::get_correct_pos() const
{
	return guess_comb.get_correct_pos();
}

int Game::get_incorrect_pos() const
{
	return guess_comb.get_incorrect_pos();
}

bool Game::is_finished() const
{
	return game_ended;
}

void Game::finish_game()
{
	game_ended = true;
}

