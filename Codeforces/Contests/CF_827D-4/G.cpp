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
        vector<ll> a(n);
        rep(i, n) cin >> a[i];


        multiset<ll, greater<ll>> st;
        for(auto it : a) st.insert(it);

        sort(all(a), greater<ll>());	
        ll x = a[0];
        st.erase(st.lower_bound(x));
        cout << x << " ";

        int max_bit = log2(x);

        int i = 1;
        for(int bit = max_bit; bit >= 0; bit--){

        	if(x >> bit & 1LL) continue;

        	while(i < n){

        		if(a[i] >> bit & 1LL) break;
        		i++;
        	}

        	if(i >= n) break;


        	st.erase(st.lower_bound(a[i]));
        	x |= a[i];
        	cout << a[i] << " ";
        	i++;
        }	

        for(auto it : st) cout << it << " ";
        cout << endl;

     /////////////////////////////////////////////////////////////////
     //    set<ll> b[32];

     //    for(int bit = 31; bit >= 0; bit--){

    	// 	for(int i = 0; i < n; i++){

    	// 		if(a[i] >> bit & 1LL) {

    	// 			b[bit].insert(a[i]);
    	// 		}
    	// 	}
    	// }

    	

     //    multiset<ll> st;
     //    for(auto it : a) st.insert(it);

     //    ll mx = *max_element(all(a));

    	// st.erase(st.lower_bound(mx));

    	// for(int i = 31; i >= 0; i--){

    	// 	if(mx >> i & 1LL){

    	// 		b[i].erase(mx);
    	// 	}
    	// }

    	// vector<ll> ans(n);
    	// ans[0] = mx;
    	// ll x = mx;

    	// int maxBit = log2(x);


    	
    	// // for(int i = 0; i < 31; i++){

    	// // 	cout << i << ": ";
    	// // 	for(auto it : b[i]) cout << it << " ";
    	// // 	cout << endl;
    	// // }

    	// cout << x << " ";
    	// for(int bit = 31; bit >= 0; bit--){

    	// 	if(x >> bit & 1LL) continue;
    	// 	if(sz(b[bit]) == 0) continue;

    	// 	ll val = *b[bit].rbegin();
    	// 	cout << val << " ";
    		
    	// 	st.erase(st.lower_bound(val));

    	// 	for(int bb = 31; bb >= 0; bb--){

    	// 		if(val >> bb & 1LL){

    	// 			b[bb].erase(val);
    	// 		}
    	// 	}

    	// 	x |= val;
    	// }


    	// for(auto it : st) cout << it << " ";
    	// cout << endl;
    	// //db1(x);
    }

    return 0;
}