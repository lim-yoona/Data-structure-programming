#include<iostream>
#include<vector>
using namespace std;
int main ()
{
	vector<int> a;
	int i;
	for(int j=0;j<5;j++)
	{
		cin>>i;
		a.push_back(i);
	}
	for(int k=0;k<5;k++)
	{
		cout<<a[k]<<endl;
	}
}
