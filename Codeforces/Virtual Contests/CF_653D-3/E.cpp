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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
      
      	ll n, k;
      	cin >> n >> k;

      	vector<ll> _11, _10, _01; 

      	rep(i,n){

      		ll s, a, b;
      		cin >> s >> a >> b;

            if(a == 0 and b == 0) continue;

            if(a == 1 and b == 1) _11.push_back(s);
            if(a == 1 and b == 0) _10.push_back(s);
            if(a == 0 and b == 1) _01.push_back(s);
       	}

        sort(all(_11));
        sort(all(_10));
        sort(all(_01));

        // If we take cnt 11s then we have to select k - cnt from 01s and 10s
        // if i can't take k - cnt then -1 for any cnt

        ll ans = INF;

        vector<ll> pref11(_11.size()), pref10(_10.size()), pref01(_01.size());

        if(_11.size() > 0)
            pref11[0] = _11[0];

        for(int i = 1; i < _11.size(); i++) pref11[i] = pref11[i - 1] + _11[i];

        if(_10.size() > 0)
            pref10[0] = _10[0];


        // for(auto it : pref11) cout << it << " ";
        // cout << endl;



        for(int i = 1; i < _10.size(); i++) pref10[i] = pref10[i - 1] + _10[i];

        // for(auto it : pref10) cout << it << " ";
        // cout << endl;

        if(_01.size() > 0)
            pref01[0] = _01[0];

        for(int i = 1; i < _01.size(); i++) pref01[i] = pref01[i - 1] + _01[i];

        // for(auto it : pref01) cout << it << " ";
        // cout << endl;

        for(ll cnt = 0; cnt <= min(k,(ll)_11.size()); cnt++){

            ll sum = 0;
            if(cnt > 0) sum = pref11[cnt - 1];

           // db2(cnt,sum);

            ll toTake = k - cnt;

            if(toTake > _10.size() or toTake > _01.size()){

                continue;
            }


            ll sum1 = toTake - 1 >= 0 ? pref10[toTake - 1] : 0;
            ll sum2 = toTake - 1 >= 0 ? pref01[toTake - 1] : 0;
 
            ll val = sum + sum1 + sum2;
            //db1(val);
            ans = min(ans,val);

        }

        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}