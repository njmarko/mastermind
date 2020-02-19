//============================================================================
// Name        : MyWindow.cpp
// Author      : Marko Njegomir sw-38-2018
// Date        : 02.19.2020
// Copyright   : GPLv3
// Description : Implementation of MyWindow class
//============================================================================
#pragma once

#include "MyWindow.h"

void MyWindow::create_fltk_elements()
{
	begin();

	end();
}


MyWindow::MyWindow(Point xy, int width, int height, const string & title) :
	Window(xy, width, height, title)
{
	create_fltk_elements();
}


MyWindow::~MyWindow()
{

}

bool MyWindow::wait_for_button()
{
	show();
	Fl::run();
	return true;
}

void MyWindow::clear_shapes()
{
}
