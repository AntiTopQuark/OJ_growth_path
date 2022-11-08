#ifndef FCD208EE_3FA1_4919_9F4B_7167615ED2A3
#define FCD208EE_3FA1_4919_9F4B_7167615ED2A3

#include <iostream>
#include <string>
using namespace std;

// https://leetcode.com/submissions/detail/839116409/
class Solution {
public:
    string makeGood(string s) {
        if (s.length() <= 1) {
            return s;
        }
        bool need_to_del ;
        do {
            need_to_del = false;
            for(int i = 0; i < s.length()-1; i++) {
                bool one_need_to_del = false;
                if ((s[i] >='a' && s[i] <= 'z') && 
                    (s[i+1]>='A' && s[i+1] <='Z') && 
                    ((s[i]-'a') == (s[i+1] - 'A')) ) {
                        need_to_del = true;
                        one_need_to_del = true;
                } else if ((s[i+1] >='a' && s[i+1] <= 'z') && 
                            (s[i]>='A' && s[i] <='Z') && 
                            ((s[i+1]-'a') == (s[i] - 'A')) ) {
                    need_to_del = true;
                    one_need_to_del = true;
                }
                if (one_need_to_del) {
                    if (s.length() == 2) {
                        return "";
                    } 
                    s.erase(i,2);
                }
            }
        } while (need_to_del);
        return s;
    }
};

#endif /* FCD208EE_3FA1_4919_9F4B_7167615ED2A3 */
