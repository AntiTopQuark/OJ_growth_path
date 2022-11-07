#include <iostream>
#include <string>
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '6') {
                s.at(i) = '9';
                break;
            }
        }
        return stoi(s);
    }
};