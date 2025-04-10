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

// 给定一个二维的 0-1 矩阵，求全由 1 构成的最大正方形面积。
// Input:
// [["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]]
// Output: 4

// 对于在矩阵内搜索正方形或长方形的题型，一种常见的做法是定义一个二维 dp 数组，
// 其中 dp[i][j] 表示满足题目条件的、以 (i, j) 为右下角的正方形或者长方形的属性。
// 对于本题，则表示以 (i, j) 为右下角的全由 1 构成的最大正方形边长。

// 如果当前位置是 0，那么 dp[i][j] 即为 0；
// 如果当前位置是 1，则 dp[i][j]为 dp[i-1][j-1], dp[i][j-1], dp[i-1][j]三个中的最小值 + 1



int main() {

    vector<vector<int>> grid = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1}
    };

    int max_side = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1) {
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
            max_side = max(max_side, dp[i][j]);
        }
    }

    print_2d_vec(dp);
    cout << max_side * max_side << endl;
    return 0;
}