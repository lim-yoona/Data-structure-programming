#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std; 
int getCurlA(char *tar, char ch, int curlA)
{
    char *p = tar;
    int delta = 0;
    while(p && *p!=ch){
        p++;
        delta =delta+ 1;
    }
    return curlA - delta;
}
 
int SundaySearch(char *src, char *tar)
{
    int srcLen = strlen(src);
    int tarLen = strlen(tar);
    int curlA = 0;
	int curlB = 0;
    while(src[curlA] == tar[curlB]){
        if(curlB == tarLen-1){
            return curlB - tarLen + 1;
        }else{
            curlA = getCurlA(&tar, src[curlA], curlB+1);
        }
        curlA++;
    }
    return -1;
}
int main ()
{
	char* s="abacaabacabacabaabb";
	char* pattern="abd";
	cout<<SundaySearch(s, pattern)<<endl;
}
