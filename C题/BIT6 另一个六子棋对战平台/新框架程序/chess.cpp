#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<vector>
using namespace std;

#define BLACK 0
#define WHITE 1
#define EMPTY 2

struct Point{ //点结构
	int x,y;
};
struct Step{ //步结构
	Point first,second;
	int value;
};
int Board[19][19];//存储棋盘信息，其元素值为 BLACK, WHITE, EMPTY 之一
vector<Point>PointSet1;
vector<Point>PointSet2; 
vector<Point>PointSet3;
vector<Point>PointSet4; 
void FindPosition(int Board[19][19],int sigh,vector<Point>&PointSet1,vector<Point>&PointSet2)
//PointSet1代表只需下一个棋子就可胜利的情况，PointSet2代表需要连下挨着的两子才能赢的情况 
{
	for(int i=0;i<19;i++)//第一个循环·横 
	{
		int num=0;//本行拥有sigh类棋子的个数 
		int First=19;//本行第一个sigh类棋子的位置 
		int Last=-1;//本行最后一个sigh类棋子的位置 
		for(int j=0;j<19;j++)//找到当前行的num、First、Last 
		{
			if(Board[i][j]==sigh)
			{
				if(j<First)
				First=j;
				if(j>Last)
				Last=j;
				num++;
			}
		}
		if(num<4)//如果棋子数目小于4，那必不可能在当前步胜利 
		continue;//跳过本行看下一行 
		if(First-Last==4)//如果有五个棋子连在一起，看五个棋子的前一个位置是否为空 
		{
			if(First>=1&&Board[i][First-1]==2)
			{
				struct Point* a=new Point;
				a->x=i;
				a->y=First-1;
				PointSet1.push_back(&a);
			}
			continue;
		}
		if(First-Last==3)//如果四子连在一起，看四个棋子的前两个位置是否为空 
		{
			if(First>=2&&Board[i][First-1]==2&&Board[i][First-2]==2)
			{
				struct Point* a=new Point;
				struct Point* b=new Point;
				a->x=i;
				b->x=i;
				a->y=First-1;
				b->y=First-2;
				PointSet2.push_back(&a);
				PointSet2.push_back(&b);
			}
			continue; 
		}
		int k=0;
		int F=19;
		int L=-1;
		while(k<19)
		{
			/*if(Board[i][k]!=sigh)
			{
				k++;
				continue;
			}*/
			
			if(Board[i][k]==sigh)
			{
				if(k<F)
				F=k;
				if(k>L)
				L=k;
				k++;
			}
			else if(k>=1&&Board[i][k-1]==sigh&&F+6<=19)
			{
				FF=F;
				LL=L;
				F=19;
				L=-1;
				if(Board[i][k]==2)
				{
					int kk=0;
					for(int mm=1;mm<=6-(FF-LL+1)-1;mm++)
					{
						if(Board[i][k+mm]!=sigh)
						{
							kk=1;
							break;
						}
					}
					if(kk==0)
					{
						//填上就能连在一起六个 
						struct Point* a=new Point;
						a->x=i;
						a->y=k;
						PointSet1.push_back(&a);
						k++;
						continue;
					}
					else if(kk==1)
					{
						k++;
						continue;
					}
					if(Board[i][k+1]==2)
					{
						int kkk=0;
						for(int mmm=1;mmm<=6-(FF-LL+1)-2;mmm++)
						{
							if(Board[i][k+1+mmm]!=sigh)
							{
								kkk=1;
								break;
							}
						}
						if(kkk==0)
						{
							//填上连续的两个棋子可以连成六个 
							struct Point* a=new Point;
							struct Point* b=new Point;
							a->x=i;
							b->x=i;
							a->y=k;
							b->y=k+1;
							PointSet2.push_back(&a);
							PointSet2.push_back(&b);
							k=k+2;
						}
						else if(kkk==1)
						{
							k=k+2;
						}
					}
				}
			}
			else
			{
				F=19;
				L=-1;
				k++;
			}
		}
	}
	for(int i=0;i<19;i++)//第二个循环·竖 
	{
		int num=0;//本列拥有sigh类棋子的个数 
		int First=19;//本列第一个sigh类棋子的位置 
		int Last=-1;//本列最后一个sigh类棋子的位置 
		for(int j=0;j<19;j++)//找到当前列的num、First、Last 
		{
			if(Board[j][i]==sigh)
			{
				if(j<First)
				First=j;
				if(j>Last)
				Last=j;
				num++;
			}
		}
		if(num<4)//如果棋子数目小于4，那必不可能在当前步胜利 
		continue;//跳过本列看下一行 
		if(First-Last==4)//如果有五个棋子连在一起，看五个棋子的前一个位置是否为空 
		{
			if(First>=1&&Board[First-1][i]==2)
			{
				struct Point* a=new Point;
				a->y=i;
				a->x=First-1;
				PointSet1.push_back(&a);
			}
			continue;
		}
		if(First-Last==3)//如果四子连在一起，看四个棋子的前两个位置是否为空 
		{
			if(First>=2&&Board[First-1][i]==2&&Board[First-2][i]==2)
			{
				struct Point* a=new Point;
				struct Point* b=new Point;
				a->y=i;
				b->y=i;
				a->x=First-1;
				b->x=First-2;
				PointSet2.push_back(&a);
				PointSet2.push_back(&b);
			}
			continue; 
		}
		int k=0;
		int F=19;
		int L=-1;
		while(k<19)
		{
			/*if(Board[i][k]!=sigh)
			{
				k++;
				continue;
			}*/
			
			if(Board[k][i]==sigh)
			{
				if(k<F)
				F=k;
				if(k>L)
				L=k;
				k++;
			}
			else if(k>=1&&Board[k-1][i]==sigh&&F+6<=19)
			{
				FF=F;
				LL=L;
				F=19;
				L=-1;
				if(Board[k][i]==2)
				{
					int kk=0;
					for(int mm=1;mm<=6-(FF-LL+1)-1;mm++)
					{
						if(Board[k+mm][i]!=sigh)
						{
							kk=1;
							break;
						}
					}
					if(kk==0)
					{
						//填上就能连在一起六个 
						struct Point* a=new Point;
						a->y=i;
						a->x=k;
						PointSet1.push_back(&a);
						k++;
						continue;
					}
					else if(kk==1)
					{
						k++;
						continue;
					}
					if(Board[k+1][i]==2)
					{
						int kkk=0;
						for(int mmm=1;mmm<=6-(FF-LL+1)-2;mmm++)
						{
							if(Board[k+1+mmm][i]!=sigh)
							{
								kkk=1;
								break;
							}
						}
						if(kkk==0)
						{
							//填上连续的两个棋子可以连成六个 
							struct Point* a=new Point;
							struct Point* b=new Point;
							a->y=i;
							b->y=i;
							a->x=k;
							b->x=k+1;
							PointSet2.push_back(&a);
							PointSet2.push_back(&b);
							k=k+2;
						}
						else if(kkk==1)
						{
							k=k+2;
						}
					}
				}
			}
			else
			{
				F=19;
				L=-1;
				k++;
			}
		}
	}
	
}
int main()
{
	Step step;//临时步结构
	char message[256];//通信消息缓冲
    int computerSide;//己方执棋颜色
    int start=0;//对局开始标记
	srand(int(time(0)));
	//此处放置初始化代码
    //...
    
	while (1)	//程序主循环
	{
		fflush(stdout);//不要删除此语句，否则程序会出问题
		scanf("%s", message);//获取平台命令消息
        //分析命令
		if (strcmp(message, "name?") == 0)//向对战平台发送队名
		{
			fflush(stdin);
			/***********将"令狐冲"改为你的队名，不超过6个汉字或12个英文字母，否则无成绩************/
			/*******/		printf("name 令狐冲\n");		/**只修改令狐冲，不要删除name空格****/
			/***********将"令狐冲"改为你的队名，不超过6个汉字或12个英文字母，否则无成绩************/
		}
		else if (strcmp(message, "new") == 0)//建立新棋局
		{
			int i, j;
			scanf("%s", message);//获取己方执棋颜色
			fflush(stdin);
			if (strcmp(message, "black") == 0)	computerSide = BLACK;  //执黑
			else  computerSide = WHITE;   //执白

			for (i = 0; i<19; ++i)   //初始化棋局
				for (j = 0; j<19; ++j)
					Board[i][j] = EMPTY;
			start = 1;

			if (computerSide == BLACK)
			{
				/**********生成第一手着法，并保存在step结构中，落子坐标为(step.first.x,step.first.y)**********/
				/****************************在下方填充代码，并替换我的示例代码******************************/


				step.first.x = 9;
				step.first.y = 9;


				/******************************在上面填充第一步行棋代码*******************************************/

				Board[step.first.x][step.first.y] = computerSide;//处理己方行棋
				//printf("move %c%c@@\n", step.first.x + 'A', step.first.y + 'A');//输出着法
				printf("move %c%c\n", step.first.x + 'A', step.first.y + 'A');//输出着法
			}
		}
		else if(strcmp(message,"move")==0)//行棋,本程序核心
		{
			scanf("%s", message);//获取对手行棋着法
            fflush(stdin); 
			int len = strlen(message);
			
			step.first.x=message[0]-'A';		step.first.y=message[1]-'A';
			if(len==4)
			{
				step.second.x=message[2]-'A';		step.second.y=message[3]-'A';
			}
            //处理对手行棋
			Board[step.first.x][step.first.y] = 1 - computerSide;
			//if(!(step.second.x==-1 && step.second.y==-1)) Board[step.second.x][step.second.y] = 1 - computerSide;
			if (len == 4) Board[step.second.x][step.second.y] = 1 - computerSide;
            /**********************************************************************************************************/
			/***生成落子的坐标，保存在step结构中，第一子下在(step.first.x,step.first.y)，第一子下在(step.first.x,step.first.y)***/
			/**************************************在下方填充代码，并替换我的示例代码*****************************************/
			FindPosition(Board,0,PointSet1,PointSet2);
			FindPosition(Board,1,PointSet3,PointSet4);
			//生成第1子落子位置step.first.x和step.first.y
			int x, y;
			int ll=0;
			int jj=0;
			x = rand() % 19; y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.first.x = x;
			step.first.y = y;
			//Board[step.first.x][step.first.y] = computerSide;
			if(PointSet1.size()!=0||PointSet2.size()!=0)
			{
				if(PointSet2.size()!=0)
				{
					step.first.x=PointSet2[0].x;
					step.first.y=PointSet2[0].y;
				}
				else if(PointSet1.size()!=0)
				{
					step.first.x=PointSet1[0].x;
					step.first.y=PointSet1[0].y;
					ll=1;
				}
			}
			else if(PointSet3.size()!=0||PointSet4.size()!=0)
			{
				if(PointSet3.size()!=0)
				{
					step.first.x=PointSet3[0].x;
					step.first.y=PointSet3[0].y;
				}
				else if(PointSet4.size()!=0)
				{
					step.first.x=PointSet4[0].x
					step.first.y=PointSet4[0].y;
					jj=1;
				}
			}
			Board[step.first.x][step.first.y] = computerSide;

			//生成第2子落子位置step.second.x和step.second.y	
			x = rand() % 19;	y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.second.x = x;
			step.second.y = y;
			//Board[step.second.x][step.second.y] = computerSide;
			if(PointSet1.size()!=0||PointSet2.size()!=0)
			{
				if(PointSet2.size()>2)
				{
					step.second.x=PointSet2[2].x;
					step.second.y=PointSet2[2].y;
				}
				else if(PointSet1.size()!=0)
				{
					if(ll==0)
					{
						step.second.y=PointSet1[0].y;
						step.second.x=PointSet1[0].x;
					}
					//step.second.y=PointSet1[0];
					else
					{
						step.second.y=PointSet1[1].y;
						step.second.x=PointSet1[1].x;
					}
				}
			}
			else if(PointSet3.size()!=0||PointSet4.size()!=0)
			{
				if(PointSet4.size()!=0)
				{
					if(jj==1)
					{
						step.first.x=PointSet4[1].x
						step.first.y=PointSet4[1].y;
					}
				}
			}
			/*****************************************在上面填充代码******************************************************/
			/**********************************************************************************************************/

			printf("move %c%c%c%c\n",step.first.x+'A',step.first.y+'A',step.second.x+'A',step.second.y+'A');//输出着法
		}
        else if (strcmp(message, "error") == 0)//着法错误
        {
            fflush(stdin);
        }
		else if (strcmp(message, "end") == 0)//对局结束
		{
            fflush(stdin);
			start = 0;
		}
		else if (strcmp(message, "quit") == 0)//退出引擎
		{
            fflush(stdin);
			printf("Quit!\n");
			break;
		}
	}
	return 0;
}
