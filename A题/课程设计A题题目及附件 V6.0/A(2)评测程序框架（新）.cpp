#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/********************************************************************************/
/********************************将学生的代码添加到下面******************************/




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
