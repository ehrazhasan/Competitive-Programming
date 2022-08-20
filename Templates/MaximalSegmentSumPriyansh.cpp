/* Priyansh Agarwal*/
#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug(x) cout << #x << " " << x <<endl;
#define set_bits __builtin_popcount
typedef long long ll;
typedef unsigned long long ull;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll* fact) {ll val1 = fact[n]; ll val2 = mminvprime(fact[r], m); ll val3 = mminvprime(fact[n - r], m); return ((val1 * val2) % m * val3) % m;}
/*--------------------------------------------------------------------------------------------------------------------------*/
struct node
{
	ll sum;
	ll msum;
	ll pref;
	ll suff;
};
void build_tree(ll *arr, node *tree, int start, int end, int index)
{
	if (start == end)
	{
		ll x = 0;
		tree[index].sum = arr[start];
		tree[index].msum = max(x, arr[start]);
		tree[index].pref = max(x, arr[start]);
		tree[index].suff = max(x, arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * index);
	build_tree(arr, tree, mid + 1, end, 2 * index + 1);
	node a = tree[2 * index];
	node b = tree[2 * index + 1];
	tree[index].sum = a.sum + b.sum;
	tree[index].pref = max(a.sum + b.pref, a.pref);
	tree[index].suff = max(b.sum + a.suff, b.suff);
	tree[index].msum = max(max(a.msum, b.msum), a.suff + b.pref);
}
node query(node*tree, int start, int end, int index, int left, int right)
{
	if (start >= left && end <= right)
		return tree[index];
	if (start > right || end < left)
		return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
	int mid = (start + end) / 2;
	node a = query(tree, start, mid, 2 * index, left, right);
	node b = query(tree, mid + 1, end, 2 * index + 1, left, right);
	node c;
	c.sum = a.sum + b.sum;
	c.pref = max(a.sum + b.pref, a.pref);
	c.suff = max(b.sum + a.suff, b.suff);
	c.msum = max(max(a.msum, b.msum), a.suff + b.pref);
	return c;
}
void update(ll *arr, node*tree, int start, int end, int index, int k, ll value)
{
	if (start == end)
	{
		arr[start] = value;
		ll x = 0;
		tree[index].sum = arr[start];
		tree[index].msum = max(x, arr[start]);
		tree[index].pref = max(x, arr[start]);
		tree[index].suff = max(x, arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	if (mid >= k)
		update(arr, tree, start, mid, 2 * index, k, value);
	else
		update(arr, tree, mid + 1, end, 2 * index + 1, k, value);
	node a = tree[2 * index];
	node b = tree[2 * index + 1];
	tree[index].sum = a.sum + b.sum;
	tree[index].pref = max(a.sum + b.pref, a.pref);
	tree[index].suff = max(b.sum + a.suff, b.suff);
	tree[index].msum = max(max(a.msum, b.msum), a.suff + b.pref);
}
int main()
{
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
	int n, q;
	cin >> n >> q;
	ll *arr = new ll[n]();
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	node *tree = new node[4 * n]();
	build_tree(arr, tree, 0, n - 1, 1);
	cout << query(tree, 0, n - 1, 1, 0, n - 1).msum << endl;
	while (q--)
	{
		int a;
		ll value;
		cin >> a >> value;
		update(arr, tree, 0, n - 1, 1, a, value);
		cout << query(tree, 0, n - 1, 1, 0, n - 1).msum << endl;
	}
	return 0;
}