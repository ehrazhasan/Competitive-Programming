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

const int N = 1e5 + 5;
 
// example: addition: identity element is 0
 
struct Node
{
    ll value = 0, sum = 0, pref = 0, suff = 0, ans = 0;

    // use more variables if you want more information
    // these default values should be identity_element
    Node(){}
    Node(ll val){
        value = val;
        sum = val;
        pref = val;
        suff = val;
        ans = max(0LL, val);
    }
    void merge(const Node &l,const Node &r){ // store the thing you wanna query
 
        sum = l.sum + r.sum;
        pref = max(l.pref, l.sum + r.pref);
        suff = max(r.suff, r.sum + l.suff);
        ans = max({l.ans, r.ans, l.suff + r.pref});
    }

    bool check(ll x){

        //write the condition for the true case
        return false;
    }
};
 
// example: add on a range: identity transformation = 0
// old += new
 
// if old is identity which is 0, then 0 + new which new
 
struct Update
{
    ll v = 0; // 4
    // use more variables if you want more information
    // these default values should be identity_transformation
    Update(){}
    Update(ll val){
        v = val; // 5
    }
    // combine the current Update with the other Update (see keynotes)
    void combine(Update &other,const int32_t &tl,const int32_t &tr){
        
        v = other.v; // 6
        // you can be sure that the "other" is newer than current
 
    }
    // store the correct information in the Node x
    void apply(Node &x,const int32_t &tl,const int32_t &tr){

        //How is entire range going to change
        //x.sum = max(x.sum, x.sum + v); 
        x.sum = v;
        x.pref = v;
        x.suff = v;
        x.ans = max(0LL, v);
    }
};
 
template<typename node,typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<int> treeLeft, treeRight;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        treeLeft.resize(4 * len);
        treeRight.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
 
    void pushdown(const int32_t &v){
        if(!lazy[v]) return;
        
        apply(v<<1,u[v]);
        apply(v<<1|1,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
 
    void apply(const int32_t &v, update upd){
        if(treeLeft[v] != treeRight[v]){
            lazy[v] = 1;
            u[v].combine(upd,treeLeft[v],treeRight[v]);
        }
        upd.apply(t[v],treeLeft[v],treeRight[v]);
    }
 
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){

        treeLeft[v] = tl;
        treeRight[v] = tr;
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    node query(const int32_t &v ,const int32_t &l,const int32_t &r){
        if(l > treeRight[v] || r < treeLeft[v]){
            return identity_element;
        }
        if(treeLeft[v] >= l && treeRight[v] <= r){
            return t[v];
        }
        pushdown(v);
        node a = query(v<<1,l,r),b = query(v<<1|1,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
 
    // rupd = range update
    void rupd(const int32_t &v, const int32_t &l,const int32_t &r,const update &upd){
        if(l > treeRight[v] || r < treeLeft[v]){
            return;
        }
        if(treeLeft[v] >= l && treeRight[v] <= r){
            apply(v, upd);
            return;
        }
        pushdown(v);
        rupd(v<<1,l,r,upd);
        rupd(v<<1|1,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
     
    template<typename T>
    int descent_right(int l, T x, int32_t v, node &prev) {
        if (l > treeRight[v]) // node is completely out of range
            return len;
        if(l <= treeLeft[v]){ // node is completely in range
            node cur;
            cur.merge(prev,t[v]);
            if (!cur.check(x)){ // go further right than this node
                swap(prev,cur); // merging this node's contribution
                return len;
            }
            if (treeLeft[v]==treeRight[v]) {
                return treeRight[v];
            }
        }
        pushdown(v);
        int ans=descent_right(l, x, v*2, prev); // trying to find in left child
        if(ans != len) return ans; // found in left child
        return descent_right(l, x, v*2+1, prev); // finding in right child
    }
    template<typename T>
    int descent_left(int r, T x, int32_t v, node &prev) {
        if (r < treeLeft[v]) // node is completely out of range
            return -1;
        if(r >= treeRight[v]){ // node is completely in range
            node cur;
            cur.merge(t[v],prev);
            if (!cur.check(x)){ // go further left than this node
                swap(cur,prev); // merging this node's contribution
                return -1;
            }
            if (treeLeft[v]==treeRight[v]) {
                return treeLeft[v];
            }
        }
        pushdown(v);
        int ans=descent_left(r, x, v*2+1, prev); // trying to find in right child
        if(ans != -1) return ans; // found in right child
        return descent_left(r, x, v*2, prev); // finding in left child
    }


    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,l,r);
    }
    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,l,r,upd);
    }
    template<typename T>
    int descent_right(int l, T x){ // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
        node prev = identity_element;
        return descent_right(l,x,1,prev);
    }
    template<typename T>
    int descent_left(int r, T x){ // maximum l such that [l...r].check(x) == true, returns -1 if not found
        node prev = identity_element;
        return descent_left(r,x,1,prev);
    }

};


// ll a[N];
// segtree<Node, Update> sgt(n);
// sgt.build(a);
vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
    
    int n = (int)nums.size();
    segtree<Node, Update> sgt(n);
    sgt.build(nums);        

    vector<long long> ans(n, 0);

    for(int i = 0; i < n; i++){

        int it = removeQueries[i];
        sgt.rupd(it, it, -INF);
        ans[i] = sgt.query(0, n - 1).ans;
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