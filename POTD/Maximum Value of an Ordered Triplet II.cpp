class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
    
            long long result = 0;
            long long maxDiff = 0;
            long long maxi = 0;
            int n = nums.size();
    
            for(int k = 0; k < n; k++){
                result = max(result, (long long)maxDiff*nums[k]);
                maxDiff = max(maxDiff, (long long)maxi - nums[k]);
                maxi = max(maxi, (long long)nums[k]);   
            }
    
            return result;
    
        }
    };