// CbuttonView.h : interface of the CCbuttonView class
// Download by http://www.srcfans.com
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CBUTTONVIEW_H__7E35BFD9_B8CA_41E4_ADBB_C878145E2260__INCLUDED_)
#define AFX_CBUTTONVIEW_H__7E35BFD9_B8CA_41E4_ADBB_C878145E2260__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCbuttonView : public CView
{
protected: // create from serialization only
	CCbuttonView();
	DECLARE_DYNCREATE(CCbuttonView)

// Attributes
public:
	CCbuttonDoc* GetDocument();

// Operations
public:
	int RefreshGamePanel(int GamePanel[30][30], int x,int y,int mine[30][30],int n,int m, int k);
	void machine(int GamePanel[30][30], int n,int m, int &x,int &y);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCbuttonView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
    
// Implementation
public:
	virtual ~CCbuttonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCbuttonView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	afx_msg void OnMenuCaption();
	afx_msg void OnMenuNew();
	afx_msg void OnMenuOut();
	afx_msg void OnMachine();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CButton cbutton[400][400];
	int i,j;
	int id;
	int x,y;
	CString str;
    int i_lei[20];
	int j_lei[20];
	int mine[30][30];
	int GamePanel[30][30];
	int showmine;
	int minenum;
	int win;
	int current_i;
	int current_j;
	bool machinestart;
	int clickcount;
};

#ifndef _DEBUG  // debug version in CbuttonView.cpp
inline CCbuttonDoc* CCbuttonView::GetDocument()
   { return (CCbuttonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CBUTTONVIEW_H__7E35BFD9_B8CA_41E4_ADBB_C878145E2260__INCLUDED_)
