class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int freq[45]={0}, cnt=0;
            for(auto& d: dominoes){
                int d0=d[0], d1=d[1], x=(d0>d1)?d0*(d0-1)/2+d1-1:d1*(d1-1)/ 2+d0-1;
                    
                cnt+=freq[x];
                freq[x]++;
            }
            return cnt;
        }
    };