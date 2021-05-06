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
ll fun(v<ll> &value, v<ll> &weight, ll tar, ll i)
{
	if (tar == 0)
	{
		return 0;
	}
	if (i == -1 || tar < 0)
	{
		return 0;
	}
	ll ans1 = intmin;
	if (tar - weight[i] >= 0)
		ans1 = fun(value, weight, tar - weight[i], i - 1) + value[i];
	ll ans2 = fun(value, weight, tar, i - 1);

	return max(ans2, ans1);
}
void dfs(ll sx, ll sy, v<ll> &w, v<ll> &val, v<v<ll>> &dp, v<ll> &ans)
{
	if (sx == 0 || sy == 0)
	{
		for (ll i = ans.size() - 1; i >= 0; i--)
		{
			cout << ans[i] << sp;
		}
		cout << endl;

		return;
	}

	ll choice1 = sx - 1 >= 0 ? dp[sx - 1][sy] : intmin;
	ll choice2 = (sx - 1 >= 0 && (sy - w[sx - 1] >= 0)) ? dp[sx - 1][sy - w[sx - 1]] + val[sx - 1] : intmin;

	ll maxw = max(choice1, choice2);

	if (maxw == intmin)
		return;
	if (maxw == choice1)
	{
		dfs(sx - 1, sy, w, val, dp, ans);
	}

	if (maxw == choice2)
	{
		ans.pb(sx - 1);
		dfs(sx - 1, sy - w[sx - 1], w, val, dp, ans);
		ans.ppb();
	}
}
int main()
{
	fastIO();
	ll n, tar;
	cin >> n;
	v<ll> value(n);
	v<ll> weight(n);
	for (ll &i : value)
		cin >> i;
	for (ll &i : weight)
		cin >> i;
	cin >> tar;
	// cout << fun(value, weight, tar, n - 1) << endl;
	v<v<ll>> dp(n + 1, v<ll>(tar + 1, 0));
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= tar; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - weight[i - 1] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
			}
		}
	}
	// for (ll i = 0; i <= n; i++)
	// {
	// 	for (ll j = 0; j <= tar; j++)
	// 	{
	// 		cout << dp[i][j] << sp;
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n][tar] << endl;
	v<ll> ans;
	dfs(n, tar, weight, value, dp, ans);
	return 0;
}