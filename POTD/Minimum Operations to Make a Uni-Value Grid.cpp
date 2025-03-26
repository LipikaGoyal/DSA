class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<int> arr;
    
            for(auto vec : grid){
                for(int val: vec){
                    arr.push_back(val);
                }
            }
    
            sort(arr.begin(), arr.end());
    
            int median = arr[arr.size()/2];
            int steps=0;
    
            for(int val: arr){
                if(abs(val-median)%x!=0){
                    return -1;
                }
                else{
                    steps+=abs(val-median)/x;
                }
            }
    
            return steps;
        }
    };