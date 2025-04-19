class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
    
            int pairs =0;
    
            for(int i =0; i<nums.size(); i++){
                int curr =  nums[i];
    
                int minVal = lower-curr;
                int maxVal = upper-curr;
    
                auto leftBound = lower_bound(nums.begin() + i + 1, nums.end(), minVal);
                auto rightBound = upper_bound(nums.begin() + i + 1, nums.end(), maxVal);
    
                pairs+=(rightBound - leftBound);
            }
    
            return pairs;
        }
    };