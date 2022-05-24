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
#define repA(i,a,n) for(int i=a;i<=(n);++i)/
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

bool isPossible(vector<pair<ll,int>> &A, ll val){

	if(val == A[A.size()-1].first) return true;
	ll power = val;
	for(int i = 0; i < A.size() - 1; i++){

		if(A[i].first <= power){

			power += (ll)A[i].second;
			if(power >= A[A.size()-1].first) return true;
		}
		else{
			return false;
		}
	}

	if(power >= A[A.size()-1].first) return true;
	else return false;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        int caves; cin >> caves;

        vector<pair<ll,int>> minPower;
        while(caves--){

        	int m; cin >> m;
        	vector<int> armor(m);
        	int cnt  = 0;
        	//ll minVal = 0;
        	rep(i,m)
        		cin >> armor[i];
        	// 	if(minVal == 0){
        	// 		minVal += armor[i] + 1;
        	// 	}
        	// 	else{

        	// 		if(minVal <= armor[i]){

        	// 			minVal = (ll)armor[i] + 1LL - (ll)cnt;
        	// 			if(minVal == armor[i]) minVal += 1LL;
        	// 		}
        	// 	}

        	// 	cnt++;
        	// 	db1(minVal);
        	// } 

        	ll minVal = (ll)armor[m-1] + 1LL;
        	for(int i = m-2; i >= 0; i--){

        		if(armor[i] >= minVal){

        			minVal = (ll)armor[i] + 1LL;
        		}
        		else{
        			minVal -= 1LL;
        			if(minVal == armor[i]){
        				minVal += 1LL;
        			}
        		}

        	}

        	minPower.push_back({minVal,m});
        }
 
        sort(all(minPower));

        ll s = minPower[0].first;
        ll e = minPower[minPower.size() - 1].first;
        ll ans = s;
        while(s <= e){

        	ll mid = (e - s)/2 + s;
        	//db3(s,e,mid);
        	if(isPossible(minPower,mid)){

        		ans = mid;
        		//db1(ans);
        		e = mid - 1;
        	}
        	else{
        		s = mid + 1;
        	}
        }
        // for(auto it : minPower) cout << it.first << " ";

        // cout << endl;

    	cout << ans << endl;
    }
    return 0;
}