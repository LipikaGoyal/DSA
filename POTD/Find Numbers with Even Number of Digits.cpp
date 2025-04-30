class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            
            bool isEven = true;
            int cntEven = 0;
    
            for(int num : nums){
                isEven = true;
                while(num!=0){
                    num = num/10;
                    if(isEven==true) isEven=false;
                    else isEven = true;
                }
                if(isEven==true) cntEven++;
            }
            return cntEven;
        }
    };