#include<stdio.h> 
int findMaxValue(int a[100],int n)
{
	if(n==1)
	return a[0];
	else
	{
		return findMaxValue(a,n-1)>a[n-1]?findMaxValue(a,n-1):a[n-1];
	}
}
int main ()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int k=findMaxValue(a,n);
	printf("%d",k);
}
