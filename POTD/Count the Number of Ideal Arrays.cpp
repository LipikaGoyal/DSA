const int MOD = 1e9 + 7;
int binomial[10001][14] = {1}, freq[10001][14] = {};

class Solution {
public:
    int idealArrays(int n, int maxVal) {
        if (binomial[1][1] == 0) {
            for (int i = 1; i <= 10000; ++i) {
                for (int j = 0; j < 14; ++j) {
                    binomial[i][j] =
                        (j == 0)
                            ? 1
                            : (binomial[i - 1][j] + binomial[i - 1][j - 1]) %
                                  MOD;
                }
            }

            for (int base = 1; base <= 10000; ++base) {
                freq[base][0] = 1;
                for (int multiple = 2 * base; multiple <= 10000;
                     multiple += base) {
                    for (int length = 0; freq[base][length]; ++length) {
                        freq[multiple][length + 1] =
                            (freq[multiple][length + 1] + freq[base][length]) %
                            MOD;
                    }
                }
            }
        }

        int result = 0;
        for (int val = 1; val <= maxVal; ++val) {
            for (int lenMinusOne = 0; lenMinusOne < min(14, n); ++lenMinusOne) {
                if (freq[val][lenMinusOne]) {
                    long long contribution = 1LL * freq[val][lenMinusOne] *
                                             binomial[n - 1][lenMinusOne];
                    result = (result + contribution % MOD) % MOD;
                }
            }
        }

        return result;
    }
};
