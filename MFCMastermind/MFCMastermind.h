
// MFCMastermind.h : main header file for the MFCMastermind application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMastermindApp:
// See MFCMastermind.cpp for the implementation of this class
//

class CMFCMastermindApp : public CWinApp
{
public:
	CMFCMastermindApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMastermindApp theApp;
