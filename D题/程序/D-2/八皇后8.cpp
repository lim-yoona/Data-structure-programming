#include<iostream> 
#include<vector>
using namespace std;
int b(int i)
{
	if(i<0)
	return -i;
	else
	return i;
}
bool a(int v[9],int m,int n)
{
	for(int i=0;i<9;i++)
	{
		if(m==v[i])
		return false;
	}
	for(int i=1;i<9;i++)
	{
		if(b(i-n)==b(v[i]-m))
		return false;
	}
	return true;
}
bool isFull(int v[9])
{
	for(int i=1;i<9;i++)
	{
		if(v[i]==-1)
		return false;
	}
	return true;
}
void output(int v[9])
{
	for(int i=1;i<9;i++)
	{
		cout<<v[i]<<endl;
	}
}
void back_(int v[9],int n)
{
	cout<<"output"<<endl;
	output(v);
	if(n==8)
	{
		cout<<"n==8"<<endl;
		output(v);
		return ;
	}
	for(int i=1;i<9;i++)
	{
		if(a(v,i,n))
		{
			
			cout<<"if" <<endl;
			cout<<i<<endl; 
			v[n+1]=i;
			back_(v,n+1);
			cout<<"end"<<endl;
		}
		
	}
	cout<<"back_end"<<endl;
	return;
}
int main ()
{
	int v[9];
	for(int i=0;i<9;i++)
	{
		v[i]=-1;
	}
	back_(v,0);
}
