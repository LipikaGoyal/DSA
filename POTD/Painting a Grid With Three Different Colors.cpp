class Solution {
public:
    vector<vector<int>> dp;
    vector<string> cols;
    const int MOD = 1e9 + 7;

    void genCols(string col, int rem, int prev) {
        if (rem == 0) {
            cols.push_back(col);
            return;
        }
        for (int c = 1; c <= 3; ++c) {
            if (c != prev)
                genCols(col + to_string(c), rem - 1, c);
        }
    }

    int count(int remCols, int prevIdx, int m) {
        if (remCols == 0) return 1;
        if (dp[remCols][prevIdx] != -1) return dp[remCols][prevIdx];

        int res = 0;
        string &prev = cols[prevIdx];

        for (int i = 0; i < cols.size(); ++i) {
            string &curr = cols[i];
            bool ok = true;

            for (int r = 0; r < m; ++r) {
                if (prev[r] == curr[r]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                res = (res + count(remCols - 1, i, m)) % MOD;
        }

        return dp[remCols][prevIdx] = res;
    }

    int colorTheGrid(int m, int n) {
        cols.clear();
        genCols("", m, -1);

        int k = cols.size();
        dp.assign(n, vector<int>(k, -1));

        int res = 0;
        for (int i = 0; i < k; ++i)
            res = (res + count(n - 1, i, m)) % MOD;

        return res;
    }
};
