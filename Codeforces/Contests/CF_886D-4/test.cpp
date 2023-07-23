class Solution {
public:
        
    long long maxScore(vector<int>& nums, int x) {
            
        int n = (int)nums.size();
        long long dp[n + 1][2];
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < 2; j++) {
                
                
                    
                    dp[i][j] = 0;
                
            }
        }
        
        dp[0][0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            //taking
            dp[i][nums[i] % 2] = max(dp[i][nums[i] % 2], dp[i - 1][0] + (nums[i] % 2 == 0 ? nums[i] : nums[i] - x));
            dp[i][nums[i] % 2] = max(dp[i][nums[i] % 2], dp[i - 1][1] + (nums[i] % 2 == 1 ? nums[i] : nums[i] - x));
                
            //not taking
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            dp[i][1] = max(dp[i][1], dp[i - 1][1]);
        }
        
        
//         for(int i = 0; i < n; i++) {
            
//             cout << i << ":" << endl;
//             for(int j = 0; j < 2; j++) {
                
//                 for(int k = 0; k < 2; k++) {
                    
//                     cout << dp[i][j][k] << " ";
//                 }
                
//                 cout << endl;
//             }
//         }
        return max({dp[n - 1][1], dp[n - 1][1], dp[n - 1][0], dp[n - 1][0]});
    }
};