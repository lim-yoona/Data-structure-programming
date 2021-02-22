#if !defined(AFX_HIDEBUTTON_H__AA24A36B_FA78_4C72_AF4A_B80DF607916B__INCLUDED_)
#define AFX_HIDEBUTTON_H__AA24A36B_FA78_4C72_AF4A_B80DF607916B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HideButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHideButton window

class CHideButton : public CCbuttonView
{
// Construction
public:
	CHideButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnHide();
	virtual ~CHideButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHideButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	int x;
	int y;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEBUTTON_H__AA24A36B_FA78_4C72_AF4A_B80DF607916B__INCLUDED_)
