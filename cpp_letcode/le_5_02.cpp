#include <bits/stdc++.h>
using namespace std;

// 给定一个二维的 0-1 矩阵，如果第 (i, j) 位置是 1，则表示第 i 个城市和第 j 个城市处于同一
// 城市圈。已知城市的相邻关系是可以传递的，即如果 a 和 b 相邻， b 和 c 相邻，那么 a 和 c 也相
// 邻，换言之这三个城市处于同一个城市圈之内。求一共有多少个城市圈。

// 输入是一个二维数组，输出是一个整数，表示城市圈数量。因为城市相邻关系具有对称性，
// 该二维数组为对称矩阵。同时，因为自己也处于自己的城市圈，对角线上的值全部为 1

// Input:
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2

// 这道题目与上一道题目本质上是同一道题：搜索城市圈（岛屿圈）的个数。


vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<int>>& g, int x, int y) {
    if(x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 0) {
        return;
    }

    g[x][y] = 0;  // 标记已访问

    for (const auto& direction : directions) {
        dfs(g, x + direction[0], y + direction[1]);
    }

    return;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int row = grid.size();
    int col = grid[0].size();
    int count = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}