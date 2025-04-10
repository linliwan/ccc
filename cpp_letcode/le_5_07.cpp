#include <bits/stdc++.h>
using namespace std;

// 定义搜索方向：上、下、左、右
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>>& grid, int x, int y, int index, string& word, vector<vector<bool>>& visited) {
    if (index == word.size()) {
        return true;
    }  // 如果匹配到整个 word，则返回 true

    int row = grid.size(), col = grid[0].size();

    // 判断越界 & 是否已经访问 & 当前字符是否匹配
    if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] != word[index]) {
        return false;
    }

    // 标记当前格子已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for (const auto& dir : directions) {
        int new_x = x + dir[0], new_y = y + dir[1];
        if (dfs(grid, new_x, new_y, index + 1, word, visited)) {
            return true;
        }
    }

    // 回溯，撤销访问标记
    visited[x][y] = false;
    return false;
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    int row = grid.size(), col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));  // 记录是否访问过

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == word[0]) {  // 找到首字符，开始 DFS
                if (dfs(grid, i, j, 0, word, visited)) {
                    cout << "true" << endl;
                    return 0;
                }     // 只要找到完整word，就直接打印结果，然后结束程序
            }
        }
    }

    return 0;
}
