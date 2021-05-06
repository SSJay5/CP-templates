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
v<v<bool>> dp(31, v<bool>(51, false));
bool fun(v<ll> &a, ll tar, ll i)
{
	if (tar == 0)
	{
		return true;
	}
	if (i == a.size())
	{
		return false;
	}
	if (dp[i][tar] != -1)
	{
		return dp[i][tar];
	}
	ll ans1 = fun(a, tar - a[i], i + 1);
	ll ans2 = fun(a, tar, i + 1);
	dp[i][tar] = ans1 | ans2;
	return ans1 | ans2;
}
void dfs(deque<ll> &ans, v<v<bool>> &dp, v<ll> &a, ll x, ll y)
{
	if (y == 0)
	{
		for (ll i = ans.size() - 1; i >= 0; i--)
		{
			cout << ans[i] << sp;
		}
		cout << endl;
		return;
	}
	if (x == 0)
	{
		return;
	}
	if (x - 1 >= 0 && y - a[x - 1] >= 0 && dp[x - 1][y - a[x - 1]])
	{
		ans.pb(x - 1);
		dfs(ans, dp, a, x - 1, y - a[x - 1]);
		ans.ppb();
	}
	if (x - 1 >= 0 && dp[x - 1][y])
	{
		dfs(ans, dp, a, x - 1, y);
	}
}
int main()
{
	fastIO();
	ll n, tar;
	cin >> n;
	v<ll> a(n);
	for (ll &i : a)
		cin >> i;
	cin >> tar;
	for (ll i = 0; i <= n; i++)
	{
		dp[i][0] = true;
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= tar; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]])
			{
				dp[i][j] = true;
			}
		}
	}
	if (dp[n][tar])
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	deque<ll> ans;
	dfs(ans, dp, a, n, tar);
	return 0;
}