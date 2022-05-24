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
const int N = 2e5 + 5, LOG = 26;
vector<ll> edges[N];
ll par[N][LOG + 1]; // for the Nth Node, 2^LOGth ancestor
vector<ll> depth, sz;
// vector<int> discoveryInTime, discoveryOutTime;
ll dp[N][26];
string s;


void dfs(int node, int p = 1){

	par[node][0] = p;
	// sz[node] = 1;
	depth[node] = depth[p] + 1;
	// discoveryInTime[node]++;
	char ch = s[node - 1];
	rep(i, 26) dp[node][i] = dp[p][i];
	dp[node][ch - 'a'] += 1;


	for(int i = 1; i <= LOG; i++) par[node][i] = par[par[node][i - 1]][i - 1];

	for(int nbr : edges[node]){

		if(nbr == p) continue;

		dfs(nbr, node);

		// sz[node] += sz[nbr];
	}

	// discoveryOutTime[node]++;
}

int kthAncestor(int node, int k){

	
	for(int i = 0; i <= LOG; i++){

		if(k & (1 << i)){

			node = par[node][i];
		}
	}

	return node;
}

// bool isAncesstor(int u, int v){

// 	return discoveryInTime[u] <= discoveryInTime[v] and discoveryOutTime[u] >= discoveryOutTime[v];
// }

int LCA(int u, int v){

	if(depth[u] < depth[v]) swap(u, v);

	int k = depth[u] - depth[v];
	u = kthAncestor(u, k);

	if(u == v) return u;

	for(int i = LOG; i >= 0; i--){

		if(par[u][i] != par[v][i]){

			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

// int distUtoV(int u, int v){

// 	return depth[u] + depth[v] - (depth[LCA(u, v)] << 1);
// }

// int kthNodeFromUtoV(int u, int v, int k){

// 	if(distUtoV(u, v) < k) return -1;

// 	int lca = LCA(u, v);

// 	if(depth[lca] + k <= depth[u]) return kthAncestor(u, k);

// 	k -= depth[u] - depth[lca];

// 	return kthAncestor(v, depth[v] - depth[lca] - k);
// }



void preprocess(int n, int node){

	depth.assign(n + 1, 0);

	// sz.assign(n + 1, 0);
	// discoveryInTime.assign(n + 1, 0);
	// discoveryOutTime.assign(n + 1, 0);

	
	dfs(node);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin >> n >> s;

        for(int i = 0; i <= n; i++){

			edges[i].clear();
			for(int j = 0; j < 26; j++){

				dp[i][j] = 0;
				par[i][j] = 0;
			}
		}	


        rep(i, n - 1){

        	int u, v;
        	cin >> u >> v;
        	edges[u].push_back(v);
        	edges[v].push_back(u);
        }



        preprocess(n, 1);

        
        int q;
        cin >> q;

       
        rep(i, q){

        	int u, v;
        	cin >> u >> v;

        	bool okay = false;

        	int lca = LCA(u, v);

        	for(int a = 0; a <= 25; a++){

        		int a1 = dp[u][a] - dp[lca][a];
        		int a2 = dp[v][a] - dp[lca][a];

        		if(a1 > 0 and a2 > 0){

        			okay = true;
        			break;
        		}

        	}

        	cout << (okay ? "YES\n" : "NO\n");
        }
    }
    return 0;
}