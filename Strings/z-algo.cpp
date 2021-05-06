#include <bits/stdc++.h>
using namespace std;
#define ll int
#define v vector

v<ll> buildZ(string s)
{
  ll n = s.length();
  v<ll> Z(n, 0);

  ll l = 0;
  ll r = 0;

  for (ll i = 1; i < n; i++)
  {
    if (i > r)
    {
      l = i;
      r = i;
      while (r < n && s[r - l] == s[r])
      {
        r++;
      }
      Z[i] = r - l;
      r--;
    }
    else
    {
      ll k = i - l;
      if (Z[k] + i < r)
      {
        Z[i] = Z[k];
      }
      else
      {
        l = i;
        while (r < n && s[r - l] == s[r])
        {
          r++;
        }
        Z[i] = r - l;
        r--;
      }
    }
  }
  return Z;
}
int main()
{
  string text, pattern;
  cin >> pattern;
  v<ll> ans = buildZ(pattern);
  for (ll i : ans)
    cout << i << ' ';
  cout << endl;
}
