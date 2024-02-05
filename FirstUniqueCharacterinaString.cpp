// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            int j;
            for (j = 0; j < s.length(); j++) {
                if (i != j && s[i] == s[j])
                    break;
            }
            if (j == s.length()) {
                return i;  
            }
        }
        return -1;  
    }
};
