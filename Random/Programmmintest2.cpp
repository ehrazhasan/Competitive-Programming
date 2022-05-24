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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, e;
    cin >> n >> e;

    vector<vector<ll> > adj_graph(n + 1, vector<ll> (n + 1, INF));

    for(int i = 1; i <= n; i++){

    	adj_graph[i][i] = 0;
    }

    rep(i,e){

    	ll u, v, wt;
    	cin >> u >> v >> wt;

    	adj_graph[u][v] = wt;
    }



    vector<vector<ll> > dist(n + 1, vector<ll> (n + 1, INF));
    for(int i = 0; i <= n; i++){

    	for(int j = 0; j <= n; j++){

    		dist[i][j] = adj_graph[i][j];
    	}
    }


    // repA(i,1,n){

    // 	repA(j,1,n){

    // 		cout << dist[i][j] << " ";
    // 	}

    // 	cout << endl;
    // }

    for(int i = 1; i <= n; i++){

    	for(int s = 1; s <= n; s++){

    		for(int d = 1; d <= n; d++){

    			if(dist[s][d] > dist[s][i] + dist[i][d] and dist[s][i] != INF and dist[i][d] != INF){

    				dist[s][d] = dist[s][i] + dist[i][d];
    			}
    		}
    	}
    }

    vector<ll> ans(n + 1);
    for(int v = 1; v <= n; v++){

    	ans[v] = INF;
    	for(int i = 1; i <= n; i++){

    		if(v != i){

    			if(dist[i][v] == INF) {

    				//db2(i,v);
    				ans[v] = INF;
    				break;
    			}
    			ans[v] = min(dist[i][v],ans[v]);
    		}
    	}
    }

    // cout << endl;
    //  repA(i,1,n){

    // 	repA(j,1,n){

    // 		cout << dist[i][j] << " ";
    // 	}

    // 	cout << endl;
    // }

    bool gotit = false;
    int node = -1;
    ll val = INF;
    for(int i = 1; i <= n; i++){

    	if(ans[i] != INF){

    		gotit = true;
    		if(val > ans[i]){

    			val = ans[i];
    			node = i;
    		}
    	}
    }


    if(!gotit) node = -1;

    cout << node << endl;
    return 0;
}