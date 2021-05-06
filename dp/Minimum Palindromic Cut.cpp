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
bool isPalindrome(string s)
{
	for (ll i = 0; i < (s.length() / 2); i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}
ll fun(string s)
{
	if (s.length() == 1)
	{
		return 0;
	}
	if (s.length() == 2)
	{
		if (s[0] == s.back())
			return 0;
		return 1;
	}
	if (isPalindrome(s))
	{
		return 0;
	}
	ll ans = s.length() - 1;
	for (ll i = 0; i < s.length() - 1; i++)
	{
		ans = min(ans, fun(s.substr(0, i + 1)) + fun(s.substr(i + 1)) + 1);
	}
	return ans;
}
int main()
{
	fastIO();
	string s;
	cin >> s;
	// cout << s << sp << s.substr(0, s.length() - 1) << endl;
	// cout << fun(s) << endl;
	ll n = s.length();
	v<v<bool>> P(n, v<bool>(n, false));
	for (ll g = 0; g < n; g++)
	{
		for (ll i = 0, j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				P[i][j] = true;
			}
			else if (g == 1)
			{
				if (s[i] == s[j])
					P[i][j] = true;
			}
			else
			{
				if (s[i] == s[j])
					P[i][j] = P[i + 1][j - 1];
			}
		}
	}
	v<v<ll>> dp(n, v<ll>(n));
	for (ll g = 0; g < n; g++)
	{
		for (ll i = 0, j = g; j < n; i++, j++)
		{
			if (g == 0)
			{
				dp[i][j] = 0;
			}
			else if (g == 1)
			{
				if (s[i] == s[j])
					dp[i][j] = 0;
				else
					dp[i][j] = 1;
			}
			else
			{
				if (P[i][j])
				{
					dp[i][j] = 0;
				}
				else
				{
					ll ans = j - i + 1;
					for (ll k = i; k < j; k++)
					{
						ans = min(ans, dp[i][k] + dp[k + 1][j] + 1);
					}
					dp[i][j] = ans;
				}
			}
		}
	}
	// cout << dp[0][n - 1] << endl;
	v<ll> dp2(n);
	dp2[0] = 0;
	for (ll j = 1; j < s.length(); j++)
	{
		ll minw = intmax;
		for (ll i = j; i >= 1; i--)
		{
			if (P[i][j])
			{
				if (P[0][i - 1] == false && dp2[i - 1] < minw)
					minw = min(minw, dp2[i - 1] + 1);
				else
					minw = 0;
			}
		}
		dp2[j] = minw;
		// cout << dp2[j] << sp;
	}
	// cout << endl;
	cout << dp2[n - 1] << endl;
	return 0;
}