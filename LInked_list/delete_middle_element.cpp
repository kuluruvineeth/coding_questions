#include<iostream>
using namespace std;

//There are two ways to solve this problem.
//1.finding the length of linked list and then dividing its length by 2 which gives us middle node position and then we can delete
//2.using two pointers fast and slow ,fast shifting by 2 and slow by 1,by the fast reaches the end of linked list slow will reach middle node

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

//method 1.Time complexity O(n)
no *delete_middle_length(no *head)
{
	if(head==NULL && head->next==NULL)
	{
		return NULL;
	}

	no *lhead=head;
	int count=0;
	while(lhead!=NULL)
	{
		lhead=lhead->next;
		count++;
	}

	int mid=count/2;

	while(mid>1)
	{
		head=head->next;
		mid--;
	}

	head->next=head->next->next;
	return lhead;
}

//method 2.Time complexity O(n)
no *delete_middle_pointer(no *head)
{
	no *fast,*slow,*prev;
	fast=head;
	slow=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		prev=slow;
		slow=slow->next;
	}

	prev->next=slow->next;
	delete slow;
	return head;
}

int main()
{
	int n;
	cin>>n;
	int data;
	cin>>data;
	no *head=new node(data);
	no *tail=head;
	for(int i=1;i<n;i++)
	{
		cin>>data;
		tail->next=new node(data);
		tail=tail->next;
	}

	cout<<"1.length method : "<<endl;
	no *curr=delete_middle_length(head);
	printlinkedlist(head);

	cout<<"2.pointer method : "<<endl;
	no *ptr=delete_middle_pointer(head);
	printlinkedlist(head);
	return 0;
}
	 
		


