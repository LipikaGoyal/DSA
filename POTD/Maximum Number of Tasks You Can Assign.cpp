class Solution {
    public:
        bool isFeasible(int taskCount, const vector<int>& tasks, const vector<int>& workers,
                        int pillsLeft, int pillPower) {
            multimap<int, int> workerPool;
            int totalWorkers = workers.size();
    
            for (int i = totalWorkers - taskCount; i < totalWorkers; ++i) {
                workerPool.emplace(workers[i], 1);
            }
    
            for (int i = taskCount - 1; i >= 0; --i) {
                int taskStrength = tasks[i];
                auto maxWorker = prev(workerPool.end());
    
                if (maxWorker->first >= taskStrength) {
                    if (--maxWorker->second == 0) workerPool.erase(maxWorker);
                } else {
                    if (pillsLeft == 0) return false;
    
                    int neededStrength = taskStrength - pillPower;
                    auto eligible = workerPool.lower_bound(neededStrength);
                    if (eligible == workerPool.end()) return false;
    
                    if (--eligible->second == 0) workerPool.erase(eligible);
                    --pillsLeft;
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int pillPower) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low = 0, high = min(tasks.size(), workers.size());
            int result = 0;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (isFeasible(mid, tasks, workers, pills, pillPower)) {
                    result = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return result;
        }
    };
    