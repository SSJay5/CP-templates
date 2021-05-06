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
void build(v<ll> &a, v<ll> &tree, ll start, ll end, ll treeNode)
{
	if (start == end)
	{
		tree[treeNode] = a[start];
		return;
	}
	ll mid = start + (end - start) / 2;

	build(a, tree, start, mid, 2 * treeNode);
	build(a, tree, mid + 1, end, (2 * treeNode) + 1);

	tree[treeNode] = min(tree[(2 * treeNode)], tree[(2 * treeNode) + 1]);
}
void update(v<ll> &a, v<ll> &tree, ll start, ll end, ll treeNode, ll idx, ll val)
{
	if (start == end)
	{
		a[idx] = val;
		tree[treeNode] = val;
		return;
	}
	ll mid = start + (end - start) / 2;
	if (idx > mid)
	{
		update(a, tree, mid + 1, end, (2 * treeNode) + 1, idx, val);
	}
	else
	{
		update(a, tree, start, mid, (2 * treeNode), idx, val);
	}

	tree[treeNode] = min(tree[(2 * treeNode)], tree[(2 * treeNode) + 1]);
}
ll query(v<ll> &a, v<ll> &tree, ll start, ll end, ll treeNode, ll left, ll right)
{
	if (start > right || end < left)
	{
		return intmax;
	}
	if (start >= left && end <= right)
	{
		return tree[treeNode];
	}

	ll mid = start + (end - start) / 2;

	ll ans1 = query(a, tree, start, mid, 2 * treeNode, left, right);
	ll ans2 = query(a, tree, mid + 1, end, (2 * treeNode) + 1, left, right);

	return min(ans1, ans2);
}
int main()
{
	fastIO();
	ll n, q;
	cin >> n >> q;
	v<ll> a(n);
	v<ll> tree(4 * n, intmax);
	for (ll &i : a)
		cin >> i;
	build(a, tree, 0, n - 1, 1);
	ll type, s, e;
	while (q--)
	{
		cin >> type >> s >> e;
		if (type == 1)
		{
			update(a, tree, 0, n - 1, 1, s, e);
		}
		else
		{
			cout << query(a, tree, 0, n - 1, 1, s, e - 1) << endl;
		}
	}
	return 0;
}