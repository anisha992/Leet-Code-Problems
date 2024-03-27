//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0)
            return 0;
        int result = 0;
        
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            product = 1;
            for (int j = i; j < nums.size(); j++) {
                product *= nums[j];
                if (product < k)
                    result++;
                else
                    break;
            }
        }
        return result;
    }
};

