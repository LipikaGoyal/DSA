class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n, 0);
            
            for (int i = n - 1; i >= 0; --i) {
                int index = i + questions[i][1] + 1;
                if (index < n) {
                    dp[i] = dp[index] + questions[i][0];
                } else {
                    dp[i] = questions[i][0];
                }
                if (i < n - 1) {
                    dp[i] = max(dp[i + 1], dp[i]);
                }
            }
            
            return dp[0];
        }
    };
    