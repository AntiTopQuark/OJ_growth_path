#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int>& nums, int start, int end, int target) {
        if (start > end) return start;
        int mid = (start + end) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return find(nums, start, mid - 1, target);
        else return find(nums, mid + 1, end, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        // Solution1:递归实现的二分查找
        //return find(nums, 0, nums.size() - 1, target);
        

        // Solution2:循环实现的二分查找
        int start =0;
        int end = nums.size() -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 7;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}