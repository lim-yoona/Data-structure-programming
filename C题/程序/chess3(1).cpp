#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<vector>

#define BLACK 0
#define WHITE 1
#define EMPTY 2
using namespace std;
struct Point { //点结构
	int x,y;
};
struct Step { //步结构
	Point first,second;
	int value;
};
int Board[19][19];//存储棋盘信息，其元素值为 BLACK, WHITE, EMPTY 之一
//3棋子判断 所用全局变量
struct sd {
	int X;
	int Y;
	int fx;
} fuhe[2],fuhe1[1]; //符合条件的情况，记录下来
// 4或5棋子判断所用全局变量
struct a { //结构体·用来存储还差一子就可以获胜的情况
	int x;
	int y;
};
struct b { //结构体·用来存储连着下两子才能获胜的情况
	int x1;
	int y1;
	int x2;
	int y2;
};
vector<a> PointSet1;//整个棋局中所有只下一子就可以获胜的坐标的集合
vector<b> PointSet2;//整个棋局中所有连下两子可以获胜的坐标的集合
bool JudgeThree(int Board[19][19],int computerSide) {
	int ttt=0;
	int ttt1=0;
	int dv[4]= {0,1,1,-1};
	int dw[4]= {1,0,1,1}; //代表方向，分别为下，右，右下，左下
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==computerSide) {
				for(int r=0; r<4; r++) {
					int k=0,m,n,bj=0,x,y;    //k存储能连成的个数,bj为标记
					for(int qqq=-2; qqq<0; qqq++) { //探查到的点的前两个,如果是我方棋子
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					for(int qqq=-1; qqq<0; qqq++) { //探查到的点的前1个,如果是对方棋子或者
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					int jug=0;//判断是否连续,0为不连续，1为连续
					for(int qqq=1; qqq<4; qqq++) { //探查后3个点
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							k++;
						}
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
						if(qqq==3&&(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY)) {
							jug=1;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					if(jug==0) {
						for(int qqq=4; qqq<6; qqq++) { //探查第4-5个,如果是我方棋子，不归我们这种情况管
							x=i+qqq*dv[r];
							y=j+qqq*dw[r];
							if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
								bj=1;
								break;
							}
						}
						if(bj==1) { //不符合情况就退出这次循环
							continue;
						}
						for(int qqq=4; qqq<5; qqq++) { //探查第4个点,如果是对方棋子或者为墙
							x=i+qqq*dv[r];
							y=j+qqq*dw[r];
							if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
								bj=1;
								break;
							}
						}
						if(bj==1) { //不符合情况就退出这次循环
							continue;
						}
					} else {
						//加你写的连续的代码
						int x1,y1,k1=0;
						x1=i;
						y1=j;
						while(y1>=0&&x1>=0&&y1<19&&x1<19&&Board[x][y]==EMPTY) {
							k1++;
							x1=x1-dv[r];
							y1=y1-dw[r];
						}
						x1=i+3*dv[r];
						y1=j+3*dw[r];
						while(y1>=0&&x1>=0&&y1<19&&x1<19&&Board[x][y]==EMPTY&&k1<=3) {
							k1++;
							x1=x1+dv[r];
							y1=y1+dw[r];
						}
						x1=i+3*dv[r];
						y1=j+3*dw[r];
						if(x1<0||y1<0||x1>=19||y1>=19||Board[x1][y1]==1-computerSide) {
							bj=1;         //如果有一端被堵就返回错误
						}
						if(k1<=3) {      //空位不够三个就返回错误
							bj=1;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					if(k==2) {
						fuhe[ttt].X=i;//记录下符合条件的情况
						fuhe[ttt].Y=j;
						fuhe[ttt].fx=r;
						ttt++;
					}
					if(ttt==2) {
						break;
					}
				}
			}
			if(ttt==2)
				break;
		}
		if(ttt==2)
			break;
	}
	if(ttt==2)
		return true;
	if(ttt==0)
		return false;
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==computerSide) {
				for(int r=0; r<4; r++) {
					int k=0,m,n,bj=0,x,y;    //k存储能连成的个数,bj为标记
					for(int qqq=-2; qqq<0; qqq++) { //探查到的点的前两个,如果是我方棋子
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					int jug=0;//判断是否连续,0为不连续，1为连续
					for(int qqq=1; qqq<4; qqq++) { //探查后3个点
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							k++;
						}
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
						if(qqq==3&&(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY)) {
							jug=1;
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					if(jug==0) {
						int m1,n1,m2,n2,t1=0,t2=0;    //t标记哪边被堵
						m1=i-dv[r];
						n1=j-dw[r];
						m2=i+4*dv[r];
						n2=j+4*dw[r];
						if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
							t1=1;
						}
						if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
							t2=1;
						}
						if((t1==1&&t2==1)||(t1==0&&t2==0)) {
							bj=1;                  //两边都被堵或者都空
						} else {
							if(t1==1) {
								m2+=dv[r];
								n2+=dw[r];
								if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
									bj=1;           //如果另一边不够六个，跳出
								}
							}
							if(t2==1) {
								m1-=dv[r];
								n1-=dw[r];
								if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
									bj=1;           //如果另一边不够六个，跳出
								}
							}
						}
					} else {
						int m1,n1,m2,n2,t1=0,t2=0;    //t标记哪边被堵
						m1=i-dv[r];
						n1=j-dw[r];
						m2=i+3*dv[r];
						n2=j+3*dw[r];
						if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
							t1=1;
						}
						if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
							t2=1;
						}
						if((t1==1&&t2==1)||(t1==0&&t2==0)) {
							bj=1;                  //两边都被堵或者都空
						} else {
							if(t1==1) {
								for(int i1=0; i1<3; i1++) {
									m2=i+(3+i1)*dv[r];
									n2=j+(3+i1)*dw[r];
									if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
										bj=1;           //如果另一边不够六个，跳出
									}
								}
							}
							if(t2==1) {
								for(int i1=0; i1<3; i1++) {
									m1=i-(1+i1)*dv[r];
									n1=j-(1+i1)*dw[r];
									if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
										bj=1;           //如果另一边不够六个，跳出
									}
								}
							}
						}
					}
					if(bj==1) { //不符合情况就退出这次循环
						continue;
					}
					if(k==2) {
						fuhe1[ttt1].X=i;//记录下符合条件的情况
						fuhe1[ttt1].Y=j;
						fuhe1[ttt1].fx=r;
						ttt1++;
					}
					if(ttt1==1)
						break;
				}
			}
			if(ttt1==1)
				break;
		}
		if(ttt1==1)
			break;
	}


	if(ttt==1&&ttt1==1) {
		fuhe[1].X=fuhe1[0].X;
		fuhe[1].Y=fuhe1[0].Y;
		fuhe[1].fx=fuhe1[0].fx;
		return true;
	}
	return false;
}

bool JudgeFourOrFive(int Board[19][19],int colour) {
	int dv[8]= {0,0,1,-1,1,-1,-1,1};
	int dw[8]= {1,-1,0,0,1,-1,1,-1}; //代表方向，分别为下，上，右，左，右下，左上，左下，右上
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==colour) { //遍历到当前坐标上棋子的颜色为colour
				for(int r=0; r<8; r++) { //遍历八个方向
					int num=1;
					for(int k=1; k<6; k++) { //遍历当前方向下的六个棋子
						if((i+dv[r]*5)>=19||(i+dv[r]*5)<0||(j+dw[r]*5)>=19||(j+dw[r]*5)<0)//判断按照当前方向遍历六个棋子会不会越界
							break;//如果越界，跳出循环，继续遍历下一个方向的六个棋子
						if(Board[i+dv[r]*k][j+dw[r]*k]==colour)
							num++;//遇到当前颜色的棋子，num加一
					}
					if(num!=4||num!=5)//如果六个棋子里面颜色为colour的棋子不足4个或5个 ，那么怎么下都不会直接赢
						continue; //进入下一方向
					else if(num==5) { //六个棋子里面有5个colour颜色的棋子，则余下的那个坐标只要为空，填上colour色的棋就会赢
						for(int k=1; k<6; k++) {
							if(Board[i+dv[r]*k][j+dw[r]*k]==2) { //找到为空的坐标
								struct a* aa=new a;
								aa->x=i+dv[r]*k;
								aa->y=j+dw[r]*k;
								PointSet1.push_back(*aa);
							}
						}
					} else if(num==4) { //六个棋子里面有4个colour颜色的棋子，则余下的两个坐标若都为空，填上两个colour色的棋就会赢
						struct b* bb=new b;
						int m=0;//判断是把坐标存在x，y还是x1，y1
						int counter=0; //判断那两个坐标里面有几个为空
						for(int k=1; k<6; k++) {
							if(Board[i+dv[r]*k][j+dw[r]*k]==2) {
								if(m==0) {
									counter++;
									bb->x1=i+dv[r]*k;
									bb->y1=j+dw[r]*k;
									m=1;//填了x，y之后改变m ,下次填到x1，y1当中
								} else if(m==1) {
									counter++;
									bb->x2=i+dv[r]*k;
									bb->y2=j+dw[r]*k;
								}
							}
						}
						if(counter==2) { //如果两个坐标都为空
							PointSet2.push_back(*bb);
						}
					}
				}
			} else //当前坐标上颜色不为colour棋子的话进入下一循环
				continue;
		}
	}
	if(PointSet1.size()==0&&PointSet2.size()==0)//如果PointSet1和PointSet2都为空，说明当前棋局中不存在可以直接赢的情况
		return false;

	vector<a>::iterator Point1,P;
	vector<b>::iterator Point2,H;
	//去重1·由于遍历了八个方向，实际上，相对两个方向得到的结果有重复，比如向左向右
	for(Point1=PointSet1.begin(); Point1!=PointSet1.end()-1; Point1++) { //去重
		for(P=Point1+1; P!=PointSet1.end(); P++) {
			if((*Point1).x==(*P).x&&(*Point1).y==(*P).y) {
				PointSet1.erase(P);
				P--;
			}
		}
	}
	for(Point2=PointSet2.begin(); Point2!=PointSet2.end()-1; Point2++) { //去重
		for(H=Point2+1; H!=PointSet2.end(); H++) {
			if((*Point2).x1==(*H).x1&&(*Point2).y1==(*H).y1&&(*Point2).x2==(*H).x2&&(*Point2).y2==(*H).y2) {
				PointSet2.erase(H);
				H--;
			}
		}
	}
	//去重2·由于5个子的情况可能包含4个子的情况，导致有的只填一个棋就可胜利的情况，在填两个子胜利的情况里面也记录了，此时把两个子的相关记录删掉
	for(Point1=PointSet1.begin(); Point1!=PointSet1.end(); Point1++) {
		for(Point2=PointSet2.begin(); Point2!=PointSet2.end();) {
			if(((*Point1).x==(*Point2).x1&&(*Point1).y==(*Point2).y1)||((*Point1).x==(*Point2).x2&&(*Point1).y==(*Point2).y2))
				PointSet2.erase(Point2);
			else
				Point2++;
		}
	}
	return true;
}

int main() {
	Step step;//临时步结构
	char message[256];//通信消息缓冲
	int computerSide;//己方执棋颜色
	int start=0;//对局开始标记
	srand(int(time(0)));
	//此处放置初始化代码
	//...

	while (1) {	//程序主循环
		fflush(stdout);//不要删除此语句，否则程序会出问题
		scanf("%s", message);//获取平台命令消息
		//分析命令
		if (strcmp(message, "name?") == 0) { //向对战平台发送队名
			fflush(stdin);
			/***********将"令狐冲"改为你的队名，不超过6个汉字或12个英文字母，否则无成绩************/
			/*******/		printf("name 麻辣香锅\n");		/**只修改令狐冲，不要删除name空格****/
			/***********将"令狐冲"改为你的队名，不超过6个汉字或12个英文字母，否则无成绩************/
		} else if (strcmp(message, "new") == 0) { //建立新棋局
			int i, j;
			scanf("%s", message);//获取己方执棋颜色
			fflush(stdin);
			if (strcmp(message, "black") == 0)	computerSide = BLACK;  //执黑
			else  computerSide = WHITE;   //执白

			for (i = 0; i<19; ++i)   //初始化棋局
				for (j = 0; j<19; ++j)
					Board[i][j] = EMPTY;
			start = 1;

			if (computerSide == BLACK) {
				/**********生成第一手着法，并保存在step结构中，落子坐标为(step.first.x,step.first.y)**********/
				/****************************在下方填充代码，并替换我的示例代码******************************/


				step.first.x = 9;
				step.first.y = 9;


				/******************************在上面填充第一步行棋代码*******************************************/

				Board[step.first.x][step.first.y] = computerSide;//处理己方行棋
				printf("move %c%c@@\n", step.first.x + 'A', step.first.y + 'A');//输出着法
			}
		} else if(strcmp(message,"move")==0) { //行棋,本程序核心
			scanf("%s", message);//获取对手行棋着法
			fflush(stdin);
			step.first.x=message[0]-'A';
			step.first.y=message[1]-'A';
			step.second.x=message[2]-'A';
			step.second.y=message[3]-'A';
			//处理对手行棋
			Board[step.first.x][step.first.y] = 1 - computerSide;
			if(!(step.second.x==-1 && step.second.y==-1)) Board[step.second.x][step.second.y] = 1 - computerSide;

			/**********************************************************************************************************/
			/***生成落子的坐标，保存在step结构中，第1子下在(step.first.x,step.first.y)，第2子下在(step.first.x,step.first.y)*****/
			/**************************************在下方填充代码，并替换我的示例代码*****************************************/
			//生成第1子落子位置step.first.x和step.first.y

//			int x, y;
//			x = rand() % 19; y = rand() % 19;
//			while (Board[x][y] != EMPTY)
//			{
//				x = rand() % 19;	y = rand() % 19;
//			}
//			step.first.x = x;
//			step.first.y = y;
//			Board[step.first.x][step.first.y] = computerSide;
//
//			//生成第2子落子位置step.second.x和step.second.y
//			x = rand() % 19;	y = rand() % 19;
//			while (Board[x][y] != EMPTY)
//			{
//				x = rand() % 19;	y = rand() % 19;
//			}
//			step.second.x = x;
//			step.second.y = y;
//			Board[step.second.x][step.second.y] = computerSide;
			bool judge;
			judge=JudgeFourOrFive(Board,computerSide);
			if(judge==true) {
				//填充你的进攻落子代码

			}
			if(judge==false&&JudgeFourOrFive(Board,1-computerSide)) {
				judge=true;
				//填充你的防守落子代码

			}
			if(judge==false&&JudgeThree(Board,computerSide)) {
				judge=true;
				//填充落子代码
				int dv[4]= {0,1,1,-1};
				int dw[4]= {1,0,1,1}; //代表方向，分别为下，右，右下，左
				int x,y;
				for(int i=-1; i<15; i++) {
					int bj=0;
					x=fuhe[0].X+i*dv[fuhe[0].fx];
					y=fuhe[0].Y+i*dw[fuhe[0].fx];
					if(Board[x][y]==EMPTY) {
						step.first.x=x;
						step.first.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.first.x][step.first.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.first.x][step.first.y] = computerSide;
				}
				for(int i=-1; i<19; i++) {
					int bj=0;
					x=fuhe[1].X+i*dv[fuhe[1].fx];
					y=fuhe[1].Y+i*dw[fuhe[1].fx];
					if(Board[x][y]==EMPTY) {
						step.second.x=x;
						step.second.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.second.x][step.second.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.second.x][step.second.y] = computerSide;
				}
			}
			if(judge==false&&JudgeThree(Board,1-computerSide)) {
				judge=true;
				//填充落子代码
				int dv[4]= {0,1,1,-1};
				int dw[4]= {1,0,1,1}; //代表方向，分别为下，右，右下，左
				int x,y;
				for(int i=-1; i<19; i++) {
					int bj=0;
					x=fuhe[0].X+i*dv[fuhe[0].fx];
					y=fuhe[0].Y+i*dw[fuhe[0].fx];
					if(Board[x][y]==EMPTY) {
						step.first.x=x;
						step.first.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.first.x][step.first.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.first.x][step.first.y] = computerSide;
				}
				for(int i=-1; i<15; i++) {
					int bj=0;
					x=fuhe[1].X+i*dv[fuhe[1].fx];
					y=fuhe[1].Y+i*dw[fuhe[1].fx];
					if(Board[x][y]==EMPTY) {
						step.second.x=x;
						step.second.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.second.x][step.second.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.second.x][step.second.y] = computerSide;
				}
			}
			if(judge==false) {
				//填充落子代码
				int dv[8]= {0,0,1,-1,1,-1,-1,1};
				int dw[8]= {1,-1,0,0,1,-1,1,-1}; //代表方向，分别为下，上，右，左，右下，左上，左下，右上

				int bj=0;
				for(int i=0; i<19; i++) {
					for(int j=0; j<19; j++) {
						if(Board[i][j]!=EMPTY) {
							for(int r=0; r<8; r++) {
								int x=i+dv[r];
								int y=j+dw[r];
								if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY) {
									step.first.x=x;
									step.first.y=y;
									bj++;
								}
								if(bj==1)
									break;
							}
						}
						if(bj==1)
							break;
					}
					if(bj==1)
						break;

				}
				Board[step.first.x][step.first.y] = computerSide;

				bj=0;
				for(int i=0; i<19; i++) {
					for(int j=0; j<19; j++) {
						if(Board[i][j]!=EMPTY) {
							for(int r=0; r<8; r++) {
								int x=i+dv[r];
								int y=j+dw[r];
								if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY) {
									step.second.x=x;
									step.second.y=y;
									bj++;
								}
								if(bj==1)
									break;
							}
						}
						if(bj==1)
							break;
					}
					if(bj==1)
						break;

				}
				Board[step.second.x][step.second.y] = computerSide;
			}




			/*****************************************在上面填充代码******************************************************/
			/**********************************************************************************************************/

			printf("move %c%c%c%c\n",step.first.x+'A',step.first.y+'A',step.second.x+'A',step.second.y+'A');//输出着法
		} else if (strcmp(message, "error") == 0) { //着法错误
			fflush(stdin);
		} else if (strcmp(message, "end") == 0) { //对局结束
			fflush(stdin);
			start = 0;
		} else if (strcmp(message, "quit") == 0) { //退出引擎
			fflush(stdin);
			printf("Quit!\n");
			break;
		}
	}
	return 0;
}
