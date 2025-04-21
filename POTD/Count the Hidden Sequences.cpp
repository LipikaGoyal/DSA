class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long sum = 0, maxi = 0, mini = 0;
    
            for (int i : differences) {
                sum += i;
                maxi = max(maxi, sum);
                mini = min(mini, sum);
            }
            long zero = 0;
            return max(zero, upper - lower - maxi + mini + 1);
        }
    };