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


void levelorder_traversal(no *root)
{
	if(root==NULL)
	{
		return;
	}

	queue<no*> q;

	q.push(root);

	while(!q.empty())
	{
		no* d1=q.front();
		cout<<d1->data<<" ";
		q.pop();

		if(d1->left!=NULL)
		{
			q.push(d1->left);
		}

		if(d1->right!=NULL)
		{
			q.push(d1->right);
		}
	}
}



int main()
{
	no *root = new node(1);
	root->left = new node(3);
	root->right = new node(2);
	root->left->left = new node(5);
	root->right->right = new node(4);

	levelorder_traversal(root);
	return 0;
}
