class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total = accumulate(nums.begin(), nums.end(), 0);
    
            if (total % 2 != 0)
                return false;
    
            int target = total / 2;
            unordered_set<int> possible_sums = {0};
    
            for (int num : nums) {
                vector<int> current_sums(possible_sums.begin(), possible_sums.end());
                for (int current_sum : current_sums) {
                    int new_sum = current_sum + num;
    
                    if (new_sum == target)
                        return true;
    
                    if (new_sum < target)
                        possible_sums.insert(new_sum);
                }
            }
    
            return false;
        }
    };
    