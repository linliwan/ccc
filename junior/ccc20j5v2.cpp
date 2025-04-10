// CCC '20 S2 - Escape Room
// Canadian Computing Competition: 2020 Stage 1, Junior #5, Senior #2
// https://dmoj.ca/problem/ccc20s2

// 这是让chatgpt优化的版本，可以拿到15分，主要改进点在于cal_factor的算法
// 测试数据中，有些数字很大，而实际的row和col根本没那么大，所以可以在计算因数部分排除掉很多没必要的可能性
#include <bits/stdc++.h>
using namespace std;

set<int> memo;  // memo缓存, grid中重复的数字，就不用看了

vector<pair<int, int>> cal_factor(int number, int row, int col) {
    vector<pair<int, int>> result;
    for (int i = 1; i * i <= number; i++) { // 只需要遍历到 sqrt(number)
        if (number % i == 0) {
            int j = number / i;
            if (i <= row && j <= col) {
                result.push_back({i - 1, j - 1}); // 直接转换为 0-based 索引
            }
            if (j <= row && i <= col && i != j) {
                result.push_back({j - 1, i - 1});
            }
        }
    }
    return result;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col));
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == row - 1 && cy == col - 1) {
            cout << "yes\n";
            return 0;
        }

        if(memo.find(grid[cx][cy]) != memo.end()) {
            continue;
        }

        vector<pair<int, int>> factors = cal_factor(grid[cx][cy], row, col);

        for (const auto& elem : factors) {
            auto [nx, ny] = elem;
            if (!visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }

        memo.insert(grid[cx][cy]);
    }

    cout << "no\n";
    return 0;
}
