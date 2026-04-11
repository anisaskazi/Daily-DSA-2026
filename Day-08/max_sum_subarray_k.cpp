#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int windowSum = 0;
        int maxSum = 0;

        // first window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        maxSum = windowSum;

        // sliding window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];        // add next
            windowSum -= nums[i - k];    // remove previous

            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};
