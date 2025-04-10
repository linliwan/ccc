#include <bits/stdc++.h>
using namespace std;

// 题目需求：逐个打印岛屿面积大小

vector<vector<int>> grid = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1}
    };
int row = grid.size();
int col = grid[0].size();

// 用来标记已经遍历过的元素
vector<vector<bool>> visited(row, vector<bool>(col, false));
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y) {
    // 如果出界，或者已经遍历过该元素，或者碰到海洋
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] == 0) {
        return 0;
    }

    int count = 1;

    // 标记已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        count += dfs(new_x, new_y);
    }

    return count;

}

int main() {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                cout << dfs(i, j) << endl;    // 这个案例直接打印dfs结果
            }
        }
    }

    return 0;
}