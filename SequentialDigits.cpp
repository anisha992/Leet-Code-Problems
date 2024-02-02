// An integer has sequential digits if and only if each digit in the number is one more than the previous digit. Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>a;
        for(int i=1; i<=9; ++i)
        {
            int num=i;
            int nextdigit=i+1;
            while(num<=high && nextdigit<=9)
            {
                num=num*10 + nextdigit;
                if(low<=num && num<=high)
                a.push_back(num);
                ++nextdigit;
            }
        }
        sort(a.begin(), a.end());
        return a;
    }
};
