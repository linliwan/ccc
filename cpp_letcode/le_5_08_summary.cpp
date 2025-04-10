#include <bits/stdc++.h>
using namespace std;

// 题目需求：逐个打印岛屿面积大小

vector<vector<int>> grid = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1}
    };
int row = grid.size();
int col = grid[0].size();

// 可能会有多个map，主要用来标记已经遍历过的元素
vector<vector<bool>> visited(row, vector<bool>(col, false));
// 四个方向
vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// void dfs(int x, int y)       // 如果dfs只是用来给bool_map做个标记，然后针对标记再处理逻辑，则无需返回什么
// bool dfs(int x, int y)       // 如果dfs用来判断某个场景是否存在，则一般要返回bool
int dfs(int x, int y /* 有可能还有第三个参数，例如index */) {        // 如果dfs用来计数，则一般要返回int
    // 如果出界，或者已经遍历过该元素
    if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || grid[x][y] == 0 /* grid[x][y]满足/不满足某个条件，因题而异 */) {
        return 0;                       // dfs函数返回int
        // return false;                // dfs函数返回bool
        // return;                      // dfs函数返回void
    }

    // 如果dfs有返回值，此处要考虑是否要计数，例如：
    int count = 1;

    // 或者 查看是否满足某个条件，返回true
    // if (index == word.size()) {
    //     return true;
    // }

    // 标记已访问
    visited[x][y] = true;

    // 尝试四个方向搜索
    for(const auto& direction: directions) {
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        // int new_index = index + 1;

        // 如果dfs返回void或者int：
        if(/* 此处可能需要判断下，满足什么条件就继续dfs，也有可能这里要判断是否出界 */ true) {
            // dfs(new_x, new_y);               // 返回void类型的dfs，一般直接干活就可以
            count += dfs(new_x, new_y);          // 返回int类型的dfs，这里可能要累计结果
        }

        // 如果dfs返回true：这里就要接住这个true，并返回
        // if (dfs(new_x, new_y, new_index)) {
        //     return true;
        // }
    }

    // 如果bool_map还要给其他可能的case再次使用，这里要回溯
    // bool_map[x][y] = false;

    // 如果dfs返回bool或者int，这里要返回
    // return false;
    return count;
    // return;      // 返回void，这个可以省略不写
}

int main() {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (/* 如果满足某个条件，就开始dfs */ grid[i][j] == 1 && !visited[i][j]) {
                // 这里有可能也要检查bool_map

                //如果dfs返回void，一般直接执行就好了
                // dfs(i, j);

                // 如果dfs返回某个计数，根据题意对dfs结果进行处理
                // max_result = max(max_result, dfs(i, j));   // 算最大值
                cout << dfs(i, j) << endl;                            // 这个案例直接打印dfs结果

                // 如果dfs返回bool值
                // if (dfs(i, j)) { /* 说明找到了什么，看题目需求接下来要干嘛 */ }
            }
        }
    }

    return 0;
}