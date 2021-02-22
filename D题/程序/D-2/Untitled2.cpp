#include<iostream>
#include<Windows.h>
#include<thread> 
using namespace std;
int i(string str)
{
	for(int i=0;i<1000;i++)
	{
		cout<<str<<endl;
		Sleep(100);
	}
	return 0;
}
int main ()
{
	int k;
	cin>>k;
	std::thread thread1(i,"aaa");
	std::thread thread2(i,"bbb");
	thread1.join();
	thread2.join();
	cout<<"end"<<endl;
}

