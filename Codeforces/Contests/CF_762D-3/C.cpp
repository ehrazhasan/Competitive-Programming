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
    int t;
    cin>>t;
    while(t--){
        
        ll a, s;
        cin >> a >> s;

        vector<int> v,ans;

        ll x = a;
        ll y = s;


        while(x > 0){

        	int d = x % 10;
        	v.push_back(d);
        	x /= 10;
        }

        while(y > 0){

        	int d = y % 10;
        	ans.push_back(d);
        	y /= 10;
        }

        int n = (int)ans.size();
        reverse(all(v));
        reverse(all(ans));

        int m = (int)v.size();
        vector<int> b;
        int j = m - 1;
        for(int i = n - 1; i >= 0; i--){

        	ll g = j < 0 ? 0 : v[j]; 
        	//db2(ans[i],g);
        	if(ans[i] < g){

        		ll no = ans[i - 1] * 10 + ans[i];
        		ll diff = no - v[j];
        		i--;
        		vector<int> temp;
        		while(diff > 0){

        			int d = diff % 10;
        			temp.push_back(d);
        			diff /= 10;
        		}

        		reverse(all(temp));

        		for(int k = 0; k < temp.size(); k++)
        			b.push_back(temp[k]);

        	}
        	else{

        		b.push_back(ans[i] - g);
        	}

        	j--;
        }

        reverse(all(v));
        while(v.size() < b.size()){

        	v.push_back(0);
        }
        
        while(v.size() > b.size()){
        	b.push_back(0);
        }

        vector<int> s1;

        for(int i = 0; i < b.size(); i++){
        	//db2(v[i],b[i]);
        	ll sum = v[i] + b[i];
        	vector<int> temp;

        	if(sum == 0){
        		s1.push_back(0);
        		continue;
        	}

        	while(sum > 0){

        		int d  = sum % 10;
        		temp.push_back(d);
        		sum /= 10;
        	}

        	for(int l = 0; l < temp.size(); l++){
        		s1.push_back(temp[l]);
        		//db1(temp[l]);
        	}
        }

        reverse(all(s1));
     //    for(auto it : v) cout << it << " ";
     //    cout << endl;
     //    for(auto it : b) cout << it << " ";
     //    cout << endl;
    	// for(auto it : s1) cout << it << " ";
     //    cout << endl;

    	if(ans != s1){

    		cout << -1 << endl;
    	}
    	else{
    		int k = b.size() - 1;
    		while(b[k--] == 0) b.pop_back();

    		reverse(all(b));

    		if(b.empty()){

    			cout << 0 << endl;
    			continue;
    		}

    		for(auto it : b) cout << it;
    		cout << endl;
    	}
    }
    return 0;
}