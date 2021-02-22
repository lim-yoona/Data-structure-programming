#include<iostream>
using namespace std;
/*设一背包可容纳物体的最大质量为m，现有n个物体，质量分别为m1.m2，m3···m(n) ，
要从n件物体中挑选若干见，使得质量和恰好为m，问是否有这样的组合*/
bool fun(int a[100],int m,int n)
{
	cout<<"数组:";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<"m:"<<m<<",";
	cout<<"n:"<<n<<","<<endl;
	if(a[n-1]==m)
	return true;
	if(n==1&&a[n-1]!=m)
	return false;
	if(n==0)
	return false;
	if(a[n-1]<m)
	{
		if(fun(a,m-a[n-1],n-1))
		return true;
		else
		return fun(a,m,n-1);
	}
	if(a[n-1]>m)
	{
		return fun(a,m,n-1);
	}
}
int main ()
{
	int n;
	cin>>n;
	int a[100];
	int m;
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bool flag=fun(a,m,n);
	if(flag)
	cout<<"True"<<endl;
	else
	cout<<"False"<<endl;
} 
