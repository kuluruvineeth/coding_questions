/*Given an array of integers, every element appears twice except for one. Find that single one.
Example : [1,2,4,4,2]
Output : 1 */


#include <bits/stdc++.h>
using namespace std;

int single(vector<int> &v)
{
  if (v.size() == 0)
  {
    return 0;
  }
  int first = v[0];
  for (int i = 1; i < v.size(); i++)
  {
    first = first ^ v[i];
  }
  return first;
}

int main()
{
  vector<int> v(5);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(3);
  v.push_back(1);
  int alone = single(v);
  cout << "single integer in array is : " << alone << endl;
  return 0;
}
