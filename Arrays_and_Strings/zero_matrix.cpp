#include<bits/stdc++.h>
using namespace std;



//to make respective rows all entries as 0.n denotes number of columns
void nullifyrow(int **matrix,int row,int n)
{
	for(int i=0;i<n;i++)
	{
		matrix[row][i]=0;
	}
}

//to make respective columns all entries as 0.m denotes number of rows
void nullifycolumn(int **matrix,int col,int m)
{
	for(int i=0;i<m;i++)
	{
		matrix[i][col]=0;
	}
}

void nullifymatrix(int **matrix,int m,int n)
{
	//checking first row entries for 0
	bool firstrow=0;
	for(int i=0;i<n;i++)
	{
		if(matrix[0][i]==0)
		{
			firstrow=true;
			break;
		}
	}

	for(int i=1;i<m;i++)
	{
		bool nullifytherow=false;
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==0)
			{
				matrix[0][j]=0;
				nullifytherow=true;
			}
		}

		if(nullifytherow)
		{
			nullifyrow(matrix,i,n);
		}
	}
	//making respective columns 0 with respect to rows
	for(int i=0;i<n;i++)
	{
		if(matrix[0][i]==0)
		{
			nullifycolumn(matrix,i,m);
		}
	}


	//if 0 entry is found in first row we make all entries as 0
	if(firstrow)
	{
		nullifyrow(matrix,0,n);
	}

	


}

void printmatrix(int **matrix,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int main()
{
	int m,n;
	cout<<"Enter no of rows : "<<endl;
	cin>>m;
	cout<<"Enter no of columns : "<<endl;
	cin>>n;

	int **matrix=new int *[m];
	for(int i=0;i<m;i++)
	{
		matrix[i]=new int [n];
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}

	cout<<"original matrix : "<<endl;
	printmatrix(matrix,m,n);
	nullifymatrix(matrix,m,n);
	cout<<"After nullifying the matrix : "<<endl;
	printmatrix(matrix,m,n);
	return 0;
}
		
