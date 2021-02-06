#include<bits/stdc++.h>
using namespace std;

//There is just one approach to solve this problem,it is called string comparison sorting algorithm.
//TIME : O(N*LOGN) , SPACE : O(1)

bool appended_string_comparison(string a,string b)
{
	string ab = a + b;
	string ba = b + a;
	return ab > ba;
}

void largest_number_from_array(vector<string> &v,int n)
{
	sort(v.begin(),v.end(),appended_string_comparison);
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
	cout<<endl;
}

int main()
{
	vector<string> v={"10","20","89","7","9"};
	vector<string> v1={"1","2","3","4"};
	int n=v.size();
	int n1=v1.size();
	largest_number_from_array(v,n);
	largest_number_from_array(v1,n1);
	return 0;
}

