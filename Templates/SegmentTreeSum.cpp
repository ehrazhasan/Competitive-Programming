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


//Associative Property

struct Node{

	ll inv = 0;
	vector<ll> freq = vector<ll> (40, 0);

	void clear(){

		inv = 0;
		freq = vector<ll> (40, 0);
	}

	void merge(const Node &l, const Node&r){

		inv = l.inv + r.inv;

		for(int i = 39; i >= 0; i--){

			for(int j = 0; j < i; j++){

				inv += l.freq[i] * r.freq[j];
			}

			freq[i] = l.freq[i] + r.freq[i]; 
		}
	}

};



const int N = 2e5 + 5;
Node tree[4 * N + 1];



// vertex = 1, treeLeft = 0, treeRight = N - 1


void build(int vertex, int treeLeft, int treeRight, vector<ll> &a){

	if(treeLeft == treeRight){

		tree[vertex].inv = 0;
		tree[vertex].freq[a[treeRight]] = 1;
		return;
	}

	int mid = (treeLeft + treeRight) >> 1;

	build(2 * vertex, treeLeft, mid, a);
	build(2 * vertex + 1, mid + 1, treeRight, a);
	tree[vertex].merge(tree[2 * vertex], tree[2 * vertex + 1]);
}


void update(int vertex, int treeLeft, int treeRight, ll value, int index){

	if(index == treeLeft and index == treeRight){
		// I am at the correct index where the value has to be updated
		tree[vertex].inv = 0;
		tree[vertex].freq = vector<ll>(40, 0);
		tree[vertex].freq[value] = 1;
		return;
	}

	//update index is out of range
	if(treeLeft > index or treeRight < index){
		return;
	}



	int mid = (treeLeft + treeRight) >> 1;
	update(2 * vertex, treeLeft, mid, value, index);
	update(2 * vertex + 1, mid + 1, treeRight, value, index);
	tree[vertex].merge(tree[2 * vertex], tree[2 * vertex + 1]);
}


Node query(int vertex, int treeLeft, int treeRight, int qLeft, int qRight){

	//Complete Overlap  
	if(qLeft <= treeLeft and qRight >= treeRight){
		return tree[vertex];
	}

	//No Overlap
	if(qRight < treeLeft or qLeft > treeRight){
		return Node();
	}

	//Partial Overlap
	int mid = (treeLeft + treeRight) >> 1;

	Node ans;
	Node leftSum = query(2 * vertex, treeLeft, mid, qLeft, qRight);
	Node rightSum = query(2 * vertex + 1, mid + 1, treeRight, qLeft, qRight);
	ans.merge(leftSum, rightSum);

	return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    
    //cin>>t;
    while(t--){
      	
      	ll n, m;
        cin >> n >> m;

        for(int i = 0; i < 4*n + 1; i++) tree[i].clear();

        vector<ll> a(n);
        rep(i, n) {
        	cin >> a[i];
        	--a[i];
        }

        build(1, 0, n - 1, a);

        rep(i, m){

        	int type;
        	cin >> type;

        	if(type == 1){

        		ll x, y;
        		cin >> x >> y;

        		cout << query(1, 0, n - 1, x - 1, y - 1).inv << endl;
        	}
        	else{

        		ll x, y;
        		cin >> x >> y;

        		update(1, 0, n - 1, y - 1, x - 1);
        	}
        }
      	 
    }
    return 0;
}