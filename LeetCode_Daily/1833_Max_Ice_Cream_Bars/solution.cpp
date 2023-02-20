#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins >= costs[i]) {
                ans++;
                coins -= costs[i];
            }
        }
        return ans;
    }
}; 