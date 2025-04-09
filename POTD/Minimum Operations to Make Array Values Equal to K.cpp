class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            if (!all_of(nums.begin(), nums.end(), [&](int v){ return v >= k; })) {
                return -1;
            }
    
            unordered_set<int> unique_vals;
            for (int v : nums) {
                if (v != k) {
                    unique_vals.insert(v);
                }
            }
    
            return unique_vals.size();
        }
    };
    