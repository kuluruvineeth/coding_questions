#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;

	node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
}no;


void printleftview(bool *levels,no *root,int currlevel)
{
	if(root==NULL)
	{
		return;
	}

	if(levels[currlevel]==false)
	{
		levels[currlevel]=true;
		cout<<root->data<<" ";
	}

	printleftview(levels,root->left,currlevel+1);
	printleftview(levels,root->right,currlevel+1);
}

void leftview(no *root)
{
	int max_level = 100;
	bool levels[202]={false};
	printleftview(levels,root,0);
}

int main()
{
	no *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->right = new node(4);
	root->left->left = new node(5);
	cout<<"left view of tree : "<<endl;
	leftview(root);
	return 0;
}
