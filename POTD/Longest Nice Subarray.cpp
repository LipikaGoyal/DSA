class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size();
            int ml = 1;
            int l = 0;
            int usb = 0;
            
            for (int r = 0; r < n; ++r) {
                while ((usb & nums[r]) != 0) {
                    usb ^= nums[l];
                    ++l;
                }
                
                usb |= nums[r];
                ml = max(ml, r - l + 1);
            }
            
            return ml;
        }
    };