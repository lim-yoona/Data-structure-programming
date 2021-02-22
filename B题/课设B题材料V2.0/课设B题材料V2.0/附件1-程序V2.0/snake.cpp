#include "machine34.h"
using namespace std;

int main();

int CreateSnake(int m, int n, point snake[5][100], int len[5], int direct[5])	//生成初始蛇
{
	int i;

	setcolor(15);	//第0条蛇白色
	snake[0][1].x = n; snake[0][1].y = m - 6;//第0条蛇panel[n][m-6]+panel[n][m-4]+panel[n][m-2], 白色
	snake[0][2].x = n; snake[0][2].y = m - 4;
	len[0] = 3;
	snake[0][3].x = n; snake[0][3].y = m - 2;
	direct[0] = 2;
	for (i = 1; i <= len[0]; i++) GOTO(snake[0][i].x, snake[0][i].y), printf("▇");

	setcolor(13);	//第1条蛇粉色
	snake[1][1].x = 1; snake[1][1].y = 6;  //第1条蛇panel[1][6]+panel[1][4]+panel[1][2]
	snake[1][2].x = 1; snake[1][2].y = 4;
	len[1] = 3;
	snake[1][3].x = 1; snake[1][3].y = 2;
	direct[1] = 1;
	for (i = 1; i <= len[1]; i++) GOTO(snake[1][i].x, snake[1][i].y), printf("▇");

	return 0;
}

void draw(int m, int n)//画边界
{
	int i;
	setcolor(6);
	for (i = 0; i <= n + 1; i++) GOTO(i, m + 2), printf("▇"), GOTO(i, 0), printf("▇");
	for (i = 1; i <= m / 2 + 1; i++) GOTO(n + 1, i * 2), printf("▇"), GOTO(0, i * 2), printf("▇");
}

void stop(int n)
{
	setcolor(7);
	GOTO(n + 1, 30);
	printf("按回车恢复");
	char ch = _getch();
	while (ch != 13) ch = _getch();
}

void Ending(int n) {
	GOTO(n + 1, 30);
	printf("按回车重来\n");
	char ch = _getch();
	while (ch != 13) ch = _getch();
	main(); exit(0);
}

bool check_food_wall_props(int m, int n, int x,int y, point snake[5][100], int len[5])
{
	int i;
	if(x<2||x>n-1||y<4||y>m-2) return false;

	for( i=1;i<=len[0];i++)
		if(x==snake[0][i].x && y==snake[0][i].y) return false;

	for (i = 1; i <= len[1]; i++)
		if (x == snake[1][i].x && y == snake[1][i].y) return false;

	return true;
}

void rand_food(point snake[5][100], int len[5], GamePanel &gp)
{
	int x,y,i,m,n;
	if (gp.currentfoodnum >0) return;
	m = gp.m;
	n = gp.n;
	
	setcolor(10);
	for(i=0;i<gp.totalfoodnum;i++)
	{
		x=brand()%(n+1);
		y=(brand()%m/2)*2;
		while(gp.panel[x][y]!=0 || !check_food_wall_props(m,n,x,y,snake,len))
		{
			x=brand()%(n+1);
			y=(brand()%m/2)*2;
		}
		gp.currentfoodnum++;	
		gp.panel[x][y]=1;
		gp.food[i].x=x;
		gp.food[i].y=y;
		GOTO(x,y);
		printf("●");
	}

}

void rand_wall(point snake[5][100], int len[5], GamePanel &gp)
{
	int x, y, i, m, n;
	m = gp.m;
	n = gp.n;
	
	setcolor(6);
	for(i=0;i<20;i++)
	{
		x=brand()%(n+1);
		y=(brand()%m/2)*2;
		while(gp.panel[x][y]!=0 || !check_food_wall_props(m, n, x, y, snake, len) )
		{
			x=brand()%(n+1);
			y=(brand()%m/2)*2;
		}
		gp.panel[x][y]=2;
		gp.wall[i].x=x;
		gp.wall[i].y=y;
		GOTO(x,y);
		printf("▇");
	}
	gp.wallnum = 20;

}
void rand_props(point snake[5][100], int len[5], GamePanel &gp)
{
	int x,y,m,n;
	m = gp.m;
	n = gp.n;
	
	setcolor(9);
	x=brand()%(n+1);
	y=(brand()%m/2)*2;
	while(gp.panel[x][y]!=0 || !check_food_wall_props(m, n, x, y, snake, len) )
	{
		x=brand()%(n+1);
		y=(brand()%m/2)*2;
	}
	gp.panel[x][y]=3;
	gp.speedprops.x=x;
	gp.speedprops.y=y;
	
	GOTO(x,y);
	printf("▲");

	setcolor(12);
	x=brand()%(n+1);
	y=(brand()%m/2)*2;
	while(gp.panel[x][y]!=0 || !check_food_wall_props(m,n,x,y,snake, len) )
	{
		x=brand()%(n+1);
		y=(brand()%m/2)*2;
	}
	gp.panel[x][y]=4;
	gp.obliqueprops[0].x=x;
	gp.obliqueprops[0].y=y;
	GOTO(x,y);
	printf("★");

	x=brand()%(n+1);
	y=(brand()%m/2)*2;
	while(gp.panel[x][y]!=0 || !check_food_wall_props(m, n, x, y, snake, len) )
	{
		x=brand()%(n+1);
		y=(brand()%m/2)*2;
	}
	gp.panel[x][y]=4;
	gp.obliqueprops[1].x=x;
	gp.obliqueprops[1].y=y;

	GOTO(x,y);
	printf("★");

	gp.speednum = 1;
	gp.obliquenum = 2;
}


int move(int t, point snake[5][100], int len[5], int direct[5], GamePanel &gp, int &iterationtime)
{
	if (t == 0) setcolor(15);
	else if (t == 1) setcolor(13);
	int m = gp.m;
	int n = gp.n;
	
	int x, y;
	
	
	x = snake[t][1].x; y = snake[t][1].y;
	/****************************************************************/
	int nextdirection =  machine_move34(snake, len, direct, t, gp);
	/****************************************************************/
	
	if(gp.obliqueowner[t]!=1) //如果蛇t不 拥有斜走道具，则其斜走指令转换为横走
	{
		if(nextdirection ==4) nextdirection =1;
		else if(nextdirection ==5) nextdirection =1;
		else if(nextdirection ==6) nextdirection =2;
		else if(nextdirection ==7) nextdirection =2;
	}
	
	int temp = -1;	//赢家编号,temp=0表示0赢，temp=1表示1赢，temp=111表示平局，temp=-1表示没赢没输正在进行
	int op = 1 - t;	//t的对手编号
	bool enough = false;
	bool timelimit = false;
	bool selfkill = false;
	if (check34(snake, len, t, gp, nextdirection) == false) { selfkill = true; temp = op; }//lose
	else
	{
		
		direct[t] = nextdirection;
		int flg[8][2] = { { 1,0 },{ 0,2 },{ 0,-2 },{ -1,0 },{ 1,2 },{ -1,2 },{ -1,-2 },{ 1,-2 } };
		x += flg[direct[t]][0]; y += flg[direct[t]][1];
	
		if (gp.panel[x][y] == 1)			//吃到食物
		{
			gp.currentfoodnum--;
			len[t]++;
			iterationtime = 0;
			setcolor(15);//cls();
			if (t == 0)
			{
				GOTO(n + 1, 77);
				printf("%d", len[t] - 3);
			}
			else
			{
				GOTO(0, 9);
				printf("%d", len[t] - 3);
				setcolor(13);
			}
		}
		else if (gp.panel[x][y] == 3)		//吃到倍速道具
		{
			gp.speedowner = t;
			gp.speednum = 0;
			gp.step_speed = 0;		
		}
		else if (gp.panel[x][y] == 4)		//吃到斜走道具
		{
			gp.obliqueowner[t] = 1;
			gp.obliquenum--;
		}
		if (gp.panel[x][y] == 0 || gp.panel[x][y] == 3 || gp.panel[x][y] == 4)
		{
			GOTO(snake[t][len[t]].x, snake[t][len[t]].y);
			printf("  ");
		}
		gp.panel[x][y] = 0;
		for (int i = len[t]; i>1; i--) snake[t][i] = snake[t][i - 1];
		snake[t][1].x = x;
		snake[t][1].y = y;
		GOTO(snake[t][1].x, snake[t][1].y);
		printf("▇");

		if (len[t] - 3 >= gp.success_num) { enough = true; temp = t; }		//蛇t赢了，返回t
		else if (iterationtime >= maxiterationtime)	//达到最大迭代次数仍未分出胜负
		{
			timelimit = true;
			if (len[0] > len[1]) temp = 0;
			else if (len[1] > len[0]) temp = 1;
			else temp = 111;			//平局
		}
	}

	if (temp != -1)
	{
		setcolor(15);//cls();
		GOTO(n+1,0);
		
		if (temp == 0)
		{
			if (enough == true) printf("白方吃够食物获胜。");
			else if (selfkill == true) printf("白方因对方自杀获胜。");
			else if (timelimit == true) printf("白方因超时获胜。");
			else printf("白方获胜。");
		}
		else if (temp == 1)
		{
			if (enough == true) printf("粉方吃够食物获胜。");
			else if (selfkill == true) printf("粉方因对方自杀获胜。");
			else if (timelimit == true) printf("粉方因超时获胜。");
			else printf("粉方获胜。");
		}
		else { printf("双方打平。"); }
		Ending(n);
	}
	else
	{
		if (gp.currentfoodnum == 0)
		{
			rand_food(snake, len, gp);
			gp.stage++;
		}
	}
	return 0;
}

int main()
{
	HideCursor();
	bsrand();

	GamePanel gp;
	gp.m = 76;
	gp.n = 28;
	gp.stage = 1;
	gp.totalfoodnum = 10;
	gp.wallnum = 0;
	gp.success_num = 350;
	gp.currentfoodnum = 0;
	MEM(gp.panel, 0);
	MEM(gp.obliqueowner, 0);


	int score=0;
	
	int iterationtime=0;
	int m, n;
	m = gp.m, n = gp.n;
	point snake[5][100];//1头 tot尾 
	int len[5], direct[8];
	
	system("title 贪吃蛇大作战");
	system("mode con cols=80 lines=31");
	SetWindowLongPtrA(
		GetForegroundWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetForegroundWindow(), GWL_STYLE)
		& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX
	);
	cls();
	int tim=50;		//值越小，显示速度越快
	MEM(snake,0);
	gp.speedowner=-1;
	gp.speednum=0;
	gp.obliquenum=0;
	cls();
	draw(m, n);	//画边界
	CreateSnake(m, n, snake, len, direct); //生成初始蛇
	
	gp.step_speed=0; //倍速道具使用的步数，
	
	setcolor(15);
	GOTO(n + 1, 68);
	printf("白方食物 ");
	GOTO(n+1, 77);
	printf("%d", len[0] - 3);
	GOTO(0, 0);
	printf("粉方食物 ");
	GOTO(0, 9);
	printf("%d", len[1] - 3);
	int t = 0;		//你控制哪条蛇
	int tt=1-t; 
	while(1)
	{
		GOTO(n + 1, 30);
		printf("按回车暂停");
		while(!_kbhit())
		{
			if(gp.speedowner!=-1) gp.step_speed++;
			iterationtime++;
			if(gp.step_speed>50) gp.speedowner=-1;	//倍速道具最多只能使用50步
			Sleep(tim);
			rand_food(snake, len, gp);
			if(gp.speedowner==-1) 
			{
				move(t, snake, len, direct, gp, iterationtime);
				//move1(tt, snake, len, direct, gp, iterationtime);
			}
			else if(gp.speedowner==t)
			{
				move(t, snake, len, direct, gp, iterationtime);
				move(t, snake, len, direct, gp, iterationtime);
				//move1(tt, snake, len, direct, gp, iterationtime);
			}
			/*else if(gp.speedowner==tt)
			{
				move(t, snake, len, direct, gp, iterationtime);
				move1(tt, snake, len, direct, gp, iterationtime);
				move1(tt, snake, len, direct, gp, iterationtime);
			}*/
			
			if(gp.stage==2 && gp.wallnum==0)	//第二面开启障碍物
			{
				rand_wall(snake, len, gp);
				rand_props(snake, len, gp);
				
			
			}	
		}
		char ch = _getch();
		if (ch == 13 ) stop(n);

	}
	return 0;
}
