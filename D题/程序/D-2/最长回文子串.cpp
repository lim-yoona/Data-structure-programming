#include<iostream>
using namespace std;
int main ()
{
	string s;
	cin>>s;
	int n=s.length();
	int * dp=new int[n];
	for(int i=0;i<n;i++)
	{
		dp[i]=-1;
	}
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		int k=i-dp[i-1]-1;
		if(k>=0&&s[i]==s[k])
		dp[i]=dp[i-1]+2;
		else if(s[i]==s[i-1])
		dp[i]=2;
		else
		dp[i]=1;
	}
	cout<<"###################"<<endl;
	for(int i=0;i<n;i++)
	cout<<dp[i]<<endl;
	cout<<"###################"<<endl;
	int maxLength=0;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>maxLength)
		maxLength=dp[i];
	}
	cout<<maxLength<<endl;
} 
