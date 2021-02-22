#include<iostream>
#include<queue>
using namespace std;
struct Binary_tree_node {
	int data;
	struct Binary_tree_node*left;
	struct Binary_tree_node*right;
};
struct Tree{
	int data;
	struct Tree* LeftChild;
	struct Tree* Brother;
};
struct Binary_tree_node* Creat_Tree() {

	int i;
	cin>>i;
	if(i==0)
		return NULL;
	struct Binary_tree_node* t=new Binary_tree_node;
	t->data=i;
	t->left=Creat_Tree();
	t->right=Creat_Tree();
	return t;
}
void Per_order(struct Binary_tree_node* t) {

	if(t==NULL) {
		return ;
	}
	cout<<t->data<<' ';
	Per_order(t->left);
	Per_order(t->right);
}
//--------------------------------------------------------------------------------------------
///二叉树到普通树转变函数//////////////////
struct Tree* change(struct Binary_tree_node *t)
{
    ///生成普通树树根///////////////////////
    struct Tree* tt = new Tree;
    tt->Brother = NULL;
    tt->LeftChild = NULL;
    tt->data = t->data;
 
    //二叉树和普通树的树根分别人队/////////////////
    queue<struct Binary_tree_node*> que;
    queue<struct Tree*> quee;
    que.push(t);
    quee.push(tt);
 
 
    while (!que.empty())
    {
        //先检查有没有左孩子,有左孩子就先处理左孩子////////////////////////
        if (que.front()->left) {
            que.push(que.front()->left);
            struct Tree* leftchild= new Tree;
            leftchild->Brother = NULL;
            leftchild->LeftChild = NULL;
            leftchild->data = que.front()->left->data;
            quee.front()->LeftChild = leftchild;
 
        //再检查有没有右孩子，有右孩子则处理右孩子//////////////////////////////
            if (que.front()->right) {
                que.push(que.front()->right);
                struct Tree* brother = new Tree;
                brother->data = que.front()->right->data;
                brother->Brother = NULL;
                brother->LeftChild = NULL;
                leftchild->Brother = brother;
                quee.push(leftchild);
                quee.push(brother);
            }
        }
        //没有左孩子有右孩子的话把父亲的LeftChild指针赋值为右孩子的地址///////////////////////
        else
        {
            if (que.front()->right) {
                que.push(que.front()->right);
                struct Tree* brother = new Tree;
                brother->data = que.front()->right->data;
                brother->Brother = NULL;
                brother->LeftChild = NULL;
                quee.front()->LeftChild = brother;
                quee.push(brother);
            }
        }
        //循环结束弹出对应的树节点/////////////////////////////////
        que.pop();
        quee.pop();
    }
    return tt;
}
void print(struct Tree* T)              
{
    struct Tree* left, right;
    queue<struct Tree*> que;
    que.push(T);
    while (!que.empty())
    {
        cout << que.front()->data<< '\t';
        left = que.front()->LeftChild;
        que.pop();
        if (left != NULL)
        {
            right = left->Brother;
            que.push(left);
            if (right != NULL)
            {
                que.push(right);
            }
 
        }
    }
    cout << endl;
}
//-------------------------------------------------------------------------------------------
int main () {
	struct Binary_tree_node* root;
	root=Creat_Tree();
	Per_order(root);
	print(change(root));
}
