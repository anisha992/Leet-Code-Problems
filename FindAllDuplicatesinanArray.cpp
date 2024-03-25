// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if (map[nums[i]] > 1)
                result.push_back(nums[i]);
        }
        return result; 
    }
};
