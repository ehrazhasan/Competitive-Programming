#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FLASH ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define mod 1000000007
// #define mod 998244353
// #define inf 10000000000

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int mex=0;
    for(int i=0; i<n; i++){
        if(arr[i]==mex) mex++;
        else if(arr[i]>mex) break;
    }
    if(mex==0) cout<<*min_element(arr.begin(), arr.end())-1<<endl;
    else if(mex==1) cout<<-1<<endl;
    else{
        map<int, int> m;
        m.insert({arr[0], 0});
        for(int i=1; i<n; i++){
            auto itr=m.end();
            itr--;
            if(itr->first!=arr[i]){
                m.insert({arr[i], itr->second+1});
            }
        }
        int count=0;
        int i=0;
        arr.clear();
        for(auto i:m) arr.push_back(i.first);
        int n=arr.size();
        while(arr[i]<mex) i++;
        for(; i<n; i++){
            int x=arr[i]+mex-1;
            if(m.find(x)==m.end() && m.find(x-1)!=m.end() && m[x-1]-m[arr[i]]+2==mex) count++;
        }
        cout<<count<<endl;
    }
}

int main(){
    FLASH
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}