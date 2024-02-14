//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers. You should rearrange the elements of nums such that the modified array follows the given conditions:
// Every consecutive pair of integers have opposite signs. For all integers with the same sign, the order in which they were present in nums is preserved.  The rearranged array begins with a positive integer. Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                positive.push_back(nums[i]);
            else
                negative.push_back(nums[i]);
        }
        for (int i = 0; i < positive.size(); i++) {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }
        return result;
    }
};
