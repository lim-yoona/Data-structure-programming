#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/********************************************************************************/
/********************************将学生的代码添加到下面******************************/
int Click(int GamePanel[30][30],int x,int y,int mine[30][30],int n,int m)
{
	if(GamePanel[x][y]>=0)
	return 2;
	if(mine[x][y]==1)
	{
		//cout<<"You lose"<<endl;
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
	//cout<<"You win"<<endl;
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
	/*for(int c=0;c<n;c++)
	{
		for(int d=0;d<m-1;d++)
		{
			cout<<setw(2)<<GamePanel[c][d]<<' ';
		}
		cout<<GamePanel[c][m-1]<<endl;
		//cout<<endl;
	} */ 
	if(IsWin(GamePanel,mine,n,m))
	return 1;
	//cout<<endl;
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
		x=0;
		y=0;
		if(GamePanel[x][y]==-1)
		return;
		x=n-1;
		y=m-1;
		if(GamePanel[x][y]==-1)
		return;
		i=(rand())%n;
		j=(rand())%m;
		while(GamePanel[i][j]!=-1)
		{
			i=(rand())%n;
			j=(rand())%m;
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
	int rr=rand()%40;
	//cout<<rr<<endl;
	if(rr>=20)
	{
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
else if(rr<20)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
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
	int bonus;
	double score;
	double  maxscore = -999, minscore = 999, sumscore=0;
	int gamenum = 1000;
	int zerocnt = 0;
	int winnum = 0;
	n = 20;
	m = 20;
	minenum = 50;
	srand(int(time(0)));
	printf("正在评测中，请稍等，我们将进行1000局游戏，取平均分*1.3作为最终成绩......\n");
	
	for (iii = 0; iii<gamenum; iii++)
	{
		
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
			{
				GamePanel[i][j] = -1;
				mine[i][j] = 0;
			}

		int cnt = 0;

		for (ii = 0; ii<400; ii++)
		{	
			for (i = 0; i < 20; i++)
				for (j = 0; j < 20; j++)
					temp[i][j] = GamePanel[i][j];
			machine(temp, n, m, x, y);
			
			if (ii == 0)
			{
				for ( k = 0; k < minenum; k++)
				{
					i = rand() % 20;
					j = rand() % 20;
					while ((i == x && j == y) || mine[i][j] != 0)
					{
						i = rand() % 20;
						j = rand() % 20;
					}
					mine[i][j] = 1;
				}
			}
			if (GamePanel[x][y] == -1)
			{
				cnt++;
				win = RefreshGamePanel(GamePanel, x, y, mine, n, m, minenum);
				if (win == 1)
				{
					if (cnt < 80) bonus = 10;
					else if (cnt < 90) bonus = 9;
					else if (cnt < 100) bonus = 8;
					else if (cnt < 120) bonus = 7;
					else if (cnt < 150) bonus = 5;
					else if (cnt < 200) bonus = 3;
					else if (cnt < 250) bonus = 1;
					else bonus = 0;
					score = 50.0 + bonus;
					if(iii==0 || (iii+1)%10==0) printf("第 %d 局,赢了,得 %d 分.\n", iii+1,(int)score);
					winnum++;

					break;
				}
				else if (win == -1)
				{
					score = 0;
					for (i = 0; i<n; i++)
						for (j = 0; j<m; j++)
						{
							if (GamePanel[i][j] != -1)
								score=score+1;
						}
					score = score/10;
									
					if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);
		
					break;
				}
			}

		}
		if (win == 0)
		{
			score = 0;
			for (i = 0; i<n; i++)
				for (j = 0; j<m; j++)
				{
					if (GamePanel[i][j] != -1)
						score=score+1;
				}
			score = score / 10;
			if (iii == 0 || (iii + 1) % 10 == 0)printf("第 %d 局,输了,得 %.2lf 分.\n", iii + 1, score);

		}
		if (score>maxscore) maxscore = score;
		if (score<minscore) minscore = score;
		sumscore = sumscore+score;
		
	}
	
	int orignscore,finalscore;

	orignscore= ceil(1.3*ceil(sumscore/gamenum));

	if (orignscore > 60) finalscore = 60;
	else finalscore = orignscore;
	//printf("该学生原始分数为 %d.\n\n", orignscore);
	
	
	printf("该学生最终分数为 %d.\n\n", finalscore);
	printf("该学生胜率为 %.1lf%%\n\n", winnum/10.0);
	
	system("pause");
	return 0;
}
