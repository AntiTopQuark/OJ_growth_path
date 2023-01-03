#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.size() == 1) {
            return 0;
        }

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
    
    return 0;
}