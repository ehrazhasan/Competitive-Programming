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
#define MOD1 = 998244353;
double eps = 1e-12;
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define PI 3.141592653589793238462
#define total_set_bits __builtin_popcountll


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
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
/*vector<ll> prime(10000000, 1);
vector<ll> ans(10000000, 0);
void isPrime()
{

    ll c = 0;
    for (ll p = 2; p * p <= 10000000; p++)

        if (prime[p] == 1)

            for (ll i = p * 2; i <= 10000000; i += p)
            {
                prime[i] = 0;
            }

    for (ll p = 2; p <= 10000000; p++)
    {
        ans[p] = ans[p - 1] + prime[p];
    }
}
*/                    
                /*******************************************************************************/



/*

	n universities (1...n)

	n students
	ith student : 
	belongs to ui university 
	and has si skill

	strength of region : total skill of the members
						 currently present in the teams
		
	
	k : k students per team from a university

	For each k (1...n) find the total strength



	k = 4;
	
	u1 -> 1    teams -> 0  students -> 0
 	u2 -> 9    teams -> 2  students -> 8 -> s1, s1 + s2, s1 + s2 + s3,....
	u3 -> 12   teams -> 3  students -> 3*4 = 12
	u4 -> 3    teams -> 0  students -> 0

	We can create a prefix sum array to get the sum faster

	
    k = 1 ... n



*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
     	
     	ll n;
     	cin >> n;

     	map<ll,ll> m;
     	vector<ll> u(n),s(n);
     	rep(i,n) {
     		cin >> u[i];
     		m[u[i]]++;
     	}
     	rep(i,n) cin >> s[i];

     	ll maxfreq = 0LL;
     	for(auto it : m){

     		maxfreq = max(maxfreq,it.second);

     	}

     
     	map<ll,vector<ll>> p;

     	for(int i = 0; i < n; i++){

     		p[u[i]].push_back(s[i]);
     	}

     	for(auto it : p){

     		sort(all(p[it.first]),greater<ll>());
   
     	}


     	
     	vector<ll> v[n + 1];

     	for(auto it : p){

     		ll a = it.first;

     		v[a].assign(p[a].size(),0LL);
     		v[a][0] = p[a][0];
     		for(int i = 1; i < p[a].size(); i++){

     			v[a][i] = v[a][i - 1] + p[a][i];
     		}
     	}

     	vector<ll> div(n + 1,0);

     	for(int i = 1; i <= n; i++){	

     		ll c = 1;

     		for(int j = 0; j < v[i].size(); j++){

     			
     			ll ind = v[i].size() / c * c;
     			ind -= 1;

     			div[c] += v[i][ind];
     			c++; 

     		}


     	}

     

     	for(ll k = 1; k <= n; k++){	

     		cout << div[k] << " ";
     	}
     	cout << endl;
    }
    return 0;
}