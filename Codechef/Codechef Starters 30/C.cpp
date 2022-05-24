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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        int s1 = x1 + y1;
        int s2 = x2 + y2;

        bool okay = false;

        ll sum = abs(x2 - x1) + abs(y2 - y1);
        if(sum % 2 == 0){

        	okay = true;
        }	

        vector<vector<int>> v(n + 1, vector<int>(m + 1,0));

      //   if(!okay){

      //   	v[x1][y1] = 1;
      //   	v[x2][y2] = 2;


      //   	if(x1 - 1 >= 1){

      //   		v[x1 - 1][y1] = 2;
      //   	}

      //   	if(x1 + 1 <= n){

      //   		v[x1 + 1][y1] = 2;
      //   	}

      //   	if(y1 - 1 >= 1){

      //   		v[x1][y1 - 1] = 2;
      //   	}

      //   	if(y1 + 1 <= m){

      //   		v[x1][y1 + 1] = 2;
      //   	}
      //   	///////////////////////
      //   	if(x2 - 1 >= 1){

      //   		v[x2 - 1][y2] = 1;
      //   	}

      //   	if(x2 + 1 <= n){

      //   		v[x2 + 1][y2] = 1;
      //   	}

      //   	if(y2 - 1 >= 1){

      //   		v[x2][y2 - 1] = 1;
      //   	}

      //   	if(y2 + 1 <= m){

      //   		v[x2][y2 + 1] = 1;
      //   	}

      //   	repA(i,1,n){

      //   		repA(j,1,m){

      //   			if(v[i][j] == 0){

      //   				bool one = false, two = false;

      //   				if(i - 1 >= 1){

			   //      		if(v[i - 1][j] == 1) one = true;
			   //      		if(v[i - 1][j] == 2) two = true;
			        		
			   //      	}

			   //      	if(i + 1 <= n){

			   //      		if(v[i + 1][j] == 1) one = true;
			   //      		if(v[i + 1][j] == 2) two = true;
			        		
			   //      	}

			   //      	if(j - 1 >= 1){

			   //      		if(v[i][j - 1] == 1) one = true;
			   //      		if(v[i][j - 1] == 2) two = true;
			        		
			   //      	}

			   //      	if(j + 1 <= m){

			   //      		if(v[i][j + 1] == 1) one = true;
			   //      		if(v[i][j + 1] == 2) two = true;
			        		
			   //      	}


			   //      	if(!one){

			   //      		v[i][j] = 1;
			   //      	}
			   //      	else if(!two){

			   //      		v[i][j] = 2;
			   //      	}
			        
      //   			}
      //   		}
      //   	}

      // //   	int cnt[2] = {1,2};

      // //   	if(m % 2){

      // //   		int y = 1;

      // //   		if(v[1][1] == 2) y = 0;

      // //   		repA(i,1,n){

      // //   			repA(j,1,m){

						// // v[i][j] = cnt[y ^ 1];
						// // y = y ^ 1;
      // //   			}
      // //   		}
      // //   	}
      // //   	else{

      // //   		int y = 1;

      // //   		if(v[1][1] == 2) y = 0;

      // //   		repA(i,1,n){

      // //   			repA(j,1,m){

      // //   				v[i][j] = cnt[y ^ 1];
      // //   				y = y ^ 1;
      // //   			}

      // //   			y = y ^ 1;
      // //   		}

      // //   	}
      //   }
      //   else{

      //   	v[x1][y1] = 1;
      //   	v[x2][y2] = 2;

      //   	if(x1 - 1 >= 1){

      //   		v[x1 - 1][y1] = 3;
      //   	}

      //   	if(x1 + 1 <= n){

      //   		v[x1 + 1][y1] = 3;
      //   	}

      //   	if(y1 - 1 >= 1){

      //   		v[x1][y1 - 1] = 3;
      //   	}

      //   	if(y1 + 1 <= m){

      //   		v[x1][y1 + 1] = 3;
      //   	}
      //   	///////////////////////
      //   	if(x2 - 1 >= 1){

      //   		v[x2 - 1][y2] = 3;
      //   	}

      //   	if(x2 + 1 <= n){

      //   		v[x2 + 1][y2] = 3;
      //   	}

      //   	if(y2 - 1 >= 1){

      //   		v[x2][y2 - 1] = 3;
      //   	}

      //   	if(y2 + 1 <= m){

      //   		v[x2][y2 + 1] = 3;
      //   	}


      //   	repA(i,1,n){

      //   		repA(j,1,m){

      //   			if(v[i][j] == 0){

      //   				bool one = false, two = false, three = false;

      //   				if(i - 1 >= 1){

			   //      		if(v[i - 1][j] == 1) one = true;
			   //      		if(v[i - 1][j] == 2) two = true;
			   //      		if(v[i - 1][j] == 3) three = true;
			   //      	}

			   //      	if(i + 1 <= n){

			   //      		if(v[i + 1][j] == 1) one = true;
			   //      		if(v[i + 1][j] == 2) two = true;
			   //      		if(v[i + 1][j] == 3) three = true;
			   //      	}

			   //      	if(j - 1 >= 1){

			   //      		if(v[i][j - 1] == 1) one = true;
			   //      		if(v[i][j - 1] == 2) two = true;
			   //      		if(v[i][j - 1] == 3) three = true;
			   //      	}

			   //      	if(j + 1 <= m){

			   //      		if(v[i][j + 1] == 1) one = true;
			   //      		if(v[i][j + 1] == 2) two = true;
			   //      		if(v[i][j + 1] == 3) three = true;
			   //      	}


			   //      	if(!three){

			   //      		v[i][j] = 3;
			   //      	}
			   //      	else if(!one){

			   //      		v[i][j] = 1;
			   //      	}
			   //      	else if(!two){

			   //      		v[i][j] = 2;
			   //      	}
      //   			}
      //   		}
      //   	}
      //   }




        repA(i,1,n){


        	repA(j,1,m){


        		int p1 = (i + j) % 2;
        		int p2 = (x1 + y1) % 2;

        		if(p1 == p2){

        			v[i][j] = 1;
        		}
        		else{

        			v[i][j] = 2;
        		}
        	}
        }


        if(okay){

        	repA(i,1,n){

        		repA(j,1,m){

        			if(v[i][j] == 2) v[i][j] = 3;
        		}
        	}

        	v[x2][y2] = 2;
        }


        repA(i,1,n){

        	repA(j,1,m){

        		cout << v[i][j] << " "; 
        	}

        	cout << endl;
        }

    }
    return 0;
}