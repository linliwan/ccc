#include <bits/stdc++.h>
using namespace std;

// 题目需求：判断是否有连在一起的“12325”，如果有，就打印"hello"，否则打印"world"；

vector<vector<int>> grid = {
    {1, 0, 0, 0, 0},
    {2, 3, 1, 1, 0},
    {5, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
int row = grid.size();
int col = grid[0].size();

vector<int> target = {1, 2, 3, 2, 5};
vector<vector<bool>> visited(row, vector<bool>(col, false));
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool dfs_stack(int x, int y) {
    queue<tuple<int, int, int>> q;  // (x, y, index)
    q.push({x, y, 0});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy, index] = q.front();
        q.pop();
        
        if (index == target.size() - 1) {
            return true;
        }
        
        for (const auto& dir : directions) {
            int nx = cx + dir[0];
            int ny = cy + dir[1];
            if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && grid[nx][ny] == target[index + 1]) {
                q.push({nx, ny, index + 1});
                visited[nx][ny] = true;
            }
        }
        
        visited[cx][cy] = false; // 回溯
    }
    return false;
}

int main() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                if(dfs_stack(i, j)) {
                    cout << "hello" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "world" << endl;
    return 0;
}
