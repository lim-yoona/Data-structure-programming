#include<stdio.h> 
#include<math.h>
int main ()
{
	double x,y,z;
	x=0;
	y=0;
	z=0;
	scanf("%lf%lf",&x,&y);
	z=x-(x-y)/(pow(x,3)-3*x-1-pow(y,3)+3*x+1);
	printf("%lf",z);
}
