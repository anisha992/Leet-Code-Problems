// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> result;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(i!=j && words[j].find(words[i])!= string::npos){
               result.push_back(words[i]);
               break;
               }
            }
        }
        return result;
    }
};
