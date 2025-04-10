// CCC '23 J5 - CCC Word Hunt
// Canadian Computing Competition: 2023 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc23j5

// 这道题是典型的dfs，在grid中找单词
// 如果不考虑拐弯，dfs可以变得异常简单，因为永远只需要在一个方向上前进，其实连stack都可以省略
// 但为了保持风格，这里我们依旧使用stack风格的写法，以确保下一步改进时方便

// 不考虑拐弯，可以拿到6分，以下为解法：

#include <bits/stdc++.h>
using namespace std;

int dfs(string word, vector<vector<char>> grid, int x, int y) {

    // 定义好8个方向
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    int count = 0;

    for(const pair<int, int>& direction: directions) {
        stack<tuple<int, int, int>> s; //<x, y, index>
        s.push({x, y, 0});

        while(!s.empty()) {
            auto [cx, cy, index] = s.top();
            s.pop();

            if(index == word.size() - 1) {
                count++;
                continue;
            }

            // 因为不考虑转弯，所以这里只需要保持当前方向前进探索即可
            int nx = cx + direction.first;
            int ny = cy + direction.second;
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == word[index + 1]) {
                s.push({nx, ny, index + 1});
            }
        }
    }

    return count;
}


int main() {
    string word;
    int r, c;
    cin >> word >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));

    for(int i =0; i < r; i++){
        for(int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    for(int i =0; i < r; i++){
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == word[0]){
                // 碰到首字母就开始dfs，传入word、grid和坐标信息；
                count += dfs(word, grid, i, j);
            }
        }
    }

    cout << count << endl;
    return 0;
}