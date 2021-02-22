// CbuttonDoc.h : interface of the CCbuttonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CBUTTONDOC_H__71C2E517_1911_4662_B46F_D2AADAF39F66__INCLUDED_)
#define AFX_CBUTTONDOC_H__71C2E517_1911_4662_B46F_D2AADAF39F66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCbuttonDoc : public CDocument
{
protected: // create from serialization only
	CCbuttonDoc();
	DECLARE_DYNCREATE(CCbuttonDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCbuttonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCbuttonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCbuttonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CBUTTONDOC_H__71C2E517_1911_4662_B46F_D2AADAF39F66__INCLUDED_)
