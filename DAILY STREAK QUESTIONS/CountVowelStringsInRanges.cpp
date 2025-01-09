// You are given a 0-indexed array of strings words and a 2D array of integers queries.

// Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

// Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> ans;
        int count = 0;
        vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
        vector<int> isVow(n, 0);
        for (int i = 0; i < n; i++) {
            char first = words[i][0];
            char last = words[i][words[i].size() - 1];
            if (find(vow.begin(), vow.end(), first) != vow.end() &&
                find(vow.begin(), vow.end(), last) != vow.end())
                isVow[i] = 1;
        }

        vector<int> prefixSum(n,0);
        prefixSum[0]=isVow[0];
        for(int i=1; i<n; i++)
        {
            prefixSum[i]=prefixSum[i-1]+isVow[i];
        }

        for (int i = 0; i < m; i++) {
            int st = queries[i][0];
            int en = queries[i][1];
            if(st==0)
            ans.push_back(prefixSum[en]);
            else
            ans.push_back(prefixSum[en]-prefixSum[st-1]);
        }
        return ans;
    }
};
