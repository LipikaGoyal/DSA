class Solution {
    public:
        unordered_map<int, vector<int>> g;
    
        int countCompleteComponents(int n, vector<vector<int>>& e) {
            for (auto& ed : e) {
                g[ed[0]].push_back(ed[1]);
                g[ed[1]].push_back(ed[0]);
            }
    
            unordered_set<int> vis;
            int cnt = 0;
    
            for (int i = 0; i < n; i++) {
                if (!vis.count(i)) {
                    unordered_set<int> comp;
                    dfs(i, comp, vis);
                    if (isComp(comp)) cnt++;
                }
            }
            return cnt;
        }
    
        void dfs(int node, unordered_set<int>& comp, unordered_set<int>& vis) {
            comp.insert(node);
            vis.insert(node);
            for (int nei : g[node]) {
                if (!vis.count(nei)) {
                    dfs(nei, comp, vis);
                }
            }
        }
    
        bool isComp(unordered_set<int>& comp) {
            for (int node : comp) {
                if (g[node].size() != comp.size() - 1) {
                    return false;
                }
            }
            return true;
        }
    };
    