class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            return possible(rectangles, 0) || possible(rectangles, 1);
        }
    
        bool possible(vector<vector<int>>& rectangles, int axis) {
            sort(rectangles.begin(), rectangles.end(), 
                 [axis](const vector<int>& a, const vector<int>& b) {
                     return a[axis] < b[axis];
                 });
    
            int cuts = 0;
            int previousEnd = -1;
    
            for (auto& rect : rectangles) {
                int start = rect[axis];
                int end = rect[axis + 2];
                if (start >= previousEnd) cuts++;
                previousEnd = max(previousEnd, end);
    
                if (cuts >= 3) return true;
            }
    
            return false;
        }
    };
    