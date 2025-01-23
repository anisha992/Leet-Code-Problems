// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.

// Link: https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);
       
        int result=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && (rowCount[i]>1 || colCount[j]>1))
                result++;
            }
        }

        return result;
    }
};
