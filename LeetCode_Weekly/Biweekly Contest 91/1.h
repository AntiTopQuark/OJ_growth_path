class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<double> m;
        for(int i = 0; i< nums.size()/2; i++){
            double avg = (nums[i] + nums[nums.size()-1-i])/2.0;
            m.insert(avg);
        }
        return m.size();
    }
};