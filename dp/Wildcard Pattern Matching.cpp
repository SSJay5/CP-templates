#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define Max 1e6
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define v vector
#define mii map<ll, ll>
#define umap unordered_map
#define pq priority_queue<ll>
#define pqm priority_queue<ll, vi, greater<ll>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  ll x;      \
  cin >> x;  \
  while (x--)
#define all(x) x.begin(), x.end()
#define sp ' '
#define pi 3.14159265359
#define intmax INT32_MAX
#define intmin INT32_MIN
#define conti continue
#define null NULL
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll d8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
ll d4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/* ordered set:
tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
member functions :
1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/
template <typename T, typename T1>
T amax(T &a, T1 b)
{
  if (b > a)
    a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
  if (b < a)
    a = b;
  return a;
}

void IO()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
}
void fastIO()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
v<v<ll>> dp(201, v<ll>(201, -1));
bool fun(string s1, string s2)
{
  if (s1.length() == 0 || s2.length() == 0)
  {
    // cout << s1 << sp << s2 << endl;
    return s1.length() == s2.length();
  }
  if (dp[s1.length()][s2.length()] != -1)
  {
    return dp[s1.length()][s2.length()];
  }
  if (s1[0] == s2[0] || (s2[0] == '?' || s2[0] == '*'))
  {
    bool ans1 = s1[0] == s2[0] ? fun(s1.substr(1), s2.substr(1)) : false;
    bool ans2 = s2[0] == '?' ? fun(s1.substr(1), s2.substr(1)) : false;
    bool ans3 = s2[0] == '*' ? fun(s1.substr(1), s2) || fun(s1.substr(1), s2.substr(1)) || fun(s1, s2.substr(1)) : false;
    dp[s1.length()][s2.length()] = ans1 | ans2 | ans3;
    return ans1 | ans2 | ans3;
  }
  dp[s1.length()][s2.length()] = false;
  return false;
}
int main()
{
  fastIO();
  string s1, s2;
  cin >> s1 >> s2;
  // if (fun(s1, s2))
  // {
  //   cout << "true" << endl;
  // }
  // else
  // {
  //   cout << "false" << endl;
  // }
  ll n = s1.length();
  ll m = s2.length();
  v<v<bool>> dp(n + 1, v<bool>(m + 1, false));
  dp[0][0] = true;
  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= m; j++)
    {
      if (s1[s1.length() - i] == s2[s2.length() - j] || (s2[s2.length() - j] == '*' || s2[s2.length() - j] == '?'))
      {
        if (s1[s1.length() - i] == s2[s2.length() - j])
          dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
        if (s2[s2.length() - j] == '*')
          dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
        if (s2[s2.length() - j] == '?')
          dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
      }
    }
  }
  if (dp[s1.length()][s2.length()])
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}