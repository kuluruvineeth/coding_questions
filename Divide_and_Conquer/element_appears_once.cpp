#include<bits/stdc++.h>
using namespace std;


/*There are two approaches that we can solve this problem:
1. XOR method: Time = O(N)
2. Divide and conquer : Time = O(LOGN)

All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …). And all elements after the required elements have the first occurrence at odd index and next occurrence at even index. 

*/


void divide_and_conquer(vector<int> &v,int low,int high)
{
	if(low > high)
	{
		return ;
	}

	if(low == high)
	{
		cout<<"Non repeated element is  : "<<v[low]<<endl;
		return;
	}

	int mid = low + (high-low)/2;
	
	if(mid%2==0)
	{
		if(v[mid]==v[mid+1])
		{
			divide_and_conquer(v,mid+2,high);
		}
		else
		{
			divide_and_conquer(v,low,mid);
		}
	}

	else
	{
		if(v[mid]==v[mid-1])
		{
			divide_and_conquer(v,mid+1,high);
		}
		else
		{
			divide_and_conquer(v,low,mid);
		}
	}
}

int main()
{
	vector<int> v={1,1,2,4,4,5,5,6,6};
	int n=v.size();
	divide_and_conquer(v,0,n-1);
	return 0;
}




