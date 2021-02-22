#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
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
	cout<<"Posution"<<endl;
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
	cout<<"sigh:"<<sigh<<endl;
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
		cout<<"x:"<<x<<endl;
		cout<<"y:"<<y<<endl;
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
		cout<<"QQ"<<endl;
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
struct Box
{
	int number;//方格上面的数字 
	int HasMine;//是否有地雷，有为1，无为0 
};
int Click(int x,int y,struct Box **a,int n,int m)
{
	if(a[x][y].number>=0)
	return 2;
	if(a[x][y].HasMine==1)
	{
		cout<<"You lose"<<endl;
		return 1;
	}
	int counter=0;
	if((y-1>=0)&&a[x][y-1].HasMine==1)
	counter++;
	if((x-1>=0)&&(y-1>=0)&&a[x-1][y-1].HasMine==1)
	counter++;
	if((x-1>=0)&&a[x-1][y].HasMine==1)
	counter++;
	if((x-1>=0)&&(y+1<m)&&a[x-1][y+1].HasMine==1)
	counter++;
	if((y+1<m)&&a[x][y+1].HasMine==1)
	counter++;
	if((x+1<n)&&(y+1<m)&&a[x+1][y+1].HasMine==1)
	counter++;
	if((x+1<n)&&a[x+1][y].HasMine==1)
	counter++;
	if((x+1<n)&&(y-1>=0)&&a[x+1][y-1].HasMine==1)
	counter++;
	a[x][y].number=counter;
	if(counter>0)
	return 0;
	if((y-1>=0)&&a[x][y-1].HasMine==0)
	Click(x,y-1,a,n,m);
	if((x-1>=0)&&(y-1>=0)&&a[x-1][y-1].HasMine==0)
	Click(x-1,y-1,a,n,m);
	if((x-1>=0)&&a[x-1][y].HasMine==0)
	Click(x-1,y,a,n,m);
	if((x-1>=0)&&(y+1<m)&&a[x-1][y+1].HasMine==0)
	Click(x-1,y+1,a,n,m);
	if((y+1<m)&&a[x][y+1].HasMine==0)
	Click(x,y+1,a,n,m);
	if((x+1<n)&&(y+1<m)&&a[x+1][y+1].HasMine==0)
	Click(x+1,y+1,a,n,m);
	if((x+1<n)&&a[x+1][y].HasMine==0)
	Click(x+1,y,a,n,m);
	if((x+1<n)&&(y-1>=0)&&a[x+1][y-1].HasMine==0)
	Click(x+1,y-1,a,n,m);
}
bool IsWin(struct Box **a,int n,int m)
{
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<m;y++)
		{
			if(a[x][y].number<0&&a[x][y].HasMine==0)
			return false;
		}
	}
	cout<<"You win";
	return true;
}
int main ()
{
	int n,m,k,l;
	n=20;
	m=20;
	cin>>k;
	cin>>l;
	struct Box **array=new Box*[n];
	for(int i=0;i<n;i++)
	{
		array[i]=new Box[m];
	} 
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<m;y++)
		{
			array[x][y].number=-1;
			array[x][y].HasMine=0;
		}
	}
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
		array[x][y].HasMine=1;
	}
	int ccc[30][30];
	for(int i=0;i<l;i++)
	{
		int x,y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ccc[i][j]=array[i][j].number;
			}
		}
		machine(ccc,n,m,x,y);
		cout<<x<<' ';
		cout<<y<<endl;
		//cin>>x;
		//cin>>y;
		if(array[x][y].number>=0)
		continue;
		int j;
		j=Click(x,y,array,n,m);
		if(j==1)
		return 0;
		/*if(j==2)
		continue;*/
		for(int c=0;c<n;c++)
		{
			for(int d=0;d<m-1;d++)
			{
				cout<<array[c][d].number<<' ';
			}
			cout<<array[c][m-1].number<<endl;
			//cout<<endl;
		}
		if(IsWin(array,n,m))
		return 0;
		cout<<endl;
	}
}
