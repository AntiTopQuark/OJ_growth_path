#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool mycompl(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    // TLE
    // int findMinArrowShots(vector<vector<int>>& points) {
    //     if (points.size() == 1) return 1;
    //     sort(points.begin(), points.end(), mycompl);
    //     int ans = 1;
    //     int pos = 0;
    //     int right = points[pos][1];

    //     while (pos < points.size()) {
    //         if ( right < points[pos][0]) {
    //             ans++;
    //             right = points[pos][1];
    //         }
    //         pos++;
    //     }
    //     return ans;
    // }

    int findMinArrowShots(vector<vector<int>>& points) {
        //应该是区间的范围越大越好
        int size = points.size();
        if(size==0) return 0;
        sort(points.begin(), points.end(),[](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int total = 1,flag = points[0][1];
        for(int i=0;i<size;i++){
            //说明这个时候两个区间不相交
            if(points[i][0]>flag){
                total++;//不相交，射箭数量+1
                flag = points[i][1];//更新尾部区间
            }
        }
        return total;
    }
};