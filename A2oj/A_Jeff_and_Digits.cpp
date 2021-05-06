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
int main()
{
	fastIO();
	ll n;
	cin >> n;
	v<ll> a(n);
	for (ll &i : a)
		cin >> i;
	if (n < 3)
	{
		bool isZero = false;
		for (ll i : a)
			if (i == 0)
				isZero = true;
		if (isZero)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	else
	{
		sort(all(a), greater<ll>());
		if (a.back() != 0)
		{
			cout << -1 << endl;
		}
		else
		{
			ll sum = 0;
			sum = a[0] + a[1];
			if (sum < 10)
			{
				cout << 0 << endl;
			}
			else
			{
				ll c5 = 0;
				ll c0 = 0;
				for (ll i = 0; i < n; i++)
				{
					if (a[i] == 5)
						c5++;
					else
						c0++;
				}
				if (c5 / 9 == 0)
				{
					cout << 0 << endl;
				}
				else
				{
					for (ll i = 0; i < c5 / 9; i++)
					{
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
						cout << 5;
					}
					for (ll i = 0; i < c0; i++)
					{
						cout << 0;
					}
				}
			}
		}
	}
	cout << endl;
	return 0;
}