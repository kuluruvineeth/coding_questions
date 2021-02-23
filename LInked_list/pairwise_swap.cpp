#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
}no;

void printlinkedlist(no *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}


void pairwise_swap(no *head)
{
	no *temp = head;
	while(temp!=NULL && temp->next!=NULL)
	{
		swap(temp->data,temp->next->data);
		temp=temp->next->next;
	}
}


int main()
{
	no *head = new node(10);
	head->next = new node(20);
	head->next->next = new node(30);
	head->next->next->next = new node(40);
	head->next->next->next->next = new node(50);
	pairwise_swap(head);
	printlinkedlist(head);
	return 0;
}
