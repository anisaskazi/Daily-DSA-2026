class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for (string word : words) {
            string lower = "";
            for (char c : word) {
                lower += tolower(c);
            }

            int rowIndex = -1;

            for (int i = 0; i < 3; i++) {
                if (rows[i].find(lower[0]) != string::npos) {
                    rowIndex = i;
                    break;
                }
            }

            bool valid = true;

            for (char c : lower) {
                if (rows[rowIndex].find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
