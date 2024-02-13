//Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "". A string is palindromic if it reads the same forward and backward.

class Solution {
public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        int n = words.size();
        if (n == 0)
            return "";
        
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            bool isPalindrome = true;
            for (int j = 0; j < m / 2; j++) {
                if (words[i][j] != words[i][m - 1 - j]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome)
                return words[i];
        }
        return "";
    }
};
