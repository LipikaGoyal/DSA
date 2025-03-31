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