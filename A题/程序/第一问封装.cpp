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
	cout<<"You win";
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
			cout<<array[c][d].number<<' ';
		}
		cout<<array[c][m-1].number<<endl;
		//cout<<endl;
	}
	if(IsWin(array,n,m))
	return 1;
	cout<<endl;
	return 0;
}
