// CCC '20 S2 - Escape Room
// Canadian Computing Competition: 2020 Stage 1, Junior #5, Senior #2
// https://dmoj.ca/problem/ccc20s2

// 此解法可以拿13分
#include <bits/stdc++.h>
using namespace std;

// 记录因数缓存
map<int, vector<int>> memo;

// 计算一个整数的因数，返回值为列表
vector<int> cal_factor(int number) {
    vector<int> result;
    for(int i = 1; i <= number; i ++){
        if(number % i == 0) {
                result.push_back(i);
        }
    }
    memo[number] = result;
    return result;
}


int main() {
    // 解决input
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col));
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> grid[i][j];
        }
    }
    
    // *** 开始bfs
    queue<pair<int, int>> q;
    // push bfs的起点
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        // 如果到达终点，则输出yes，并终止程序
        if((cx == row - 1) &&(cy == col -1)) {
            cout << "yes" << endl;
            return 0;
        }
        
        // 算一下因数，调用之前定义好的函数，如果缓存中存在，则使用缓存
        vector<int> factors;
        if(memo.find(grid[cx][cy]) != memo.end()) {
            factors = memo[grid[cx][cy]];
        } else {
            factors = cal_factor(grid[cx][cy]);
        }
        
        for(const int& elem : factors){
            // 计算下一个x和下一个y
            int nx = elem - 1;
            int ny = grid[cx][cy] / elem - 1;
            // 如果nx和ny没有出界...
            if(nx < row && ny <col) {
                // 如果nx和ny也没有被访问过...
                if(!visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << "no" << endl;
    return 0;
}

