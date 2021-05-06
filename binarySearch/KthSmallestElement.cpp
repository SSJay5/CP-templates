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
void modify(v<pii> &a)
{
	v<pii> ans;
	sort(all(a));
	ans.pb(a[0]);
	for (ll i = 1; i < a.size(); i++)
	{
		if (a[i].ff <= ans.back().ss)
		{
			ans.back().ff = min(ans.back().ff, a[i].ff);
			ans.back().ss = max(ans.back().ss, a[i].ss);
		}
		else
		{
			ans.pb(a[i]);
		}
	}
	swap(a, ans);
}
int main()
{
	fastIO();
	w(t)
	{
		ll n, q;
		cin >> n >> q;
		v<pii> a(n + 1, mp(0, 0));
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i].ff >> a[i].ss;
		}
		modify(a);
		v<ll> r(n + 1, 0);
		v<ll> l(n + 1, 0);
		v<ll> sum(n + 1, 0);
		for (ll i = 1; i <= n; i++)
		{
			l[i] = a[i].ff;
			r[i] = a[i].ss;
			sum[i] = sum[i - 1] + (r[i] - l[i] + 1);
		}
		while (q--)
		{
			ll p;
			cin >> p;
			ll index = lower_bound(all(sum), p) - sum.begin();
			if (((l[index] + p - 1) - r[index - 1]) > 0)
			{
				cout << ((l[index] + p - 1) - r[index - 1]) << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}