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

void preorder_traversal(no *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

bool ismirror(no *root1,no* root2)
{
	if(root1==NULL && root2==NULL)
	{
		return true;	
	}

	if(root1!=NULL && root2!=NULL)
	{
		return (root1->data==root2->data && ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left));
	}
	return false;
}

bool issymmetric(no *root)
{
	return ismirror(root,root);
}

int main()
{
	no *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);

	if(issymmetric(root))
	{
		cout<<"tree is mirror of itself"<<endl;
	}
	else
	{
		cout<<"tree is not mirror of itself"<<endl;
	}
	return 0;
}
