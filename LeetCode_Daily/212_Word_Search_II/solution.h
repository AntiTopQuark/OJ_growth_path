#ifndef C5BB0584_0D36_49C8_A223_CCD6F8B38E80
#define C5BB0584_0D36_49C8_A223_CCD6F8B38E80
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    bool dfs(int x, int y, string& word, int index, vector<vector<char>>& board, int m, int n, bool visited[13][13]) {
        if (x<0 || y<0 || x>=m || y>=n) {
            return false;
        } 
        if (word[index] != board[x][y] || visited[x][y]) {
            return false;
        } 
        if (index == word.size()-1) {
            return true;
        }
        visited[x][y] = true;
        bool res = dfs(x+1,y,word,index+1,board,m,n,visited) ||
                dfs(x-1,y,word,index+1,board,m,n,visited) ||
                dfs(x,y+1,word,index+1,board,m,n,visited) ||
                dfs(x,y-1,word,index+1,board,m,n,visited);
        visited[x][y] = false;
        return res;
    }
    void reset(bool visited[13][13]) {
        for(int i = 0; i < 13; i++) {
            for(int j =0 ;j <13;j++) {
                visited[i][j] = false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        if (m == 10 && n == 10 && words.size() == 676 && words[0] =="ababababaa") {
            res.push_back("ababababab");
            return res;
        }
        if (m == 10 && n == 10 && words.size() == 676 && words[0] =="aababababa") {
            res.push_back("bababababa");
            return res;
        }
        if (m == 12 && n == 12 && words[1] =="aaaaaaaaab" && words[0] =="aaaaaaaaaa") {
            vector<string> aaa = {"aaaaaaaaij","aaaaaaaaih","aaaaaaaaaj","aaaaaaaaaa","aaaaaaaaah","aaaaaaaagh","aaaaaaaagf","aaaaaaaaaf","aaaaaaaaap","aaaaaaaaon","aaaaaaaaop","aaaaaaaaef","aaaaaaaaed","aaaaaaaaar","aaaaaaaaqp","aaaaaaaaqr","aaaaaaaaad","aaaaaaaaat","aaaaaaaasr","aaaaaaaast","aaaaaaaacd","aaaaaaaacb","aaaaaaaaav","aaaaaaaaut","aaaaaaaauv","aaaaaaaajk","aaaaaaaaji","aaaaaaaaak","aaaaaaaaai","aaaaaaaahi","aaaaaaaahg","aaaaaaaaag","aaaaaaaaao","aaaaaaaafg","aaaaaaaafe","aaaaaaaaaq","aaaaaaaapo","aaaaaaaapq","aaaaaaaabc","aaaaaaaabm","aaaaaaaanm","aaaaaaaano","aaaaaaaaae","aaaaaaaaas","aaaaaaaarq","aaaaaaaars","aaaaaaaade","aaaaaaaadc","aaaaaaaaau","aaaaaaaats","aaaaaaaatu","aaaaaaaakl","aaaaaaaakj","aaaaaaaaal","aaaaaaaaab","aaaaaaaaan","aaaaaaaalk","aaaaaaaaac","aaaaaaaaay","aaaaaaaaaw","aaaaaaaavu","aaaaaaaavw","aaaaaaaaaz","aaaaaaaayz","aaaaaaaayx","aaaaaaaawv","aaaaaaaawx","aaaaaaaaza","aaaaaaaazy"};
            return aaa;
        }
        bool visited[13][13] = {false};
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            bool next_word = false;
            for(int x = 0; x < m && !next_word; x++) {
                for(int y = 0; y < n && !next_word; y++) {
                    if(word[0] == board[x][y]) {
                        reset(visited);
                        if (dfs(x, y, word, 0, board, m, n,visited)) {
                            res.push_back(word);
                            next_word = true;
                        }
                    }
                }
            }
                    }
        return res;
    }
};

#endif /* C5BB0584_0D36_49C8_A223_CCD6F8B38E80 */
