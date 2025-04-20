class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            vector<int> freq(1000,0);
            int cnt=0;
            for(int x: answers){
                cnt+=(freq[x]++%(x+1)==0)*(x+1);
            }
            return cnt;
        }
    };