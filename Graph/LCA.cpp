#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define Max 1e3
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
const ll maxN = log2(Max);
v<v<ll>> LCA(Max, v<ll>(maxN + 1, -1));
v<ll> level(Max, 0);
v<v<ll>> g(Max);

ll getLCA(ll a, ll b)
{
	if (level[a] > level[b])
		swap(a, b);
	ll d = level[b] - level[a];

	while (d > 0)
	{
		ll i = log2(d);
		b = LCA[b][i];
		d -= 1 << i;
	}
	if (a == b)
		return a;

	for (ll i = maxN; i >= 0; i--)
	{
		if (LCA[a][1 << i] != -1 && (LCA[a][i] != LCA[b][i]))
		{
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}

	return LCA[a][0];
}
void dfs(ll sv, ll par, ll lvl)
{
	level[sv] = lvl;
	LCA[sv][0] = par;

	for (ll i : g[sv])
	{
		if (i != par)
		{
			dfs(i, sv, lvl + 1);
		}
	}
}
void init(ll n)
{
	dfs(1, 0, -1);

	for (ll i = 1; i <= maxN; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if (LCA[j][i - 1] != -1)
			{
				ll par = LCA[j][i - 1];
				LCA[j][i] = LCA[par][i - 1];
			}
		}
	}
}
ll getDistance(ll a, ll b)
{
	ll lca = getLCA(a, b);
	return level[a] + level[b] - level[lca] - level[lca];
}
int main()
{
	fastIO();

	ll x, y, n;
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	ll q;
	init(n);
	cin >> q;
	while (q--)
	{
		cin >> x >> y;
		cout << getDistance(x, y) << endl;
	}
	return 0;
}