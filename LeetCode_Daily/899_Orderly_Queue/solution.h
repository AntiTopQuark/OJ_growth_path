#ifndef F402E55F_B79D_485A_B2DD_15E130638E98
#define F402E55F_B79D_485A_B2DD_15E130638E98
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string string_pinjie(string s, int index) {
        string res = "";
        for (int i = index; i < s.length(); i++){
            res.push_back(s[i]);
        }
        cout<< res<<endl;
        for (int i = 0; i < index; i++){
            res.push_back(s[i]);
        }
        return res;
    }
    string orderlyQueue(string s, int k) {
        if (s == "" || k == 0 || s.length() == 1) {
            return s;
        } else if (k == 1) {
            char min_char = s[0];
            int index = 0;
            for(int i = 0; i < s.length();i++) {
                if (s[i] < min_char) {
                    min_char = s[i];
                    index = i;
                }
            }
            vector<string> res;
            for(int i = 0; i < s.length();i++) {
                if (s[i] == min_char) {
                    res.push_back(string_pinjie(s, i));
                }
            }
            sort(res.begin(), res.end());
            return res[0];
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};

#endif /* F402E55F_B79D_485A_B2DD_15E130638E98 */
