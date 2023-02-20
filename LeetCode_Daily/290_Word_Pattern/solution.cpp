#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    /*C++手动实现split函数*/
    void split(const string& s, vector<string>& tokens, const string& delimiters = " ") {
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) {
            tokens.push_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delimiters, pos);
            pos = s.find_first_of(delimiters, lastPos);
        }
    }
    /*
    * 思路是建立一个映射map，key是pattern中的字符，value是s中的单词
    * 遍历pattern和s，如果map中没有pattern[i]，则将s中的单词加入map
    * 如果map中有pattern[i]，则判断map中的value是否等于s中的单词
    * */
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        split(s, words);
        if (pattern.size() == 1 && words.size() == 1) {
            return true;
        } else if (pattern.size() != words.size()) {
            return false;
        }
        map<string, char> s2p_map;
        map<char,string> p2s_map;
        for (auto i = 0; i < pattern.size(); i++) {
            if (s2p_map.find(words[i]) == s2p_map.end()) {
                // 没找到的情况, 需要判断value是否重复
                if (p2s_map.find(pattern[i]) != p2s_map.end()) {
                    return false;
                }
                s2p_map[words[i]] = pattern[i];
                p2s_map[pattern[i]] = words[i];
            } else {
                if (s2p_map[words[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main () {
    Solution s;
    string pattern = "aaaa";
    string input = "dog cat cat dog";
    cout<< s.wordPattern(pattern,input) << endl;
    return 0;
}