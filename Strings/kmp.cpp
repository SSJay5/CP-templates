#include <bits/stdc++.h>
using namespace std;
#define ll int
#define v vector
#define pb push_back

v<ll> getLps(string s)
{
  v<ll> lps(s.length(), 0);
  ll i = 1;
  ll j = 0;

  while (i < s.length())
  {
    if (s[i] == s[j])
    {
      lps[i] = j + 1;
      i++;
      j++;
    }
    else
    {
      if (j == 0)
      {
        lps[i] = 0;
        i++;
      }
      else
      {
        j = lps[j - 1];
      }
    }
  }
  return lps;
}

v<ll> kmp(string text, string pattern)
{
  v<ll> lps = getLps(pattern);
  ll i = 0;
  ll j = 0;
  v<ll> ans;

  while (i < text.length())
  {
    if (j == pattern.length())
    {
      ans.pb(i - 1);
      j = 0;
    }

    if (text[i] == pattern[j])
    {
      i++, j++;
    }
    else
    {
      if (j == 0)
      {
        i++;
      }
      else
      {
        j = lps[j - 1];
      }
    }
  }

  return ans;
}

int main()
{
  string text, pattern;
  cin >> text >> pattern;
  v<ll> ans = kmp(text, pattern);

  for(ll i:ans)
  {
    cout<<i<<' ';
  }
  cout<<endl;
}