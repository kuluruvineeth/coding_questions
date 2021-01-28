#include<bits/stdc++.h>
using namespace std;

/*There are three approaches to solve this problem in order of their efficiency
1.NAIVE APPROACH : sort the array and then do linear traversal if a[i]=a[i+1]
2.BETTER APPROACH : use count sort (maintain frequency array if any index is 2 that is dupicate number)
3.OPTIMAL APPROACH : linked list cycle method(Tortoise method)- two pointers method

*/

//1.NAIVE APPROACH : TIME=O(NLOGN),SPACE=O(1)

void duplicate_naive(vector<int> &v,int n)
{
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		if(v[i]==v[i+1])
		{
			cout<<"duplicate element is : "<<v[i]<<endl;
			break;
		}
		else
		{	
			continue;
		}
	}
}

//2.BETTER APPROACH : TIME=O(N),SPACE=O(N)

void duplicate_better(vector<int> &v,int n)
{
	int f[n+1];
	for(int i=0;i<=n;i++)
	{
		f[i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		f[v[i]]++;
	}

	for(int i=1;i<=n;i++)
	{
		if(f[i]>1)
		{
			cout<<"duplicate element is : "<<i<<endl;
			break;
		}
		else
		{
			continue;
		}
	}
}

//3.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1)

void duplicate_optimal(vector<int> &v,int n)
{
	int slow=v[0];
	int fast=v[0];

	do
	{
		slow=v[slow];
		fast=v[v[fast]];
	}while(slow!=fast);
	
	fast=v[0];
	while(slow!=fast)
	{
		slow=v[slow];
		fast=v[fast];
	}
	cout<<"duplicate element is : "<<v[slow]<<endl;
}


int main()
{
	vector<int> v={1,3,2,4,5,6,3};
	int n=v.size();
	duplicate_naive(v,n);
	duplicate_better(v,n);
	duplicate_optimal(v,n);
}

