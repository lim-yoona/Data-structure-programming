#include<iostream>
#include<cmath>
using namespace std;
struct Edge_Node {
	int adjvex;//编号
	int weight;//权值
	struct Edge_Node* nextarc;
};
struct Edge_Node2{
	int i;//房间i 
	int j;//房间j 
	int f;//成本f 
	struct Edge_Node2*nextarc;
};
class DAS {
	private:
		int n;
		struct Edge_Node* DynamicA;
		int num;
	public:
		DAS(int b) {
			//cout<<"DAConstractor"<<endl;
			n=b;
			num=0;
			DynamicA=new Edge_Node;
			DynamicA->adjvex=-1;
			DynamicA->nextarc=NULL;
		}
		void Add(int k) {
			//cout<<"Function_Add"<<endl;
			struct Edge_Node* p=DynamicA;
			int sigh=0;
			while(p!=NULL) {
				if(p->adjvex==k) {
					sigh=1;
					break;
				}
				p=p->nextarc;
			}
			//cout<<"Mid"<<endl;
			if(sigh==1)
				return ;
			//cout<<"MidBehind"<<endl;
			struct Edge_Node* e=new Edge_Node;
			e->adjvex=k;
			e->nextarc=NULL;
			p=DynamicA;
			while(p->nextarc!=NULL) {
				p=p->nextarc;
			}
			p->nextarc=e;
			num++;
			//cout<<"Function_Add_End"<<endl;
		}
		bool JudjeIsWholeG() {
			if(num==n)
				return true;
			else
				return false;
		}
		void PrintS() {
			struct Edge_Node* p=DynamicA->nextarc;
			while(p!=NULL) {
				//cout<<"PrintS"<<endl;
				cout<<p->adjvex<<endl;
				p=p->nextarc;
			}
		}
		bool Research(int k) {
			struct Edge_Node* p=DynamicA->nextarc;
			while(p!=NULL) {
				if(p->adjvex==k)
					return true;
				p=p->nextarc;
			}
			return false;
		}
		int Get_Num() {
			return num;
		}
		int Index(int k) {
			struct Edge_Node* p=DynamicA->nextarc;
			int sigh=0;
			while(sigh!=k) {
				p=p->nextarc;
				sigh++;
			}
			return p->adjvex;
		}
//		int Compare(DAS &k) {
//			for(int i=0; i<k.Get_Num(); i++) {
//				if(this->Index(i)==k.Index(i))
//					continue;
//				if(this->Index(i)<k.Index(i))
//					return 1;
//				if(this->Index(i)>k.Index(i))
//					return 2;
//			}
//		}
};
class DA {
	private:
		int n;
		struct Edge_Node2* DynamicA;
		int num;
	public:
		DA(int b) {
			//cout<<"DAConstractor"<<endl;
			n=b;
			num=0;
			DynamicA=new Edge_Node2;
			DynamicA->i=-1;
			DynamicA->j=-1;
			DynamicA->f=-1;
			DynamicA->nextarc=NULL;
		}
		void Add(int i,int j,int f) {
			//cout<<"Function_Add"<<endl;
//			struct Edge_Node* p=DynamicA;
//			int sigh=0;
//			while(p!=NULL) {
//				if(p->adjvex==k) {
//					sigh=1;
//					break;
//				}
//				p=p->nextarc;
//			}
//			//cout<<"Mid"<<endl;
//			if(sigh==1)
//				return ;
			//cout<<"MidBehind"<<endl;
			struct Edge_Node2* e=new Edge_Node2;
			e->i=i;
			e->j=j;
			e->f=f;
			e->nextarc=NULL;
			struct Edge_Node2*p=DynamicA;
			while(p->nextarc!=NULL) {
				p=p->nextarc;
			}
			p->nextarc=e;
			num++;
			//cout<<"Function_Add_End"<<endl;
		}
		bool JudjeIsWholeG() {
			if(num==n)
				return true;
			else
				return false;
		}
//		void PrintS() {
//			struct Edge_Node2* p=DynamicA->nextarc;
//			while(p!=NULL) {
//				//cout<<"PrintS"<<endl;
//				cout<<p->adjvex<<endl;
//				p=p->nextarc;
//			}
//		}
		bool Research(int k) {
			struct Edge_Node2* p=DynamicA->nextarc;
			while(p!=NULL) {
				if(p->f==k)
					return true;
				p=p->nextarc;
			}
			return false;
		}
		int Get_Num() {
			return num;
		}
//		int Index(int k) {
//			struct Edge_Node* p=DynamicA->nextarc;
//			int sigh=0;
//			while(sigh!=k) {
//				p=p->nextarc;
//				sigh++;
//			}
//			return p->adjvex;
//		}
//		int GetSign(int k)
//		{
//			struct Edge_Node* p=DynamicA->nextarc;
//			int sigh=0;
//			while(sigh!=k) {
//				p=p->nextarc;
//				sigh++;
//			}
//			return p->sign;
//		}
//		int Compare(DA &k) {
//			for(int i=0; i<k.Get_Num(); i++) {
//				if(this->Index(i)==k.Index(i))
//					continue;
//				if(this->Index(i)<k.Index(i))
//					return 1;
//				if(this->Index(i)>k.Index(i))
//					return 2;
//			}
//		}
		int Find_f_smallest(int &x,int &y)
		{
			int sum=pow(2,30);
			struct Edge_Node2* p=DynamicA->nextarc;
			while(p!=NULL)
			{
				if(p->f<sum)
				{
					sum=p->f;
					x=p->i;
					y=p->j;
				}
				p=p->nextarc;
			}
			return sum;
		}
		void Delete(int k)
		{
			struct Edge_Node2* p=DynamicA->nextarc;
			struct Edge_Node2* p0=DynamicA;
			while(p!=NULL)
			{
				if(p->f==k)
				{
					p0->nextarc=p->nextarc;
					break;
				}
				p=p->nextarc;
				p0=p0->nextarc;
			}
		}
		int Sum_()
		{
			struct Edge_Node2* p=DynamicA->nextarc;
			int b=0;
			while(p!=NULL)
			{
				b=b+p->f;
				p=p->nextarc;
			}
			return b;
		}
};
int main ()
{
	int n,e;//n为房间数， e为可能的连接数
	cin>>n;
	cin>>e;
	int L[n];
	DA s(e);
	//cout<<"000000000000000"<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		L[i]=x;
	}
	//cout<<"1111111111111111111"<<endl;
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		s.Add(a,b,c);
	}
	//cout<<"*******************"<<endl;
	DAS v(n);
	DA d(e);
	while(!v.JudjeIsWholeG())
	{
		//cout<<"####################"<<endl;
		int x;
		int y;
		int u=s.Find_f_smallest(x,y);
		s.Delete(u);
		if(v.Research(x)&&v.Research(y))
		continue;
		v.Add(x);
		v.Add(y);
		d.Add(x,y,u);
	}
	//cout<<"----------------"<<endl;
	int b=pow(2,30);
	for(int i=0;i<n;i++)
	{
		if(L[i]<b)
		{
			b=L[i];
		}
	}
	int c=d.Sum_()+b;
	cout<<c<<endl;
}
