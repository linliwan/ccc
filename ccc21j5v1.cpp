// CCC '21 S2 - Modern Art
// Canadian Computing Competition: 2021 Stage 1, Junior #5, Senior #2
// https://dmoj.ca/problem/ccc21s2

// 此解法10分
#include <bits/stdc++.h>
using namespace std;

int main() {

    int row, col, k;
    cin >> row >> col >> k;
    vector<vector<int>> grid(row, vector<int>(col, 0));
    for(int i = 0; i < k; i++){
        string dir;
        int number;
        cin >> dir >> number;
        if(dir == "R") {
            for(int j = 0; j < col; j++) {
                grid[number - 1][j]++;
            }
        } else {
            for(int i = 0; i < row; i++) {
                grid[i][number - 1]++;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] % 2 == 1) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}