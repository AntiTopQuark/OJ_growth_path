#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


// 基于DFS的方式来先求出全部的组合情况，然后找到其中的回文字符串，用一个全局变量找到最大长度
class Solution {
public:
    bool is_palindrome (string s) {
        for (int i = 0; i < s.length()/2; i++) {
            if (s.at(i) == s.at(s.length()-1 -i)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    void dfs(string pos, vector<string>& words, vector<bool> &visited, int& max_length) {
        // 剪枝条件
        if (pos != "" && is_palindrome(pos)) {
            for (int i = 0; i < words.size(); i++) {
                if (!visited[i]) {
                    string next_pos = pos + words[i];
                    visited[i] = true;
                    dfs(next_pos,words,visited, max_length);
                    visited[i] = false;
                }
            }
        } else {
            for (int i = 0; i < words.size(); i++) {
                if (!visited[i]) {
                    string next_pos = pos + words[i];
                    visited[i] = true;
                    if (is_palindrome(next_pos)) {
                        if (next_pos.length() > max_length) {
                            max_length = next_pos.length();
                        }
                    }
                    dfs(next_pos,words,visited, max_length);
                    visited[i] = false;
                }
            }
        }
        
    }
    int longestPalindrome(vector<string>& words) {
        string start = "";
        int max_length = 0;
        vector<bool> visited(words.size(), false);
        dfs(start, words, visited, max_length);
        return max_length;
    }
};


//计算两边增长的情况，分情况讨论: (max_length 最初为0)
//1. cl出现3次 lc出现4次，这种情况 就构造出 clclcl lclclc 回文字符串，即 max_length += min(cl出现次数, lc出现次数) * 4
//2. cc出现偶数次，例如4次，就可以构造出cc cc cc cc的回文字符串，即max_length += cc出现次数*4
//3. cc出现奇数次，例如3次
//        a. 有其他奇数次的一对字母，例如dd出现3次，此时只能使用只能一个字母放到回文字符串的最中间.即 cc dd cc dd cc. 这里记录一个flag
//        b. 无其他奇数次的字母，很显然，
class Solution2 {
public:
    bool is_single_palindrome (string s) {
        if (s.at(0) == s.at(1)) {
            return true;
        }
        return false;
    }
    bool is_partner_palindrome (string a, string b) {
        if (a[0] == b[1] && a[1] == b[0]) {
            return true;
        }
        return false;
    }
    int longestPalindrome(vector<string>& words) {
        map<string, int> list;
        int max_length = 0;
        for (int i = 0; i <words.size(); i++) {
            list[words[i]]++;
        }
        map<string, int>::iterator iter;
        bool flag = false;
        for(iter = list.begin(); iter != list.end(); iter++){
            if (is_single_palindrome(iter->first)) {
                if (iter->second % 2 == 1) {
                    if (flag == false) {
                        max_length = max_length + iter->second * 2;
                        flag = true;
                    } else {
                        max_length = max_length + iter->second*2-2;
                    }
                } else {
                    max_length = max_length + iter->second * 2;
                }
            } else {
                map<string, int>::iterator j = iter;
                j++;
                for(; j != list.end();j++) {
                    if(is_partner_palindrome(iter->first, j->first)) {
                        int tmp = min(iter->second, j->second);
                        max_length = max_length + 4 * tmp;
                        iter->second = iter->second - tmp;
                        j->second = j->second - tmp;
                    }
                }
            }
        }
        return max_length;
    }
};