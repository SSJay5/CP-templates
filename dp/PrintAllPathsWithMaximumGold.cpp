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
void dfs(ll x, ll y, v<v<ll>> &dp, deque<ll> &ans, ll i)
{
	if (y + 1 == dp[0].size())
	{
		cout << i << ' ';
		for (ll i = 0; i < ans.size(); i++)
			cout << "d" << ans[i] << ' ';
		cout << endl;
		return;
	}
	ll maxw = intmin;
	if (x + 1 < dp.size())
		maxw = max(maxw, dp[x + 1][y + 1]);
	maxw = max(maxw, dp[x][y + 1]);
	if (x - 1 >= 0)
		maxw = max(maxw, dp[x - 1][y + 1]);
	if (x + 1 < dp.size() && maxw == dp[x + 1][y + 1])
	{
		ans.pb(3);
		dfs(x + 1, y + 1, dp, ans, i);
		ans.ppb();
	}
	if (maxw == dp[x][y + 1])
	{
		ans.pb(2);
		dfs(x, y + 1, dp, ans, i);
		ans.ppb();
	}
	if (x - 1 >= 0 && maxw == dp[x - 1][y + 1])
	{
		ans.pb(1);
		dfs(x - 1, y + 1, dp, ans, i);
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
	for (ll i = 0; i < n; i++)
	{
		dp[i][m - 1] = g[i][m - 1];
	}
	for (ll i = m - 2; i >= 0; i--)
	{
		for (ll j = 0; j < n; j++)
		{
			dp[j][i] = g[j][i];
			ll maxw = dp[j][i + 1];
			if (j + 1 < n)
			{
				maxw = max(maxw, dp[j + 1][i + 1]);
			}
			if (j - 1 >= 0)
			{
				maxw = max(maxw, dp[j - 1][i + 1]);
			}
			dp[j][i] += maxw;
		}
	}
	ll maxw = 0;
	ll maxi = 0;
	for (ll i = 0; i < n; i++)
	{
		maxw = max(dp[i][0], maxw);
	}
	cout << maxw << endl;
	deque<ll> ans;
	for (ll i = 0; i < n; i++)
	{
		if (dp[i][0] == maxw)
		{
			dfs(i, 0, dp, ans, i);
		}
	}
	return 0;
}