#include<iostream>
#include<string>
using namespace std;
int Find_good_infix(string s)
{
	//DA * Array=new DA(100000);
	int Array[100000];
	int mm=0;
	int n=s.size();
	int i=0;
	int j=n-1;
	for(int k=1;k<=n-1;k++)
	{
		//j--;
		if(s[0]!=s[n-k])
		continue;
		string str1=s.substr(i,k);
		string str2=s.substr(n-k,k);
		//j--;
		if(str1==str2)
		{
			Array[mm]=k;
			mm++;
		} 
	}
	if(mm==0)
	{
		return n;
	}
	if(mm==1)
	{
		if(n-Array[0]*2>=0)
		return n-Array[0]*2;
		else
		return 0;
	}
	else
	{
		if(n-Array[mm-2]*2>=0)
		return n-Array[mm-2]*2;
		else
		return 0;
	}
}
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
int Find_good_postfix(string s)
{
	int n=s.size();
	int Array[100000];
	int i=0;
	int j=n-1;
	int mm=0;
	for(int k=1;k<=n-1;k++)
	{
		string str1=s.substr(n-k,k);
		string str2=s.substr(0,n-1);
		int next[str1.size()];
		NEXT(str1,next);
		if(KMP(str2,str1,next)!=-1)
		{
			Array[mm]=k;
			mm++;
		}
	}
	if(mm==0)
	return 0;
	else
	return Array[mm-1];
}
int main ()
{
	string str;//输入的字符串，长度不超过100000
	cin>>str;
	cout<<Find_good_infix(str)+Find_good_postfix(str)<<endl;
	//cout<<Find_good_postfix(str)<<endl;
}
