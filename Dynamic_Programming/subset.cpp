#include<bits/stdc++.h>
using namespace std;

bool issubset(int arr[],int sum,int n)
{
	bool t[n+1][sum+1];

	for(int i=0;i<n+1;i++)
	{
		t[i][0]=true;
	}

	for(int j=1;j<sum+1;j++)
	{
		t[0][j]=false;
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
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

	return t[n][sum];
}

int main()
{
	int arr[]={2,6,9,1,5,7};
	int sum=10;
	int n=sizeof(arr)/sizeof(arr[0]);
	if(issubset(arr,sum,n)==true)
	{
		cout<<"subset exists with given sum"<<endl;
	}

	else
	{
		cout<<"no subset exists with given sum"<<endl;
	}
	return 0;
}

