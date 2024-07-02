// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
// Example 1:
// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int odd = 0;
            if (arr[i] % 2 != 0) {
                odd += 1;
                if (i+1<arr.size() && arr[i + 1] % 2 != 0)
                    odd += 1;
                if (i+2<arr.size() && arr[i + 2] % 2 != 0)
                    odd += 1;
            }
            if (odd == 3)
                return true;
        }
        return false;
    }
};
