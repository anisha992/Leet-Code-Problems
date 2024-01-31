// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
class Solution {
public:
    vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indices;

        for (int i = 0; i < n; ++i) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                int prevIndex = indices.top();
                indices.pop();
                result[prevIndex] = i - prevIndex;
            }
            indices.push(i);
        }

        return result;
    }
};
  
