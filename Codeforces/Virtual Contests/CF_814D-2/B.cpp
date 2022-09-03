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
	
	4 8 12 12 16 20 24
	4 3) 8 7) 12 11)  1 2)  5 6)  9 10)	13 14)


*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        ll n, k;
        cin >> n >> k;

       	ll pairs = n / 2;

       	set<ll> st;
       	for(ll i = 1; i <= n; i++) st.insert(i);

       	ll a = 4;
       	vector<ll> aa, bb;
       	ll cnt = 0;
       	while(a <= n){

       		aa.push_back(a);
       		st.erase(a);
       		a += 4;
       		cnt++;
       	}

       	ll left = pairs - cnt;
       	a = k / 4 * 4;

       	while(left and a - k <= n){

       		if(st.find(a - k) != st.end()){
       			st.erase(a - k);
       			bb.push_back(a - k);
       			left--;
       		}
       		a += 4;
       	}


       	for(auto it : aa) cout << it << " ";
       	cout << endl;
       	for(auto it : bb) cout << it << " ";
       	cout << endl;
       	for(auto it : st) cout << it << " ";
       	cout << endl;

       	vector<pair<ll, ll>> ans;
        bool okay = true;
       	for(auto it : aa){

       		if(st.empty()) {
       			okay = false;
       			break;
       		}
       		ans.push_back(make_pair(*st.begin(), it));
       		st.erase(st.begin());
       	}

       	for(auto it : bb){

       		if(st.empty()) {
       			okay = false;
       			break;
       		}
       		ans.push_back(make_pair(it, *st.begin()));
       		st.erase(st.begin());
       	}

        while(st.size() >= 2){

            auto it = st.begin();
            auto it1 = next(it);

            if(((*it + k) * *it1) % 4 == 0){

                ans.push_back({*it, *it1});
                st.erase(it);
                st.erase(it1);
            }  
            else if(((*it1 + k) * *it) % 4 == 0){

                ans.push_back({*it1, *it});
                st.erase(it);
                st.erase(it1);
            }
            else break;

        }

        //db1(st.size());
       	if((!okay or !st.empty() or ans.size() != n / 2)){

       		cout << "NO\n";
       		continue;
       	}


       	cout << "YES\n";
       	for(auto it : ans){

       		cout << it.first << " " << it.second << endl;

       	}
    }
    return 0;
}