//Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        for(int i=0; i<n; i++)
        {
             int flag=1;
            for(int j=i+1; j<n; j++)
            {
               
                if(nums[i]==nums[j])
                {
                    flag++;
                }
                if(flag>n/2)
                return nums[i];
            }
        }
        return 1;
    }
};
