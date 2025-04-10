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

// 给定一个由 0 和 1 组成的二维矩阵，求每个位置到最近的 0 的距离。

// Input:
// [[0,0,0],
//  [0,1,0],
//  [1,1,1]]
// Output:
// [[0,0,0],
//  [0,1,0],
//  [1,2,1]]

//思路：先从左到右、从上到下找，再从右到左，从下到上找，两次动态搜索，完成四个方向上的查找。

int main() {

    vector<vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, numeric_limits<int>::max() -1));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
    }

    print_2d_vec(dp);
    for(int i = row - 1; i >= 0; i--) {
        for(int j = col - 1; j >= 0; j--) {
            if (grid[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                if (i < row - 1) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                if (j < col - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
    }
    print_2d_vec(dp);

    return 0;
}