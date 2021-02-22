/*The KMP function find the position that
pattern string first appears in the target string 
and then return the position*/
#include<iostream>
#include<vector>
using namespace std;
void NEXT(string s,int next[100000])
{
	next[0]=-1;
	int i=1;
	for(;i<s.size();i++)
	{
		int j=next[i-1];
		while(j>=0&&s[j]!=s[i-1])
		j=next[j];
		if(j>=0&&s[j]==s[i-1])
		next[i]=j+1;
		else
		next[i]=0;
	}
}
int KMP(string s,string pattern,int next[100000])
{
	int n=s.size();
	int m=pattern.size();
	int i=0;
	while(i<n)
	{
		int j=0;
		while(s[i]==pattern[j]&&i<n&&j<m)
		{
			i++;
			j++;
		}
		if(j==m)
		return i-m;
		if(i>=n)
		return -1;
		if(j==0)
		i++;
		else
		j=next[j];
	}
	if(i==n)
	return -1;
}
int main ()
{
	string s="abacaabacabacabaabb";
	string pattern="abd";
	//vector<int>next(pattern.size());
	int next[pattern.size()];
	NEXT(pattern,next);
	int k=KMP(s,pattern,next);
	cout<<k<<endl;
}
