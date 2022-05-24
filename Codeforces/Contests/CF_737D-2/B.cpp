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
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define tolowecase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::tolower)
#define touppercase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::toupper)
#define MOD = 998244353;
double eps = 1e-12;
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n);

        rep(i,n){
        	cin >> v[i];
        }


        vector<ll> co = v;
        sort(all(co));

        ll cnt = 0;

        for(int i = 0; i <= n-2; i++){

        	cnt++;

        	int index = upper_bound(co.begin(),co.end(),v[i]) - co.begin();
        	db2(v[i],index);
        	while(index < n and i < n-1 and v[i+1] == co[index]){
        		db1(v[i+1]);
        		i++;
        		index++;

        	}
        }

        if(n >= 2){

        	int index = upper_bound(co.begin(),co.end(),v[n-2]) - co.begin();
        	if(v[n-1] != co[index]) cnt++;
        }
        db1(cnt);
        if(cnt <= k) cout << "yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}