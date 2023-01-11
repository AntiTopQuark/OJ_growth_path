#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& graph, vector<bool>& hasApple, int node, int parent) {
        int res = 0;
        for (int child : graph[node]) {
            // 避免成环导致的重复访问
            if (child == parent) {
                continue;
            }
            int sub = dfs(graph, hasApple, child, node);
            if (sub > 0 || hasApple[child]) {
                res += sub + 2;
            }
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // 构造无向图
        unordered_map<int, vector<int>> graph; 
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // 使用深度优先搜索，找到最短路径
        return dfs(graph, hasApple, 0, -1);
    }
};
/*
* 这道题有些机贼，如果你看到树，想到了递归、遍历之类的，那就拜拜了 （＃￣～￣＃）
* 对于有苹果的节点，我们一定会走过它的父节点，而且每访问一个带苹果的节点就要+ 2 +2+2s，一来一回
* 那这样子的话，其实不用递归、遍历什么的了，直接找到带苹果的节点标记其所有父节点为带苹果节点，最后有几个带苹果节点就加几个两秒
* */
class Solution2 {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int res = 0;
        for(int i=edges.size()-1;i;i--)
            if(hasApple[edges[i][1]]) hasApple[edges[i][0]] = true;
        for(int i=0;i<edges.size();i++)
            if(hasApple[edges[i][1]]) res += 2;
        return res;
    }
};

