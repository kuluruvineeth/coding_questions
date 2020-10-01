#include<bits/stdc++.h>
using namespace std;


//function without using the concept of substring,not optimal one

bool string_rotation(string str1,string str2)
{
	if(str1.length()!=str2.length())
	{
		return false;
	}
	string startingrotation="";
	string endingrotation="";
	string fullrotation="";
	int i=0;
	for(int j=0;j<str2.length();j++)
	{
		if(str2[j]==str1[i])
		{
			startingrotation+=str2[j];
			i++;
		}

		else
		{
			endingrotation+=str2[j];
		}
	}

	fullrotation=startingrotation+endingrotation;

	if(fullrotation==str1)
	{
		return true;
	}

	else
	{
		return false;
	}
}


//using issubstring concept,optimal solution

bool issubstring(string str1,string str2)
{
	string s1=str1+str1;               //find() returns the first occurrence of substring in original string
	if(s1.find(str2)!=string::npos)    //string::npos is static member which returns big value if string is not substring of original string
	{
		return true;
	}

	else
	{
		return false;
	}
}

//main function
int main()
{
	string str1,str2;
	cout<<"Enter first string : "<<endl;
	cin>>str1;
	cout<<"Enter second string : "<<endl;
	cin>>str2;
	cout<<"issubstring method : "<<endl;
	if(issubstring(str1,str2))
	{
		cout<<str2<<" "<<"is rotation of"<<" "<<str1<<endl;
	}
	else
	{
		cout<<str2<<" "<<"is not rotation of"<<" "<<str1<<endl;
	}


	cout<<"Naive approach : "<<endl;
	if(string_rotation(str1,str2))
	{
		cout<<str2<<" "<<"is rotation of"<<" "<<str1<<endl;
	}
	else
	{
		cout<<str2<<" "<<"is not rotation of"<<" "<<str1<<endl;
	}
	return 0;
}

		
