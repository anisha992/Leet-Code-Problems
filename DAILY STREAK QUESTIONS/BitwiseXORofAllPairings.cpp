// You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

// Return the bitwise XOR of all integers in nums3.
// Note: Take a pen and paper while solving this problem.

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 ^= nums1[i];
        }

        for (int i = 0; i < m; i++) {
            xor2 ^= nums2[i];
        }

        int res = 0;
        if (m % 2 != 0) {
            res ^= xor1;
        }             
        if (n % 2 != 0) {
            res ^= xor2;
        }
        return res;
    }
};
