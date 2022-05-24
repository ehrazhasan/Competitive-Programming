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
#define repA(i,a,n) for(int i=a;i<=(n);++i)/
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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> ans(700,0);
vector<string> v;
multimap<pair<int,int>,pair<int,int>> uniq;
void bfs(int x, int y,int n,int m){


    queue<pair<int,int>> q;
    q.push({x,y});

    // map<pair<int,int>,int> visited;
    // map<pair<int,int>,int> dist;
    int dist[305][305];
    int visited[305][305];

    memset(dist,0,sizeof(dist)) 
    visited[x][y] = 1;
    dist[x][y] = 0;

    while(!q.empty()){

        auto it = q.front();
        q.pop();
        int cx = it.first;
        int cy = it.second;
        

        for(int i = 0; i < 4; i++){

            int nx = cx + dx[i];
            int ny = cy + dy[i];



            if(nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[{nx,ny}]){

                visited[{nx,ny}] = 1;

                if(v[nx][ny] == '1'){

                    

                    auto res = uniq.equal_range({x,y});
                    int cnt = distance(res.first,res.second);

                    bool flag = false;
                    if(cnt != 0){

                        for(auto it = res.first; it != res.second ; it++){

                            if(it->second.first == nx and it->second.second == ny){
                                flag = true;
                                break;
                            }
                        }
                    }

                    // if(flag){
                    //     db3(x,y,ny);
                    // }
                    // else{
                    //     db2(nx,ny);
                    // }
                    
                    q.push({nx,ny});    
                    dist[{nx,ny}] = 1 + dist[{cx,cy}];

                    // int z = dist[{nx,ny}];
                    // db1(z);
                    if(cnt == 0 or !flag)
                        ans[dist[{nx,ny}] - 1]++;

                    uniq.insert({{nx,ny},{x,y}});
                    uniq.insert({{x,y},{nx,ny}});

                }
                else{
                    q.push({nx,ny});
                    dist[{nx,ny}] = 1 + dist[{cx,cy}];
                }

            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        int n, m;
        cin >> n >> m;
        
        for(int i = 0; i < 700; i++) ans[i] = 0;
        v.clear();
        //uniq.clear();
        vector<pair<int,int>> p; 

        uniq.erase(all(uniq));
        //db2(n,m);

        rep(i,n){

             string s;
             cin >> s;
             //db1(s);

             v.push_back(s);
            
             for(int j = 0; j < m; j++){

                if(s[j] == '1'){

                    p.push_back({i,j});
                }
             }
        }

        for(auto it : p){

            int i = it.first;
            int j = it.second;
            //db2(i,j);
            bfs(i,j,n,m);
        }
        //bfs(0,2,n,m);

        for(int i = 0; i < n + m - 2; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}