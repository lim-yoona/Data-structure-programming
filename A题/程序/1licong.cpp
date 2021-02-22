#include<iostream>
using namespace std;
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
	cin>>n;
	cin>>m;
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
	for(int i=0;i<l;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
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
