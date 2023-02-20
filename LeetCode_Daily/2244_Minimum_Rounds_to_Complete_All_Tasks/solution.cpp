#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // if (tasks.size() == 0) return -1;
        // int ans = 0;
        // map<int, int> word_count;
        // for (int i = 0; i < tasks.size(); i++) {
        //     if (word_count.find(tasks[i]) == word_count.end()) {
        //         word_count[tasks[i]] = 1;
        //     } else {
        //         word_count[tasks[i]]++;
        //     }
        // }

        // int max_num = -1;
        // for (auto it = word_count.begin(); it != word_count.end(); it++) {            
        //     max_num = max(max_num, it->second);
        // }

        // int result[10000+5];
        // result[0] = 9999999;
        // result[1] = 9999999;
        // result[2] = 1;
        // result[3] = 1;
        // for (int i = 4; i <= max_num+5; i++) {
        //     result[i] = min(result[i-2] + 1, result[i-3] + 1);
        // }

        // for (auto it = word_count.begin(); it != word_count.end(); it++) {            
        //     if (result[it->second] == 9999999) return -1;
        //     ans += result[it->second];
        // }
        // return ans;

        int ans = 0;
        unordered_map<int, int> umap;
        for (auto i: tasks) {
            umap[i]++;
        }
        for (auto i: umap) {
            int num = i.second;
            if (num == 1) return -1;
            ans += (num + 2) / 3;
        }
        return ans;
    }

};

int main() {
    Solution s;
    vector<int> input1 = {2,2,3,3,2,4,4,4,4,4};
    cout << s.minimumRounds(input1) << endl;
    
    return 0;
}