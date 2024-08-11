class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        if (countComponents(grid) != 1) return 0;  // Already disconnected

        int n = grid.size();
        int m = grid[0].size();

        // Check by removing one land cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countComponents(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        // If removing one cell doesn't disconnect, two cells will
        return 2;
    }

private:
    // Helper function to count the number of connected components of land
    int countComponents(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int components = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++components;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return components;
    }

    // Helper function to perform BFS to mark all land cells in a component
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};