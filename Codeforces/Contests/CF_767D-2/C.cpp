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

 -> Array B: lexicographically maximum array by finding the mex of 
    first K numbers of the array

    MEX : minimum number excluded from the array

    1 24 0 12 2 4 -> 3

    k = 1 -> 0
    k = 2 -> 0
    k = 3 -> 2
    k = 4 -> 2
    k = 5 -> 3
    k = 6 -> 3

    NOTE 1:  MEX of first k numbers never exceed the MEX of the array
    NOTE 2:  MEX never decrease on including more elements,
             it either stays the same or may increase

    B : 3 0


    EX : 2

    0 1 1 0 -> 2

    k = 1 -> 1
    k = 2 -> 2
    k = 3 -> 2
    k = 4 -> 2

    B : 2 2


    EX : 3

    0 0 2 1 1 1 0 0 1 1 -> 3

    k = 1  -> 1
    k = 2  -> 1
    k = 3  -> 1
    k = 4  -> 3
    k = 5  -> 3
    k = 6  -> 3
    k = 7  -> 3
    k = 8  -> 3
    k = 9  -> 3
    k = 9  -> 3
    k = 10 -> 3
 
    B : 3 2 2 0 


    Algorithm : 
    First I will find the mex of the array
    Find the first position that matches with the mex of the remaining array
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
        map<ll,ll> m;
        rep(i,n){

        	cin >> v[i];
        	m[v[i]]++;
        }

        vector<ll> position[n + 1];

        for(ll i = 0; i < n; i++){

            position[v[i]].push_back(i + 1);
        }

        
        ll mex = 0;
        while(m[mex]) mex++;


        vector<ll> ans;
        ll pos = 1;

        while(pos <= n){

            ll temp_pos = pos;
            for(ll curr_mex = 0;; curr_mex++){


                //db1(curr_mex);
                auto it = lower_bound(all(position[curr_mex]),pos);

                if(it != position[curr_mex].end()){

                    ll index = it - position[curr_mex].begin();

                    //db1(position[curr_mex][index]);
                    temp_pos = max(temp_pos,position[curr_mex][index]);  
                }
                else{

                    ans.push_back(curr_mex);
                    break;
                }

                


            }

            pos = temp_pos + 1;
        }

        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";

        cout << endl;
    }
    return 0;
}