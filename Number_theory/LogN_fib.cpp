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
void multiply(ll A[2][2], ll M[2][2])
{
	ll fv = ((A[0][0] * M[0][0]) % mod + (A[0][1] * M[1][0]) % mod + mod) % mod;
	ll sv = ((A[0][0] * M[0][1]) % mod + (A[0][1] * M[1][1]) % mod + mod) % mod;
	ll tv = ((A[1][0] * M[0][0]) % mod + (A[1][1] * M[1][0]) % mod + mod) % mod;
	ll Fv = ((A[1][0] * M[0][1]) % mod + (A[1][1] * M[1][1]) % mod + mod) % mod;

	A[0][0] = fv;
	A[0][1] = sv;
	A[1][0] = tv;
	A[1][1] = Fv;
}
void power(ll A[2][2], ll n)
{
	if (n <= 1)
	{
		return;
	}

	power(A, n / 2);

	multiply(A, A);
	if ((n % 2) != 0)
	{
		ll M[2][2] = {{1, 1}, {1, 0}};
		multiply(A, M);
	}
}
ll fib(ll n, ll x, ll y)
{
	ll A[2][2] = {{1, 1}, {1, 0}};

	power(A, n - 2);

	return ((A[0][0] * y) % mod + (A[0][1] * x) % mod + mod) % mod;
}
int main()
{
	fastIO();
	ll x, y, n;
	cin >> x >> y >> n;
	if (n == 1)
	{
		cout << (x + mod) % mod << endl;
	}
	else if (n == 2)
	{
		cout << (y + mod) % mod << endl;
	}
	else
		cout << (fib(n, x, y) + mod) % mod << endl;
	return 0;
}
/*
	since f(n)=f(n-1)+f(n-2)

	here we have 2 states i.e f(n-1) & f(n-2)

	so size of matrix A will be 2X2 | a b |
																	| c d |

	now | a b |^(k-1)| f(1) |=| f(k)   |
			| c d |			 | f(0) | | f(k-1) |
		a*f(1)+b*f(0)=f(2)
		therefore a=1 b=1
		c*f(1)+d*f(0)=f(1)
		therefore c=1 d=0
	
*/