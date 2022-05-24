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

ll cnt = 0;
const int N = 405;
vector<ll> fact(N);
string s;
bool isPalindrome(string &p){

	// if(i > j) return false;
	// string p = s.substr(i, j - i + 1);
	string c = p;
	reverse(all(c));

	return c == p;
}

ll dfs(int i, string temp){

	db1(temp);
	
	if(temp == "") return 1LL;
	
	ll ans = 0;
	if(isPalindrome(temp) and temp.size() != s.size()) ans = mod_add(ans, 1, MOD);

	for(int j = i; j < temp.size(); j++){

		string a = "";
		string b = "";

		if(j - 1 >= 0) a = temp.substr(0, j);
		if(j + 1 < temp.size()) b = temp.substr(j + 1);
		//db2(j, a + b);
		string req = a + b;
		
		ans = mod_add(ans, dfs(0, a + b), MOD);

		if(isPalindrome(temp) and temp.size() != s.size()) ans = mod_add(ans, 1, MOD);
	}

	

	db1(ans);
	cnt += ans;
	return ans;
}	


void preprocess(){

	fact.clear();
	fact[0] = 1LL;

	for(ll i = 1; i < N; i++){

		fact[i] = mod_mul(i, fact[i - 1], MOD);
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    preprocess();
    for(int tt = 1; tt <= t; tt++){
        
    	google(tt);
    	int n; 
    	cin >> n >> s;
    	
    	cnt = 0;
    	ll f = fact[n];
    	ll ans = dfs(0, s);

    	db3(ans, f, cnt);
    	cout << mod_div(ans, f, MOD) << endl;


  //   	ll dp[n + 5][n + 5];


  //   	for(int i = 0; i <= n + 1; i++){

  //   		for(int j = 0; j <= n + 1; j++){

  //   			if(i == j) dp[i][j] = 1;
  //   			else dp[i][j] = 0;
  //   		}
  //   	}

  //   	for(int i = n - 2; i >= 0; i--){

  //   		for(int j = 1; j <= n; j++){

  //   			if(i > j) continue;

  //   			if(isPalindrome(i + 1, j)){

  //   				dp[i][j] += dp[i + 1][j];
  //   			}

  //   			if(isPalindrome(i, j - 1)){

  //   				dp[i][j] += dp[i][j - 1];
  //   			}

  //   			//dp[i][j] = mod_add(dp[i][j], mod_add(dp[i][j - 1], dp[i + 1][j], MOD), MOD);
  //   		}
  //   	}


  //   	for(int i = 0; i <= n; i++){

  //   		for(int j = 0; j <= n; j++){

  //   			cout << dp[i][j] << " ";
  //   		}
  //   		cout << endl;
  //   	}

  //   	ll ans = dp[0][n - 1];

		// ll val = mod_div(ans, fact[n], MOD);
		// cout << val << endl;
    	

    }
    return 0;
}