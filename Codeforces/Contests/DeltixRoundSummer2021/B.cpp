#include<bits/stdc++.h>
#define task "B"
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
const ll INF = 1e18 + 5;
 
int n;
vector<int> ev;
 
void Input()
{
    ev.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            ev.pb(i);
    }
}
 
void Solve()
{
    int res;
    if(n % 2 == 0)
    {
        if(ev.size() != n / 2)
            cout << -1 << '\n';
        else
        {
            res = INF;
            int i = 1, d = 0;
            for(int j = 0; j < ev.size(); j++)
            {
                d += abs(ev[j] - i);
                i += 2;
            }
            res = min(res, d);
            i = 2, d = 0;
            for(int j = 0; j < ev.size(); j++)
            {
                d += abs(ev[j] - i);
                i += 2;
            }
            cout << min(res, d) <<'\n';
        }
    }
    else
    {
        int sz = ev.size();
        if((sz != n / 2) && (sz != (n + 1) / 2))
        {
            cout << -1 << '\n';
        }
        else if (sz == n / 2)
        {
            res = INF;
            int i = 2, d = 0;
            for(int j = 0; j < sz; j++)
            {
                d += abs(ev[j] - i);
                i += 2;
            }
            cout << min(res, d) <<'\n';
        }
        else
        {
            res = INF;
            int i = 1, d = 0;
            for(int j = 0; j < sz; j++)
            {
                d += abs(ev[j] - i);
                i += 2;
            }
            cout << min(res, d) <<'\n';
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(task".INP","r",stdin);
    //freopen(task".OUT","w",stdout);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        Input();
        Solve();
    }
}