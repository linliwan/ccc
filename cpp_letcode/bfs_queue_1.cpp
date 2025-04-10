#include <bits/stdc++.h>
using namespace std;

// 题目需求：逐个打印岛屿面积大小，用bfs_queue实现

vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1}
};
int row = grid.size();
int col = grid[0].size();

vector<vector<bool>> visited(row, vector<bool>(col, false));
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int area = 0;

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();  // q.front() 返回的是 队列 q 的第一个元素（即队头元素）。
        q.pop();
        area++;

        for (const auto& dir : directions) {
            int new_x = cur_x + dir[0];
            int new_y = cur_y + dir[1];

            if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col &&
                !visited[new_x][new_y] && grid[new_x][new_y] == 1) {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }
    }

    return area;
}

int main() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                cout << bfs(i, j) << endl;
            }
        }
    }
    return 0;
}
