#include <bits/stdc++.h>
using namespace std;
#define ll int
#define v vector

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

int main()
{
  string s;
  cin>>s;
  v<ll> ans=getLps(s);

  for(ll i:ans)
  cout<<i<<' ';
  cout<<endl;
}