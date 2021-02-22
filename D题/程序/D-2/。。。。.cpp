#include<iostream>
using namespace std;
int Find_Substr(string str1, string str2) {
	int m=str1.size();
	int n=str2.size();
	int i=0,j=0;//i指向源串首位 j指向子串首位
	int k;
	int m=n;//第一次匹配时 源串中参与匹配的元素的下一位

	for(; i<m;) {
		if(str1[i]!=str2[j]) {
			for(k=n-1; k>=0; k--) { //遍历查找此时子串与源串[i+n+1]相等的最右位置
				if(str2[k]==str1[m])
					break;
			}
			i=m-k;//i为下一次匹配源串开始首位 Sunday算法核心：最大限度跳过相同元素
			j=0;//j依然为子串首位
			m=i+n;//m为下一次参与匹配的源串最后一位元素的下一位
			if(m>m)//当下一次参与匹配的源串字数的最后一位的下一位超过源串长度时
				return -1;
		} else {
			if(j==n-1)//若j为子串末位 匹配成功 返回源串此时匹配首位
				return i-j;
			i++;
			j++;
		}
	}
	return -1;//当超过源串长度时
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
		if(strStr(str2,str1)!=-1) {
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
	cin>>str;
	cout<<Find_good_postfix(str)<<endl;
}
