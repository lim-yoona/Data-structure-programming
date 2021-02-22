#include<iostream>
#include<string>
using namespace std;
int Find_good_infix(string s) {
	int Array[100000];
	int mm=0;
	int n=s.size();
	int i=0;
	int j=n-1;
	for(int k=1; k<=n-1; k++) {
		if(s[0]!=s[n-k])
			continue;
		string str1=s.substr(i,k);
		string str2=s.substr(n-k,k);
		if(str1==str2) {
			Array[mm]=k;
			mm++;
		}
	}
	if(mm==0) {
		return n;
	}
	if(mm==1) {
		if(n-Array[0]*2>=0)
			return n-Array[0]*2;
		else
			return 0;
	} else {
		if(n-Array[mm-2]*2>=0)
			return n-Array[mm-2]*2;
		else
			return 0;
	}
}
int Find_Substr(string haystack, string needle) {
	int h=haystack.size(),n=needle.size(),j,count;
	if(n>h)
		return -1;
	for(int i=0; i<h-n+1; i++) {
		j=0;
		count=0;
		while(haystack[i+j]==needle[j]&&needle[j]!='\0') {
			j++;
			count++;
		}
		if(count==n)
			return i;
	}
	return -1;
}
int Find_good_postfix(string s) {
	int n=s.size();
	int Array[100000];
	int i=0;
	int j=n-1;
	int mm=0;
	for(int k=1; k<=n-1; k++) {
		string str1=s.substr(n-k,k);
		string str2=s.substr(0,n-1);
		if(Find_Substr(str2,str1)!=-1) {
			Array[mm]=k;
			mm++;
		}
	}
	if(mm==0)
		return 0;
	else
		return Array[mm-1];
}
int main () {
	string str;//输入的字符串，长度不超过100000
	while(true)
	{
		cin>>str;
		cout<<Find_good_infix(str)+Find_good_postfix(str)<<endl;
	}
}
