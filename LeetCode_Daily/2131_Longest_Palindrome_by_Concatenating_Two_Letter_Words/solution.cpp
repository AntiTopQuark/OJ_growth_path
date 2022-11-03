#include "solution.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution s;
    vector<string> words;
    words.push_back("dd");
    words.push_back("aa");
    words.push_back("bb");words.push_back("dd");words.push_back("aa");words.push_back("dd");
    words.push_back("bb");words.push_back("dd");words.push_back("aa");
    words.push_back("cc");words.push_back("bb");words.push_back("cc");
    words.push_back("dd");words.push_back("cc");
    cout << s.longestPalindrome(words) << endl;
}