class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<vector<int>> dp(n);
    
            for (int i = 0; i < n; ++i) {
                dp[i] = {nums[i]};
                for (int j = 0; j < i; ++j) {
                    if (nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size()) {
                        dp[i] = dp[j];
                        dp[i].push_back(nums[i]);
                    }
                }
            }
    
            vector<int> result;
            for (auto& subset : dp) {
                if (subset.size() > result.size()) {
                    result = subset;
                }
            }
    
            return result;
        }
    };
    