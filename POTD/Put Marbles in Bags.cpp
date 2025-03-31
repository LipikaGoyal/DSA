class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            if(k==1 || weights.size()==k) return 0;
            int n = weights.size();
    
            priority_queue<int>pq;
    
            for(int i = 0; i< weights.size()-1; i++){
                pq.push(weights[i]+weights[i+1]);
            }
    
            long long maxi = weights[0]+weights[n-1], mini = weights[0]+weights[n-1];
            for(int i = 0; i< k-1; i++){
                auto p = pq.top();
                pq.pop();
                maxi+= p;
            }
    
    
            priority_queue<int,vector<int>,greater<int>>pq1;
    
            for(int i = 0; i< weights.size()-1; i++){
                pq1.push(weights[i]+weights[i+1]);
            }
    
            for(int i = 0; i< k-1; i++){
                auto p = pq1.top();
                pq1.pop();
                mini+= p;
            }
    
            return maxi-mini;
    
        }
    };


    //Solution 2 (Better)

    class Solution {
        public:
            long long putMarbles(vector<int>& weights, int k) {
                if(k==1 || weights.size()==k) return 0;
                int n = weights.size();
                vector<int> pw(n - 1, 0);
        
                for(int i = 0; i< weights.size()-1; i++){
                    pw[i]=(weights[i]+weights[i+1]);
                }
        
                sort(pw.begin(), pw.end());
        
                long long maxi = weights[0]+weights[n-1], mini = weights[0]+weights[n-1];
                for(int i = 0; i< k-1; i++){
                    auto p = pw[n-2-i];
                    maxi+= p;
                }
        
                for(int i = 0; i< k-1; i++){
                    auto p = pw[i];
                    mini+= p;
                }
        
                return maxi-mini;
        
            }
        };