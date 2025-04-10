#include <bits/stdc++.h>
using namespace std;

// 题目需求：找到所有的“12325”，打印其数量；

vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {2, 3, 0, 1, 0},
    {5, 2, 3, 2, 0},
    {0, 0, 0, 3, 0},
    {0, 0, 5, 2, 1}
};
int row = grid.size();
int col = grid[0].size();

// 定义目标
vector<int> target = {1, 2, 3, 2, 5};

// 用来标记已经遍历过的元素
vector<vector<bool>> visited(row, vector<bool>(col, false));
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// 这里又要改计数了
int dfs(int x, int y, int index) {

    // 超出边界，已访问，数字与目标不匹配
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] != target[index]) {
        return 0;
    }

    // 找到了12345，注意这里相对于上一个bool int，调换了顺序，这样更合理，只要没有”超出边界、已访问、数字与目标不匹配“，则说明找到了目标数字
    if(index == target.size() - 1) {
        visited[x][y] = false;    // 回溯，因为还要接着找，visited不能乱套
        return 1;
    }

    // 计数，因为可能能找到多条
    int count = 0;

    // 标记已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        count += dfs(new_x, new_y, index + 1);
    }

    // 回溯
    visited[x][y] = false;

    return count;
}

int main() {

    int total_count = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                total_count += dfs(i, j, 0);
            }
        }
    }

    cout << total_count << endl;
    return 0;
}