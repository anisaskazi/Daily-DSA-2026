#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);

                if (dp[j] && dictionary.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main() {
    Solution obj;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << (obj.wordBreak(s, wordDict) ? "true" : "false") << endl;

    return 0;
}
