#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
  unordered_map<char, int> uno;

  int maxi = 0;

  int j = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (uno.find(s[i]) == uno.end())
    {
      uno[s[i]] = i;
      maxi = max(i - j + 1, maxi);
    }
    else
    {
      maxi = max(i - j, maxi);
      j = j + uno[s[i]] + 1;
      for (auto itr : uno)
      {
        if (itr.second < uno[s[i]])
        {
          uno.erase(itr.first);
        }
      }
      uno[s[i]] = i;
    }
  }

  for (auto itr : uno)
  {
    cout << itr.first << " " << itr.second << endl;
  }

  return maxi;
}

int main()
{

  string s;
  cin >> s;

  cout << lengthOfLongestSubstring(s);
};
