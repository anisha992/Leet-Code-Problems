// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstOccurrence(26, -1); // Store the first occurrence of each character
        vector<int> lastOccurrence(26, -1);  // Store the last occurrence of each character
        
        // Populate first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            if (firstOccurrence[s[i] - 'a'] == -1) {
                firstOccurrence[s[i] - 'a'] = i;
            }
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        int count = 0;
        
        // Check for each character as the boundary of the palindrome
        for (int i = 0; i < 26; i++) {
            int start = firstOccurrence[i];
            int end = lastOccurrence[i];
            
            if (start != -1 && end != -1 && start < end) {
                unordered_set<char> uniqueChars; // Store unique characters between start and end
                
                for (int j = start + 1; j < end; j++) {
                    uniqueChars.insert(s[j]);
                }
                
                count += uniqueChars.size(); // Add the number of unique characters as valid palindromes
            }
        }
        
        return count;
    }
};
