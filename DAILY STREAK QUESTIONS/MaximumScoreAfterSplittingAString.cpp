// Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int count0 = 0, count1 = 0, maxi = INT_MIN;

        for (int i = 1; i < n; i++) {  // Start at 1 to ensure non-empty left and right parts
            // Count zeros in the left part
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') count0++;
            }

            // Count ones in the right part
            for (int j = i; j < n; j++) {
                if (s[j] == '1') count1++;
            }

            // Calculate the score for the current split
            int sum = count0 + count1;

            // Update the maximum score
            maxi = max(maxi, sum);

            // Reset counts for the next iteration
            count0 = 0;
            count1 = 0;
        }

        return maxi;
    }
};
