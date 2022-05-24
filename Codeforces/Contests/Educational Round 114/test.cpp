#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define ll long long
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define tolowecase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::tolower)
#define touppercase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::toupper)
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       
       int n , k;
       cin >> n >> k;
       vector<int > v;
       
       rep(i,n){
       	int a;
       	cin >> a;
       	v.push_back(a);
       }

       unordered_map<int,int> m;
       for(auto it : v) {

       		m[it] = 1;
       }

       int maxi = *max_element(v.begin(),v.end());

       int ans = 0;
       for(int i = 0 ; i < n ; i++){
       	
       		int mul = v[i];
       		
       		// while(mul - i <= n){

       		// 	if((i < mul - i) && ((ll)v[mul-i]*v[i] == (ll)mul)) ans++;

       			
       		// 	mul += v[i];

       		// }
     //   		for(int j = 2*mul; j <= 100; j += mul){
     //   			db1(j);
     //   			int val = j * k;
     //   			int f = val / mul;
     //   			if(m[f]){
     //   				db2(mul,f);
					// ans++;
     //   			}
     //   		}

       		if(mul % k == 0){

       			ans += n - 1;
       			continue;
       		}

       		for(int j = k; j <= maxi; j += k){

       			if(m[j]){

       				ans++;
       			}
       		}
       }
       cout << ans/2 << endl;
    }
    return 0;
}