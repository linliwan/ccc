#include <bits/stdc++.h>
using namespace std;

// 题目需求：判断是否有连在一起的“12345”，如果有，就打印"hello"，否则打印"world"；

vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {2, 0, 0, 1, 1},
    {5, 4, 3, 2, 0},
    {1, 1, 4, 3, 0},
    {0, 1, 5, 2, 2}
};
int row = grid.size();
int col = grid[0].size();

// 定义目标
vector<int> target = {1, 2, 3, 4, 5};

// 用来标记已经遍历过的元素
vector<vector<bool>> visited(row, vector<bool>(col, false));
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//这里的dfs，要多一个参数了，index用于传递找第几个元素，即target数组的下标，返回值类型为bool，因为只要找到一个”12345“就可以出结果了
bool dfs(int x, int y, int index) {

    // 这里首先要想想，什么情况下才可以返回true，当index等于target长度（5）时，说明已经在找第”6“个元素了，也就是说前5个都找到了
    if(index == target.size()) {
        return true;
    }
    
    // 超出边界，已访问，数字与目标不匹配
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] != target[index]) {
        return false;
    }

    // 其实前面那个判断true的，放这里更合理，当index等于4时（第五个元素了），只要过了”超出边界、已访问、数字与目标不匹配“的判断，就说明已经找到了
    // 这个元素找到后，直接return true，更合理，根本不需要再往四个方向上跑了再找第”6“个元素
    // if(index == target.size() - 1) {
    //     return true;
    // }

    // 标记已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        if (dfs(new_x, new_y, index + 1)) {
            return true;
        }
    }

    // 回溯
    visited[x][y] = false;

    return false;
}

int main() {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (grid[i][j] == target[0]) {
                if (dfs(i, j, 0)) {
                    cout << "hello" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "world" << endl;
    return 0;
}