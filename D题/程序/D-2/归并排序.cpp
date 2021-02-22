#include<iostream> 
using namespace std;
void MSort(int a[100],int len,int i,int j)
{
	if(len==1)
	return;
	if(len==2)
	{
		if(a[j]<a[i])
		{
			int k=a[j];
			a[j]=a[i];
			a[i]=k;
		}
		return;
	}
	MSort(a,len/2,i,i+len/2-1);
	MSort(a,len-len/2,i+len/2,j);
	for(int m=i+len/2;m<=j;m++)
	{
		int mm=i;
		while(a[m]>a[mm])
		{
			mm++;
		}
		int mid=a[m];
		for(int kk=m-1;kk>=mm;kk--)
		{
			a[kk+1]=a[kk];
		}
		a[mm]=mid;
	}
	return;
}
int main ()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	MSort(a,n,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
