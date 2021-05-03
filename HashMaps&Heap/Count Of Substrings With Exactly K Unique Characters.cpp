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
	string s;
	ll k;
	cin >> s >> k;
	map<char, ll> m1;
	map<char, ll> m2;
	ll p1 = 0;
	ll p2 = 0;
	ll p3 = 0;
	ll ans = 0;
	ll score1 = 0;
	ll score2 = 0;

	if (k >= 2)
	{
		while (true)
		{
			bool f1 = false;
			bool f2 = false;
			bool f3 = false;

			while (p3 < s.length())
			{
				f1 = true;

				m1[s[p3]]++;
				if (m1[s[p3]] == 1)
				{
					score1++;
				}

				if (score1 == k + 1)
				{
					m1[s[p3]]--;
					if (m1[s[p3]] == 0)
					{
						score1--;
					}
					break;
				}
				p3++;
			}

			while (p2 < p3)
			{
				f2 = true;

				m2[s[p2]]++;
				if (m2[s[p2]] == 1)
				{
					score2++;
				}

				if (score2 == k)
				{
					m2[s[p2]]--;
					if (m2[s[p2]] == 0)
					{
						score2--;
					}
					break;
				}
				p2++;
			}

			while (p1 < p2)
			{
				if (score1 == k && score2 == k - 1)
					ans += p3 - p2;
				f3 = true;
				m1[s[p1]]--;
				m2[s[p1]]--;

				if (m1[s[p1]] == 0)
					score1--;
				if (m2[s[p1]] == 0)
				{
					score2--;
				}
				p1++;
				if (score1 < k || score2 < k - 1)
				{
					break;
				}
			}
			if (f1 == false && f2 == false && f3 == false)
			{
				break;
			}
		}
	}
	else
	{
		while (true)
		{
			bool f1 = false;
			bool f2 = false;

			while (p2 < s.length())
			{
				f1 = true;

				m1[s[p2]]++;
				if (m1[s[p2]] == 1)
				{
					score1++;
				}

				if (score1 == 2)
				{
					m1[s[p2]]--;
					if (m1[s[p2]] == 0)
					{
						score1--;
					}
					break;
				}
				p2++;
			}

			while (p1 < p2)
			{
				f2 = true;
				ans += p2 - p1;
				m1[s[p1]]--;
				if (m1[s[p1]] == 0)
				{
					score1--;
				}
				p1++;
				if (score1 < 1)
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

	cout << ans << endl;
	return 0;
}

// https://www.youtube.com/watch?v=CBSeilNvZHs&list=TLGGUtXeDoZGukgwMzA1MjAyMQ