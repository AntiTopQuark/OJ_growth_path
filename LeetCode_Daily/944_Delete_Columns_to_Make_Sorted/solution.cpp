#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 思路： 实际上就是一个二维数组，从竖向看，遍历一遍就可以。
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for(int i = 0; i < strs[0].length(); i++) {
            for(int j = 0; j < strs.size()-1; j++) {
                if (strs[j+1][i] < strs[j][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> input1 = {"cba","daf","ghi"};
    cout << s.minDeletionSize(input1) << endl;
    vector<string> input2 = {"a","b"};
    cout << s.minDeletionSize(input2) << endl;
    return 0;
}