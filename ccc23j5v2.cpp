// CCC '23 J5 - CCC Word Hunt
// Canadian Computing Competition: 2023 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc23j5

// 此解法为满分解法
// 拐弯只带一次，这个要想想如何处理，stack中要携带的信息恐怕会有些复杂
// 如何规划dfs/bfs在stack/quue中存储的信息？与其问这个问题，不如问自己，哪些信息需要标注给下一轮循环？
// 这个例子中，很明显，能想到的是，x/y坐标、word索引、是否已经转弯、前进方向
//   需要处理的复杂逻辑是：当已经拐弯了，前进方向就必须保持不变；而当没有拐弯时，前进方向就有可能产生三个分支（原方向、90度、270度）

#include <bits/stdc++.h>
using namespace std;

int dfs(string word, vector<vector<char>> grid, int x, int y) {

    // 这8个主要的方向保持不变
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    int count = 0;

    for(const pair<int, int>& main_dir: directions) {
        // 8个方向上分开探索，压栈
        stack<tuple<int, int, int, bool, pair<int, int>>> s;  // <x, y, index, turned, current_direction>
        s.push({x, y, 0, false, main_dir});

        while(!s.empty()) {
            auto [cx, cy, index, turned, current_dir] = s.top();
            s.pop();

            // 如果已经到达字母最后一个字符，说明成功找到了
            if(index == word.size() - 1) {
                count++;
                continue;
            }

            // 这里是处理转弯的逻辑
            // 因为转弯就会产生分支，而且在整个生命周期中，转弯只能转一次，所以要为接下来的for循环做点准备；
            // 不管之前收否转过弯，当前的方向上肯定是可以继续探索的，所以把当前方向先放进来
            vector<tuple<pair<int, int>, bool>> dirs_with_turn = {{current_dir, turned}};
            // 如果没有转过弯，还可以额外探索90度和270度两个方向，但是turned位置一定要变成true
            if (!turned && index > 0) {
                pair<int, int> turn_90, turn_270;
                turn_90 = {-current_dir.second, current_dir.first};
                turn_270 = {current_dir.second, -current_dir.first};
                dirs_with_turn.push_back({turn_90, true});
                dirs_with_turn.push_back({turn_270, true});
            } 

            for(const auto& dir_with_turn: dirs_with_turn) {
                auto[direction, turned] = dir_with_turn;
                int nx = cx + direction.first;
                int ny = cy + direction.second;
                // 如果没有出界，并且下一个字母匹配，则继续push
                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == word[index + 1]) {
                    s.push({nx, ny, index + 1, turned, direction});
                }
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
                count += dfs(word, grid, i, j);
            }
        }
    }


    cout << count << endl;
    return 0;
}




