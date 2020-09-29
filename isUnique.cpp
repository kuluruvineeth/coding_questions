#include<bits/stdc++.h>
using namespace std;


//There are four ways to solve this problem.Methods are listed in order of their efficiency
//1.Brute force - using two loops,it takes O(n^2) time


bool bruteforce_isUnique(const string &str)
{
	for(int i=0;i<str.length()-1;i++)
	{
		for(int j=i+1;j<str.length();j++)
		{
			if(str[i]==str[j])
			{
				return false;
			}
		}
	}

	return true;
}


//2.sorting - sorting characters of string based on its ascii values.It takes O(nlogn) time


/*bool sorting_isUnique(const string &str)
{
	sort(str.begin(),str.end());

	for(int i=0;i<str.length()-1;i++)
	{
		if(str[i]==str[i+1])
		{
			return false;
			break;
		}
	}
	return true;
}*/

//3.Hashing - using boolean array of 128 characters which sets particular index 1 if that character is found.It takes O(n) time 

bool hashing_isUnique(const string &str)
{
	if(str.length()>128)
	{
		return false;
	}

	vector<bool> char_set(128);

	for(int i=0;i<str.length();i++)
	{
		int val=str[i];
		if(char_set[val])
		{
			return false;
		}
		char_set[val]=true;
	}
	return true;
}


//4.Using extra data structure(BIT_VECTOR) it stores each boolean value in bit space only so it takes less space.It takes O(n) time

bool extra_datastructure_isUnique(const string &str)
{
	bitset<128> bits(0);
	
	for(int i=0;i<str.length();i++)
	{
		int val=str[i];
		if(bits.test(val)>0)
		{
			return false;
		}
		bits.set(val);
	}
	return true;
}


//main function

int main()
{
	vector<string> vec;
	vec.push_back("abcde");
	vec.push_back("abcdea");
	vec.push_back("vineeth");
	vec.push_back("rythm");
	vec.push_back("sudhu");

	cout<<"1.using hashing"<<endl;
	for(auto it:vec)
	{
		cout << it <<string(": ") << boolalpha<< hashing_isUnique(it) <<endl;
	}
	cout<<endl;

	cout<<"2.using bit_vector"<<endl;
	for(auto it:vec)
	{
		cout << it <<string(": ") << boolalpha<< extra_datastructure_isUnique(it) <<endl;
	}
	cout<<endl;

	/*cout<<"3.using sorting"<<endl;
	for(auto it:vec)
	{
		cout << it <<string(": ") << boolalpha<< sorting_isUnique(it) <<endl;
	}
	cout<<endl;*/

	cout<<"4.using brute force"<<endl;
	for(auto it:vec)
	{
		cout << it <<string(": ") << boolalpha<< bruteforce_isUnique(it) <<endl;
	}
	cout<<endl;
	

	return 0;
}





