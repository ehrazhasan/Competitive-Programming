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
        
        ll x, y;
        cin >> x >> y;
        
        ll a = 2;
        ll b = x ^ a;
        ll c = y ^ b;

        int cnt = 0;
        if(a % 2 == 0) cnt++;
        if(b % 2 == 0) cnt++;
        if(c % 2 == 0) cnt++;

        if(cnt == 1){

            cout << 2 << " " << min(b, c) << " " << max(b, c) << endl;
            continue;
        }


        b = 2;
        a = x ^ b;
        c = y ^ b;

        cnt = 0;
        if(a % 2 == 0) cnt++;
        if(b % 2 == 0) cnt++;
        if(c % 2 == 0) cnt++;

        if(cnt == 1){

            cout << 2 << " " << min(a, c) << " " << max(a, c) << endl;
            continue;
        }


        c = 2;
        b = y ^ b;
        a = x ^ b;

        cnt = 0;
        if(a % 2 == 0) cnt++;
        if(b % 2 == 0) cnt++;
        if(c % 2 == 0) cnt++;

        if(cnt == 1){

            cout << 2 << " " << min(a, b) << " " << max(a, b) << endl;
            continue;
        }

        // if(x % 2 == 0){

        //     ll a = x < 5 ? 3 : 5;
        //     ll b = a ^ x;
        //     ll c = y ^ b;

        //     vector<ll> v = {a, b, c};
        //     sort(all(v));

        //     cout << v[0]  << " "  << v[1] << " " << v[2] << endl;
        // }
        // else{

        //     ll a = 2;
        //     ll b = x ^ a;
        //     ll c;

        //     if(y % 2) c = y ^ a;
        //     else c = y ^ b;



        //     vector<ll> v = {a, b, c};
        //     sort(all(v));

        //     cout << v[0]  << " "  << v[1] << " " << v[2] << endl;
        // }

        // int cnt = 100;
        // for(int i = 2; i < cnt; i++){

        //     for(int j = 2; j < cnt; j++){

        //         for(int k = 2; k < cnt; k++){

        //             if(i == j or j == k or i == k) continue;

        //             int a1 = (i ^ j);
        //             int a2 = (j ^ k);
                    

        //             if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //                 db3(i, j, k);
        //             }

        //             // a1 = (i ^ k);
        //             // a2 = (k ^ j);
                   

        //             // if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //             //     db3(i, j, k);
        //             // }


        //             // a1 = (j ^ i);
        //             // a2 = (i ^ k);
                   

        //             // if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //             //     db3(i, j, k);
        //             // }

        //             // a1 = (j ^ k);
        //             // a2 = (k ^ i);
                   

        //             // if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //             //     db3(i, j, k);
        //             // }

        //             // a1 = (k ^ i);
        //             // a2 = (i ^ j);
                   

        //             // if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //             //     db3(i, j, k);
        //             // }

        //             // a1 = (k ^ j);
        //             // a2 = (j ^ i);
                   

        //             // if((a1 == x and a2 == y) or (a1 == y and a2 == x)){

        //             //     db3(i, j, k);
        //             // }
        //         }
        //     }
        // }
        // cout << endl;
    }
    return 0;
}