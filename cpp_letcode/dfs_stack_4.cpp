#include <bits/stdc++.h>
using namespace std;

// 打印二维数组的函数
template <typename T>
void print_2d_vec(const vector<vector<T>>& v){
    cout << "[";
    for(size_t i = 0; i < v.size(); i++) {
        cout << "[";
        for(size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j != v[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {2, 0, 0, 1, 1},
    {5, 4, 3, 2, 0},
    {1, 1, 4, 3, 0},
    {0, 1, 5, 2, 1}
};
int row = grid.size();
int col = grid[0].size();

// 定义目标
vector<int> target = {1, 2, 3, 4, 5};
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs_stack(int start_x, int start_y) {
    stack<tuple<int, int, int, vector<vector<int>>, vector<vector<bool>>>> s;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // 初始状态入栈 (x, y, index, path, visited)
    s.push({start_x, start_y, 0, {{start_x, start_y}}, visited});

    while (!s.empty()) {
        auto [x, y, index, path, cur_visited] = s.top();
        s.pop();

        // 找到了完整路径，打印
        if (index == target.size() - 1) {
            print_2d_vec(path);
            continue;
        }

        // 标记访问
        cur_visited[x][y] = true;

        // 遍历四个方向
        for (const auto& direction : directions) {
            int new_x = x + direction[0];
            int new_y = y + direction[1];
            int next_index = index + 1;

            if (new_x >= 0 && new_y >= 0 && new_x < row && new_y < col &&
                !cur_visited[new_x][new_y] && grid[new_x][new_y] == target[next_index]) {
                
                vector<vector<int>> new_path = path;  // 复制当前路径
                new_path.push_back({new_x, new_y});  // 记录路径

                s.push({new_x, new_y, next_index, new_path, cur_visited});
            }
        }
    }
}

int main() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                dfs_stack(i, j);
            }
        }
    }
    return 0;
}
