struct P {
    int t, x, y, d;
    P(int t, int x, int y, int d) : t(t), x(x), y(y), d(d) {}
    bool operator>(const P& o) const { return t > o.t; }
};

class Solution {
public:
    static int minTimeToReach(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> minT(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.emplace(-1, 0, 0, 1);
        minT[0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j, d] = pq.top(); pq.pop();

            if (i + 1 < n) upd(i + 1, j, t, d, g, minT, pq);
            if (i - 1 >= 0) upd(i - 1, j, t, d, g, minT, pq);
            if (j + 1 < m) upd(i, j + 1, t, d, g, minT, pq);
            if (j - 1 >= 0) upd(i, j - 1, t, d, g, minT, pq);

            if (minT[n - 1][m - 1] != INT_MAX) return minT[n - 1][m - 1];
        }
        return -1;
    }

private:
    static void upd(int x, int y, int t, int d, vector<vector<int>>& g,
                    vector<vector<int>>& minT, priority_queue<P, vector<P>, greater<P>>& pq) {
        int nt = d + max(t, g[x][y]);
        if (minT[x][y] > nt) {
            minT[x][y] = nt;
            pq.emplace(nt, x, y, d == 1 ? 2 : 1);
        }
    }
};
