#include<bits/stdc++.h>
using namespace std;

/*Here the approach i am following is two pointer method:
 1st pointer for keeping count of words
 2nd pointer for keeping count of letters in particular words

 TIME = O(N) , SPACE = O(N)
*/

string reverse_words(string &s1)
{
	string result;
	int n=s1.length();
	int i=0;
	int j;
	while(i<n)
	{
		while(i<n && s1[i]=='.')
		{
			i++;
		}
		if(i>n)
		{
			break;
		}

		j=i+1;
		while(j<n && s1[j]!='.')
		{
			j++;
		}
		string sub=s1.substr(i,j-i);
		if(result.length()==0)
		{
			result=sub;
		}
		else
		{
			result = sub + " " + result;
		}
		i=j+1;
	}
	return result;
}

int main()
{
	string s1="i.love.you";
	cout<<reverse_words(s1)<<endl;
	return 0;
}


