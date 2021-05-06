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
ll fun(v<pii> &range, ll k)
{
	ll start = 0;
	ll end = range.size() - 1;
	ll ans = -1;

	while (start <= end)
	{
		ll mid = start + (end - start) / 2;
		if (range[mid].ff <= k)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	if (ans != -1 && range[ans].ff <= k && range[ans].ss >= k)
	{
		return ans;
	}
	return -1;
}
int main()
{
	fastIO();
	w(t)
	{
		ll n, q;
		cin >> n >> q;
		v<pii> A(n);
		v<pii> a;
		for (ll i = 0; i < n; i++)
		{
			cin >> A[i].ff >> A[i].ss;
		}
		sort(all(A));
		a.pb(A[0]);
		for (ll i = 1; i < A.size(); i++)
		{
			if (A[i].ff <= a.back().ss)
			{
				a.back().ff = min(a.back().first, A[i].ff);
				a.back().ss = max(a.back().ss, A[i].ss);
			}
			else
			{
				a.pb(A[i]);
			}
		}
		v<pii> range;
		ll maxw = 0;
		for (ll i = 0; i < a.size(); i++)
		{
			ll numOfEle = a[i].ss - a[i].first + 1;
			range.push_back(mp(maxw + 1, maxw + numOfEle));
			maxw = maxw + numOfEle;
		}
		while (q--)
		{
			ll x;
			cin >> x;
			ll ans = fun(range, x);
			if (ans == -1)
			{
				cout << -1 << endl;
			}
			else
			{
				ans = x - range[ans].ff + a[ans].ff;
				cout << ans << endl;
			}
		}
	}
	return 0;
}