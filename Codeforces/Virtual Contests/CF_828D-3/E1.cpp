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

void bruteForce(){

	int n = 10;

	for(int a = 1; a <= n; a++){

		for(int b = 1; b <= n; b++){

			for(int c = 1; c <= n; c++){

				for(int d = 1; d <= n; d++){

					if(a < c and b < d){

						for(int x = a + 1; x <= c; x++){

							for(int y = b + 1; y <= d; y++){

								if((x * y) % (a * b) == 0){

									db2(a, b);
									db2(c, d);
									db2(x, y);
									cout << endl;
								}
							}
						}
					}
				}
			}
		}
	}
}

const ll N = 1e5 + 5;
vector<ll> prime(N + 1, 1);
vector<ll> countPrimes(N + 1, 0);
vector<ll> fprime(N + 1); //smallest prime factor
void isPrime(){

    ll c = 0;
    for (ll p = 2; p * p <= N; p++)

        if (prime[p] == 1){

        	fprime[p] = p;

            for (ll i = p * 2; i <= N; i += p){
            
                prime[i] = 0;
                if(fprime[i] == 0){
                	fprime[i] = p;
                }
            }
        }


    for(ll p = 2; p <= N; p++) if(prime[p]) fprime[p] = p;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    isPrime();
    int t;
    cin>>t;
    while(t--){
       	
       	ll a, b, c, d;
       	cin >> a >> b >> c >> d;


       	if(a == 1 and b == 1){
       		cout << "2 2" << endl;
       		continue;
       	}

       	vector<ll> ff;
       	ll num = a;

       	while(num > 1 and fprime[num] != num){
       		
       		ff.push_back(fprime[num]);
       		num /= fprime[num];
       	}

       	if(num > 1)
       		ff.push_back(fprime[num]);

       	num = b;
       	while(num > 1 and fprime[num] != num){
       		
       		ff.push_back(fprime[num]);
       		num /= fprime[num];
       	}

       	if(num > 1)
       		ff.push_back(fprime[num]);

       	sort(all(ff));

       	map<ll, ll> freq;

       	for(auto it : ff) freq[it]++;

       	// for(auto it : ff) cout << it << " ";
       	// cout << endl;

       	bool okay = false;
       	for(ll x = a + 1; x <= c; x++){

       		map<ll, ll> freqq = freq;
       		map<ll, ll> currFreq;

       		ll num = x;
       		while(fprime[num] != num){
       		
	       		currFreq[fprime[num]]++;
	       		num /= fprime[num];
	       	}

	       	currFreq[fprime[num]]++;

	       	for(auto it : currFreq){

	       		ll val = it.first;
	       		ll f = it.second;

	       		if(!freqq[val] or !f){
	       			continue;
	       		}

	       		freqq[val] = max(freqq[val] - f, 0LL);
	       	}

	       	ll p = 1LL;

	       	for(auto it : freqq){

	       		if(it.second > 0){

	       			ll times = it.second;
	       			while(times--){

	       				p *= it.first;
	       			}
	       		}
	       	}

	       	//db1(p);
	       	// p = max(b, p);
	       	// while(p <= d){

	       	// 	if(p > b){
		       // 		okay = true;
		       // 		cout << x << " " << p << endl;
		       // 		break;
		       // 	}

		       // 	p *= 2;
	       	// }
	       	
	       	if(d - (d % p) <= b) continue;

	       	cout << x << " " << d - (d % p) <<  endl;
	       	okay = true;
	       	break;
	       	db2(x, p);
       	}

       	if(!okay){
       		cout << "-1 -1" << endl;
       	}


    }
    return 0;
}