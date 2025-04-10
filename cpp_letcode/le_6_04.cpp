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

// 给定一个 m × n 大小的非负整数矩阵，求从左上角开始到右下角结束的、经过的数字的和最
// 小的路径。每次只能向右或者向下移动。

// Input:
// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]
// Output: 7

// 解法：定义一个同样是二维的 dp 数组，其中 dp[i][j] 表示从左上角开始到 (i, j) 位置的最优路径的数字和。
// 状态转移方程：dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
int main() {

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0) {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            } else {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    print_2d_vec(dp);
    return 0;
}