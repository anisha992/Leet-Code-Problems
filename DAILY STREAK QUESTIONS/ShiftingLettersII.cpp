// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftImpact(n + 1, 0); // Difference array to track shift impacts
        
        // Populate the shift impact array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2]; // 1 for forward, 0 for backward
            
            if (direction == 1) { // Forward shift
                shiftImpact[start] += 1;
                shiftImpact[end + 1] -= 1;
            } else { // Backward shift
                shiftImpact[start] -= 1;
                shiftImpact[end + 1] += 1;
            }
        }
        
        // Compute prefix sum to determine the net shift for each index
        int netShift = 0;
        for (int i = 0; i < n; i++) {
            netShift += shiftImpact[i];
            int effectiveShift = (netShift % 26 + 26) % 26; // Handle negative shifts
            
            // Apply the shift to the current character
            s[i] = 'a' + (s[i] - 'a' + effectiveShift) % 26;
        }
        
        return s;
    }
};
