#include<bits/stdc++.h>
using namespace std;

/*There are three appraoches to solve this problem in order of their efficiency
1.NAIVE APPROACH : count sort techinque(maintaining the frequency array)
2.BETTER APPROACH : (sum of first n natural numbers - sum of the array) gives missing number
3.OPTIMAL APPROACH : XOR method(Xor between first n numbers and given array)

*/

//1.NAIVE APPROACH : TIME=O(N),SPACE=O(N)

void missing_naive(vector<int> &v,int n)
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
		if(f[i]==0)
		{
			cout<<"missing number is : "<<i<<endl;
			break;
		}
		else
		{
			continue;
		}
	}
}

//2.BETTER APPRAOCH : TIME=O(N),SPACE=O(1),Overflow problem can occur

void missing_better(vector<int> &v,int n)
{
	int sum=(n+1)*(n+2)/2;
	for(int i=0;i<n;i++)
	{
		sum-=v[i];
	}
	cout<<"missing number is : "<<sum<<endl;
}

//3.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1),No overflow problem
void missing_optimal(vector<int> &v,int n)
{
	int x1=v[0];
	int x2=1;

	for(int i=1;i<n;i++)
	{
		x1=x1 ^ v[i];
	}
	for(int i=2;i<=n+1;i++)
	{
		x2=x2 ^ i;
	}
	cout<<"missing number is : "<<(x1 ^ x2)<<endl;
}


int main()
{
	vector<int> v{1,2,4,5,3,6,8};
	int n=v.size();
	missing_naive(v,n);
	missing_better(v,n);
	missing_optimal(v,n);
}
	
