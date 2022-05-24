#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

vector<int> add(vector<int> a, vector<int> b)
{
	vector<int> ans;
	int carry = 0;
	cout << "a: ";
	for(auto it : a) cout << it << " ";
	cout << endl;
	cout << "b: ";
	for(auto it : b) cout << it << " ";
	cout << endl;
	while(a.size()!=b.size())
	{
		if(a.size()<b.size())
			a.pb(0);
		else
			b.pb(0);
	}
	for(int i = 0;i<a.size();i++)
	{
		int res = a[i]+b[i]+carry;
		carry = res/6;
		res = res%6;
		ans.pb(res);
	}
	while(carry!=0)
	{
		ans.pb(carry%6);
		carry /= 6;
	}
	cout << "ans: ";
	for(auto it : ans) cout << it << " ";
	cout << endl;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l;
		cin>>l;
		vector<int> num;
		while(l--)
		{
			int te;cin>>te;num.pb(te);
		}

		vector<int> ans;
		ans.pb(0);
		vector<int> pow;
		pow.pb(1);
		for(int i = 0;i<num.size();i++)
		{
			if(num[i])
				ans = add(ans,pow);
			pow = add(pow,pow);
		}
		for(auto it : ans)
			cout<<it<<" ";
		cout<<"\n";
	}
	return 0;

}
