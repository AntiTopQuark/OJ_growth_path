class Solution {
public:
    int calc_diff_count(string &a, string &b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
        }
        return count;
    }
    int dfs(string &start, string &end, vector<string> &bank, vector<bool> &visited, int count) {
        if (start == end) {
            return count;
        }
        int min_count = INT_MAX;
        for (int i = 0; i < bank.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (calc_diff_count(start, bank[i]) == 1) {
                visited[i] = true;
                int tmp_count = dfs(bank[i], end, bank, visited, count + 1);
                if (tmp_count < min_count) {
                    min_count = tmp_count;
                }
                visited[i] = false;
            }
        }
        return min_count;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> visited(bank.size(),false);
        int count = dfs(start, end, bank, visited, 0);
        if (count == INT_MAX) {
            return -1;
        }
        return count;
    }
};