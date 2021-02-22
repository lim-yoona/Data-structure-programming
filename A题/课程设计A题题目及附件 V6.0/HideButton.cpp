// HideButton.cpp : implementation file
// Download by http://www.srcfans.com

#include "stdafx.h"
#include "Cbuttonview.h"
#include "HideButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHideButton

CHideButton::CHideButton()
{
}

CHideButton::~CHideButton()
{
}


BEGIN_MESSAGE_MAP(CHideButton, CButton)
	//{{AFX_MSG_MAP(CHideButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideButton message handlers

void CHideButton::OnHide()
{
	::ShowWindow(cbutton[0][0],SW_HIDE); 
}
