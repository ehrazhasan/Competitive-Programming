#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int n, d;
	cin >> n >> d;

	vector<ll> power(n);

	for(int i = 0; i < n; i++) {
		cin >> power[i];
	}

	sort(power.begin(), power.end());

	if(d > power[n-1] * n) {
		cout << 0 << endl;
		return 0;
	}

	ll low = 0, high = n - 1;
	ll ans = 0;

	while(low <= high) {
		ll req = d/power[high] + 1;

		// if(req * power[high] == d) {
		// 	req++;
		// }

		ll diff = high - low + 1;


		if(diff < req) {
			break ;
		}
		else {
			low += req - 1;

			high--;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}