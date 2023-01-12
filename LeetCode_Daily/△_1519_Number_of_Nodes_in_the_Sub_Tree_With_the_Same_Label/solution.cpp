#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<vector<int>> totLabels;

    void solve(int u, int fa, const vector<vector<int>> &graph)
    {
        for (int v : graph[u])
            if (v != fa)
            {
                solve(v, u, graph);
                for (int i = 0; i < 26; i++)
                    totLabels[u][i] += totLabels[v][i];
            }
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> graph(n);

        for (const auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        totLabels.resize(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
            totLabels[i][labels[i] - 'a']++;

        solve(0, -1, graph);

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = totLabels[i][labels[i] - 'a'];

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    string labels = "abaedcd";
    vector<int> result = s.countSubTrees(7, edges, labels);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}