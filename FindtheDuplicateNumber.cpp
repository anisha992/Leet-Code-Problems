// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if (map[nums[i]] > 1)
                return nums[i];
        }
        return 0; 
    }
};
