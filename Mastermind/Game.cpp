//============================================================================
// Name        : Game.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 11.17.2020
// Copyright   : GPLv3
// Description : Implementation of the Game class
//============================================================================


#include "Game.h"

Game::Game():game_ended(false),possibilities(NUM_SIGNS,NUM_POSITIONS),points(POINTS_START),one_comb_remaining(false), points_decr_v2(POINTS_DECREMENT_V2)
{
	// Generates a random combination that needs to be guessed
	srand((unsigned)time(0));
	for (int i = 0; i < 4; ++i) {
		correct_comb.add_sign(rand()%6);
	}

	// If you want to set your combination manually comment out the code above and uncomment the code below
	//correct_comb.add_sign(Signs::SPADE);
	//correct_comb.add_sign(Signs::SPADE);
	//correct_comb.add_sign(Signs::STAR);
	//correct_comb.add_sign(Signs::STAR);
}

Game::~Game()
{
}

bool Game::add_sign(const Signs& s)
{
	if (guess_comb.get_size()<NUM_POSITIONS && !game_ended)
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

int Game::get_points_decr_v2() const
{
	return points_decr_v2;
}

void Game::clear_guess()
{
	guess_comb.clear_comb();
	
}

void Game::enter_guess()
{
	played_combs.push_back(guess_comb);
	// if the correct combination is guessed.
	if (evaluate_guess()) {
		finish_game();
	}
	else {
		guess_comb = Combination();
		// if maximum number of guesses were entered, finish the game
		if (get_curr_row() >= NUM_ROWS) {
			finish_game();
		}
		else {
			update_points();
		}
	}
	if (get_num_possibilities()==1)
	{
		one_comb_remaining = true;
	}
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

void Game::update_possibilities()
{
	possibilities.update_possibilities(guess_comb, guess_comb.get_correct_pos(), guess_comb.get_incorrect_pos());
}

unsigned int Game::get_num_possibilities() const
{
	return possibilities.get_num_possibilities();
}

Combination Game::get_correct_comb() const
{
	return correct_comb;
}

void Game::update_points()
{
	if (one_comb_remaining && !is_finished()) {
		//version 1 of the scoring where 3 was subtracted after 
		//every wrong guess when there was only one combination remaining
		//points -= POINTS_DECREMENT;

		//version 2 of scoring where decrement starts at 5 and steadily decreases
		points -= points_decr_v2;
		update_points_decrement_v2();
	}
}

int Game::get_points() const
{
	return points;
}

void Game::update_points_decrement_v2()
{
	--points_decr_v2;
}

