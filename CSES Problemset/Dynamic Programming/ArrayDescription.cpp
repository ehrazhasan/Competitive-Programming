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

/*

	
	We have been given an array containing some unknown values represented by 0
	The difference between two adjacent element must be atmost 1
		
	
	dp[1][0] = m
	dp[1][1] = 1
	dp[1][2] = 1
	dp[1][3] = 1
	dp[1][4] = 1
	dp[1][5] = 1
	...


	dp[2][0] = dp[1][0 - 1] + dp[pos - 1][0 + 1] + dp[pos - 1][0] 
		
	dp[pos][curr_element] = curr_element = 0  ->  dp[pos - 1][curr_element]
							curr_element != 0 ->
*/

vector<int> a;
int n, m;
vector<vector<ll>> dp;

// ll solve(int i, int lastSeen){

// 	db2(i, lastSeen);

// 	if(i == n){
// 		return 1LL;
// 	}

// 	if(dp[i][lastSeen] != -1) return dp[i][lastSeen];
// 	int ans = 0;
	
	
// 	if(a[i] != 0 and lastSeen == 0)
// 		ans = mod_add(ans,solve(i + 1, a[i]),MOD);

// 	if(a[i] != 0 and lastSeen != 0){

// 		if(abs(a[i] - lastSeen) <= 1){

// 			ans = mod_add(ans,solve(i + 1, a[i]),MOD);
// 		}
// 		else{

// 			return dp[i][lastSeen] = 0;
// 		}
// 	}

// 	if(a[i] == 0 and lastSeen == 0){

// 		for(int j = 1; j <= m; j++){

// 			ans = mod_add(ans,solve(i + 1, j),MOD);
// 		}
// 	}
// 	else if(a[i] == 0){

// 		for(int j = 1; j <= m; j++){

// 			if(abs(lastSeen - j) <= 1){

// 				ans = mod_add(ans,solve(i + 1, j),MOD);
// 			}
// 		}
// 	}

// 	//db1(ans);
// 	return dp[i][lastSeen] = ans;
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
      	
      	cin >> n >> m;
      	a.assign(n + 1, 0); 
      	rep(i, n) cin >> a[i]; 

      	dp = vector<vector<ll>>(n + 5, vector<ll>(m + 5, 0));

      	if(a[0] == 0) for(int i = 1; i <= m; i++) dp[0][i] = 1;
      	else dp[0][a[0]] = 1;


      	for(int i = 1; i < n; i++){

      		int curr = a[i];

      		if(curr == 0){

      			for(int j = 1; j <= m; j++){

      				dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
      				dp[i][j] %= MOD;
      			}

      		}
      		else{

      			dp[i][curr] += dp[i - 1][curr] + dp[i - 1][curr - 1] + dp[i - 1][curr + 1];
      			dp[i][curr] %= MOD;

      		}
      	}

      	
      	// for(int i = 0; i < n; i++){

      	// 	for(int j = 0; j <= m; j++) cout << dp[i][j] << " ";
      	// 	cout << endl;
      	// }
      	//cout << solve(0, 0);

      	ll ans = 0;
      	for(int j = 1; j <= m; j++) ans = mod_add(ans, dp[n - 1][j], MOD);
      	cout << ans;
      	
    }
    return 0;
}