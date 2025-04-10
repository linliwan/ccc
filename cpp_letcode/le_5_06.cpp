#include <bits/stdc++.h>
using namespace std;

// 给定一个字母矩阵，所有的字母都与上下左右四个方向上的字母相连。给定一个字符串，求字符串能不能在字母矩阵中寻找到。

// 输入是一个二维字符数组和一个字符串，输出是一个布尔值，表示字符串是否可以被寻找到。
// Input: word = "ABCCED", board =
// [[’A’,’B’,’C’,’E’],
//  [’S’,’F’,’C’,’S’],
//  [’A’,’D’,’E’,’E’]]
// Output: true
// 从左上角的’A’ 开始，我们可以先向右、再向下、最后向左，找到连续的"ABCCED"。

vector<vector<char>> grid = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
};

int row = grid.size();
int col = grid[0].size();

string word = "ABCCED";

vector<vector<int>> directions = {{-1 ,0}, {1, 0}, {0, 1}, {0, -1}};

//当开始dfs时，要记录哪些字母已经被访问了，防止一个字母被反复利用，例如加入word是"ABCBA"，到'C'的时候，不能回过头还去用之前的"BA"
vector<vector<bool>> visited(row, vector<bool>(col, false));

bool dfs(int x, int y, int index) {
    // 如果index已经等于word的长度了，说明已经找到了，返回true
    if (index == word.size()) {
        return true;
    }

    // 判断越界 & 是否已经访问 & 当前字符是否匹配
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] != word[index]) {
        return false;
    }
    
    // 标记当前格子已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        int new_index = index + 1;
        // 如果任意一个方向上的dfs返回了true，要在这里接住这个true，并返回
        if (dfs(new_x, new_y, new_index)) {
            return true;
        }
    }

    // 如果四个方向上均没有返回true，就走到这里了，说明条路已经game over，要清除visited的标记
    visited[x][y] = false;
    return false;
}


int main() {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            // 找到首字符，开始 DFS
            if (grid[i][j] == word[0]) {
                // 只要找到完整word，就直接打印结果，然后结束程序
                if(dfs(i, j, 0)) {
                    cout << "true" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}