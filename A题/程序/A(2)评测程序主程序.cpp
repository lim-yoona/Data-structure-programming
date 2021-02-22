#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;


/********************************************************************************/
/********************************将学生的代码添加到下面******************************/
int Click(int GamePanel[30][30],int x,int y,int mine[30][30],int n,int m)
{
	if(GamePanel[x][y]>=0)
	return 2;
	if(mine[x][y]==1)
	{
		cout<<"You lose"<<endl;
		return 1;
	}
	int counter=0;
	if((y-1>=0)&&mine[x][y-1]==1)
	counter++;
	if((x-1>=0)&&(y-1>=0)&&mine[x-1][y-1]==1)
	counter++;
	if((x-1>=0)&&mine[x-1][y]==1)
	counter++;
	if((x-1>=0)&&(y+1<m)&&mine[x-1][y+1]==1)
	counter++;
	if((y+1<m)&&mine[x][y+1]==1)
	counter++;
	if((x+1<n)&&(y+1<m)&&mine[x+1][y+1]==1)
	counter++;
	if((x+1<n)&&mine[x+1][y]==1)
	counter++;
	if((x+1<n)&&(y-1>=0)&&mine[x+1][y-1]==1)
	counter++;
	GamePanel[x][y]=counter;
	if(counter>0)
	return 0;
	if((y-1>=0)&&mine[x][y-1]==0)
	Click(GamePanel,x,y-1,mine,n,m);
	if((x-1>=0)&&(y-1>=0)&&mine[x-1][y-1]==0)
	Click(GamePanel,x-1,y-1,mine,n,m);
	if((x-1>=0)&&mine[x-1][y]==0)
	Click(GamePanel,x-1,y,mine,n,m);
	if((x-1>=0)&&(y+1<m)&&mine[x-1][y+1]==0)
	Click(GamePanel,x-1,y+1,mine,n,m);
	if((y+1<m)&&mine[x][y+1]==0)
	Click(GamePanel,x,y+1,mine,n,m);
	if((x+1<n)&&(y+1<m)&&mine[x+1][y+1]==0)
	Click(GamePanel,x+1,y+1,mine,n,m);
	if((x+1<n)&&mine[x+1][y]==0)
	Click(GamePanel,x+1,y,mine,n,m);
	if((x+1<n)&&(y-1>=0)&&mine[x+1][y-1]==0)
	Click(GamePanel,x+1,y-1,mine,n,m);
}
bool IsWin(int GamePanel[30][30],int mine[30][30],int n,int m)
{
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<m;y++)
		{
			if(GamePanel[x][y]<0&&mine[x][y]==0)
			return false;
		}
	}
	cout<<"You win"<<endl;
	return true;
}
int RefreshGamePanel(int GamePanel[30][30],int x,int y,int mine[30][30],int n,int m,int k)
{
	int j;
	j=Click(GamePanel,x,y,mine,n,m);
	if(j==1)
	return -1;
	/*if(j==2)
	continue;*/
	for(int c=0;c<n;c++)
	{
		for(int d=0;d<m-1;d++)
		{
			cout<<setw(2)<<GamePanel[c][d]<<' ';
		}
		cout<<GamePanel[c][m-1]<<endl;
		//cout<<endl;
	}  
	if(IsWin(GamePanel,mine,n,m))
	return 1;
	cout<<endl;
	return 0;
}
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
	//cout<<"Posution"<<endl;
	if((j-1>=0)&&GamePanel[i][j-1]==-1&&MineLocation[i][j-1]!=1)
	{
		x=i;
		y=j-1;
		return;
	}
	if((i-1>=0)&&(j-1>=0)&&GamePanel[i-1][j-1]==-1&&MineLocation[i-1][j-1]!=1)
	{
		x=i-1;
		y=j-1;
		return;
	}
	if((i-1>=0)&&GamePanel[i-1][j]==-1&&MineLocation[i-1][j]!=1)
	{
		x=i-1;
		y=j;
		return ;
	}
	if((i-1>=0)&&(j+1<m)&&GamePanel[i-1][j+1]==-1&&MineLocation[i-1][j+1]!=1)
	{
		x=i-1;
		y=j+1;
		return;
	}
	if((j+1<m)&&GamePanel[i][j+1]==-1&&MineLocation[i][j+1]!=1)
	{
		x=i;
		y=j+1;
		return;
	}
	if((i+1<n)&&(j+1<m)&&GamePanel[i+1][j+1]==-1&&MineLocation[i+1][j+1]!=1)
	{
		x=i+1;
		y=j+1;
		return;
	}
	if((i+1<n)&&GamePanel[i+1][j]==-1&&MineLocation[i+1][j]!=1)
	{
		x=i+1;
		y=j;
		return;
	}
	if((i+1<n)&&(j-1>=0)&&GamePanel[i+1][j-1]==-1&&MineLocation[i+1][j-1]!=1)
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
	//srand(time(0));
	int sigh=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(GamePanel[i][j]==0)
			sigh=1;
		}
	}
	//cout<<"sigh:"<<sigh<<endl;
	if(sigh==0)
	{
		int i,j;
		i=(rand())%n;
		j=(rand())%m;
		while(GamePanel[i][j]!=-1)
		{
			i=(rand())%n;
			j=(rand())%m;
		}
		x=i;
		y=j;
		//cout<<"x:"<<x<<' ';
		//cout<<"y:"<<y<<endl;
		//cout<<"x:"<<x<<endl;
		//cout<<"y:"<<y<<endl;
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
		//cout<<"QQ"<<endl;
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
	//cout<<"死局"<<endl; 
	cout<<"machine"<<endl;
	int ii;
	int jj;
	ii=rand()%n;
	jj=rand()%m;
	while(GamePanel[ii][jj]!=-1||MineLocation[ii][jj]==1)
	{
		//cout<<"ii"<<ii<<' ';
		//cout<<"jj"<<jj<<endl;
		ii=rand()%n;
		jj=rand()%m;
	}
	x=ii;
	y=jj;
	return;
}

/********************************将学生的代码添加到上面******************************/
/********************************************************************************/



int main()
{
	int GamePanel[30][30];
	int temp[30][30];
	int mine[30][30];
	int iii, ii, n, m, k, i, j, minenum, x, y, win = 0;
	int score, bonus, finalscore = -999;
	n = 20;
	m = 20;
	minenum = 50;
	srand(int(time(0)));
	printf("正在评测中，请稍等\n");

	for (iii = 0; iii<10; iii++)
	{
		cout<<"第"<<iii<<"次"<<endl;
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
			{
				GamePanel[i][j] = -1;
				mine[i][j] = 0;
			}
		for (k = 0; k<minenum; k++)
		{
			i = rand() % 20;
			j = rand() % 20;
			while (mine[i][j] != 0)
			{
				i = rand() % 20;
				j = rand() % 20;
			}
			mine[i][j] = 1;
		}
		/*cout<<"地雷矩阵"<<endl;
		for(int io=0;io<n;io++)
		{
			for(int jo=0;jo<m;jo++)
			{
				cout<<setw(2)<<mine[io][jo];
			}
			cout<<endl;
		}*/ 
		int cnt = 0;

		for (ii = 0; ii<400; ii++)
		{
			int t1, t2;
			for (t1 = 0; t1 < 20; t1++)
				for (t2 = 0; t2 < 20; t2++)
					temp[t1][t2] = GamePanel[t1][t2];
	
			machine(temp, n, m, x, y); //该函数由学生实现
	
			if (GamePanel[x][y] == -1)
			{
				cnt++;
				win = RefreshGamePanel(GamePanel, x, y, mine, n, m, minenum);//该函数老师已经实现
				if (win == 1)		//扫雷成功，游戏结束
				{
					//cout<<"hfrufheuhgvyu"<<endl;
					if (cnt < 80) bonus = 100;
					else if (cnt < 90) bonus = 90;
					else if (cnt < 100) bonus = 80;
					else if (cnt < 120) bonus = 70;
					else if (cnt < 150) bonus = 50;
					else if (cnt < 200) bonus = 30;
					else if (cnt < 250) bonus = 10;
					else bonus = 0;
					score = 500 + bonus;
					break;
				}
				else if (win == -1)		//扫雷失败，游戏结束
				{
					score = 0;
					for (i = 0; i<n; i++)
						for (j = 0; j<m; j++)
						{
							if (GamePanel[i][j] != -1)
								score++;
						}
					break;
				}
			}

		} //end for ii

		if (win == 0)	//点击超400次游戏仍未结束，分数等于目前打开的格子数
		{
			score = 0;
			for (i = 0; i<n; i++)
				for (j = 0; j<m; j++)
				{
					if (GamePanel[i][j] != -1)
						score++;
				}
		}
		if (score>finalscore) finalscore = score;
	}	// end for iii

	printf("\n该学生分数为 %d.\n\n", finalscore/10);
	system("pause");
	return 0;
}
