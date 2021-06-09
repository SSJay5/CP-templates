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
#define sc(x) static_cast<x>
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
int power(ll x, ll y, int p) //x^y
{
	int res = 1; // Initialize result
	x = x % p;	 // Update x if it is more than or
	if (x == 0)
		return 0; // In case x is divisible by p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
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
int main()
{
	fastIO();
	ll n, m;
	cin >> n >> m;
	v<v<pii>> a(n + 1);
	ll x, y, W;
	for (ll i = 0; i < m; i++)
	{
		cin >> x >> y >> W;
		a[x].pb(mp(y, W));
	}
	priority_queue<pii, v<pii>, greater<pii>> q;
	v<ll> dist(n + 1, intmax);
	dist[1] = 0;
	q.push(mp(1, 0));

	while (!q.empty())
	{
		ll curr = q.top().ff;
		ll curr_dist = q.top().ss;
		q.pop();

		for (auto i : a[curr])
		{
			if (curr_dist + i.ss < dist[i.first])
			{
				dist[i.ff] = curr_dist + i.ss;
				q.push(mp(i.ff, dist[i.first]));
			}
		}
	}
	for (ll i = 2; i <= n; i++)
	{
		cout << dist[i] << sp;
	}
	cout << endl;

	return 0;
}