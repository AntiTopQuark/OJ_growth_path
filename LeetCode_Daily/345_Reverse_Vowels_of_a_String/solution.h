#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    inline bool is_vowel(char a) {
        if (a == 'a' || a == 'A' ||
            a == 'e' || a == 'E' ||
            a == 'i' || a == 'I' ||
            a == 'o' || a == 'O' ||
            a == 'u' || a == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() -1;
        while (start <= end) {
            if (!is_vowel(s[start])) {
                start ++;continue;
            }
            if (!is_vowel(s[end])) {
                end --; continue;
            }
            
            char tmp;
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start ++;end--;
        }
        return s;
    }
};