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

void build(int vertex, int treeLeft, int treeRight, vector<int> &a){

	if(treeLeft == treeRight){

		tree[vertex] = a[treeRight];
		return;
	}

	int mid = (treeLeft + treeRight) >> 1;

	build(2 * vertex, treeLeft, mid, a);
	build(2 * vertex + 1, mid + 1, treeRight, a);

	tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
}


//this function is the process of telling the man to remember the value
void apply(int vertex, int treeLeft, int treeRight, ll value){ 

	
	tree[vertex] += value;

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
	tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
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
	return max(leftSum, rightSum);
}



bool isPossible(vector<int> &pref, vector<int>& charge, vector<int>& costs, long long budget, int k){
        
    int n = (int)charge.size();
    for(int i = 0; i + k - 1 < n; i++){
        
        int l = i;
        int r = i + k - 1;
        int sum = pref[r] - (l - 1 >= 0 ? pref[l - 1] : 0);
        //int maxi = sgt.query(l, r).sum;
        int maxi = query(n, 0, n - 1, l, r);
        
        long long ans = (long long)maxi + (long long)k * (long long)sum;
        if(ans <= budget) return true;
    }
    
    return false;
}

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
    int n = (int)chargeTimes.size();
    
    vector<int> pref(n);
    pref[0] = runningCosts[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + runningCosts[i];
    
	// segtree<Node, Update> sgt(n);
 //    sgt.build(chargeTimes);

    build(n, 0, n - 1, chargeTimes);
    
    int start = 0;
    int end = n;
    int ans = 0;
    while(start <= end){
        
        int mid = (start + end) >> 1;
        
        if(isPossible(pref, chargeTimes, runningCosts, budget, mid)){
            
            ans = max(ans, mid);
            start = mid + 1;
        }
        else{
            
            end = mid - 1;
        }
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        
        vector<int> a = {997,532,507,382,556,657,774,878,640,56,52,113,369,685,579,40,344,772,302,592,817,749,277,575,776,16,866,732,835,823,455,992,4,804,550,265,272,603,443,932,367,404,227,499,736,824,301,116,348,678,367,709,659,730,23,513,171,490,75,334,176,790,28,141,724,883,531,717,611,119,792,32,819,455,292,677,454,897,230,620,137,976,339,314,678,163,632,907,606,160,832,614,223,274,387,567,316,213,447,70,801,246,971,25,746,177,40,183,880,958,485,243,615,286,724,472,579,396,161,422,119,823,352,754,165,238,978,91,8,733,274,587,192,56,24,90,127,135,294,568,441,554,751,724,349,131,588,755,222,313,384,344,626,897,801,308,556,78,295,144,600,27,132,151,856,959,347,740,423,407,650,579,222,57,819,391,123,417,423,522,387,975,622,522,426,564,639,62,385,281,91,477,646,706,325,596,608,539,746,57,722,28,923,774,61,801,170,343,885,541,877,878,669,744,103,540,833,1,732,753,725,753,868,496,402,805,551,869,213,832,162,199,750,110,880,681,217,945,67,975,342,644,406,482,213,812,722,439,180,537,913,188,984,376,617,237,736,691,430,232,902,498,989,249,741,588,482,112,324,856,222,480,301,297,278,215,736,377,188,704,76,19,728,55,496,970,425,507,986,835,578,579,520,613,454,771,736,915,269,43,443,662,357,261,463,906,169,771,258,644,88,598,982,332,72,259,933,793,548,361,298,978,182,717,982,78,989,832,330,503,592,665,462,597,98,599,687,699,238,441,535,941,567,611,264,147,334,639,317,694,669,195,857,756,332,795,329,147,216,780,637,947,564,895,53,952,616,256,798,696,705,993,722,323,501,553,475,375,517,126,745,948,461,546,817,821,954,31,338,225,190,860,320,721,496,521,288,599,578,765};
        vector<int> b = {606,691,771,968,162,44,961,296,668,544,879,700,295,557,664,278,94,337,680,542,562,946,384,46,627,402,832,53,544,960,22,748,714,184,696,787,326,905,142,659,722,448,984,694,582,686,85,768,276,132,894,802,60,204,47,174,378,642,860,500,131,548,222,920,543,622,711,425,290,452,220,139,23,83,617,43,955,471,39,325,596,592,206,922,955,237,886,837,149,392,159,986,375,455,985,683,654,53,940,794,790,321,598,437,602,105,977,575,176,137,626,752,447,556,789,619,616,459,155,523,727,11,442,779,567,545,229,228,97,294,523,739,122,743,330,421,492,374,948,812,756,908,825,155,533,24,293,525,642,399,822,111,468,612,554,503,997,931,710,542,250,646,797,982,57,726,664,695,192,178,837,254,77,577,591,981,489,400,563,796,156,4,53,238,187,510,582,451,68,537,846,705,857,439,48,932,942,960,750,570,248,336,842,312,888,731,327,890,265,384,25,118,196,653,604,271,928,557,573,433,365,904,22,778,687,512,601,135,682,794,982,189,1000,982,287,15,686,559,392,866,720,413,125,390,927,462,177,422,632,325,169,347,973,87,783,58,749,735,819,70,384,842,722,100,66,947,981,142,784,563,881,146,776,494,283,867,776,78,45,921,735,609,820,669,129,335,325,737,909,342,43,135,118,160,58,646,929,392,804,505,399,382,396,27,40,460,100,75,273,512,725,722,913,636,955,91,759,890,53,288,889,605,382,826,109,951,749,53,409,609,807,201,761,629,465,315,584,557,474,169,888,464,398,580,742,285,373,746,245,241,7,283,682,19,622,437,205,544,415,259,491,670,420,891,386,786,738,985,39,252,302,814,663,432,550,34,940,356,45,593,327,236,542,720,545,928,140,173,670,860,265,164,501,756,616,570,595,314,169,967};
        int budget = 9794129;
        cout << maximumRobots(a, b, budget) << endl;
    }
    return 0;
}