#include<vector>
#include<iostream>
using namespace std;
int main ()
{
	vector<int> G;
	G=vector<int>(11,4);
	cout<<G.size()<<endl;
	for(int &x:G)
	cout<<x<<endl;
} 
