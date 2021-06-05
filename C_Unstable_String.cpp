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
//////////////////////////////////////////////
int power(ll x, ll y, int p) //x^y
{
	int res = 1; // Initialize result

	x = x % p; // Update x if it is more than or
						 // equal to p

	if (x == 0)
		return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}
//////////////////////////////////////////////
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
	w(t)
	{
		string s;
		cin >> s;
		ll n = s.length();
		ll ans = 0;
		ll p1 = 0;
		ll p2 = 0;
		ll P0 = -1;
		ll P1 = -1;
		while (true)
		{
			bool f1 = false;
			bool f2 = false;

			while (p2 < n)
			{
				f1 = true;
				if (p2 + 1 < n && s[p2] != '?' && s[p2] == s[p2 + 1])
				{
					break;
				}
				if (s[p2] == '0')
					P0 = p2;
				if (s[p2] == '1')
					P1 = p2;
				if (p1 == p2)
				{
					p2++;
					conti;
				}
				if (s[p1] == '0')
				{
					if (s[p2] == '?')
					{
						p2++;
					}
					else if (s[p2] == '1' && ((p2 - p1 - 1) % 2 == 0))
					{
						p2++;
					}
					else if (s[p2] == '0' && ((p2 - p1 - 1) % 2 == 1))
					{
						p2++;
					}
					else
					{
						break;
					}
				}
				else if (s[p1] == '1')
				{
					if (s[p2] == '?')
					{
						p2++;
					}
					else if (s[p2] == '0' && ((p2 - p1 - 1) % 2 == 0))
					{
						p2++;
					}
					else if (s[p2] == '1' && ((p2 - p1 - 1) % 2 == 1))
					{
						p2++;
					}
					else
					{
						break;
					}
				}
				else
				{
					if (s[p2] == '?')
					{
						p2++;
					}
					else if (s[p2] == '1')
					{
						if (P0 == -1)
							p2++;
						else if ((P1 - P0 - 1) % 2 == 0)
						{
							p2++;
						}
						else
						{
							break;
						}
					}
					else if (s[p2] == '0')
					{
						if (P1 == -1)
							p2++;
						else if ((P0 - P1 - 1) % 2 == 0)
						{
							p2++;
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}5
			}
			if (p2 + 1 < n && s[p2] != '?' && s[p2] == s[p2 + 1])
			{
				ll ln = p2 - p1 + 1;
				ans += ((ln) * (ln + 1)) / 2;
				p2++;
				p1 = p2;
				P0 = -1;
				P1 = -1;
			}
			if (p1 < p2)
			{
				f2 = true;
				ans += p2 - p1;
				if(P0==p1)

				p1++;
			}

			if (f1 == false && f2 == false)
			{
				break;
			}
		}

		cout << ans << endl;
	}
	return 0;
}