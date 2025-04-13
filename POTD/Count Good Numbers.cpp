class Solution {
    public:
        long long MOD = 1e9 + 7;
    
        long long myPow(long long base, long long exp) {
            long long result = 1;
            base = base % MOD;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % MOD; 
                }
                base = (base * base) % MOD; 
                exp /= 2;
            }
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long cnteven = (n + 1) / 2; 
            long long cntodd = n / 2;       
            
            long long result = (myPow(5, cnteven) * myPow(4, cntodd)) % MOD;
            return (int)result; 
        }
    };
    