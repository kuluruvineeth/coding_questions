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
		head = head->next;
	}
	cout<<endl;
}


//APPROACH 1 : counting 0s,1s and 2s
void sort_counting(no *head)
{
	int count0=0,count1=0,count2=0;
	for(no *temp = head;temp!=NULL;temp=temp->next)
	{
		switch(temp->data)
		{
			case 0 : count0++;
				 break;

			case 1 : count1++;
				 break;
	
			case 2 : count2++;
				 break;
		}
	}

		for(int i=0;i<count0;i++)
		{
			head->data = 0;
			head = head->next;
		}

		for(int i=0;i<count1;i++)
		{
			head->data=1;
			head=head->next;
		}

		for(int i=0;i<count2;i++)
		{
			head->data=2;
			head=head->next;
		}
}

//APPROACH 2 : 

void sort_1traversal(no *head)
{
	if(head == NULL || head->next==NULL)
	{
		return ;
	}

	no *last = head;
	int nodes = 1;
	while(last->next!=NULL)
	{
		last=last->next;
		nodes++;
	}
	no *tail=last,*current=head,*prev=head;
	
	for(int i=0;i<nodes;i++)
	{
		no *temp = current;
		current = current->next;

		if(temp->data==0)
		{
			if(prev!=temp)
			{
				temp->next=head;
				head=temp;
				prev->next=current;
			}
		}

		else if(temp->data==2)
		{
			tail->next=temp;
			temp->next=NULL;
			tail=temp;
			if(prev==temp)
			{
				head=current=prev;
			}
			else
			{
				prev->next=current;
			}
		}

		else
		{
			if(prev!=temp)
			{
				prev=prev->next;
			}
		}
	}
}
		
int main()
{
	no *head = new node(2);
	head->next = new node(1);
	head->next->next = new node(0);
	sort_counting(head);
	//sort_1traversal(head);
	printlinkedlist(head);
	return 0;
}
	
