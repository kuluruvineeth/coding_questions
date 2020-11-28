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
