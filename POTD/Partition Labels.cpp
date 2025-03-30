class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> lastOccurrence;
            int n = s.size();
            
            for (int i = 0; i < n; i++) {
                lastOccurrence[s[i]] = i;
            }
    
            vector<int> result;
            int start = 0, end = 0;
    
            for (int i = 0; i < n; i++) {
                end = max(end, lastOccurrence[s[i]]); 
                
                if (i == end) { 
                    result.push_back(end - start + 1);
                    start = i + 1;
                }
            }
    
            return result;
        }
    };