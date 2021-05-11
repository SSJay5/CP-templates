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
bool matSearch(v<v<ll>> &a, ll k)
{
	ll n = a.size();
	ll m = a[0].size();
	ll x = 0;
	ll y = m - 1;

	while (x >= 0 && x < n && y >= 0 && y < m)
	{
		if (a[x][y] == k)
		{
			return true;
		}
		else if (k > a[x][y])
		{
			x++;
		}
		else if (k < a[x][y])
		{
			y--;
		}
	}
	return false;
}
int main()
{
	fastIO();
	ll n, x;
	cin >> n;
	v<v<ll>> a(n, v<ll>(n));
	v<v<ll>> b(n, v<ll>(n));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}
	cin >> x;
	ll ans = 0;
	map<ll, ll> m;
	for (auto i : b)
	{
		for (auto j : i)
			m[j]++;
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			ans += m[x - a[i][j]];
		}
	}
	cout << ans << endl;
	return 0;
}