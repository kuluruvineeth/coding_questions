#include<bits/stdc++.h>
using namespace std;

int knapsack(int v[],int w[],int c,int n)
{
	int t[n+1][c+1];

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<c+1;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=0;
			}
		
			else if(w[i-1]<=c)
			{
				t[i][j]=max(v[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][c];
}

int main()
{
	int v[]={60,100,120};
	int w[]={10,20,30};

	int c=50;

	int n=sizeof(v)/sizeof(v[0]);

	int max_value=knapsack(v,w,c,n);
	cout<<"maximum profit is : "<<max_value<<endl;
	return 0;
}
