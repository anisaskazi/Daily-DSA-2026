#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfitValue = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfitValue = max(maxProfitValue, price - minPrice);
        }

        return maxProfitValue;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.maxProfit(prices) << endl; // Output: 5

    return 0;
}
