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

/*

	The numbers lie between [-2, 2]

	The minimum best answer is 1 by removing all the elements from the array

	This means we do no need zeros and odd number of negative elements in our answer

	Now we need to find the subarray that contains positive and even number of negative elements such
	that the product is maximum

	We can find the product between the zero indices
	If the segment product is positive -> no problem
	If the segment product is negative -> remove one negative element
	
	How do we maintain the product of subarray?

	Our answer will either be 1 or power of two.
	We can simply just count the number of abs(2)


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

    	vector<ll> v(n);
    	rep(i, n) cin >> v[i];

    	deque<int> zeroInd, negInd;
    	for(int i = 0; i < n; i++){

    		if(v[i] == 0) zeroInd.push_back(i);
    		if(v[i] < 0) negInd.push_back(i);
    	}

    	negInd.push_front(-1);


    	vector<vector<ll>> cs(5LL, vector<ll>(n + 1));

    	for(int i = 0; i < 5; i++){

    		for(int j = 0; j < n; j++){

    			if(j == 0){

    				cs[i][j] = (v[j] == i - 2 ? 1LL : 0LL);
    				continue;
    			}

    			cs[i][j] = cs[i][j - 1] + (v[j] == i - 2 ? 1LL : 0LL);
    		}
    	}

    	auto getEval = [&](ll l, ll r){

    		ll res = cs[2][r] - (l - 1 >= 0 ? cs[2][l - 1] : 0LL);
    		if(res > 0) return 0LL;

    		res = cs[0][r] - (l - 1 >= 0 ? cs[0][l - 1] : 0LL) + 
    			  cs[1][r] - (l - 1 >= 0 ? cs[1][l - 1] : 0LL);

    		if(res % 2) return -1LL;

    		res = cs[4][r] - (l - 1 >= 0 ? cs[4][l - 1] : 0LL) + 
    			  cs[0][r] - (l - 1 >= 0 ? cs[0][l - 1] : 0LL);

    		return res;
    	}; 

    	// for(int k : {0, 1, 2, 3, 4}){

    	// 	for(int i = 0; i < n; i++){

    	// 		cout << cs[k][i] << " ";
    	// 	}
    	// 	cout << endl;
    	// }
    	// db1(getEval(0, 2));

    	ll x = 0, y = -1;
    	ll ans = 0;

    	for(ll left = 0; left < n; left++){
    		
    		if(v[left] == 0) continue;

    		auto it = lower_bound(all(zeroInd), left);

    		ll nextZero;

    		if(it == zeroInd.end()) nextZero = n;
    		else nextZero = zeroInd[it - zeroInd.begin()];

    		ll right = nextZero - 1;



    		ll stats = getEval(left, right);
    		//db3(left, right, stats);
    		if(stats == 0){

    			continue;
    		}
    		else if(stats == -1){

    			// remove the last negative element

				auto it1 = lower_bound(all(negInd), nextZero);

				it1 = prev(it1);

				ll nextNeg = negInd[it1 - negInd.begin()];
				//db1(nextNeg);
				if(nextNeg <= right and nextNeg >= left){

					if(left == nextNeg) continue;

					ll val = getEval(left, nextNeg - 1);
					//db1(val);
					if(val > ans){

						ans = val;
						x = left;
						y = nextNeg - 1;
					}
				}

    		}
    		else{

    			if(stats > ans){

    				ans = stats;
    				x = left;
    				y = right;
    			}
    		}
    	//	db2(x, y);
    	}

    	cout << x << " " << n - y - 1 << endl;
    }
    return 0;
}