#include <bits/stdc++.h>
using namespace std;


// 给定一个二维的 0-1 矩阵，其中 0 表示海洋， 1 表示陆地。
// 单独的或相邻的陆地可以形成岛屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。

// 输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
// Input:
// [[1,0,1,1,0,1,0,1],
//  [1,0,1,1,0,1,1,1],
//  [0,0,0,0,0,0,0,1]]
// Output: 6
// 最大的岛屿面积为 6，位于最右侧。

// 深度优先搜索 deepth first search

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(vector<vector<int>>& g, int x, int y) {
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 0) {
        return 0;
    }

    int area = 1;
    g[x][y] = 0;  // 标记已访问

    for (const auto& direction : directions) {
        area += dfs(g, x + direction[0], y + direction[1]);
    }

    return area;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1}
    };

    int row = grid.size();
    int col = grid[0].size();
    int max_area = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }

    cout << max_area << endl;

    return 0;
}