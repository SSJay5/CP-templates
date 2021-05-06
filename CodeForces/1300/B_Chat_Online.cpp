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

bool fun(v<ll> &b1, v<ll> &b2, ll a, ll b)
{
	bool ans = false;
	auto it1 = upper_bound(all(b1), a);
	if (it1 != b1.begin())
		--it1;
	auto it2 = upper_bound(all(b2), b);
	if (it2 != b2.begin())
		--it2;
	if (*it1 > a || *it2 > b)
	{
		return false;
	}

	ll i = it1 - b1.begin();
	ll j = it2 - b2.begin();
	if (i <= j)
	{
		return true;
	}
	return false;
}
int main()
{
	fastIO();
	ll p, q, l, r;
	cin >> p >> q >> l >> r;
	v<ll> a1(p);
	v<ll> a2(p);
	v<ll> b1(q);
	v<ll> b2(q);
	ll ans = 0;
	unordered_map<ll, ll> m;
	for (ll i = 0; i < p; i++)
	{
		cin >> a1[i] >> a2[i];
		for (ll j = a1[i]; j <= a2[i]; j++)
		{
			m[j]++;
		}
	}

	for (ll i = 0; i < q; i++)
	{
		cin >> b1[i] >> b2[i];
	}

	for (ll i = l; i <= r; i++)
	{
		for (ll j = 0; j < q; j++)
		{
			bool found = false;
			for (ll k = b1[j] + i; k <= b2[j] + i; k++)
			{
				if (m[k] > 0)
				{
					ans++;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}