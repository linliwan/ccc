#include <bits/stdc++.h>
using namespace std;

// 题目需求：找到所有的“12345”，记录下它经过的坐标，放到二维数组中，并打印；
// 例如:
    // [[1, 3], [2, 3], [3, 3], [3, 2], [4, 2]]
    // [[1, 3], [2, 3], [2, 2], [3, 2], [4, 2]]
    // [[1, 3], [2, 3], [2, 2], [2, 1], [2, 0]]
    // [[4, 4], [4, 3], [3, 3], [3, 2], [4, 2]]

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

// 用来标记已经遍历过的元素
vector<vector<bool>> visited(row, vector<bool>(col, false));
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// path vector记录路径
vector<vector<int>> path;

void dfs(int x, int y, int index) {

    // 超出边界，已访问，数字与目标不匹配
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] != target[index]) {
        return;
    }

    // 能撞到这里，说明元素满足要求，记录path
    path.push_back({x, y});

    // 找到了12345，
    if(index == target.size() - 1) {
        // 打印并清空path
        print_2d_vec(path);
        visited[x][y] = false;   // 成功找到了，打印完结果，别忘了回溯，
        path.pop_back();   
        return;
    }

    // 标记已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        dfs(new_x, new_y, index + 1);
    }

    // 回溯，能撞到这里，说明历史任务已经完成，要回溯visited，也要把path回溯，以便下一次记录
    visited[x][y] = false;
    path.pop_back();
    return;  // 这句可以不写，写上更便于理解
}

int main() {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                dfs(i, j, 0);
            }
        }
    }

    return 0;
}