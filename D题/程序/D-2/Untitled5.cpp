#include<iostream>
//#include<cmath>
using namespace std;
struct Edge_Node {
	int adjvex;//编号
	int weight;//权值
	struct Edge_Node* nextarc;
};
struct Vertex_Node {
	int data;//顶点域
	struct Edge_Node* nextarc;//边表头指针
};
struct Conclusion_Vertex_Node {
	int path_length;
	struct Edge_Node* nextarc;
};
class DA {
	private:
		int n;
		struct Edge_Node* DynamicA;
		int num;
	public:
		DA(int b) {
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
		int Compare(DA &k) {
			for(int i=0; i<k.Get_Num(); i++) {
				if(this->Index(i)==k.Index(i))
					continue;
				if(this->Index(i)<k.Index(i))
					return 1;
				if(this->Index(i)>k.Index(i))
					return 2;
			}
		}
};
class Dijkstra {
	private:
		int Vertex_num;
		DA * FS;
		struct Vertex_Node* Vertex_Table;//顶点表
		struct Conclusion_Vertex_Node* Conclusion;//结果表
	public:
		Dijkstra(int n) {
			Vertex_num=n;
			Vertex_Table=new Vertex_Node[n];
			Conclusion=new Conclusion_Vertex_Node[n];
			for(int i=0; i<n; i++) {
				Vertex_Table[i].nextarc=NULL;
			}
			for(int i=0; i<n; i++) {
				Conclusion[i].path_length=0;
				Conclusion[i].nextarc=NULL;
			}
			FS=new DA(Vertex_num);
		}
		void Add_Edge(int a,int b,int c) {
			struct Edge_Node* e=new Edge_Node;
			e->adjvex=b;
			e->weight=c;
			e->nextarc=NULL;
			if(Vertex_Table[a].nextarc==NULL) {
				Vertex_Table[a].nextarc=e;
			} else {
				struct Edge_Node* p=Vertex_Table[a].nextarc;
				while(p->nextarc!=NULL) {
					p=p->nextarc;
				}
				p->nextarc=e;
			}
		}
		void Add_Vertex(int a,int b) { //a是终点编号，b是添加的顶点编号
			struct Edge_Node* e=new Edge_Node;
			e->adjvex=b;
			e->nextarc=NULL;
			e->weight=0;
			if(Conclusion[a].nextarc==NULL) {
				Conclusion[a].nextarc=e;
			} else {
				struct Edge_Node* p=Conclusion[a].nextarc;
				while(p->nextarc!=NULL) {
					p=p->nextarc;
				}
				p->nextarc=e;
			}
		}
		void Adjacency_List_Print() {
			for(int i=0; i<Vertex_num; i++) {
				struct Edge_Node* p=Vertex_Table[i].nextarc;
				while(p!=NULL) {
					cout<<"("<<p->adjvex<<","<<p->weight<<")"<<"->";
					p=p->nextarc;
				}
				cout<<endl;
			}
		}
		int Find_Shortest(int a,int b) {
			struct Edge_Node* p=Vertex_Table[a].nextarc;
			//int k=0;
			while(p!=NULL) {
				if(p->adjvex==b) {
					return p->weight;
				}
				p=p->nextarc;
			}
			return INT_MAX;
		}
		void Dijkstra_Algorithm() {
			//cout<<"Dijkstra_Algorithm"<<endl;
			DA S(Vertex_num);//存放已经遍历过的点的集合
			S.Add(0);
//			for(int i=0;i<Vertex_num;i++)
//			{
//				Add_Vertex(i,0);
//			}
			for(int i=0; i<Vertex_num; i++) {
				if(S.JudjeIsWholeG())
					return ;
				if(Vertex_Table[i].nextarc==NULL)
					continue;
				struct Edge_Node* p= Vertex_Table[i].nextarc;
				//int k=0;
				while(p!=NULL) {
					if(!S.Research(p->adjvex)) {
						//k=1;
						//break;
						//cout<<"开始"<<endl;
						//DA **A=new (DA*)[10000];
						DA* A[10000];
						for(int h=0; h<10000; h++) {
							A[h]=NULL;
						}
						//DA*数组初始化完成
						//int nnnn=0;
						int sum=INT_MAX;
						for(int h=0; h<S.Get_Num(); h++) {
							int path_length;
							if(Find_Shortest(S.Index(h),p->adjvex)==INT_MAX)
							continue; 
							path_length=Conclusion[S.Index(h)].path_length+Find_Shortest(S.Index(h),p->adjvex);
							if(path_length<sum) {
								sum=path_length;
							}
						}
						int mm=0;
						for(int h=0; h<S.Get_Num(); h++) {
							//int mm=0;
							int path_length;
							if(Find_Shortest(S.Index(h),p->adjvex)==INT_MAX)
							continue;
							path_length=Conclusion[S.Index(h)].path_length+Find_Shortest(S.Index(h),p->adjvex);
							if(path_length==sum) {
								//cout<<"mupli_Path_Length"<<endl;
								A[mm]=new DA(this->Vertex_num);
								struct Edge_Node* pp=Conclusion[S.Index(h)].nextarc;
								while(pp!=NULL) {
									A[mm]->Add(pp->adjvex);
									pp=pp->nextarc;
								}
								A[mm]->Add(p->adjvex);
								mm++;
							}
						}
						int aaa=INT_MAX;
						for(int h=0; h<10000; h++) {
							if(A[h]==NULL)
								continue;
							if(A[h]->Get_Num()<aaa)
								aaa=A[h]->Get_Num();
						}
						for(int h=0; h<10000; h++) {
							if(A[h]==NULL)
								continue;
							if(aaa!=A[h]->Get_Num()) {
								A[h]=NULL;
							}
						}
						int bbb=0;
						for(int h=0; h<10000; h++) {
							if(A[h]!=NULL)
								bbb++;
						}
						if(bbb==1) {
							int hh;
							for(hh=0; hh<10000; hh++) {
								if(A[hh]!=NULL)
									break;
							}
							//cout<<"Text"<<endl;
//							for(int g=0; g<aaa; g++) {
//								cout<<A[hh]->Index(g)<<"->";
//							}
//							cout<<endl;
							//Add_Vertex(p->adjvex,0);
							for(int g=0; g<aaa; g++) {
								Add_Vertex(p->adjvex,A[hh]->Index(g));
							}
							Conclusion[p->adjvex].path_length=sum;
							S.Add(p->adjvex);
						} else {
							DA *fff[bbb];
							int ss=0;
							for(int hh=0; hh<10000; hh++) {
								if(A[hh]!=NULL) {
									fff[ss]=A[hh];
									ss++;
								}
							}
							DA *ddd=fff[0];
							for(int hh=1; hh<ss; hh++) {
								if(ddd->Compare(*fff[hh])==2)
									ddd=fff[hh];
							}
							//Add_Vertex(p->adjvex,0);
							for(int g=0; g<aaa; g++) {
								Add_Vertex(p->adjvex,ddd->Index(g));
							}
							Conclusion[p->adjvex].path_length=sum;
							S.Add(p->adjvex);
						}
					}
					p=p->nextarc;
				}
			}
		}
		void Print_Path() {
			//cout<<"Print_Path"<<endl;
			for(int i=1; i<Vertex_num; i++) {
				//cout<<"Print_Path_For"<<endl;
				if(!FS->Research(i))
				continue;
				struct Edge_Node*p=Conclusion[i].nextarc;
				if(p==NULL)
				continue ;
				cout<<0<<"->";
				if(p->nextarc==NULL)
				{
					cout<<(p->adjvex)<<endl;
					continue ;
				}
				while(p->nextarc!=NULL) {
					cout<<(p->adjvex)<<"->";
					p=p->nextarc;
				}
				cout<<(p->adjvex)<<endl;
			}
		}
		void DFS(int k)
		{
			FS->Add(k);
			struct Edge_Node*p=Vertex_Table[k].nextarc;
			while(p!=NULL)
			{
				if(!FS->Research(p->adjvex))
				DFS(p->adjvex);
				p=p->nextarc;
			}
		}
};
int main() {
	int n,e;//n顶点数，e边数
	cin>>n;//n<=15000
	cin>>e;//e<=1000
	Dijkstra Adjacency_Table(n);
	for(int i=0; i<e; i++) {
		int a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Adjacency_Table.Add_Edge(a,b,c);
	}
	Adjacency_Table.DFS(0);
	//Adjacency_Table.Adjacency_List_Print();
	Adjacency_Table.Dijkstra_Algorithm();
	Adjacency_Table.Print_Path();
}
