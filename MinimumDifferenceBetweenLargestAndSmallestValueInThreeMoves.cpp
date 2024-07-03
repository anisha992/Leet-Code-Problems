class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (nums.size() <= 4)
            return 0;

        int diff1 = nums[n - 1] - nums[3];
        int diff2 = nums[n - 2] - nums[2];
        int diff3 = nums[n - 3] - nums[1];
        int diff4 = nums[n - 4] - nums[0];

        return min({diff1, diff2, diff3, diff4});
    }
};
