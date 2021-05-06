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
void dfs(v<v<ll>> &dp, deque<char> &ans, ll sx, ll sy)
{
  if (sx + 1 == dp.size() && sy + 1 == dp[0].size())
  {
    for(ll i=0;i<ans.size();i++)
    {
      cout<<ans[i];
    }
    cout << endl;
    return;
  }
  ll minw = intmax;
  if (sx + 1 < dp.size())
  {
    minw = min(minw, dp[sx + 1][sy]);
  }
  if (sy + 1 < dp[0].size())
  {
    minw = min(minw, dp[sx][sy + 1]);
  }
  if (sx + 1 < dp.size() && dp[sx + 1][sy] == minw)
  {
    ans.pb('V');
    dfs(dp, ans, sx + 1, sy);
    ans.ppb();
  }
  if (sy + 1 < dp[0].size() && dp[sx][sy + 1] == minw)
  {
    ans.pb('H');
    dfs(dp, ans, sx, sy + 1);
    ans.ppb();
  }
}
int main()
{
  fastIO();
  ll n, m;
  cin >> n >> m;
  v<v<ll>> g(n, v<ll>(m));
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      cin >> g[i][j];
    }
  }
  v<v<ll>> dp(n, v<ll>(m, 0));
  dp[n - 1][m - 1] = g[n - 1][m - 1];

  for (ll i = n - 2; i >= 0; i--)
    dp[i][m - 1] += g[i][m - 1] + dp[i + 1][m - 1];
  for (ll i = m - 2; i >= 0; i--)
    dp[n - 1][i] += g[n - 1][i] + dp[n - 1][i + 1];

  for (ll i = n - 2; i >= 0; i--)
  {
    for (ll j = m - 2; j >= 0; j--)
    {
      dp[i][j] = g[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  cout << dp[0][0] << endl;
  deque<char> ans;
  dfs(dp, ans, 0, 0);
  return 0;
}