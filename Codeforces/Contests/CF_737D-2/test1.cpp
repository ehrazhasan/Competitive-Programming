#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        
        int n = (int)boxes.size();
        
        if(n == 1) return 1;
        
        int dp[100][100][100] = {0};

        for(int i = 0; i < n; i++){

            for(int k = 0; k <= i; k++){

                dp[i][i][k] = (k+1)*(k+1);
            }
        }
        cout << "haf";
        for(int i = n-1; i >= 0; i--){

            for(int j = i+1; j < n; j++){


                for(int k = 0; k <= j; k++){

                    int a = (k+1)*(k+1) + dp[i+1][j][0];


                    for(int l = i+1; l <= j; l++){

                        if(boxes[i] == boxes[l])
                            a = max(a, dp[i+1][l-1][0] + dp[l][j][k+1]);
                    }

                    dp[i][j][k] = a;
                }

                
            }
        }
        return dp[0][n-1][0];
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << "akjhf";
    Solution t;
    int c;
    cin >> c;
    
    vector<int> values{1,1,1};
    cout << "haf";
    cout << t.removeBoxes(values);
    return 0;
}