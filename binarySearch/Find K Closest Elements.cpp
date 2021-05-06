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
ll dk8[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
ll d4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/* ordered set:
tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
member functions :
1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/
template <typename T, typename T1>
T amax(T &a, T1 b)
{
	if (b > a)
		a = b;
	return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
	if (b < a)
		a = b;
	return a;
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
v<ll> fun(v<ll> &a, ll k, ll x)
{
	v<ll> ans;
	ll start = 0;
	ll end = 0;
	ll i = lower_bound(a.begin(), a.end(), x) - a.begin();
	start = i - 1;
	end = i;
	while (start >= 0 && end < a.size() && k)
	{
		if (abs(a[start] - a[i]) <= abs(a[end] - a[i]))
		{
			k--;
			start--;
		}
		else
		{
			k--;
			end++;
		}
	}
	while (k && start >= 0)
	{
		k--;
		start--;
	}
	while (k && end < a.size())
	{
		k--;
		end++;
	}
	for (ll j = start + 1; j <= end - 1; j++)
	{

		ans.push_back(a[j]);
	}
	return ans;
}
v<ll> fun1(v<ll> &a, ll k, ll x)
{
	ll start = 0;
	ll end = 0;
	ll sum = 0;
	ll s = 0;
	ll e = 0;
	ll max_sum = 0;
	ll n = a.size();
	while (k-- && e < n)
	{
		sum += abs(x - a[e]);
		e++;
		// cout << e << endl;
	}
	e--;
	start = 0;
	end = e;
	max_sum = sum;
	while (e < n)
	{
		sum -= abs(x - a[s]);
		s++;
		e++;
		if (e == n)
			break;
		sum += abs(x - a[e]);
		if (sum < max_sum)
		{
			max_sum = sum;
			start = s;
			end = e;
		}
	}
	v<ll> ans;
	for (ll i = start; i <= end; i++)
	{
		ans.push_back(a[i]);
	}
	return ans;
}
int main()
{
	fastIO();
	ll n, k, x;
	cin >> n >> k >> x;
	v<ll> a(n);
	for (ll &i : a)
		cin >> i;

	v<ll> ans = fun1(a, k, x);
	for (ll i : ans)
		cout << i << sp;
	cout << endl;
	return 0;
}