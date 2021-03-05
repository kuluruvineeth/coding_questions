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

int height(no *root)
{
	if(root==NULL)
	{
		return 0;
	}


	int leftheight = height(root->left);
	int rightheight = height(root->right);
	if(leftheight > rightheight)
	{
		return (1 + leftheight);
	}
	else
	{
		return (1 + rightheight);
	}
}

bool isbalanced(no *root)
{
	if(root==NULL)
	{
		return true;
	}

	int leftheight = height(root->left);
	int rightheight = height(root->right);

	if(abs(leftheight - rightheight)<=1 && isbalanced(root->left) && isbalanced(root->right))
	{
		return true;
	}
	return false;
}

int main()
{
	no *root = new node(1);
	root->left = new node(2);
	root->left->left = new node(3);
	root->right = new node(4);

	if(isbalanced(root))
	{
		cout<<"Tree is balanced " <<endl;	
	}
	else
	{
		cout<<"Tree is not balanecd " <<endl;
	}
	return 0;
}



