class Solution {
    public:
        long long countValidNumbers(string numberStr, string suffix, int maxDigit) {
            int totalLength = numberStr.size(), suffixLength = suffix.size();
            if (totalLength < suffixLength) return 0;
            if (totalLength == suffixLength) return numberStr >= suffix ? 1 : 0;
    
            string numberSuffix = numberStr.substr(totalLength - suffixLength, suffixLength);
            long long count = 0;
            int prefixLength = totalLength - suffixLength;
    
            for (int i = 0; i < prefixLength; i++) {
                int currentDigit = numberStr[i] - '0';
    
                if (maxDigit < currentDigit) {
                    count += (long)pow(maxDigit + 1, prefixLength - i);
                    return count;
                }
    
                count += (long)currentDigit * (long)pow(maxDigit + 1, prefixLength - i - 1);
            }
    
            if (numberSuffix >= suffix) count++;
            return count;
        }
    
        long long numberOfPowerfulInt(long long start, long long finish, int maxDigit, string suffix) {
            string startStr = to_string(start - 1);
            string finishStr = to_string(finish);
            return countValidNumbers(finishStr, suffix, maxDigit) - countValidNumbers(startStr, suffix, maxDigit);
        }
    };
    