#include <bits/stdc++.h>
using namespace std;

// 题目需求：找到所有的“12345”，打印其数量；
vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {2, 0, 0, 1, 1},
    {5, 4, 3, 2, 0},
    {1, 1, 4, 3, 0},
    {0, 1, 5, 2, 1}
};
int row = grid.size();
int col = grid[0].size();

vector<int> target = {1, 2, 3, 4, 5};
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs_stack(int x, int y) {
    stack<tuple<int, int, int>> s; // (x, y, index, visited)
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    s.push({x, y, 0});
    visited[x][y]  = true;
    int count = 0;

    while (!s.empty()) {
        auto [cx, cy, index] = s.top();
        s.pop();

        if (index == target.size() - 1) {
            count++;
            visited[cx][cy] = false;
            continue;
        }

        for (const auto& direction : directions) {
            int nx = cx + direction[0];
            int ny = cy + direction[1];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && grid[nx][ny] == target[index + 1]) {
                s.push({nx, ny, index + 1});
                visited[nx][ny] = true;
            }
        }
        visited[cx][cy] = false;
    }
    return count;
}

int main() {
    int total_count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                total_count += dfs_stack(i, j);
            }
        }
    }
    cout << total_count << endl;
    return 0;
}
