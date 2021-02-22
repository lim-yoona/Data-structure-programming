#include "snake.h"
using namespace std;


bool check(point snake[5][100], int len[5], int t, GamePanel gp, int direction ) 
{
	//将你的check函数体放在此处，并删去下面示例代码
	if (snake[t][1].y == gp.m && direction == 1) return false;
	if (snake[t][1].y == 2 && direction == 2) return false;
	return true;
}
void FindNearestFood(point snake[5][100],int &x,int &y,GamePanel gp,int t)
{
	int xx=snake[t][1].x;
	int yy=snake[t][1].y;
	int s=10000;
	for(int i=0;i<gp.totalfoodnum;i++)
	{
		if(gp.food[i].x<=0||gp.food[i].x>=gp.n+1||gp.food[i].y<2||gp.food[i].y>=gp.m+2)
		continue;
		int mid=(gp.food[i].x-xx)*(gp.food[i].x-xx)+(gp.food[i].y-yy)*(gp.food[i].y-yy);
		if(mid<s)
		{
			s=mid;
			x=gp.food[i].x;
			y=gp.food[i].y;
		}
	} 
}
int machine_move(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)	
{
	//将你的machine_move函数体放在此处，并删去下面示例代码
	int x,y;
	FindNearestFood(snake,x,y,gp,t);
	int xx=snake[t][1].x;
	int yy=snake[t][1].y;
	if(xx>x)
	return 3;
	if(xx<x)
	return 0;
	if(yy>y)
	return 2;
	if(yy<y)
	return 1;
}
