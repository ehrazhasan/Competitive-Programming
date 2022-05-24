//****************************Template Begins****************************//

// Header Files
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
// Header Files End

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define sz(x) (ll)x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//
/*
    for th i'th position:
    
    we will always have a[i]^2*(i-1) + b[i]^2*(i-1)
    then we will also have (a[1]^2 + a[2]^2....a[i-1]^2)
    +(b[1]^2 + b[2]^2....b[i-1]^2)
    this is all constant.
    
    now we will have 2*a[i]*(a[1] + a[2]....a[i-1])
                    + 2*b[i]*(b[1] + b[2].....b[i-1])



    2*a[1]*(sum-a[1]) + 2*a[2]*(sum-a[2])....2*a[n]*(sum-a[n])

  = 2*sum*(sum) - 2*(a[1]^2 + a[2]^2......  )
    
*/
int main() {
    DIVYA;
    ll t, n, i, j, ans, temp, sum;
    string sans;
    t = 1;
    cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n;
        vll a(n+1,0),b(n+1,0);
        fo(i,1,n)
        {
            cin>>a[i];
            sum+=a[i];
        }
        fo(i,1,n)
        {
            cin>>b[i];
            sum+=b[i];
        }
        vector<vll>dp(n+5,vll(10005,0));
        dp[0][0] = 1;
        fo(i,0,n-1)
        {
            fo(j,0,10000)
            {
                if(!dp[i][j])continue;
                if(j + a[i+1]<=10000)
                {
                    dp[i+1][j + a[i+1]] = 1;
                }
                if(j + b[i+1]<=10000)
                {
                    dp[i+1][j + b[i+1]] = 1;
                }                
            }
        }
        ll sum1,sum2;
        ll mn = inf;
        fo(i,0,10000)
        {
            if(dp[n][i])
            {
                ll s1,s2;
                s1 = i;
                cout << s1 << endl;
                s2 = sum-i;
                ll val = s1*s1 + s2*s2;
                if(val<mn)
                {
                    mn = val;
                }
            }
        }
        ans = 0;
        ll sq_sum = 0;
        fo(i,1,n)
        {
            sq_sum+=(a[i]*a[i]);
            sq_sum+=(b[i]*b[i]);
        }
        ans+=(n-2)*sq_sum;
        ans+=mn;
        cout<<ans<<"\n";
    }
    return 0;
}













