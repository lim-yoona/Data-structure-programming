// Cbutton.h : main header file for the CBUTTON application
//

#if !defined(AFX_CBUTTON_H__240DD99D_BEDE_49BD_A960_3268C3644816__INCLUDED_)
#define AFX_CBUTTON_H__240DD99D_BEDE_49BD_A960_3268C3644816__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCbuttonApp:
// See Cbutton.cpp for the implementation of this class
//

class CCbuttonApp : public CWinApp
{
public:
	CCbuttonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCbuttonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCbuttonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CBUTTON_H__240DD99D_BEDE_49BD_A960_3268C3644816__INCLUDED_)
