#ifndef C4E25E10_DE75_4D53_A2CC_2DBC65DCF224
#define C4E25E10_DE75_4D53_A2CC_2DBC65DCF224
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        int len = s.length();
        while (i < len) {
            while (i < len && s[i] == ' ') {
                i++;
            }
            if (i < len) {
                if (j != 0) {
                    s[j++] = ' ';
                }
                int start = j;
                while (i < len && s[i] != ' ') {
                    s[j++] = s[i++];
                }
                reverse(s.begin() + start, s.begin() + j);
            }
        }
        s.erase(s.begin() + j, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
#endif /* C4E25E10_DE75_4D53_A2CC_2DBC65DCF224 */
