class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            string result = dominoes;
    
            int i = 0;
            char left = 'L';
    
            while (i < n) {
                int j = i;
                while (j < n && result[j] == '.') {
                    j++;
                }
    
                char right = (j < n) ? result[j] : 'R'; 
    
                if (left == right) {
                    for (int k = i; k < j; k++) result[k] = left;
                } else if (left == 'R' && right == 'L') {
                    int l = i, r = j - 1;
                    while (l < r) {
                        result[l++] = 'R';
                        result[r--] = 'L';
                    }
                }
    
                left = right;
                i = j + 1;
            }
    
            return result;
        }
    };
    