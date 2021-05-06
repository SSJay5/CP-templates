#include <bits/stdc++.h>
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
#define w(x) ll x; cin >> x; while (x--)
#define all(x) x.begin(), x.end()
#define sp ' '
#define pi 3.14159265359
#define intmax INT32_MAX
#define intmin INT32_MIN
#define conti continue
#define null NULL
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll d8[8][2] = {{ -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
ll d4[4][2] = {{ -1, 0}, {0, -1}, {0, 1}, {1, 0}};
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
ll fun(string s, string t, v<v<ll>> &dp)
{
	if (s.length() == 0 && t.length() == 0)
	{
		return 0;
	}
	if (t.length() == 0)
	{
		return s.length();
	}
	if (s.length() == 0)
	{
		return t.length();
	}
	if (dp[s.length() - 1][t.length() - 1] != -1)
	{
		return dp[s.length() - 1][t.length() - 1];
	}
	ll ans1 = intmax;
	ll ans2 = intmax;
	ll ans3 = intmax;

	if (s[0] == t[0])
	{
		ans1 = fun(s.substr(1), t.substr(1), dp);
	}

	ans1 = min(ans1, fun(s.substr(1), t.substr(1), dp) + 1);
	ans2 = fun(s.substr(1), t, dp) + 1;
	ans3 = fun(s, t.substr(1), dp) + 1;
	dp[s.length() - 1][t.length() - 1] = min(ans1, min(ans2, ans3));
	return min(ans1, min(ans2, ans3));
}
int main()
{
	fastIO();
	string s, t;
	cin >> s >> t;
	v<v<ll>> dp(s.length(), v<ll>(t.length(), -1));
	cout << fun(s, t, dp) << endl;
	return 0;
}