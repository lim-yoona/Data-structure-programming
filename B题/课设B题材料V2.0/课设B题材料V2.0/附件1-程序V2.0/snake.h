#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
#define MEM(a,b) memset(a,(b),sizeof(a))
#define setcolor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)//设置颜色


const int maxiterationtime = 200;
struct point
{
	int x;
	int y;
};
struct GamePanel
{
	int n;		//地图规模
	int m;		//地图规模
	int totalfoodnum;		//当前地图中的食物总数
	int wallnum;			//障碍物总数
	int success_num;		//获胜所需吃的食物数
	int speednum;			//当前地图中倍速道具数
	int step_speed;			//玩家吃倍速道具后，走的步数，此变量值不超过50
	int obliquenum;			//当前地图中斜走道具数
	int speedowner;			//倍速道具的拥有者，值为0或1
	int obliqueowner[5];	//斜走道具的拥有者，obliqueowner[t]==1表示蛇t拥有斜走道具，obliqueowner[t]==0表示蛇t没吃斜走道具
	int currentfoodnum;		//当前地图中所剩食物数
	point food[20];			//当前地图中所有食物的坐标
	point wall[20];			//当前地图中所有障碍物的坐标
	point speedprops;		//当前地图中倍速道具的坐标
	point obliqueprops[2];	//当前地图中倍速斜走的坐标
	int panel[50][100];		//游戏盘面,panel[i][j]的值为0,1,2,3,4，分别表示地图中点i,j为空位置，食物，障碍物，倍速道具，斜走道具
	int stage;
};

int brand()
{
	return (rand()<<16)|(rand()<<1)|(rand()&1);
}
void bsrand()
{
	srand(GetTickCount());
}
void cls()
{
	system("cls");
}
void retr()	//退出程序 
{
    HWND hWnd=GetForegroundWindow();
    ShowWindow(hWnd,SW_HIDE);
    exit(0);
}
void GOTO(int x,int y)	//将光标移动到屏幕中的位置
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.Y = x;
    csbiInfo.dwCursorPosition.X = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void HideCursor()//隐藏控制台的光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

