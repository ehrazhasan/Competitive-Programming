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

const int N = 2e5 + 5;
ll tree[4 * N + 1];
bool lazy[4 * N + 1]; // denotes whether the vertex is currently holding the unpropagated value
ll lazyUpd[4 * N + 1]; // stores the values of the unpropagated vertex

// vertex = 1, treeLeft = 0, treeRight = N - 1

void build(int vertex, int treeLeft, int treeRight, vector<ll> &a){

    if(treeLeft == treeRight){

        tree[vertex] = a[treeRight];
        return;
    }

    int mid = (treeLeft + treeRight) >> 1;

    build(2 * vertex, treeLeft, mid, a);
    build(2 * vertex + 1, mid + 1, treeRight, a);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}


//this function is the process of telling the man to remember the value
void apply(int vertex, int treeLeft, int treeRight, ll value){ 

    int range = treeRight - treeLeft + 1;
    tree[vertex] += value * range;

    if(treeLeft != treeRight){
        // we are not at the leaf vertex

        lazy[vertex] = 1;
        lazyUpd[vertex] += value;
    } 
}

//propagating the unpropagated value to its children
void pushdown(int vertex, int treeLeft, int treeRight){

    if(lazy[vertex]){

        lazy[vertex] = 0;

        int mid = (treeLeft + treeRight) >> 1;

        apply(2 * vertex, treeLeft, mid, lazyUpd[vertex]);
        apply(2 * vertex + 1, mid + 1, treeRight, lazyUpd[vertex]);

        lazyUpd[vertex] = 0;
    }
}

void update(int vertex, int treeLeft, int treeRight, ll value, int index){

    if(index == treeLeft and index == treeRight){
        // I am at the correct index where the value has to be updated
        // ask this vertex to remember it
        apply(vertex, treeLeft, treeRight, value);
        return;
    }

    //update index is out of range
    if(treeLeft > index or treeRight < index){
        return;
    }

    //Since we are moving down, the children needs to have correct information
    pushdown(vertex, treeLeft, treeRight);

    int mid = (treeLeft + treeRight) >> 1;
    update(2 * vertex, treeLeft, mid, value, index);
    update(2 * vertex + 1, mid + 1, treeRight, value, index);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}


ll query(int vertex, int treeLeft, int treeRight, int qLeft, int qRight){

    //Complete Overlap  
    if(qLeft <= treeLeft and qRight >= treeRight){
        return tree[vertex];
    }

    //No Overlap
    if(qRight < treeLeft or qLeft > treeRight){
        return 0;
    }

    //Partial Overlap

    //Since we are moving down, the children needs to have correct information
    pushdown(vertex, treeLeft, treeRight);

    int mid = (treeLeft + treeRight) >> 1;
    ll leftSum = query(2 * vertex, treeLeft, mid, qLeft, qRight);
    ll rightSum = query(2 * vertex + 1, mid + 1, treeRight, qLeft, qRight);
    return leftSum + rightSum;
}

int findKth(int vertex, int treeLeft, int treeRight, int k) {
    if (k > tree[vertex])
        return -1;
    if (treeLeft == treeRight)
        return treeLeft;

    int mid = (treeLeft + treeRight) >> 1;

    if (tree[2 * vertex] >= k)
        return findKth(2 * vertex, treeLeft, mid, k);
    else 
        return findKth(2 * vertex + 1, mid + 1, treeRight, k - tree[2 * vertex]);
}


// ll a[N];
// segtree<Node, Update> sgt(n);
// sgt.build(a);
vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
    
    int n = (int)nums.size();
    segtree<Node, Update> sgt(n);
    sgt.build(nums);        

    vector<long long> ans(n, 0);

    int l = 0;
    int r = n - 1;
    
    for(int i = 0; i < n; i++){

        int it = removeQueries[i];
        sgt.rupd(it, it, 0LL);

        int l1 = 0;
        int r1 = max(0, it - 1);
        int l2 = min(it + 1, n - 1);
        int r2 = n - 1;

        int val1 = sgt.query(l1, r1).sum;
        int val2 = sgt.query(l2, r2).sum;

        if(val1 > val2)

        ans[i] = sgt.query(0, n - 1).sum;
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        
          int n; cin >> n;

          vector<int> nums(n);
          rep(i, n) cin >> nums[i];

          vector<int> removeQueries(n);
          rep(i, n) cin >> removeQueries[i];

          vector<ll> ans = maximumSegmentSum(nums, removeQueries);
          for(auto it : ans) cout << it << " ";
    }
    return 0;
}