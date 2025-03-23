const int MOD = 1e9 + 7;
using pii = pair<unsigned long long, int>;
vector<pii> graph[200];

class Solution {
public:
    unsigned long long dijkstra(int start, int n, unsigned long long* dist) {
        vector<unsigned long long> ways(n, 0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.emplace(0, start);
        dist[start] = 0;
        ways[start] = 1;
        
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();
            
            for (auto [edgeWeight, neighbor] : graph[node]) {
                unsigned long long newDist = currDist + edgeWeight;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.emplace(newDist, neighbor);
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for (int i = 0; i < n; ++i) {
            graph[i].clear();
        }
        
        for (const auto& road : roads) {
            int u = road[0], v = road[1];
            unsigned long long weight = road[2];
            graph[u].emplace_back(weight, v);
            graph[v].emplace_back(weight, u);
        }
        
        unsigned long long dist[200];
        fill(dist, dist + n, ULLONG_MAX);
        
        return dijkstra(0, n, dist);
    }
};