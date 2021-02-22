#include "snake.h"
using namespace std;
int counter34=-1;
int direction34[10000];
bool Judje_34(point snake[5][100], int len[5], int t, GamePanel gp, int direction,int x,int y)
{
	if(direction==0)
	{
		x++;
	}
	else if(direction==1)
	{
		y=y+2;
	}
	else if(direction==2)
	{
		y=y-2;
	}
	else if(direction==3)
	{
		x--;
	}
	else if(direction==4)
	{
		x++;
		y=y+2;
	} 
	else if(direction==5)
	{
		x--;
		y=y+2;
	 } 
	else if(direction==6)
	{
		x--;
		y=y-2;
	} 
	else if(direction==7)
	{
		x++;
		y=y-2;
	} 
	if(x<=0||x>=gp.n+1||y<2||y>=gp.m+2)
	return false;
	int tt=1-t;
	for(int i=1;i<=len[tt];i++)
	{
		if(snake[tt][i].x==x&&snake[tt][i].y==y)
		return false;
	}
	for(int i=1;i<len[t];i++)
	{
		if(snake[t][i].x==x&&snake[t][i].y==y)
		return false;
	}
	return true;
}
bool Judje34(point snake[5][100], int len[5], int t, GamePanel gp, int direction,int x,int y)
{
	if(direction==0)
	{
		x++;
	}
	else if(direction==1)
	{
		y=y+2;
	}
	else if(direction==2)
	{
		y=y-2;
	}
	else if(direction==3)
	{
		x--;
	}
	else if(direction==4) 
	{
		x++;
		y=y+2;
	} 
	else if(direction==5)
	{
		x--;
		y=y+2;
	 } 
	else if(direction==6)
	{
		x--;
		y=y-2;
	} 
	else if(direction==7)
	{
		x++;
		y=y-2;
	} 
	if(x<=0||x>=gp.n+1||y<2||y>=gp.m+2)
	return false;
	for(int i=0;i<20;i++)
	{
		if(gp.wall[i].x==x&&gp.wall[i].y==y)
		return false;
	}
	int tt=1-t;
	for(int i=1;i<=len[tt];i++)
	{
		if(snake[tt][i].x==x&&snake[tt][i].y==y)
		return false;
	}
	for(int i=1;i<len[t];i++)
	{
		if(snake[t][i].x==x&&snake[t][i].y==y)
		return false;
	}
	return true;
}
bool check34(point snake[5][100], int len[5], int t, GamePanel gp, int direction ) 
{
	int x=snake[t][1].x;
	int y=snake[t][1].y;
	if(direction==0)
	{
		x++;
	}
	else if(direction==1)
	{
		y=y+2;
	}
	else if(direction==2)
	{
		y=y-2;
	}
	else if(direction==3)
	{
		x--;
	}
	else if(direction==4)
	{
		x++;
		y=y+2;
	} 
	else if(direction==5)
	{
		x--;
		y=y+2;
	 } 
	else if(direction==6)
	{
		x--;
		y=y-2;
	} 
	else if(direction==7)
	{
		x++;
		y=y-2;
	} 
	if(x<=0||x>=gp.n+1||y<2||y>=gp.m+2)
	return false;
	for(int i=0;i<20;i++)
	{
		if(gp.wall[i].x==x&&gp.wall[i].y==y)
		return false;
	}
	int tt=1-t;
	for(int i=1;i<=len[tt];i++)
	{
		if(snake[tt][i].x==x&&snake[tt][i].y==y)
		return false;
	}
	for(int i=1;i<len[t];i++)
	{
		if(snake[t][i].x==x&&snake[t][i].y==y)
		return false;
	}
	if(direction==4||direction==5||direction==6||direction==7)
	{
		if(direction==4) 
		{
			if(Judje34(snake,len,t,gp,2,x,y)==false&&Judje34(snake,len,t,gp,3,x,y)==false)
			return false;
		}
		if(direction==5)
		{
			if(Judje34(snake,len,t,gp,2,x,y)==false&&Judje34(snake,len,t,gp,0,x,y)==false)
			return false;
		}
		if(direction==6)
		{
			if(Judje34(snake,len,t,gp,0,x,y)==false&&Judje34(snake,len,t,gp,1,x,y)==false)
			return false;
		} 
		if(direction==7)
		{
			if(Judje34(snake,len,t,gp,1,x,y)==false&&Judje34(snake,len,t,gp,3,x,y)==false)
			return false;
		}
	}
	if(Judje34(snake,len,t,gp,0,x,y)==false&&Judje34(snake,len,t,gp,1,x,y)==false&&Judje34(snake,len,t,gp,2,x,y)==false&&Judje34(snake,len,t,gp,3,x,y)==false)
	return false;
	return true;
}
void FindNearestFood34(point snake[5][100],int &x,int &y,GamePanel gp,int t)
{
	int s=-1;
	int xx=snake[t][1].x;
	int yy=snake[t][1].y;
	int num=-1;
	point *prop=new point[3];
	for(int i=1;i<=gp.n;i++)
	{
		for(int j=2;j<=gp.m;j=j+2)
		{
			if(gp.panel[i][j]==3||gp.panel[i][j]==4)
			{
				num++;
				prop[num].x=i;
				prop[num].y=j;
			}
		}
	}
	if(num!=-1)
	{
		s=100000;
		for(int i=0;i<=num;i++)
		{
			int mid=(prop[i].x-xx)*(prop[i].x-xx)+(prop[i].y-yy)*(prop[i].y-yy);
			if(mid<s)
			{
				s=mid;
				x=prop[i].x;
				y=prop[i].y;
			}
		} 
	}
	if(num!=-1)
	return;
	num=-1;
	point *interim=new point[20];
	for(int i=1;i<=gp.n;i++)
	{
		for(int j=2;j<=gp.m;j=j+2)
		{
			if(gp.panel[i][j]==1)
			{
				num++;
				interim[num].x=i;
				interim[num].y=j;
			}
		}
	}
	s=100000;
	for(int i=0;i<=num;i++)
	{
		int mid=(interim[i].x-xx)*(interim[i].x-xx)+(interim[i].y-yy)*(interim[i].y-yy);
		if(mid<s)
		{
			s=mid;
			x=interim[i].x;
			y=interim[i].y;
		}
	} 
}
int machine_move34(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)	
{
	int x=0;
	int y=0;
	FindNearestFood34(snake,x,y,gp,t);
	int xx=snake[t][1].x;
	int yy=snake[t][1].y;
	if(Judje_34(snake,len,t,gp,direction34[counter34],xx,yy)==false&&counter34>=2)
	{
		int h=counter34; 
		while(direction34[h]==direction34[h-1])
		{
			h--;
		}
		if(check34(snake,len,t,gp,direction34[h-1]))
		{
			direction34[++counter34]=direction34[h-1];
			return direction34[h-1];
		}
		if(direction34[h-1]==4)
		{
			if(check34(snake,len,t,gp,0))
			{
				direction34[++counter34]=0;
				return 0;
			}
			if(check34(snake,len,t,gp,1))
			{
				direction34[++counter34]=1;
				return 1;
			}
		}
		if(direction34[h-1]==5)
		{
			if(check34(snake,len,t,gp,3))
			{
				direction34[++counter34]=3;
				return 3;
			}
			if(check34(snake,len,t,gp,1))
			{
				direction34[++counter34]=1;
				return 1;
			}
		}
		if(direction34[h-1]==6)
		{
			if(check34(snake,len,t,gp,2))
			{
				direction34[++counter34]=2;
				return 2;
			}
			if(check34(snake,len,t,gp,3))
			{
				direction34[++counter34]=3;
				return 3;
			}
		}
		if(direction34[h-1]==7)
		{
			if(check34(snake,len,t,gp,0))
			{
				direction34[++counter34]=0;
				return 0;
			}
			if(check34(snake,len,t,gp,2))
			{
				direction34[++counter34]=2;
				return 2;
			}
		}
	}
	if(gp.obliqueowner[t]==1&&yy<y&&xx<x&&check34(snake,len,t,gp,4))
	{
		direction34[++counter34]=4;
		return 4;
	}
	if(gp.obliqueowner[t]==1&&yy<y&&xx>x&&check34(snake,len,t,gp,5))
	{
		direction34[++counter34]=5;
		return 5;
	}
	if(gp.obliqueowner[t]==1&&yy>y&&xx>x&&check34(snake,len,t,gp,6))
	{
		direction34[++counter34]=6;
		return 6;
	}
	if(gp.obliqueowner[t]==1&&yy>y&&xx<x&&check34(snake,len,t,gp,7))
	{
		direction34[++counter34]=7;
		return 7;
	}
	if(yy>y&&check34(snake,len,t,gp,2))
	{
		direction34[++counter34]=2;
		return 2;
	}
	if(yy<y&&check34(snake,len,t,gp,1))
	{
		direction34[++counter34]=1;
		return 1;
	}
	if(xx<x&&check34(snake,len,t,gp,0))
	{
		direction34[++counter34]=0;
		return 0;
	}
	if(xx>x&&check34(snake,len,t,gp,3))
	{
		direction34[++counter34]=3;
		return 3;
	}
	int i=rand()%4;
	while(check34(snake,len,t,gp,i)==false)
	{
		i=rand()%4;
	}
	direction34[++counter34]=i;
	return i;
}
