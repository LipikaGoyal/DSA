
class UnionFind {
    public:
        UnionFind(int n) {
            root.resize(n);
            rank.resize(n, 0);
            iota(root.begin(), root.end(), 0); 
        }
    
        int find(int x) {
            if (root[x] != x) {
                root[x] = find(root[x]);
            }
            return root[x];
        }
    
        bool merge(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
    
            if (root_x == root_y) {
                return true; 
            }
    
            if (rank[root_x] > rank[root_y]) {
                root[root_y] = root_x;
            } else if (rank[root_x] < rank[root_y]) {
                root[root_x] = root_y;
            } else {
                root[root_y] = root_x;
                rank[root_x]++;
            }
            return false;
        }
    
    private:
        vector<int> root;
        vector<int> rank;
    };
    
    class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
            UnionFind unionFind(n);
    
            for (const auto& edge : edges) {
                unionFind.merge(edge[0], edge[1]);
            }
            unordered_map<int, int> connectedComponentMinCost;
    
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (unionFind.find(u) == unionFind.find(v)) {
                    int root = unionFind.find(u);
                    if (connectedComponentMinCost.find(root) == connectedComponentMinCost.end()) {
                        connectedComponentMinCost[root] = w;
                    } else {
                        connectedComponentMinCost[root] &= w;
                    }
                }
            }
    
            vector<int> minCost;
            for (const auto& query : queries) {
                int origin = query[0], destination = query[1];
                if (unionFind.find(origin) != unionFind.find(destination)) {
                    minCost.push_back(-1);
                } else {
                    minCost.push_back(connectedComponentMinCost[unionFind.find(origin)]);
                }
            }
        
            return minCost;
        }
    };
    