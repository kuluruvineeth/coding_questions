#include<bits/stdc++.h>
using namespace std;


//There are two ways to solve this problem.
//1.sorting - sorting both strings and then comparing each other.It takes O(nlogn) time
//2.hashing - using array to store 1 or 0.It takes O(n) time


bool sorting_permutation(string str1,string str2)
{
	int n1=str1.length();
	int n2=str2.length();

	if(n1!=n2)
	{
		return false;
	}

	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());

	for(int i=0;i<n1;i++)
	{
		if(str1[i]!=str2[i])
		{
			return false;
		}
	}

	return true;
}


bool hashing_permutation(const string &str1,const string &str2)
{
	if(str1.length()!=str2.length())
	{
		return false;
	}

	int count[128]={0};

	for(int i=0;i<str1.length();i++)
	{
		int val=str1[i];
		count[val]++;
	}

	for(int i=0;i<str2.length();i++)
	{
		int val=str2[i];
		count[val]--;

		if(count[val]<0)
		{
			return false;
		}
	}
	return true;
}


//main function

int main()
{
	cout<<"1.sorting"<<endl;

	string str1="abc";
	string str2="bac";

	if(sorting_permutation(str1,str2))
	{
		cout<<str1<<" "<<"and"<<" "<<str2<<" are permutation of each other"<<endl;
	}
	else
	{
		cout<<str1 <<" "<<"and"<<" "<<str2<<" are not permutation of each other"<<endl;
	}

	cout<<"2.hashing"<<endl;

	string s1="vineeth";
	string s2="theevib";

	if(hashing_permutation(s1,s2))
	{
		cout<<s1<<" "<<"and"<<" "<<s2<<" are permutation of each other"<<endl;
	}

	else
	{
		cout<<s1<<" "<<"and"<<" "<<s2<<" are not permutation of each other"<<endl;
	}

	return 0;
}
		

	

		
		
