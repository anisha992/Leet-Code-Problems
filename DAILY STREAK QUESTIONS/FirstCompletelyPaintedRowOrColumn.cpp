// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

// Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int, pair<int, int>>pos;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                pos[mat[i][j]]={i, j};
            }
        }

        vector<int> row(n, 0), col(m, 0);

        for(int i=0; i<arr.size(); i++)
        {
            int value=arr[i];

            auto [r,c]=pos[value];
            row[r]++;
            col[c]++;

            if(row[r]==m || col[c]==n)
            return i;
        }
        return -1;
    }
};
