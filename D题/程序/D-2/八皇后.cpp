#include<iostream>
#include<queue>
using namespace std;
bool IsSuitable(queue<int> Q,int i)
{
	output(Q);
	while(!Q.empty())
	{
		if(Q.back()==i)
		return false;
		Q.pop();
	}
	return true;
}
void output(queue<int> s) 
{
	cout<<"output"<<endl;
	while(!s.empty())
	{
		//cout<<"1"<<endl;
		cout<<s.back()<<endl;
		s.pop();
	}
}
void back(int n,queue<int>&s)
{
	cout<<"back"<<endl;
	//output(s);
	if(n==8)
	{
		//cout<<"n==8"<<endl;
		output(s);
		return ;
	}
	bool f=true; 
	//cout<<"2"<<endl;
	for(int i=1;i<=8;i++)
	{
		//cout<<"4"<<endl;
		if(IsSuitable(s,i))
		{
			//cout<<"i:"<<i<<endl;
			s.push(i);
			//output(s);
			back(s.size(),s);
			return ;
			f=false;
		}
	}
}
int main ()
{
	queue<int> s;
	back(0,s);
}
