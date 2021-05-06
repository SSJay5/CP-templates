#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define Max 1e6
#define ff first
#define ss second
#define ll int
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
map<ll, ll> m;

void addNum(int val)
{
	m[val] = val;
	if (m.find(val - 1) != m.end())
	{
		m[val] = m[val - 1];
	}
	if (m.find(val + 1) != m.end())
	{
		for (auto i = m.find(val + 2); i != m.end(); i++)
		{
			if (i->second == m[val + 1])
			{
				i->second = m[val];
			}
		}
		m[val + 1] = m[val];
	}
}

vector<vector<int>> getIntervals()
{
	v<v<ll>> ans;
	ll curr = -1;
	ll minw = INT32_MAX;
	ll maxw = INT32_MIN;

	for (auto i : m)
	{
		if (i.second != curr)
		{
			ans.push_back({minw, maxw});
			curr = i.second;
			minw = i.first;
			maxw = i.second;
		}
		else
		{
			minw = min(minw, i.first);
			maxw = max(maxw, i.second);
		}
	}
	ans.erase(ans.begin());
	return ans;
}
int main()
{
	addNum(1);
	addNum(3);
	addNum(7);
	addNum(2);
	addNum(6);
	v<v<ll>> ans = getIntervals();
	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j << sp;
		}
		cout << endl;
	}
	return 0;
}