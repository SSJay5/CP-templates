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
	ll k;
	cin >> k;
	sort(all(a));

	v<v<ll>> ans;

	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			ll left = j + 1;
			ll right = n - 1;
			ll req_sum = k - a[i] - a[j];
			while (left < right)
			{
				if (a[left] + a[right] < req_sum)
				{
					left++;
				}
				else if (a[left] + a[right] > req_sum)
				{
					right--;
				}
				else
				{
					v<ll> temp(4);
					temp[0] = a[i];
					temp[1] = a[j];
					temp[2] = a[left];
					temp[3] = a[right];

					ans.pb(temp);

					while (left < right && a[left] == temp[2])
						left++;
					while (left < right && a[right] == temp[3])
						right--;
				}
			}

			while (j + 1 < n && a[j + 1] == a[j])
			{
				j++;
			}
		}
		while (i + 1 < n && a[i + 1] == a[i])
		{
			i++;
		}
	}
	for (v<ll> i : ans)
	{
		for (ll j : i)
		{
			cout << j << sp;
		}
		cout << endl;
	}
	return 0;
}