// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> a;
        vector<int> b;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            a.push_back(A[i]);
            b.push_back(B[i]);
            int m = a.size();
            int count = 0;

            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if (a[j] == b[k])
                        count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
