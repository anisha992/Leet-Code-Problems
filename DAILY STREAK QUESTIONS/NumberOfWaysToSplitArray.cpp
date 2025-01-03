// You are given a 0-indexed integer array nums of length n.

// nums contains a valid split at index i if the following are true:

// The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
// There is at least one element to the right of i. That is, 0 <= i < n - 1.
// Return the number of valid splits in nums.

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0; 
        long long sum2 = 0;
        long long totalSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        for (int i = 0; i < n-1; i++) {
            sum1 += nums[i];
            sum2 = totalSum - sum1;
            if (sum1 >= sum2) {
                count++;
            }
            
        }
        return count;
    }
};
