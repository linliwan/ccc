#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_2d_vec(const vector<vector<T>>& v){
    for(const vector<T>& row : v) {
        for(const T& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// 给定一个二维的非负整数矩阵，每个位置的值表示海拔高度。假设左边和上边是太平洋，右
// 边和下边是大西洋，求从哪些位置向下流水，可以流到太平洋和大西洋。水只能从海拔高的位置
// 流到海拔低或相同的位置。

// 输入是一个二维的非负整数数组，表示海拔高度。输出是一个二维的数组，表示满足条件的位置坐标。

// Input:
// 太平洋 ~ ~ ~ ~ ~
//     ~ 1 2 2 3 5 *
//     ~ 3 2 3 4 4 *
//     ~ 2 4 5 3 1 *
//     ~ 6 7 1 4 5 *
//     ~ 5 1 1 2 4 *
//       * * * * * 大西洋
// Output: [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]


vector<vector<int>> grid = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

int row = grid.size();
int col = grid[0].size();


vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<bool>>& reach_map, int x, int y) {
    if(reach_map[x][y] == true) {
        return;
    }
    reach_map[x][y] = true;

    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        if(new_x >= 0 && new_y >= 0 && new_x < row && new_y < col){   // 先判断边界
            if(grid[x][y] <= grid[new_x][new_y]) {   // 再看大小
                dfs(reach_map, new_x, new_y);
            }
        }
    }
}

int main() {


    vector<vector<bool>> pacific_map(row, vector<bool>(col, false));
    vector<vector<bool>> atlantic_map(row, vector<bool>(col, false));

    vector<vector<int>> result;

    for(int i = 0; i < row; i++) {
        dfs(pacific_map, i, 0);
        dfs(atlantic_map, i, col -1);
    }

    for(int j = 0; j <= col; j++) {
        dfs(pacific_map, 0, j);
        dfs(atlantic_map, row - 1, j);
    }

    print_2d_vec(pacific_map);
    print_2d_vec(atlantic_map);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (pacific_map[i][j] && atlantic_map[i][j]) {
                result.push_back({i, j});
            }
        }
    }

    print_2d_vec(result);

    return 0;
}