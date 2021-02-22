

#include "stdafx.h"
#include "Cbutton.h"
#include <queue>
#include "CbuttonDoc.h"
#include "CbuttonView.h"
#include<time.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDB_ZLH 0
/////////////////////////////////////////////////////////////////////////////
// CCbuttonView

IMPLEMENT_DYNCREATE(CCbuttonView, CView)

BEGIN_MESSAGE_MAP(CCbuttonView, CView)
	//{{AFX_MSG_MAP(CCbuttonView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_CANCELMODE()
	ON_COMMAND(ID_MENU_CAPTION, OnMenuCaption)
	ON_COMMAND(ID_MENU_NEW, OnMenuNew)
	ON_COMMAND(ID_MENU_OUT, OnMenuOut)
	ON_COMMAND(ID_MACHINE, OnMachine)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()



int Click(int GamePanel[30][30], int x, int y, int mine[30][30], int n, int m)
{
	if (GamePanel[x][y] >= 0)
		return 2;
	if (mine[x][y] == 1)
	{
		//cout<<"You lose"<<endl;
		return 1;
	}
	int counter = 0;
	if ((y - 1 >= 0) && mine[x][y - 1] == 1)
		counter++;
	if ((x - 1 >= 0) && (y - 1 >= 0) && mine[x - 1][y - 1] == 1)
		counter++;
	if ((x - 1 >= 0) && mine[x - 1][y] == 1)
		counter++;
	if ((x - 1 >= 0) && (y + 1 < m) && mine[x - 1][y + 1] == 1)
		counter++;
	if ((y + 1 < m) && mine[x][y + 1] == 1)
		counter++;
	if ((x + 1 < n) && (y + 1 < m) && mine[x + 1][y + 1] == 1)
		counter++;
	if ((x + 1 < n) && mine[x + 1][y] == 1)
		counter++;
	if ((x + 1 < n) && (y - 1 >= 0) && mine[x + 1][y - 1] == 1)
		counter++;
	GamePanel[x][y] = counter;
	if (counter > 0)
		return 0;
	if ((y - 1 >= 0) && mine[x][y - 1] == 0)
		Click(GamePanel, x, y - 1, mine, n, m);
	if ((x - 1 >= 0) && (y - 1 >= 0) && mine[x - 1][y - 1] == 0)
		Click(GamePanel, x - 1, y - 1, mine, n, m);
	if ((x - 1 >= 0) && mine[x - 1][y] == 0)
		Click(GamePanel, x - 1, y, mine, n, m);
	if ((x - 1 >= 0) && (y + 1 < m) && mine[x - 1][y + 1] == 0)
		Click(GamePanel, x - 1, y + 1, mine, n, m);
	if ((y + 1 < m) && mine[x][y + 1] == 0)
		Click(GamePanel, x, y + 1, mine, n, m);
	if ((x + 1 < n) && (y + 1 < m) && mine[x + 1][y + 1] == 0)
		Click(GamePanel, x + 1, y + 1, mine, n, m);
	if ((x + 1 < n) && mine[x + 1][y] == 0)
		Click(GamePanel, x + 1, y, mine, n, m);
	if ((x + 1 < n) && (y - 1 >= 0) && mine[x + 1][y - 1] == 0)
		Click(GamePanel, x + 1, y - 1, mine, n, m);
}
bool IsWin(int GamePanel[30][30], int mine[30][30], int n, int m)
{
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (GamePanel[x][y] < 0 && mine[x][y] == 0)
				return false;
		}
	}
	//cout<<"You win"<<endl;
	return true;
}
/******************************************************************************************************************/
/************************************************需要添加的两个函数如下********************************************/
int CCbuttonView::RefreshGamePanel(int GamePanel[30][30], int x, int y, int mine[30][30], int n, int m, int k)
{
	//请将你封装的RefreshGamePanel函数体添加到此处，并去掉下行的return 0
	int j;
	j = Click(GamePanel, x, y, mine, n, m);
	if (j == 1)
		return -1;
	/*if(j==2)
	continue;*/
	/*for(int c=0;c<n;c++)
	{
		for(int d=0;d<m-1;d++)
		{
			cout<<setw(2)<<GamePanel[c][d]<<' ';
		}
		cout<<GamePanel[c][m-1]<<endl;
		//cout<<endl;
	} */
	if (IsWin(GamePanel, mine, n, m))
		return 1;
	//cout<<endl;
	return 0;
}
int BlankNumber(int GamePanel[30][30], int n, int m, int i, int j)
{
	int counter = 0;
	if ((j - 1 >= 0) && GamePanel[i][j - 1] == -1)
		counter++;
	if ((i - 1 >= 0) && (j - 1 >= 0) && GamePanel[i - 1][j - 1] == -1)
		counter++;
	if ((i - 1 >= 0) && GamePanel[i - 1][j] == -1)
		counter++;
	if ((i - 1 >= 0) && (j + 1 < m) && GamePanel[i - 1][j + 1] == -1)
		counter++;
	if ((j + 1 < m) && GamePanel[i][j + 1] == -1)
		counter++;
	if ((i + 1 < n) && (j + 1 < m) && GamePanel[i + 1][j + 1] == -1)
		counter++;
	if ((i + 1 < n) && GamePanel[i + 1][j] == -1)
		counter++;
	if ((i + 1 < n) && (j - 1 >= 0) && GamePanel[i + 1][j - 1] == -1)
		counter++;
	return counter;
}
void PutFlag(int GamePanel[30][30], int MineLocation[30][30], int n, int m, int i, int j)
{
	if ((j - 1 >= 0) && GamePanel[i][j - 1] == -1)
		MineLocation[i][j - 1] = 1;
	if ((i - 1 >= 0) && (j - 1 >= 0) && GamePanel[i - 1][j - 1] == -1)
		MineLocation[i - 1][j - 1] = 1;
	if ((i - 1 >= 0) && GamePanel[i - 1][j] == -1)
		MineLocation[i - 1][j] = 1;
	if ((i - 1 >= 0) && (j + 1 < m) && GamePanel[i - 1][j + 1] == -1)
		MineLocation[i - 1][j + 1] = 1;
	if ((j + 1 < m) && GamePanel[i][j + 1] == -1)
		MineLocation[i][j + 1] = 1;
	if ((i + 1 < n) && (j + 1 < m) && GamePanel[i + 1][j + 1] == -1)
		MineLocation[i + 1][j + 1] = 1;
	if ((i + 1 < n) && GamePanel[i + 1][j] == -1)
		MineLocation[i + 1][j] = 1;
	if ((i + 1 < n) && (j - 1 >= 0) && GamePanel[i + 1][j - 1] == -1)
		MineLocation[i + 1][j - 1] = 1;
}
int FindFlag(int MineLocation[30][30], int n, int m, int i, int j)
{
	int counter = 0;
	if ((j - 1 >= 0) && MineLocation[i][j - 1] == 1)
		counter++;
	if ((i - 1 >= 0) && (j - 1 >= 0) && MineLocation[i - 1][j - 1] == 1)
		counter++;
	if ((i - 1 >= 0) && MineLocation[i - 1][j] == 1)
		counter++;
	if ((i - 1 >= 0) && (j + 1 < m) && MineLocation[i - 1][j + 1] == 1)
		counter++;
	if ((j + 1 < m) && MineLocation[i][j + 1] == 1)
		counter++;
	if ((i + 1 < n) && (j + 1 < m) && MineLocation[i + 1][j + 1] == 1)
		counter++;
	if ((i + 1 < n) && MineLocation[i + 1][j] == 1)
		counter++;
	if ((i + 1 < n) && (j - 1 >= 0) && MineLocation[i + 1][j - 1] == 1)
		counter++;
	return counter;
}
void Position(int GamePanel[30][30], int MineLocation[30][30], int n, int m, int i, int j, int& x, int& y)
{
	//cout<<"Posution"<<endl;
	if ((j - 1 >= 0) && GamePanel[i][j - 1] == -1 && MineLocation[i][j - 1] != 1)
	{
		x = i;
		y = j - 1;
		return;
	}
	if ((i - 1 >= 0) && (j - 1 >= 0) && GamePanel[i - 1][j - 1] == -1 && MineLocation[i - 1][j - 1] != 1)
	{
		x = i - 1;
		y = j - 1;
		return;
	}
	if ((i - 1 >= 0) && GamePanel[i - 1][j] == -1 && MineLocation[i - 1][j] != 1)
	{
		x = i - 1;
		y = j;
		return;
	}
	if ((i - 1 >= 0) && (j + 1 < m) && GamePanel[i - 1][j + 1] == -1 && MineLocation[i - 1][j + 1] != 1)
	{
		x = i - 1;
		y = j + 1;
		return;
	}
	if ((j + 1 < m) && GamePanel[i][j + 1] == -1 && MineLocation[i][j + 1] != 1)
	{
		x = i;
		y = j + 1;
		return;
	}
	if ((i + 1 < n) && (j + 1 < m) && GamePanel[i + 1][j + 1] == -1 && MineLocation[i + 1][j + 1] != 1)
	{
		x = i + 1;
		y = j + 1;
		return;
	}
	if ((i + 1 < n) && GamePanel[i + 1][j] == -1 && MineLocation[i + 1][j] != 1)
	{
		x = i + 1;
		y = j;
		return;
	}
	if ((i + 1 < n) && (j - 1 >= 0) && GamePanel[i + 1][j - 1] == -1 && MineLocation[i + 1][j - 1] != 1)
	{
		x = i + 1;
		y = j - 1;
		return;
	}
}
void CCbuttonView::machine(int GamePanel[30][30], int n, int m, int &x, int &y)
{
	//请将你实现的machine函数体添加到此处
	int MineLocation[30][30];//雷位置的记录矩阵，有为1，无为零 
	//初始化雷矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			MineLocation[i][j] = 0;
	}
	//srand(time(0));
	int sigh = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (GamePanel[i][j] == 0)
				sigh = 1;
		}
	}
	//cout<<"sigh:"<<sigh<<endl;
	if (sigh == 0)
	{
		int i, j;
		x = n - 1;
		y = m - 1;
		if (GamePanel[x][y] == -1)
			return;
		i = (rand()) % n;
		j = (rand()) % m;
		while (GamePanel[i][j] != -1)
		{
			i = (rand()) % n;
			j = (rand()) % m;
		}
		x = i;
		y = j;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (GamePanel[i][j] == -1 || GamePanel[i][j] == 0)
				continue;
			if (BlankNumber(GamePanel, n, m, i, j) == GamePanel[i][j])
				PutFlag(GamePanel, MineLocation, n, m, i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (GamePanel[i][j] == -1 || GamePanel[i][j] == 0)
				continue;
			if (FindFlag(MineLocation, n, m, i, j) == GamePanel[i][j] && BlankNumber(GamePanel, n, m, i, j) > GamePanel[i][j])
			{
				Position(GamePanel, MineLocation, n, m, i, j, x, y);
				return;
			}
		}
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(GamePanel[i][j]==-1||GamePanel[i][j]==0)
			continue;
			if(FindFlag(MineLocation,n,m,i,j)==GamePanel[i][j]&&BlankNumber(GamePanel,n,m,i,j)>GamePanel[i][j])
			{
				Position(GamePanel,MineLocation,n,m,i,j,x,y);
				return ;
			}
		}
	}*/
	//cout<<"machine"<<endl;
	int ii;
	int jj;
	ii = rand() % n;
	jj = rand() % m;
	while (GamePanel[ii][jj] != -1 || MineLocation[ii][jj] == 1)
	{
		//cout<<"ii"<<ii<<' ';
		//cout<<"jj"<<jj<<endl;
		ii = rand() % n;
		jj = rand() % m;
	}
	x = ii;
	y = jj;
	return;
}
/************************************************需要添加的两个函数如上********************************************/
/******************************************************************************************************************/






/*************************************以下代码不用管********************************************/

CCbuttonView::CCbuttonView()
{

	// TODO: add construction code here
	srand(int(time(0)));
	minenum=50;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{	
			mine[i][j]=0;
			GamePanel[i][j]=-1;
		}

	/*for(int k=0;k<minenum;k++)
	{
		i=rand()%20;
		j=rand()%20;
		while(mine[i][j]!=0)
		{
			i=rand()%20;
			j=rand()%20;
		}
		mine[i][j]=1;
	}*/
	clickcount = 0;
	x=0;y=0;
	id=0;
	i=0;j=0;
	showmine=-1;
	win=0;
	current_j=-1;
	current_i=-1;
}

CCbuttonView::~CCbuttonView()
{
}


void CCbuttonView::OnMenuNew() 
{
	// TODO: Add your command handler code here
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		{	
			mine[i][j]=0;
			GamePanel[i][j]=-1;
			::ShowWindow(cbutton[i][j],SW_SHOW);
		}
		
		/*for(int k=0;k<minenum;k++)
		{
			i=rand()%20;
			j=rand()%20;
			while(mine[i][j]!=0)
			{
				i=rand()%20;
				j=rand()%20;
			}
			mine[i][j]=1;
		}*/
		x=0;y=0;
		id=0;
		i=0;j=0;
		win=0;
		clickcount = 0;
		showmine=-1;
		current_i=-1;
		current_j=-1;
		CRect rect1;
		GetClientRect(&rect1);
		InvalidateRect(rect1);

}
void CCbuttonView::OnMenuOut() 
{
	// TODO: Add your command handler code here
	 
	//PostQuitMessage(0);
	exit(0) ;
}


BOOL CCbuttonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCbuttonView drawing

void CCbuttonView::OnDraw(CDC* pDC)
{
	CCbuttonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCbuttonView printing

BOOL CCbuttonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCbuttonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCbuttonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCbuttonView diagnostics

#ifdef _DEBUG
void CCbuttonView::AssertValid() const
{
	CView::AssertValid();
}

void CCbuttonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCbuttonDoc* CCbuttonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCbuttonDoc)));
	return (CCbuttonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCbuttonView message handlers

int CCbuttonView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	id = 0;
	x=0;y=0;
	int realid;
	for(i=0;i<20;i++)
	 {
		 for(j=0;j<20;j++)
		 {
			 if (id == 0) realid = 1;
			 else realid = id;
			  cbutton[i][j].Create("",WS_CHILD | WS_VISIBLE,CRect(x,y,x+20,y+20),this,realid);
			  x+=20;
			  id+=20;
		 }
		 x=0;
		 y+=20;
	 }
     return 0;
}

void CCbuttonView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	
	CView::OnLButtonDown(nFlags, point);
}


void CCbuttonView::OnRButtonDown(UINT nFlags, CPoint point)			 
{
	// TODO: Add your message handler code here and/or call default
	/*for(int k=0;k<20;k++)
	{
	  ::ShowWindow(cbutton[i_lei[k]][j_lei[k]],SW_HIDE);
	}*/
	showmine*=-1;
		CClientDC dc(this);
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP_LEI);
	if(showmine==1)
	{
	
		CBrush brush(&bitmap);
		//cbutton[0][0].SetBitmap();
		//dc.FillRect(CRect(point.x,point.y,point.x+20,point.y+20),&brush);
		
		for(i=0;i<20;i++)
		{
			 for(j=0;j<20;j++)
			 {
				 if(mine[i][j]==1)
				 {
					 dc.FillRect(CRect(j*20,i*20,j*20+20,i*20+20),&brush);
				 }
			 }
		}
	}
	else{
	
		CRect rect1;
		GetClientRect(&rect1);
		InvalidateRect(rect1);
	}
	//cbutton[0][0].SetBitmap(bitmap);

	CView::OnRButtonDown(nFlags, point);
}

void CCbuttonView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
    CBrush brush(RGB(255,255,255));
	dc.SelectObject(&brush);
	dc.FillRect(CRect(0,0,800,600),&brush);

	CPen pen(PS_SOLID,1,RGB(180,180,180));
 
	for( i=0;i<420;i+=20)
	{
		dc.SelectObject(&pen);
		dc.MoveTo(i,0);
		dc.LineTo(i,440);
		dc.MoveTo(0,i);
		dc.LineTo(400,i);
	}
				
    COLORREF col=dc.SetBkColor(RGB(255,255,255));
	dc.SetTextColor(RGB(0,0,255));

	if(win==0)
	{

		for(i=0;i<20;i++)
            for(j=0;j<20;j++)
			{
				if(GamePanel[i][j]==0)
					::ShowWindow(cbutton[i][j],SW_HIDE);
				else if(GamePanel[i][j]>0 && GamePanel[i][j]<9)
				{
					::ShowWindow(cbutton[i][j],SW_HIDE);
					str.Format("%d",GamePanel[i][j]);
					dc.SetTextColor(RGB(0,0,255));
					dc.DrawText(str,CRect(j*20,i*20,j*20+20,i*20+20),DT_CENTER);
				}
			}
	}
	else if(win==-1 || win==1)
	{
		
		for(i=0;i<20;i++)
            for(j=0;j<20;j++)
			{
				if(GamePanel[i][j]==0)
					::ShowWindow(cbutton[i][j],SW_HIDE);
				else if(GamePanel[i][j]>0 && GamePanel[i][j]<9)
				{
					::ShowWindow(cbutton[i][j],SW_HIDE);
					str.Format("%d",GamePanel[i][j]);
					dc.SetTextColor(RGB(0,0,255));
					dc.DrawText(str,CRect(j*20,i*20,j*20+20,i*20+20),DT_CENTER);
				}
				CBitmap bitmap,bitmap1;
				bitmap.LoadBitmap(IDB_BITMAP_LEI);
				CBrush brush(&bitmap);
		
				if(mine[i][j]==1)
				{
					::ShowWindow(cbutton[i][j],SW_HIDE);
					
					if(win==-1 && current_i==i && current_j==j)
					{
						bitmap1.LoadBitmap(IDB_REDMINE_BITMAP);
						CBrush brush1(&bitmap1);
						dc.FillRect(CRect(j*20,i*20,j*20+20,i*20+20),&brush1);
					}
					else dc.FillRect(CRect(j*20,i*20,j*20+20,i*20+20),&brush);

				}

			}
	}
	// Do not call CView::OnPaint() for painting messages
}


void CCbuttonView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CCbuttonView::OnMenuCaption() 
{
	// TODO: Add your command handler code here

  MessageBox("简易版扫雷游戏图形界面框架","扫雷");
}


BOOL CCbuttonView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
    
	int ii,jj,k,ButtonCmdId=LOWORD(wParam);
	//CString string;
	//string.Format("%d",ButtonCmdId);
	//MessageBox(string);
	if(ButtonCmdId==1)
	{
		ii = 0;
		jj = 0;
	}
	else
	{
		ii = (ButtonCmdId / 400);
		jj = (ButtonCmdId - 400 * ii) / 20;
	}
	//string.Format("%d,%d", ii, jj);
	//MessageBox(string);
	
	if (clickcount == 0)
	{
		for (int k = 0; k < minenum; k++)
		{
			i = rand() % 20;
			j = rand() % 20;
			while ( (i==ii && j==jj) || mine[i][j] != 0)
			{
				i = rand() % 20;
				j = rand() % 20;
			}
			mine[i][j] = 1;
		}
	}
	clickcount++;
		/********************************************************************/
		/***/ win=RefreshGamePanel(GamePanel,ii,jj,mine,20,20,minenum); /***/
        /********************************************************************/

		CRect rect1;
		GetClientRect(&rect1);
		current_j=jj;
		current_i=ii;
		
		if(win==-1 || win==1)
		{
			InvalidateRect(rect1);
		
			if(win==-1)
				MessageBox("你输了！点击确定重新开始","扫雷",MB_ICONEXCLAMATION);
			else MessageBox("恭喜，你赢了！点击确定重新开始","扫雷",MB_ICONINFORMATION);
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
				{	
					mine[i][j]=0;
					GamePanel[i][j]=-1;
					::ShowWindow(cbutton[i][j],SW_SHOW);
				}
			
			/*for(int k=0;k<minenum;k++)
			{
				i=rand()%20;
				j=rand()%20;
				while(mine[i][j]!=0)
				{
					i=rand()%20;
					j=rand()%20;
				}
				mine[i][j]=1;
			}*/
			clickcount = 0;
			x=0;y=0;
			id=0;
			i=0;j=0;
			win=0;
			showmine=-1;
			current_i=-1;
			current_j=-1;
			machinestart=false;
		}
		//InvalidateRect(rect1);
		{
			CClientDC dc(this); // device context for painting
			for(i=0;i<20;i++)
				for(j=0;j<20;j++)
				{
					if(GamePanel[i][j]==0)
						::ShowWindow(cbutton[i][j],SW_HIDE);
					else if(GamePanel[i][j]>0 && GamePanel[i][j]<9)
					{
						::ShowWindow(cbutton[i][j],SW_HIDE);
						str.Format("%d",GamePanel[i][j]);
						dc.SetTextColor(RGB(0,0,255));
						dc.DrawText(str,CRect(j*20,i*20,j*20+20,i*20+20),DT_CENTER);
					}
				}
			
		}
	
	return CView::OnCommand(wParam, lParam);
}

void CCbuttonView::OnMachine() 
{
	// TODO: Add your command handler code here
	int x = -1, y = -1;
	machinestart = true;
	int tim = 50, count = 0;
	while (machinestart && count<400)
	{
		/****************************************************/
		/*********/machine(GamePanel, 20, 20, x, y);/********/
		/****************************************************/
		if (x<0 || x>19 || y<0 || y>19) break;
		count++;
		SendMessage(WM_COMMAND, MAKEWPARAM(x * 400 + 20 * y, BN_CLICKED), 0);
		Sleep(tim);
	}
}

