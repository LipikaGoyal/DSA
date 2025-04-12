class Solution {
    vector<long long> factorials;

    long long calculateValidPermutations(vector<int>& digitCount, int totalDigits) {
        long long totalPerms = factorials[totalDigits];
        for (int d = 0; d < 10; ++d) {
            totalPerms /= factorials[digitCount[d]];
        }

        long long invalidPerms = 0;
        if (digitCount[0] > 0) {
            vector<int> updatedCount = digitCount;
            updatedCount[0]--;
            invalidPerms = factorials[totalDigits - 1];
            for (int d = 0; d < 10; ++d) {
                invalidPerms /= factorials[updatedCount[d]];
            }
        }

        return totalPerms - invalidPerms;
    }

    string generateSignature(vector<int>& digitFreq) {
        string signature = "";
        for (int d = 0; d < 10; ++d)
            signature += to_string(digitFreq[d]) + "#";
        return signature;
    }

    string createPalindrome(int base, int totalLength) {
        string half = to_string(base);
        string mirrorPart = (totalLength % 2 == 0) ? half : half.substr(0, half.size() - 1);
        reverse(mirrorPart.begin(), mirrorPart.end());
        return half + mirrorPart;
    }

public:
    long long countGoodIntegers(int digitLength, int divisor) {
        factorials = vector<long long>(digitLength + 1, 1);
        for (int i = 1; i <= digitLength; ++i)
            factorials[i] = factorials[i - 1] * i;

        unordered_set<string> seen;
        long long count = 0;

        int halfLen = (digitLength + 1) / 2;
        int lower = (halfLen > 1) ? pow(10, halfLen - 1) : 1;
        int upper = pow(10, halfLen);

        for (int num = lower; num < upper; ++num) {
            string palindrome = createPalindrome(num, digitLength);
            long long value = stoll(palindrome);
            if (value % divisor != 0) continue;

            vector<int> digitFreq(10, 0);
            for (char ch : palindrome)
                digitFreq[ch - '0']++;

            string signature = generateSignature(digitFreq);
            if (seen.count(signature)) continue;
            seen.insert(signature);

            count += calculateValidPermutations(digitFreq, digitLength);
        }

        return count;
    }
};
