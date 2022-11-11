#ifndef C7006ED9_EAE8_4A71_A6E8_4733AB3D26ED
#define C7006ED9_EAE8_4A71_A6E8_4733AB3D26ED
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};

#endif /* C7006ED9_EAE8_4A71_A6E8_4733AB3D26ED */
