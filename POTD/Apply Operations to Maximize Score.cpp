class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxElement);

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int prime : primes) {
                if (prime * prime > num) break;
                if (num % prime != 0) continue;
                primeScores[i]++;
                while (num % prime == 0) num /= prime;
            }
            if (num > 1) primeScores[i]++;
        }

        vector<int> nextDominant(n, n), prevDominant(n, -1);
        deque<int> decreasingPrimeScoreStack;

        for (int i = 0; i < n; ++i) {
            while (!decreasingPrimeScoreStack.empty() && primeScores[decreasingPrimeScoreStack.back()] < primeScores[i]) {
                nextDominant[decreasingPrimeScoreStack.back()] = i;
                decreasingPrimeScoreStack.pop_back();
            }
            if (!decreasingPrimeScoreStack.empty()) {
                prevDominant[i] = decreasingPrimeScoreStack.back();
            }
            decreasingPrimeScoreStack.push_back(i);
        }

        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; ++i) {
            numOfSubarrays[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }

        vector<pair<int, int>> sortedArray;
        for (int i = 0; i < n; ++i) {
            sortedArray.emplace_back(nums[i], i);
        }
        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;

        while (k > 0) {
            int num = sortedArray[processingIndex].first;
            int index = sortedArray[processingIndex].second;
            processingIndex++;

            int operations = min(k, (int)min(numOfSubarrays[index], (long long)INT_MAX));
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }

        return (int)score;
    }

private:
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int num = 2; num <= limit; ++num) {
            if (!isPrime[num]) continue;
            primes.push_back(num);
            for (long long multiple = (long long)num * num; multiple <= limit; multiple += num) { 
                isPrime[multiple] = false;
            }
        }
        return primes;
    }

    long long power(long long base, int exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }
};
