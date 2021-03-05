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

void preorder_traversal(no* root)
{
	if(root == NULL)
	{
		return;
	}

	cout<<root->data<<" ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

int countleaves(no* root)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL)
	{
		return 1;
	}

	else
	{
		return countleaves(root->left) + countleaves(root->right);
	}
}

int main()
{
	no *root=new node(1);
	root->left = new node(2);
	root->right = new node(3);
	preorder_traversal(root);
	cout<<"leaves in tree is : "<<countleaves(root)<<endl;
	return 0;
}
