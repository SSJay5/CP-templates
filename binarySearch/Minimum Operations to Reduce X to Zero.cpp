#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Max 1e6
#define ff first
#define ss second
#define ll int
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
ll dk8[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
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
ll fun(v<ll> &a, ll s, ll e, ll x, v<v<ll>> &dp)
{
	if (x == 0)
	{
		return 0;
	}
	if (s > e)
	{
		return INT32_MAX;
	}
	if (s == e)
	{
		if (a[s] != x)
		{
			return INT32_MAX;
		}
		return 1;
	}
	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}
	ll ans1 = INT32_MAX;
	ll ans2 = INT32_MAX;

	if (x >= a[s])
	{
		ans1 = fun(a, s + 1, e, x - a[s], dp) + 1;
	}
	if (x >= a[e])
	{
		ans2 = fun(a, s, e - 1, x - a[e], dp) + 1;
	}

	return min(ans1, ans2);
}
int minOperations(vector<int> &a, int x)
{
	ll sum = 0;
	ll req_sum = 0;
	ll n = a.size();
	for (ll i : a)
	{
		sum += i;
	}
	req_sum = sum - x;

	if (req_sum < 0)
	{
		return -1;
	}
	sum = a[0];
	ll s = 0;
	ll e = 0;
	ll ans = 0;
	if (req_sum == 0)
	{
		return n;
	}
	while (e < n)
	{
		if (sum < req_sum)
		{
			e++;
			sum += a[e];
			if (sum == req_sum)
			{
				ans = max(ans, e - s + 1);
			}
		}
		else if (sum == req_sum)
		{
			ans = max(ans, e - s + 1);
			e++;
			sum += a[e];
		}
		else
		{
			sum -= a[s];
			s++;
		}
	}

	return ans == 0 ? -1 : n - ans;
}
int main()
{
	fastIO();
	ll n, x;
	cin >> n;
	v<ll> a(n);
	for (ll &i : a)
		cin >> i;
	cin >> x;
	cout << minOperations(a, x) << endl;
	return 0;
}