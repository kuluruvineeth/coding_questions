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

bool isBST(no *root,int min,int max)
{
	if(root==NULL)
	{
		return true;
	}

	if(root->data<=min || root->data>max)
	{
		return false;
	}

	if(!isBST(root->left,min,root->data) || !isBST(root->right,root->data,max))
	{
		return false;
	}

	return true;
}

int main()
{
	no *root = new node(3);
	root->left = new  node(1);

	if(isBST(root,INT_MIN,INT_MAX))
	{
		cout<<"It is BST"<<endl;	
	}

	else
	{
		cout<<"Tree is not BST"<<endl;
	}
	return 0;
}

	
