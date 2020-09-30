#include<bits/stdc++.h>
using namespace std;


//aabbbcccc to a2b3c4 this way we have to compress string
string compression(string str)
{
	if(str.length()<2) //base case
	{
		return str;
	}

	string deststr="";

	int count=1;

	for(int i=1;i<str.length();i++)
	{
		if(str[i-1]==str[i])
		{
			count++;
		}

		else
		{
			deststr+=str[i-1];
			deststr+=to_string(count);
			count=1;
		}

		if(deststr.length()>=str.length())
		{
			return str;
		}
	}

	deststr+=str[str.length()-1];
	deststr+=to_string(count);
	if(deststr.length()>=str.length())
	{
		return str;
	}
	return deststr;
}

//main function
int main()
{
	string str;
	cout<<"enter string : "<<endl;
	cin>>str;
	string dstr=compression(str);
	if(str.compare(dstr))
	{
		cout<<str<<" "<<"can be compressed to"<<" "<<dstr<<endl;
	}

	else
	{
		cout<<str<<" "<<"can not be compressed"<<endl;
	}
}
	


	
		

	
