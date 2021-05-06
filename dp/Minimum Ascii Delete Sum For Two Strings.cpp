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
ll fun(string a, string b, ll ans)
{
	if (a == b)
	{
		return ans;
	}
	if (a.length() == 0 && b.length() == 0)
	{
		return 0;
	}
	if (a.length() == 0 && b.length() != 0)
	{
		return b[0] + fun(a, b.substr(1), ans + b[0]);
	}
	if (a.length() != 0 && b.length() == 0)
	{
		return a[0] + fun(a.substr(1), b, ans + a[0]);
	}
	ll ans3 = intmax;
	if (a[0] == b[0])
		ans3 = fun(a.substr(1), b.substr(1), ans);
	ll ans1 = fun(a, b.substr(1), ans + (ll)b[0]);
	ll ans2 = fun(a.substr(1), b, ans + (ll)a[0]);

	return min(ans3, min(ans1, ans2));
}
int main()
{
	fastIO();
	string s1, s2;
	cin >> s1 >> s2;
	// cout << fun(s1, s2, 0) << endl;
	ll n = s1.length();
	ll m = s2.length();
	v<v<ll>> dp(n + 1, v<ll>(m + 1, intmax));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + (ll)s1[i - 1];
	}
	for (ll i = 1; i <= m; i++)
	{
		dp[0][i] = dp[0][i - 1] + (ll)s2[i - 1];
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + (ll)s1[i - 1], dp[i][j - 1] + (ll)s2[j - 1]));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}