// CbuttonDoc.cpp : implementation of the CCbuttonDoc class
// Download by http://www.srcfans.com

#include "stdafx.h"
#include "Cbutton.h"

#include "CbuttonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCbuttonDoc

IMPLEMENT_DYNCREATE(CCbuttonDoc, CDocument)

BEGIN_MESSAGE_MAP(CCbuttonDoc, CDocument)
	//{{AFX_MSG_MAP(CCbuttonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCbuttonDoc construction/destruction

CCbuttonDoc::CCbuttonDoc()
{
	// TODO: add one-time construction code here

}

CCbuttonDoc::~CCbuttonDoc()
{
}

BOOL CCbuttonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCbuttonDoc serialization

void CCbuttonDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCbuttonDoc diagnostics

#ifdef _DEBUG
void CCbuttonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCbuttonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCbuttonDoc commands
