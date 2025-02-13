// CCC '24 J5 - Harvest Waterloo
// Canadian Computing Competition: 2024 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc24j5

// 这道题比较简单，标准的dfs，没什么花样，此解法为满分

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<char>> grid, vector<vector<bool>> visited, map<char, int> price, int x, int y) {
    int value = 0;
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    stack<pair<int, int>> s;
    s.push({x, y});
    value += price[grid[x][y]];
    visited[x][y] = true;

    while(!s.empty()) {
        auto [cx, cy] = s.top();
        s.pop();

        for(const auto& direction: directions){
            int nx = cx + direction.first;
            int ny = cy + direction.second;
            // 在边界内、不是草堆、没有访问过
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] != '*' && !visited[nx][ny]) {
                s.push({nx, ny});
                value += price[grid[nx][ny]];
                visited[nx][ny] = true;
            }

        }

    }

    return value;
}


int main() {
    int r, c, a, b;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }

    cin >> a >> b;
    map<char, int> price = {{'S', 1}, {'M', 5}, {'L', 10}};

    int v = dfs(grid, visited, price, a, b);
    cout << v << endl;

    return 0;
}