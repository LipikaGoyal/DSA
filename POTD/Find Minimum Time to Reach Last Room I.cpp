
class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
            vector<vector<int>> minArrivalTime(rows, vector<int>(cols, INT_MAX));
            vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            int minimumTime = INT_MAX;
    
            function<void(int, int, int)> dfs = [&](int r, int c, int currentTime) {
                if (currentTime >= minArrivalTime[r][c])
                    return;
                minArrivalTime[r][c] = currentTime;
    
                if (r == rows - 1 && c == cols - 1) {
                    minimumTime = min(minimumTime, currentTime);
                    return;
                }
    
                for (auto& dir : directions) {
                    int newRow = r + dir.first;
                    int newCol = c + dir.second;
    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                        newCol < cols && !isVisited[newRow][newCol]) {
                        isVisited[newRow][newCol] = true;
                        int cellWait = grid[newRow][newCol];
                        int arrival =
                            cellWait > currentTime ? cellWait + 1 : currentTime + 1;
    
                        if (r == 0 && c == 0 && cellWait <= currentTime) {
                            arrival = cellWait + 1;
                        }
    
                        dfs(newRow, newCol, arrival);
                        isVisited[newRow][newCol] = false;
                    }
                }
            };
    
            isVisited[0][0] = true;
            dfs(0, 0, 0);
            return minimumTime;
        }
    };