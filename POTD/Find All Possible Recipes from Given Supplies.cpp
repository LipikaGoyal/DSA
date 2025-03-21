class Solution {
    public:
        static vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            unordered_set<string> supplySet(supplies.begin(), supplies.end());
            unordered_map<string, vector<int>> graph;
            vector<int> degree(n, 0);
    
            for (int i = 0; i < n; i++) {
                for (const string& ing : ingredients[i]) {
                    if (!supplySet.count(ing)) {
                        graph[ing].push_back(i);
                        degree[i]++;
                    }
                }
            }
    
            queue<int> q;
            for (int i = 0; i < n; i++)
                if (degree[i] == 0) q.push(i);
    
            vector<string> res;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                res.push_back(recipes[i]);
                for (int j : graph[recipes[i]])
                    if (--degree[j] == 0) q.push(j);
            }
            return res;
        }
    };
    