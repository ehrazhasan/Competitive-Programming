
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
int dp[N][N], a[N], n;
int solve(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    int &best = dp[l][r];
    if (best != -1) {
        return best;
    }
    best = solve(l + 1, r) + 1;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] == a[l]) {
            best = min(best, solve(l + 1, i - 1) + solve(i, r));
        }
    }
    return best;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
}