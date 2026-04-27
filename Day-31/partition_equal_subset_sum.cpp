#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int num : nums) {
            for (int sum = target; sum >= num; sum--) {
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 11, 5};

    cout << (obj.canPartition(nums) ? "true" : "false") << endl;

    return 0;
}
