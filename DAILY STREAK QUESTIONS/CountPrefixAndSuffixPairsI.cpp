// You are given a 0-indexed string array words.

// Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

 class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int n = words.size();
        int count = 0;

        // Iterate through all pairs of indices (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        // Check if str1 is both a prefix and suffix of str2
        if (n1 > n2) {
            return false; // str1 cannot be both prefix and suffix if it is longer than str2
        }

        // Check prefix
        if (str2.substr(0, n1) != str1) {
            return false;
        }

        // Check suffix
        if (str2.substr(n2 - n1) != str1) {
            return false;
        }

        return true; // str1 is both prefix and suffix of str2
    }
};
