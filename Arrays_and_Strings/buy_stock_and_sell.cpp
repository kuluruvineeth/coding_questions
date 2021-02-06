#include<bits/stdc++.h>
using namespace std;

//ONLY ONE TRANSACTION ALLOWED
/*There are two approches to solve this problem
1.Naive approach : Use two loops and maintain maximum_profit variable
2.Optimal approach :maintain min variable storing the minimum stock price value till that point from left,and also maintain maxprofit variable to store maximum profit we can make till that point from left.

*/

//1.NAIVE APPROACH : TIME : O(N^2) , SPACE : O(1)
void best_time_to_buy_and_sell_naive(vector<int> &v,int n)
{
	int maximum_profit=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int profit=v[j]-v[i];
			if(profit > maximum_profit)
			{
				maximum_profit=profit;
			}
		}
	}
	cout<<"Maximum profit that can be made is : "<<maximum_profit<<endl;
}

//2.OPTIMAL APPROACH : TIME : O(N) , SPACE : O(1)
void best_time_to_buy_and_sell_optimal(vector<int> &v,int n)
{
	int minimum_price=v[0];
	int maximum_profit=0;
	for(int i=0;i<n;i++)
	{
		minimum_price=min(minimum_price,v[i]);
		maximum_profit=max(v[i]-minimum_price,maximum_profit);
	}
	cout<<"Maximum profit we can make is : "<<maximum_profit<<endl;
}
	


int main()
{
	vector<int> v={7,1,5,3,6,4};
	int n=v.size();
	best_time_to_buy_and_sell_naive(v,n);
	best_time_to_buy_and_sell_optimal(v,n);
	return 0;
}
