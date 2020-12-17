#include<bits/stdc++.h>
using namespace std;

bool ispartition(int arr[],int n)
{
	
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}

	if(sum%2!=0)
	{
		return false;
	}

	bool t[n+1][sum/2+1];

	for(int i=0;i<n+1;i++)
	{
		t[i][0]=true;
	}

	for(int j=1;j<sum/2+1;j++)
	{
		t[0][j]=false;
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum/2+1;j++)
		{
			if(j<arr[i-1])
			{
				t[i][j]=t[i-1][j];
			}
			else if(j>=arr[i-1])
			{
				t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
			}
		}
	}

	return t[n][sum/2];
}

int main()
{
	int arr[]={1,2,3,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	if(ispartition(arr,n)==true)
	{
		cout<<"equal partition exists with given sum"<<endl;
	}
	else
	{
		cout<<"equal partition does not exists with given sum"<<endl;
	}
	return 0;
}
	
				
		
