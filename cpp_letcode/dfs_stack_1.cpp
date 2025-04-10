#include <bits/stdc++.h>
using namespace std;

// 题目需求：逐个打印岛屿面积大小，用dfs_stack实现

vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1}
};
int row = grid.size();
int col = grid[0].size();

vector<vector<bool>> visited(row, vector<bool>(col, false));
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs_stack(int x, int y) {
    stack<pair<int, int>> stk;
    stk.push({x, y});
    visited[x][y] = true;   // 注意，一定要在push的时候做标记，而不是在pop的时候做标记
    int area = 0;

    while (!stk.empty()) {
        // C++17 引入了 结构化绑定（structured binding），用于 解构（unpack）结构体、数组、元组等。语法规定必须用 []
        // auto [变量1, 变量2, ...] = 结构体/数组/元组;

        // pair<int, int> p = stk.top(); 
        // int current_x = p.first;
        // int current_y = p.second;

        //下面一句话相当于上面的三句话
        auto [current_x, current_y] = stk.top();    // stk.top() 返回的是 栈顶元素，也就是 最后一个被压入栈的元素
        stk.pop();                                  // C++的pop()没有返回值，只负责干活：把栈顶元素”弹“出去
        area++;

        for (const auto &dir : directions) {
            int next_x = current_x + dir[0];
            int next_y = current_y + dir[1];
            
            if (next_x >= 0 && next_y >= 0 && next_x < row && next_y < col && !visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                stk.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
    return area;
}

int main() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                cout << dfs_stack(i, j) << endl;
            }
        }
    }
    return 0;
}
