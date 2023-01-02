#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1) {
            return true;
        }

        bool res1 = true;
        for(auto i = 0; i < word.length(); i++) {
            if (word[i] <= 'Z' && word[i] >= 'A') {

            } else {
                res1 = false;
            }
        }

        bool res2 = true;
        for(auto i = 0; i < word.length(); i++) {
            if (word[i] <= 'z' && word[i] >= 'a') {

            } else {
                res2 = false;
            }
        }

        bool res3 = true;
        for(auto i = 0; i < word.length(); i++) {
            if (i == 0 && word[i] <= 'Z' && word[i] >= 'A') {
                continue;
            } else if (word[i] <= 'z' && word[i] >= 'a') {
                continue;
            } else {
                res3 = false;
            }
        }

        return res1 || res2 || res3;
    }
};

int main() {
    Solution s;
    string input = "USA";
    cout << s.detectCapitalUse(input) << endl;
    string input2 = "FlaG";
    cout << s.detectCapitalUse(input2) << endl;
    return 0;
}