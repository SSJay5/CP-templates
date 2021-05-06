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
void dfs(v<ll> &a, v<ll> &dp, v<ll> &ans, ll currJump, ll end)
{
  if (currJump == 0)
  {
    if (ans.back() == 0)
    {
      for (ll i = ans.size() - 1; i >= 1; i--)
      {
        cout << ans[i] << " -> ";
      }
      cout << ans[0] << " ." << endl;
    }
    return;
  }

  for (ll i = 0; i <= end; i++)
  {
    if (i == 0)
    {
      ans.pb(0);
      dfs(a, dp, ans, currJump - 1, i - 1);
      auto it = ans.end();
      --it;
      ans.erase(it);
    }
    else if (a[i] != 0 && dp[i] == currJump - 1 && end - i <= a[i])
    {
      ans.pb(i);
      dfs(a, dp, ans, currJump - 1, i);
      auto it = ans.end();
      --it;
      ans.erase(it);
    }
  }
}
int main()
{
  fastIO();
  ll n;
  cin >> n;
  v<ll> a(n);
  for (ll &i : a)
    cin >> i;
  v<ll> dp(n, intmax);
  for (ll i = 0; i < n; i++)
  {
    if (a[i] != 0)
    {
      if (dp[i] == intmax)
      {
        dp[i] = 0;
      }
      for (ll j = i + 1; j < n && j <= i + a[i]; j++)
      {
        dp[j] = min(dp[i] + 1, dp[j]);
      }
    }
  }
  v<ll> ans;
  cout << dp[n - 1] << endl;
  ans.pb(n - 1);
  dfs(a, dp, ans, dp[n - 1], n - 1);
  return 0;
}