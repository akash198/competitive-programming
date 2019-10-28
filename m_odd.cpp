// CPP program to count the Number
// of subarrays with m odd numbers
// O(N) approach
#include <bits/stdc++.h>
using namespace std;

// function that returns the count
// of subarrays with m odd numbers
int countSubarrays(int a[], int n, int m)
{
  int count = 0;
  int prefix[n] = {0};
  int odd = 0;

  // traverse in the array
  for (int i = 0; i < n; i++)
  {

    prefix[odd]++;

    // if array element is odd
    if (a[i] & 1)
      odd++;

    // when number of odd elements>=M
    if (odd >= m)
      count += prefix[odd - m];
  }

  return count;
}

// Driver Code
int main()
{
  int a[] = {3, 2, 3, 4};
  int n = sizeof(a) / sizeof(a[0]);
  int m = 1;

  cout << countSubarrays(a, n, m);

  return 0;
}
