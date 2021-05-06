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
bool ask(ll minw, ll a, ll b)
{
	cout << minw << sp << a << sp << b << endl;
	ll ans;
	cin >> ans;
	if (ans == a)
	{
		return true;
	}
	return false;
}
void merge_count(v<ll> &a, ll s, ll mid, ll e, ll minw, ll q)
{
	if (q == 0)
	{
		return;
	}
	ll i = s;
	ll j = mid;
	v<ll> ans(e - s + 1);
	ll c = 0;
	while (i < mid && j <= e)
	{
		if (ask(minw, i, j))
		{
			ans[c++] = a[i++];
		}
		else
		{
			ans[c++] = a[j++];
		}
	}
	while (i < mid)
		ans[c++] = a[i++];
	while (j <= e)
		ans[c++] = a[j++];
	c = 0;
	for (ll k = s; k <= e; k++)
	{
		a[k] = ans[c++];
	}
}
void merge_sort(v<ll> &a, ll s, ll e, ll minw, ll q)
{
	if (q == 0)
	{
		return;
	}
	if (s < e)
	{
		ll mid = s + (e - s) / 2;
		merge_sort(a, s, mid, minw, q);
		merge_sort(a, mid + 1, e, minw, q);
		merge_count(a, s, mid + 1, e, minw, q);
	}
}
int main()
{
	fastIO();
	ll C = 0;
	w(t)
	{
		ll n, q;
		cin >> n >> q;
		v<ll> m(n + 1, 0);
		ll ans = -1;
		for (ll i = 1; i <= (n - 2); i++)
		{
			for (ll j = i + 1; j <= (n - 1); j++)
			{
				for (ll k = j + 1; k <= n; k++)
				{
					q--;
					if (q == 0)
					{
						break;
					}
					cout << i << sp << j << sp << k << endl;
					cin >> ans;
					m[ans]++;
				}
			}
		}
		ll minw = -1;
		for (ll i = 1; i <= n; i++)
		{
			if (m[i] == 0)
			{
				minw = i;
				break;
			}
		}
		v<ll> a(n);
		for (ll i = 1; i <= n; i++)
		{
			a[i] = i;
		}
		if (q > 0)
			merge_sort(a, 0, n - 1, minw, q);
		while (q--)
		{
			ask(1, 2, 3);
		}
		for (ll i = 0; i < n; i++)
		{
			cout << a[i] << sp;
		}
		cout << endl;
		cin >> ans;
		if (ans == -1)
		{
			return 0;
		}
	}
	return 0;
}