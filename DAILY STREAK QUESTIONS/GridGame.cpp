// You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

// The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

// Link: https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res=LLONG_MAX;
        int n=grid[0].size();

        vector<long long> topPrefix(n+1, 0), bottomPrefix(n+1, 0);

        // Calculate prefix sums for both rows
        for(int i=0; i<n; i++)
        {
           topPrefix[i+1]=topPrefix[i]+grid[0][i];
           bottomPrefix[i+1]=bottomPrefix[i]+grid[1][i];
        }

        // We will be iterating through all possible switch points
        for(int i=0; i<n; i++)
        {
            // Points left for the second robot in the top row
            long long topLeft=topPrefix[n]-topPrefix[i+1];

            // Points left for the second robot in the bottom row
            long long bottomLeft=bottomPrefix[i];

            // Second robot collects the maximum of these two
            long long maxi=max(topLeft, bottomLeft);

            // Minimize the maximum score the second robot can collect
            res=min(res, maxi);
        }

        return res;
    }
};
