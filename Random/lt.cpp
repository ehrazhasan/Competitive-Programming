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
    int dp[80][101][101];
    int cherryPickup(vector<vector<int>>& grid) {
        
        

        memset(dp, 0, sizeof(dp));
        
        int n = (int)grid.size();
        int m = (int)grid[0].size();
    
            
       dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
    
       
        for(int row = 1; row < n; row++){
            
            int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0;
            
            for(int j = 0; j < min(m,row + 1); j++){

                for(int k = max(0,n - 1 - row); k < m; k++){

                    // int c1 = j, c2 = k;
                    // int prev_max = 0;
                    // for (int offset1 = max(0, c1 - 1); offset1 <= min(m - 1, c1 + 1); offset1++) {
                    //     for (int offset2 = max(0, c2 - 1); offset2 <= min(m - 1, c2 + 1); offset2++) {
                    //             prev_max = max(prev_max, dp[row - 1][offset1][offset2]);
                    //     }
                    // }
                    //int prev_max = 0;
                    if(j >= 0 and j <= m - 1 and k >= 0 and k <= m - 1){
                        a = dp[row - 1][j][k];
                        //prev_max = max(prev_max,a);
                    }
                    if(j - 1 <= m - 1 and j - 1 >= 0){

                        b = dp[row - 1][j - 1][k];
                        //prev_max = max(prev_max,b);
                    }
                    if(j + 1 >= 0 and j + 1 <= m - 1){

                        c = dp[row - 1][j + 1][k];
                         //prev_max = max(prev_max,c);
                    }
                    if(k - 1 <= m - 1 and k - 1 >= 0){

                        d = dp[row - 1][j][k - 1];
                         //prev_max = max(prev_max,d);
                    }
                    if(k + 1 >= 0 and k + 1 <= m - 1){

                        e = dp[row - 1][j][k + 1];
                       //  prev_max = max(prev_max,e);
                    }
                    if(j - 1 <= m - 1 and j - 1 >= 0 and k - 1 <= m - 1 and k - 1 >= 0){

                        f = dp[row - 1][j - 1][k - 1];
                         //prev_max = max(prev_max,f);
                    }
                    if(j - 1 <= m - 1 and j - 1 >= 0 and k + 1 >= 0 and k + 1 <= m - 1){

                        g = dp[row - 1][j - 1][k + 1];
                        //prev_max = max(prev_max,g);
                    }
                    if(j + 1 >= 0 and j + 1 <= m - 1 and k - 1 <= m - 1 and k - 1 >= 0){

                        h = dp[row - 1][j + 1][k - 1];
                        //prev_max = max(prev_max,h);
                    }
                    if(j + 1 >= 0 and j + 1 <= m - 1 and k + 1 >= 0 and k + 1 <= m - 1){
                    
                        i = dp[row - 1][j + 1][k + 1];
                       // prev_max = max(prev_max,i);
                    }

                    int prev_max = 0;
                    prev_max = max({a,b,c,d,e,f,g,h,i});
                    if(row == 9) db1(prev_max);
 
                    if(j == k){

                        dp[row][j][k] += grid[row][j] + prev_max;
                    }
                    else
                        dp[row][j][k] += grid[row][j] + grid[row][k] + prev_max;
                    //db3(row,j,k);
                   // db1(dp[row][j][k]);
                }

                
                
            }

            // for(int j = 0; j < m; j++){

            //     for(int k = 0; k < m; k++){

            //         cout << dp[row][j][k] << " ";
            //     }

            //     cout << endl;
            //  }

            //  cout << endl;
        }
    
        int ans = 0;


        for(int j = 0; j < m; j++){

            for(int k = 0; k < m; k++){

                ans = max(ans,dp[n - 1][j][k]);
            }
        }

        return ans;
        
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
 
    vector<vector<int> > v{{8,8,10,9,1,7},{8,8,1,8,4,7},{8,6,10,3,7,7},{3,0,9,3,2,7},{6,8,9,4,2,5},{1,1,5,8,8,1},{5,6,5,2,9,9},{4,4,6,2,5,4},{4,4,5,3,1,6},{9,2,2,1,9,3}};
    
    cout << cherryPickup(v);
 
    return 0;
}