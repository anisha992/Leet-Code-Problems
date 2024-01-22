//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number. You are given an integer array nums representing the data status of this set after the error. Find the number that occurs twice and the number that is missing and return them in the form of an array.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> vec;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        std::set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                vec.push_back(nums[i]);  // Duplicate
                vec.push_back(i + 1);    // Missing
                break;
            }
        }

        return vec;
    }
};
