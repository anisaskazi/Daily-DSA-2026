#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }

        vector<int> result;
        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
