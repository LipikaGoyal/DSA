class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount, 0);
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;
        vector<int> thresholdForMaxPoints(totalCells + 1, 0);
        vector<vector<int>> minValueToReach(rowCount, vector<int>(colCount, numeric_limits<int>::max()));
        
        minValueToReach[0][0] = grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(grid[0][0], 0, 0);
        int visitedCells = 0;
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!minHeap.empty()) {
            auto [currentValue, row, col] = minHeap.top();
            minHeap.pop();
            thresholdForMaxPoints[++visitedCells] = currentValue;
            
            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 && newCol < colCount && 
                    minValueToReach[newRow][newCol] == numeric_limits<int>::max()) {
                    minValueToReach[newRow][newCol] = max(currentValue, grid[newRow][newCol]);
                    minHeap.emplace(minValueToReach[newRow][newCol], newRow, newCol);
                }
            }
        }
        
        for (int i = 0; i < queryCount; ++i) {
            int threshold = queries[i], left = 0, right = totalCells;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (thresholdForMaxPoints[mid] < threshold)
                    left = mid;
                else
                    right = mid - 1;
            }
            result[i] = left;
        }
        return result;
    }
};
