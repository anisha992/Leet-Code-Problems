// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time. ​Return the minimum number of intervals required to complete all tasks.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);
        for (char i : tasks) {
            frequencies[i - 'A']++;
        }
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        int maxFreq = frequencies[0] - 1;
        int idleSlots = maxFreq * n;
        for (int i = 1; i < frequencies.size(); i++) {
            idleSlots -= min(frequencies[i], maxFreq);
        }
        idleSlots = max(0, idleSlots);

        return idleSlots + tasks.size();
    }
};
