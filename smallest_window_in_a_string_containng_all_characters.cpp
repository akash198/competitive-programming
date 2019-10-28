// C++ program to find smallest window containing
// all characters of a pattern.
#include <iostream>
using namespace std;

const int no_of_chars = 256;

// Function to find smallest window containing
// all characters of 'pat'
string findSubString(string str, string pat)
{
  int len1 = str.length();
  int len2 = pat.length();

  // check if string's length is less than pattern's
  // length. If yes then no such window can exist
  if (len1 < len2)
  {
    cout << "No such window exists";
    return "";
  }

  int hash_pat[no_of_chars] = {0};
  int hash_str[no_of_chars] = {0};

  // store occurrence ofs characters of pattern
  for (int i = 0; i < len2; i++)
    hash_pat[pat[i]]++;

  int start = 0, start_index = -1, min_len = INT_MAX;
  int count = 0; // count of characters
  for (int i = 0; i < len1; i++)
  {
    hash_str[str[i]]++;

    if (hash_pat[str[i]] != 0 and hash_str[str[i]] <= hash_pat[str[i]])
      count++;

    if (count == len2)
    {
      while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
      {
        if (hash_str[str[start]] > hash_pat[str[start]])
        {
          hash_str[str[start]]--;
        }
        start++;
      }

      int len_window = i - start + 1;
      if (min_len > len_window)
      {
        min_len = len_window;
        start_index = start;
      }
    }
  }

  return str.substr(start_index, min_len);
}

// Driver code
int main()
{
  string str = "abcddbca";
  string pat = "abcd";

  cout << "Smallest window is : \n"
       << findSubString(str, pat);
  return 0;
}
