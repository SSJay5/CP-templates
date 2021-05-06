#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Max 1e3 + 5
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
ll fun(string a, string b, v<v<ll>> &dp)
{
	if (a.length() == 0)
	{
		return Max;
	}
	if (b.length() == 0)
	{
		return 1;
	}
	ll ans1 = intmax;
	ll ans2 = intmax;
	if (dp[a.length()][b.length()] != -1)
	{
		return dp[a.length()][b.length()];
	}
	ll k = b.length();
	// cout << ans1 << sp << ans2 << endl;
	for (ll i = 0; i < b.length(); i++)
	{
		if (a[0] == b[i])
		{
			k = i;
			break;
		}
	}
	if (k == b.length())
	{
		return 1;
	}
	ans1 = 1 + fun(a.substr(1), b.substr(k + 1), dp);
	ans2 = fun(a.substr(1), b, dp);
	// cout << ans1 << sp << ans2 << endl;
	dp[a.length()][b.length()] = min(ans1, ans2);
	return min(ans1, ans2);
}
int main()
{
	fastIO();
	string s1, s2;
	cin >> s1 >> s2;
	v<v<ll>> dp(s1.length() + 1, v<ll>(s2.length() + 1, 0));
	// cout << fun(s1, s2, dp) << endl;
	for (ll i = 0; i <= s1.length(); i++)
	{
		dp[i][0] = 1;
	}
	for (ll i = 0; i <= s2.length(); i++)
	{
		dp[0][i] = Max;
	}
	for (ll i = 1; i <= s1.length(); i++)
	{
		for (ll j = 1; j <= s2.length(); j++)
		{
			ll k = -1;
			for (k = j - 1; k >= 0; k--)
			{
				if (s2[k] == s1[i - 1])
				{
					break;
				}
			}
			if (k == -1)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = min(1 + dp[i - 1][k], dp[i - 1][j]);
			}
		}
	}
	if (dp[s1.length()][s2.length()] == Max)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dp[s1.length()][s2.length()] << endl;
	}
	return 0;
}