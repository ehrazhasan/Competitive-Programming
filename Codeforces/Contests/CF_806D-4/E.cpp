#include <bits/stdc++.h> 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define db1(x) cout<<#x<<"="<<x<<"\n"
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define tolowecase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::tolower)
#define touppercase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::toupper)
#define MOD1 998244353
#define eps 1e-12
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define PI 3.141592653589793238462
#define total_set_bits __builtin_popcountll
#define endl '\n'


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3 // return x, y, gcd
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
    
                /*******************************************************************************/



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;

        vector<vector<char>> v(n, vector<char>(n));

        rep(i,n){

        	rep(j,n){

        		cin >> v[i][j];
        	}
        }


        ll ans = 0;
        if(n % 2){


        	for(int i = 0; i < n / 2; i++){

        		int ones = 0, zeros = 0;

        		// db2(n / 2, i);
	        	// db2(n - i - 1, n / 2);
	        	// db2(n / 2, n - i - 1);
	        	// db2(i, n / 2);

        		int a = v[n / 2][i] - '0';
        		int b = v[n - i - 1][n / 2] - '0';
        		int c = v[n / 2][n - i - 1] - '0';
        		int d = v[i][n / 2] - '0';

        		if(a == 1) ones++;
	        	else zeros++;

	        	if(b == 1) ones++;
	        	else zeros++;

	        	if(c == 1) ones++;
	        	else zeros++;

	        	if(d == 1) ones++;
	        	else zeros++;

	        	//db3(n, ones, zeros);
	        	
	        	ans += min(zeros, ones);
        	}
        }

        //db1(ans);
        // continue;
        // db1(ans);
        int j = 0;

        while(j < n / 2){

        	int i = 0;
	        while(i < n / 2){

	        	int ones = 0;
	        	int zeros = 0;
	        		
	        	
	        	// db2(i, j);
	        	// db2(i, n - j - 1);
	        	// db2(n - i - 1, j);
	        	// db2(n - i - 1, n - j - 1);

	        	int a = v[i][j] - '0';
	        	int b = v[j][n - i - 1] - '0';
	        	int c = v[n - j - 1][i] - '0';
	        	int d = v[n - i - 1][n - j - 1] - '0';


	        	// if(n % 2 and i == n / 2){

	        	// 	c = v[j][n - i - 1] - '0';
	        	// 	d = v[n - j - 1][n - i - 1] - '0';
	        	// }

	        	// if(n % 2 and i == n / 2 and j == n / 2){

	        	// 	i++;
	        	// 	continue;
	        	// }

	        	if(a == 1) ones++;
	        	else zeros++;

	        	if(b == 1) ones++;
	        	else zeros++;

	        	if(c == 1) ones++;
	        	else zeros++;

	        	if(d == 1) ones++;
	        	else zeros++;

	        	//db2(ones, zeros);
	        	
	        	ans += min(zeros, ones);
	        	i++;
	        }

	        j++;
	    }

        cout << ans << endl;
    }
    return 0;
}


const int N = 3e5 + 9;

struct DSU {
  vector<int> par, rnk, sze;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sze(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sze[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sze[j] += sze[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};