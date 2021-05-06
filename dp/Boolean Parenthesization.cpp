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
bool eval(char c1, char c2, char op)
{
	if (op == '&')
	{
		if (c1 == 'F' || c2 == 'F')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	if (op == '|')
	{
		if (c1 == 'T' || c2 == 'T')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (op == '^')
	{
		if (c1 == c2)
		{
			return false;
		}
	}
	return true;
}
ll fun(string s, bool isTrue)
{
	if (s.length() == 0)
	{
		return 0;
	}
	if (s.length() == 1)
	{
		if (isTrue)
		{
			return s[0] == 'T';
		}
		else
		{
			return s[0] == 'F';
		}
	}
	// cout << s << endl;
	ll ans = 0;
	for (ll k = 1; k < s.length() - 1; k += 2)
	{
		ll lt = fun(s.substr(0, k), true);
		ll lf = fun(s.substr(0, k), false);
		ll rt = fun(s.substr(k + 1), true);
		ll rf = fun(s.substr(k + 1), false);
		if (isTrue)
		{
			if (s[k] == '&')
			{
				ans += lt * rt;
			}
			else if (s[k] == '|')
			{
				ans += (lt * rt) + (lt * rf) + (lf * rt);
			}
			else
			{
				ans += (lt * rf) + (lf * rt);
			}
		}
		else
		{
			if (s[k] == '&')
			{
				ans += lf * rt + rf * lt + lf * rf;
			}
			else if (s[k] == '|')
			{
				ans += lf * rf;
			}
			else
			{
				ans += (lt * rt) + (lf * rf);
			}
		}
	}
	return ans;
}
int main()
{
	fastIO();
	string s1, s2;
	cin >> s1 >> s2;
	string s;
	for (ll i = 0; i < s2.length(); i++)
	{
		s += s1[i];
		s += s2[i];
	}
	s += s1.back();
	// cout << s << endl;
	// cout << fun(s, true) << endl;
	ll n = s.length();
	// cout << n << endl;
	v<v<v<ll>>> dp(n, v<v<ll>>(n, v<ll>(2, 0)));
	for (ll g = 0; g < n; g += 2)
	{
		for (ll i = 0, j = g; j < n; i += 2, j += 2)
		{
			cout << endl;
			if (g == 0)
			{
				if (s[i] == 'T')
				{
					dp[i][j][1] = 1;
					dp[i][j][0] = 0;
				}
				else if (s[i] == 'F')
				{
					dp[i][j][0] = 1;
					dp[i][j][1] = 0;
				}
			}
			else
			{
				for (ll k = i + 1; k < j; k += 2)
				{
					if (s[k] == '&')
					{
						dp[i][j][0] += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][0] * dp[k + 1][j][0];
						dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][1];
					}
					else if (s[k] == '|')
					{
						dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0];
						dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][1];
					}
					else
					{
						dp[i][j][0] += dp[i][k - 1][1] * dp[k + 1][j][1] + dp[i][k - 1][0] * dp[k + 1][j][0];
						dp[i][j][1] += dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][0];
					}
				}
			}
		}
	}
	cout << dp[0][n - 1][1] << endl;
	return 0;
}