#include<bits/stdc++.h>
using namespace std;


//Binary search : TIME = O(LOGN)  SPACE = O(1)


int binary_search(vector<int> &v,int low,int high,int element)
{
	while(low<=high)
	{	
		int mid =low + (high-low)/2;
		
		if(v[mid]==element)
		{
			return mid;
		}

		else if(v[mid]>element)
		{
			high=mid-1;
		}

		else
		{
			low=mid+1;
		}
	}
	return -1;
}


int main()
{
	vector<int> v={1,2,3,4,5};
	int n=v.size();
	int loc = binary_search(v,0,n-1,4);
	if(loc==-1)
	{
		cout<<"Element not found " <<endl;
	}
	else
	{
		cout<<"Element found at location : "<<loc<<endl;
	}
	return 0;
}
