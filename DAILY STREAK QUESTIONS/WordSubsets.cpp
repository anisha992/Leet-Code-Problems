// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        // int m = words2.size();
        unordered_map<char, int> req;

        for (const string word : words2) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }

            for (const auto entry : freq) {
                req[entry.first] = max(req[entry.first], entry.second);
            }
        }

        vector<string> ans;

        for (const string word : words1) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }

            bool isValid = true;

            for (const auto entry : req) {
                if (entry.second > freq[entry.first]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                ans.push_back(word);
        }

        return ans;
    }
};
