class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> freq;
            
            for (int num : nums) {
                freq[num]++;
            }
    
            int dom = -1;
            int n = nums.size();
            
            for (auto p : freq) {
                if (p.second * 2 > n) {
                    dom = p.first;
                    break;
                }
            }
    
    
            int leftCount = 0, rightCount = freq[dom];
    
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == dom) {
                    leftCount++;
                    rightCount--;
                }
    
                if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                    return i;
                }
            }
    
            return -1;
        }
    };
    