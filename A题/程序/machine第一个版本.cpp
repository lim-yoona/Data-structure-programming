#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
int BlankNumber(int GamePanel[30][30],int n,int m,int i,int j)
{
	int counter=0;
	if((j-1>=0)&&GamePanel[i][j-1]==-1)
	counter++;
	if((i-1>=0)&&(j-1>=0)&&GamePanel[i-1][j-1]==-1)
	counter++;
	if((i-1>=0)&&GamePanel[i-1][j]==-1)
	counter++;
	if((i-1>=0)&&(j+1<m)&&GamePanel[i-1][j+1]==-1)
	counter++;
	if((j+1<m)&&GamePanel[i][j+1]==-1)
	counter++;
	if((i+1<n)&&(j+1<m)&&GamePanel[i+1][j+1]==-1)
	counter++;
	if((i+1<n)&&GamePanel[i+1][j]==-1)
	counter++;
	if((i+1<n)&&(j-1>=0)&&GamePanel[i+1][j-1]==-1)
	counter++;
	return counter;
}
void PutFlag(int GamePanel[30][30],int MineLocation[30][30],int n,int m,int i,int j)
{
	if((j-1>=0)&&GamePanel[i][j-1]==-1)
	MineLocation[i][j-1]=1;
	if((i-1>=0)&&(j-1>=0)&&GamePanel[i-1][j-1]==-1)
	MineLocation[i-1][j-1]=1;
	if((i-1>=0)&&GamePanel[i-1][j]==-1)
	MineLocation[i-1][j]=1;
	if((i-1>=0)&&(j+1<m)&&GamePanel[i-1][j+1]==-1)
	MineLocation[i-1][j+1]=1;
	if((j+1<m)&&GamePanel[i][j+1]==-1)
	MineLocation[i][j+1]=1;
	if((i+1<n)&&(j+1<m)&&GamePanel[i+1][j+1]==-1)
	MineLocation[i+1][j+1]=1;
	if((i+1<n)&&GamePanel[i+1][j]==-1)
	MineLocation[i+1][j]=1;
	if((i+1<n)&&(j-1>=0)&&GamePanel[i+1][j-1]==-1)
	MineLocation[i+1][j-1]=1;
}
int FindFlag(int MineLocation[30][30],int n,int m,int i,int j)
{
	int counter=0;
	if((j-1>=0)&&MineLocation[i][j-1]==1)
	counter++;
	if((i-1>=0)&&(j-1>=0)&&MineLocation[i-1][j-1]==1)
	counter++;
	if((i-1>=0)&&MineLocation[i-1][j]==1)
	counter++;
	if((i-1>=0)&&(j+1<m)&&MineLocation[i-1][j+1]==1)
	counter++;
	if((j+1<m)&&MineLocation[i][j+1]==1)
	counter++;
	if((i+1<n)&&(j+1<m)&&MineLocation[i+1][j+1]==1)
	counter++;
	if((i+1<n)&&MineLocation[i+1][j]==1)
	counter++;
	if((i+1<n)&&(j-1>=0)&&MineLocation[i+1][j-1]==1)
	counter++;
	return counter;
}
void Position(int GamePanel[30][30],int MineLocation[30][30],int n,int m,int i,int j,int &x,int &y)
{
	if((j-1>=0)&&GamePanel[i][j-1]==-1&&MinePanel[i][j-1]!=1)
	{
		x=i;
		y=j-1;
		return;
	}
	if((i-1>=0)&&(j-1>=0)&&GamePanel[i-1][j-1]==-1&&MinePanel[i-1][j-1]!=1)
	{
		x=i-1;
		y=j-1;
		return;
	}
	if((i-1>=0)&&GamePanel[i-1][j]==-1&&MinePanel[i-1][j]!=1)
	{
		x=i-1;
		y=j;
		return ;
	}
	if((i-1>=0)&&(j+1<m)&&GamePanel[i-1][j+1]==-1&&MinePanel[i-1][j+1]!=1)
	{
		x=i-1;
		y=j+1;
		return;
	}
	if((j+1<m)&&GamePanel[i][j+1]==-1&&MinePanel[i][j+1]!=1)
	{
		x=i;
		y=j+1;
		return;
	}
	if((i+1<n)&&(j+1<m)&&GamePanel[i+1][j+1]==-1&&MinePanel[i+1][j+1]!=1)
	{
		x=i+1;
		y=j+1;
		return;
	}
	if((i+1<n)&&GamePanel[i+1][j]==-1&&MinePanel[i+1][j]!=1)
	{
		x=i+1;
		y=j;
		return;
	}
	if((i+1<n)&&(j-1>=0)&&GamePanel[i+1][j-1]==-1&&MinePanel[i+1][j-1]!=1)
	{
		x=i+1;
		y=j-1;
		return;
	}
}
void machine(int GamePanel[30][30],int n,int m,int &x,int &y)
{
	int MineLocation[30][30];//雷位置的记录矩阵，有为1，无为零 
	//初始化雷矩阵
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		MineLocation[i][j]=0;
	} 
	srand(time(0));
	int sigh=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(GamePanel[i][j]==0)
			sigh=1;
		}
	}
	if(sigh==0)
	{
		int i,j;
		i=rand()%n;
		j=rand()%m;
		while(GamePanel[i][j]!=-1)
		{
			i=rand()%n;
			j=rand()%m;
		}
		x=i;
		y=j;
		return;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(GamePanel[i][j]==-1||GamePanel[i][j]==0)
			continue;
			if(BlankNumber(GamePanel,n,m,i,j)==GamePanel[i][j])
			PutFlag(GamePanel,MineLocation,n,m,i,j);
		}
	}
	for(int i=0;i<n;i++)
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
	}
}
