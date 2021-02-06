#include<bits/stdc++.h>
using namespace std;

/*There is one approach to solve this problem 
use two variables : left=i and right=min(i+k-1,v.size()-1),here k=group of how many numbers
TIME : O(N) , SPACE : O(1)
*/

void reverse_in_groups(vector<int> &v,int k,int n)
{
	int left,right;
	for(int i=0;i<n;i=i+k)
	{
		left=i;
		right=min(i+k-1,n-1);
		while(left<=right)
		{
			swap(v[left++],v[right--]);
		}
	}
	cout<<"Array after reversing in groups : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> v={1,2,3,4,5,6};
	int n=v.size();
	int k=2;
	reverse_in_groups(v,2,n);
	return 0;
}
	
