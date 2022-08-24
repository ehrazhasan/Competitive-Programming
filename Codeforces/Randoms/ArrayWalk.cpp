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

const int N = 3e5 + 5;
ll dp[N][6][2];


ll solve(int index, ll movesLeft, ll leftRem, bool allowedLeft, vector<ll> &a){

	if(dp[index][leftRem][allowedLeft] != -1) return dp[index][leftRem][allowedLeft];
	int n = (int)a.size();
	if(movesLeft == 0) return 0;

	

	ll ans = 0;
	if(allowedLeft and leftRem and index - 1 >= 1){

		ans = max(ans, solve(index - 1, movesLeft - 1, leftRem - 1, 0, a) + a[index - 1]);
	}
	
	ans = max(ans, solve(index + 1, movesLeft - 1, leftRem, 1, a) + a[index + 1]);
	
	


	return dp[index][leftRem][allowedLeft] = ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        ll n, k, z;
        cin >> n >> k >> z;

        vector<ll> v(n + 1);
        repA(i, 1, n) cin >> v[i];

        for(int i = 0; i <= n; i++){

        	for(int j = 0; j <= 5; j++){

        		for(int k = 0; k <= 1; k++){

        			dp[i][j][k] = -1;
        		}
        	}
        }

        cout << v[1] + solve(1, k, z, 0, v) << endl;

     //    vector<ll> pref(n + 1);
     //    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i];

     //    // for(int i = 1; i <= n; i++) cout << pref[i] << " ";
     //    // cout << endl;

     //    ll ans = 0;
    	// ll rem = k;
    	// for(int i = 2; i <= n; i++){

    	// 	rem = k;
    	// 	ll sum = pref[i];
    	// 	rem -= (i - 1);

    	// 	if(rem < 0){
    	// 		continue;
    	// 	}

    	// 	ll can = (rem + 1) / 2;
    	// 	can = min(z, can);

    	// 	//db2(i,can);

    	// 	sum += can * v[i - 1];
    	// 	// if(rem % 2 == 0){

    	// 	// 	sum += can * v[i];
    	// 	// 	rem -= 2 * can;
    	// 	// 	//db2(i,sum);
    	// 	// }
    	// 	// else{

    	// 		sum += (can - 1) * v[i];
    	// 		rem -= (2 * can - 1);
    	// 	//}

    	// 	if(rem > 0){

    	// 		// if(can % 2 == 0){

    	// 		// 	ll r = min(n, i + rem);
    	// 		// 	sum += pref[r] - pref[i];
    	// 		// }
    	// 		// else{

    	// 			ll r = min(n, i - 1 + rem);
    	// 			sum += pref[r] - pref[i - 1];
    	// 		// }
    	// 	}
    		
    	// 	//db2(i, sum);
    	// 	ans = max(ans, sum);
    	// }

     //    cout << ans << endl;
    }
    return 0;
}