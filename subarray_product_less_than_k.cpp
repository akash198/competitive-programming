#include <bits/stdc++.h>
using namespace std;

// Important Obervation
// No of subarrays in an array = ∑i+j-1 for each term

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
  if (k <= 1)
    return 0;

  int n = nums.size(), prod = 1, count = 0;

  for (int i = 0, j = 0; i < n; i++)
  {
    prod = prod * nums.at(i);

    while (prod >= k)
    {
      prod = prod / nums.at(j);
      j++;
    }
    count += i - j + 1;
  }
  return count;
}

int main()
{
  vector<int> v = {10, 5, 2, 6};
  int k = 100;
  int n = numSubarrayProductLessThanK(v, k);
  cout << n << endl;
}

// Important Obervation
// No of subarrays in an array = ∑i+j-1 for each term
