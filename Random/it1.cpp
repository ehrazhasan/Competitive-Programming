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

bool isRobotBounded(string s) {
        
        int n = (int)s.size();
        
        if(n == 1 and (s[0] == 'L' or s[0] == 'R'))  return true;
        
        map<pair<int,int>, int> m;
        map<pair<int,int>, char> dir;
        
        int x = 0, y = 0;
        char current_dir = 'N';
        
        m[{0,0}] = 1;
        dir[{0,0}] = 'N';
            

        map<char,char> left, right;
        
        left['N'] = 'W';
        left['W'] = 'S';
        left['S'] = 'E';
        left['E'] = 'N';
    
        right['N'] = 'E';
        right['W'] = 'N';
        right['S'] = 'W';
        right['E'] = 'S';
        
        int k = 0;
        bool okay = false;
        while(true){
            
            for(auto it : s){
                
               // db3(x,y,current_dir);

                if(it == 'G'){
                    

                    if(current_dir == 'N'){

                         y += 1;
                         //db2(x,y);
                         //cout << m[{x,y}] << endl;
                         if(m[{x,y}] and dir[{x,y}] == current_dir and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                         if(m[{x,y}] != 1)
                            dir[{x,y}] = 'N';

                         m[{x,y}] = 1;
                         current_dir = 'N';
                    }
                    else if(current_dir == 'S'){
                        
                        y -= 1;
                        if(m[{x,y}] and dir[{x,y}] == current_dir and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                        if(m[{x,y}] != 1)
                            dir[{x,y}] = 'S';
                        m[{x,y}] = 1;
                        current_dir = 'S';
                    }
                    else if(current_dir == 'E'){
                        x += 1;
                        if(m[{x,y}] and dir[{x,y}] == current_dir and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                        if(m[{x,y}] != 1)
                            dir[{x,y}] = 'E';
                        m[{x,y}] = 1;
                        current_dir = 'E';
                    }
                    else{
                        
                        x -= 1;
                        if(m[{x,y}] and dir[{x,y}] == current_dir and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                        if(m[{x,y}] != 1)
                            dir[{x,y}] = 'W';
                        m[{x,y}] = 1;
                        current_dir = 'W';
                    }

                }
                else if(it == 'L'){
                    
                    if(current_dir == 'N'){
                         
                         if(m[{x,y}] and dir[{x,y}] == left['N'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                         if(m[{x,y}] != 1)
                            dir[{x,y}] = left['N'];
                         m[{x,y}] = 1;
                         current_dir = left['N'];
                    }
                    else if(current_dir == 'S'){
                        
                        if(m[{x,y}] and dir[{x,y}] == left['S'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                       if(m[{x,y}] != 1)
                            dir[{x,y}] = left['S'];
                        m[{x,y}] = 1;
                        current_dir = left['S'];
                    }
                    else if(current_dir == 'E'){
                        if(m[{x,y}] and dir[{x,y}] == left['E'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                       if(m[{x,y}] != 1)
                            dir[{x,y}] = left['E'];
                        m[{x,y}] = 1;
                        current_dir = left['E'];
                    }
                    else{
                        
                        if(m[{x,y}] and dir[{x,y}] == left['W'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                        if(m[{x,y}] != 1)
                            dir[{x,y}] = left['W'];
                        m[{x,y}] = 1;
                        current_dir = left['W'];
                    }
                }
                else{
                    
                    if(current_dir == 'N'){
                        
                         if(m[{x,y}] and dir[{x,y}] == right['N'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                         if(m[{x,y}] != 1)
                            dir[{x,y}] = right['N'];
                         m[{x,y}] = 1;
                         current_dir = right['N'];
                    }
                    else if(current_dir == 'S'){
                        
                        if(m[{x,y}] and dir[{x,y}] == right['S'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                        if(m[{x,y}] != 1)
                            dir[{x,y}] = right['S'];
                        m[{x,y}] = 1;
                        current_dir = right['S'];
                    }
                    else if(current_dir == 'E'){
                       if(m[{x,y}] and dir[{x,y}] == right['E'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                       if(m[{x,y}] != 1)
                            dir[{x,y}] = right['E'];
                        m[{x,y}] = 1;
                        current_dir = right['E'];
                    }
                    else{
                        
                       if(m[{x,y}] and dir[{x,y}] == right['W'] and (k + 1) % n == 0 and x == 0 and y == 0) return true;
                       if(m[{x,y}] != 1)
                            dir[{x,y}] = right['W'];
                        m[{x,y}] = 1;
                        current_dir = right['W'];
                    }
                }
                
              k++;  
            }
            
            
            if(k >= 800) break;
        }
        
        
        return false;
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    cout << isRobotBounded(s);
    return 0;
}