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
	ll n, k;
	cin >> n;
	v<ll> a(n);
	for (ll &i : a)
		cin >> i;
	cin >> k;
	ll p1 = 0;
	ll p2 = 0;
	ll ans = 0;
	ll score = 0;
	if (k > 0)
	{
		while (true)
		{
			bool f1 = false;
			bool f2 = false;

			while (p2 < n)
			{
				f1 = true;
				if (a[p2] == 1)
				{
					p2++;
				}
				else if (score < k)
				{
					score++;
					p2++;
				}
				else
				{
					break;
				}
			}

			while (p1 < p2)
			{
				f2 = true;
				ans = max(ans, p2 - p1);
				if (a[p1] == 0)
				{
					score--;
				}
				p1++;
				if (score < k)
				{
					break;
				}
			}

			if (f1 == false && f2 == false)
			{
				break;
			}
		}
	}
	else
	{
		ll temp = 0;
		for (ll i = 0; i < n; i++)
		{
			if (a[i])
			{
				temp++;
			}
			else
			{
				ans = max(ans, temp);
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
	return 0;
}