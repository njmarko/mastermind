
// MFCMastermindView.cpp : implementation of the CMFCMastermindView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMastermind.h"
#endif

#include "MFCMastermindDoc.h"
#include "MFCMastermindView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMastermindView

IMPLEMENT_DYNCREATE(CMFCMastermindView, CView)

BEGIN_MESSAGE_MAP(CMFCMastermindView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCMastermindView construction/destruction

CMFCMastermindView::CMFCMastermindView()
{
	// TODO: add construction code here

}

CMFCMastermindView::~CMFCMastermindView()
{
}

BOOL CMFCMastermindView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMastermindView drawing

void CMFCMastermindView::OnDraw(CDC* /*pDC*/)
{
	CMFCMastermindDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCMastermindView printing

BOOL CMFCMastermindView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMastermindView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMastermindView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCMastermindView diagnostics

#ifdef _DEBUG
void CMFCMastermindView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMastermindView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMastermindDoc* CMFCMastermindView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMastermindDoc)));
	return (CMFCMastermindDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMastermindView message handlers
