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

bool bs(ll mid, ll n){

	ll maxVal = (3 * mid) + (2 * mid);
	//db2(mid, maxVal);

	return n <= maxVal; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
       	ll n;
       	cin >> n;

       	if(n == 1){

       		cout << 0 << endl;
       		continue;
       	}

       	if(n <= 4){

       		cout << 1 << endl;
       		continue;
       	}

       	n--;

       	ll s = 0;
       	ll e = 1e9;
       	ll ans = 1e9;

       	while(s <= e){


       		ll mid = (s + e) / 2;

       		if(bs(mid, n)){

       			ans = min(ans, mid);
       			e = mid - 1;
       		}
       		else{

       			s = mid + 1;
       		}
       	}

       	//db1(ans);

       	ll val = 3 * ans + 2 * ans;

       	if(n > val - 2) cout << ans + ans - 1 + 1 << endl;
       	else cout << ans + ans - 1 << endl;
       	// ll ans1 = n / 5;
       	// ll rem1 = n % 5;

       	// ans1 *= 2;

       	// if(rem1 == 3) ans1 += 1;
       	// if(rem1 == 1) ans1 += 1;
       	// if(rem1 == 4) ans1 += 2;
       	// if(rem1 != 0 and rem1 != 3 and rem1 != 1 and rem1 != 4) ans1 = INF;



       	// ll ans2 = n / 6;
       	// ans2 *= 3;
       	// ll rem2 = n % 6;

       	// if(rem2 == 3) ans2 += 1;
       	// if(rem2 == 5) ans2 += 2;
       	// if(rem2 == 2) ans2 += 1;
       	// if(rem2 == 4) ans2 += 2;

       	// if(rem2 != 0 and rem2 != 3 and rem2 != 5 and rem2 != 2 and rem2 != 4) ans2 = INF;


       	// ll ans3 = n / 4;
       	// ll rem3 = n % 4;

       	// ans3 *= 2;

       	// if(rem3 == 3) ans3 += 1;
       	// if(rem3 == 2) ans3 += 1;
       	// if(rem3 != 0 and rem3 != 3 and rem3 != 2) ans3 = INF;

       	// //db3(ans1, ans2, ans3);
       	// cout << min({ans1, ans2, ans3}) << endl;
    }
    return 0;
}