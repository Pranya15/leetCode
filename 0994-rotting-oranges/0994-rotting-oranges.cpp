class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;

        // push all rotten oranges
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {

                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while (q.size() > 0) {

            pair<pair<int, int>, int> curr = q.front();
            q.pop();

            int i = curr.first.first;
            int j = curr.first.second;
            int time = curr.second;

            ans = max(ans, time);

            // top
            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {

                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }

            // right
            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {

                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }

            // bottom
            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {

                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }

            // left
            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {

                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }

        // check for fresh orange
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {

                    return -1;
                }
            }
        }

        return ans;
    }
};