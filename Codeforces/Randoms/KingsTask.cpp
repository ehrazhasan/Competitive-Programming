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

// vector<int> p(1005,0);
// int getSteps(int ind, int pos, vector<int> &v, int n){

	

// 	queue<int> q;

// 	q.push(ind);
// 	int ans = 0;
// 	vector<bool> visited(2*n + 1, false);

// 	while(!q.empty()){

// 		int s = q.size();

// 		for(int i = 0; i < s; i++){

// 			int ci = q.front();
// 			q.pop();
// 			//db1(ci);
// 			visited[ci] = true;
			
// 			if(ci + n < 2*n and ci + n == pos){

// 				p[ci + n] = ci;
// 				return ans + 1;				
// 			}
// 			else if(ci % 2 == 0 and ci + 1 == pos){

// 				p[ci + 1] = ci;
// 				return ans + 1;
// 			}
// 			else if(ci % 2 and ci - 1 == pos){

// 				p[ci - 1] = ci;
// 				return ans + 1;
// 			}
// 			else{

				
// 				if(!visited[ci + n] and ci + n < 2*n){
// 					q.push(ci + n);
// 					p[ci + n] = ci;
// 				}
// 				if(ci % 2 == 0 and !visited[ci + 1]){
// 					q.push(ci + 1);
// 					p[ci + 1] = ci;
// 				}
// 				if(ci % 2 and !visited[ci - 1]){
// 					q.push(ci - 1);
// 					p[ci - 1] = ci;
// 				}

// 			}

			
// 		}
// 		ans++;
// 	}

// 	return ans;
// }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   	
   	int n;
   	cin >> n;


   	vector<int> v(2*n);
   	rep(i,2*n) cin >> v[i];

   	int el = -1;
   	int ind = -1;

   	rep(i,2*n){

   		if(v[i] != i + 1){

   			el = v[i];
   			ind = i;
   			break;
   		}
   	}

   	if(el == -1){

   		cout << 0 << endl;
   		return 0;
   	}
 

   	// queue<int> q;
   	// int pos = el - 1;

   	// p.clear();
   	// int steps = getSteps(ind,pos,v,n);
   	// //db1(steps);

   	// vector<int> trace;
   	// //rep(i,2*n) cout << p[i] << " ";
   	// while(pos != ind){

   	// 	trace.push_back(p[pos]);
   	// 	pos = p[pos];
   	// }


   	// reverse(all(trace));
   	// // for(auto it : trace) cout << it << " ";
   	// // cout << endl;

   	// queue<int> t;
   	// for(int i = 0; i < trace.size() - 1; i++){

   	// 	if(i + 1 < trace.size() and trace[i + 1] == trace[i] + n){

   	// 		t.push(2);
   	// 	}
   	// 	else{

   	// 		t.push(1);
   	// 	}
   	// }


   	// if(trace.back() + n == el - 1) t.push(2);
   	// else t.push(1);

   	int steps = 0;
   	int a = 1;
   	int z[2] = {0, 1};


   	vector<int> p = v;
   	while(true){ 
   		
   		a = z[a ^ 1];

   		if(a == 0){

   			for(int i = 0; i < 2*n; i+=2){

   				if(i + 1 < 2*n)
   					swap(v[i],v[i + 1]);
   			}
   		}
   		else{

   			for(int i = 0; i < n; i++){

   				swap(v[i],v[i + n]);
   			}
   		}

   		steps++;
   		bool f = false;
   		for(int i = 0; i < 2*n; i++){

	   		if(v[i] != i + 1) {

	   			f = true;
	   		}
   		}


   		if(!f or steps > 2*n){

   			break;
   		}

   		
   	}
   	
   	v = p;
   	int newSteps = 0;
   	a = 1;
   	while(true){ 
   		
   		a = z[a ^ 1];

   		if(a == 1){

   			for(int i = 0; i < 2*n; i+=2){

   				if(i + 1 < 2*n)
   					swap(v[i],v[i + 1]);
   			}
   		}
   		else{

   			for(int i = 0; i < n; i++){

   				swap(v[i],v[i + n]);
   			}
   		}

   		newSteps++;
   		bool f = false;
   		for(int i = 0; i < 2*n; i++){

	   		if(v[i] != i + 1) {

	   			f = true;
	   		}
   		}


   		if(!f or newSteps > 2*n){

   			break;
   		}

   		
   	}

   	
   	int ans = 0;
   	ans = min(steps,newSteps);
   	if(min(steps,newSteps) > 2*n) ans = -1;

   	
   	cout <<  ans << endl;
    return 0;
}