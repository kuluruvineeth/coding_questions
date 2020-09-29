#include<bits/stdc++.h>
using namespace std;

//repalcing space by %20 in given string;

void URLify(char *str,int len)
{
	int noofspaces=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			noofspaces++;
		}
	}

	int extendedlength= len + 2 * noofspaces;  //here 2*noofspaces because _(space) is already included in original string 
	
	int j=extendedlength-1;
	for(int i=len-1;i>=0;i--)     //len-1 because last character is null by default
	{
		if(str[i]==' ')
		{
			str[j--]='0';    //tracing from backwards
			str[j--]='2';
			str[j--]='%';
		}

		else
		{
			str[j--]=str[i];
		}
	}

}


//main function

int main()
{
	char str[]="mr john smith ";
	cout<<"Actual string : "<<str<<endl;
	URLify(str,13);
	cout<<"Replaced string : "<<str<<endl;
	return 0;
}		
