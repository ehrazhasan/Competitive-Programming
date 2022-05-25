#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tt=1;
	cin >> tt;
	while(tt--)
	{
		int n,p,k;
		cin >> n >> p >> k;
		p--;
		string a;
		cin >> a;
		int x,y;
		cin >> x >> y;
		int ans=INF;
		int cnt[n];
		for(int i=n-1;i>=n-k;i--)
		{
			if(a.at(i)=='1')
				cnt[i]=0;
			else
				cnt[i]=1;
		}
		for(int i=n-k-1;i>=0;i--)
		{
			cnt[i]=cnt[i+k];
			if(a.at(i)=='0')
				cnt[i]++;
		}

		for(int i = 0; i < n; i++) cout << cnt[i] << " ";
		for(int i=p;i<n;i++)
		{
			ans=min(ans,y*(i-p)+x*cnt[i]);
		}
		cout << ans << endl;
	}
	return 0;
}