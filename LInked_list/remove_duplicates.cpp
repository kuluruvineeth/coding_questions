#include<bits/stdc++.h>
using namespace std;


//There are three ways to solve this problem
//1.naive approach
//2.sorting
//3.hashing

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
	no *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


//1.naive approach is just normal way of finding duplicates like fixing one node and comparing that node to all other nodes present in linked list.Time complexity is O(n^2)

void removeduplicates_naive(no *head)
{
	no *temp,*curr,*dup;
	curr=head;
	//picking elements one by one
	while(curr!=NULL && curr->next!=NULL)
	{
		temp=curr;
		
		//comparing picked element with rest of the elements
		while(temp->next!=NULL)
		{
			//if duplicate is found,delete it
			if(curr->data==temp->next->data)
			{
				dup=temp->next;
				temp->next=temp->next->next;
				delete(dup);
			}

			else
			{
				temp=temp->next;
			}
		}
		curr=curr->next;
	}
}


//3.Hashing : using unordered set(stores only unique numbers) to store key and values.Time complexity is O(n)

void removeduplicates_hashing(no *head)
{
	no *previous=NULL;
	no *current=head;
	unordered_set<int> s;
	while(current!=NULL)
	{
		//if current is already found,just ignore this
		if(s.find(current->data)!=s.end())
		{
			previous->next=current->next;
		}
	
		else
		{
			s.insert(current->data);
			previous=current;
		}

		current=previous->next;
	}
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

	cout<<"1.Naive approach : "<<endl;
	removeduplicates_naive(head);
	printlinkedlist(head);

	cout<<"2.Hashing : "<<endl;
	removeduplicates_hashing(head);
	printlinkedlist(head);

	return 0;
}
	
	
	
