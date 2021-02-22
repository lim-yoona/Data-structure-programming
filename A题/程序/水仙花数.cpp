#include<stdio.h>
#include<math.h>
int main ()
{
	int num=0;
	for(int i=100;i<10000;i++)
	{
		int a=i/100;
		int b=i%100/10;
		int c=i%10;
		if(pow(a,3)+pow(b,3)+pow(c,3)==i)
		{
			num++;
			printf("%d\n",i);
		}
	}
	printf("%d\n",num);
 } 
