Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

#include <bits/stdc++.h>
using namespace std;

//code to implement pascal triangle

void pascal(int n)
{
  int v[n][n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (i == j || j == 0)
      {
        v[i][j] = 1;
      }
      else
      {
        v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
      }
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n = 5;
  pascal(5);
  return 0;
}
