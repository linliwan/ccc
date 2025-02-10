// CCC '21 S2 - Modern Art
// Canadian Computing Competition: 2021 Stage 1, Junior #5, Senior #2
// https://dmoj.ca/problem/ccc21s2

// 此解法15分，做了空间压缩
// 相比v1解法：
//     v1解法的空间复杂度为 O(row × col)，维护的是一个二维数组
//     v2解法的空间复杂度为 O(row + col)，维护的是两个一维数组

#include <bits/stdc++.h>
using namespace std;
int main() {

    int row, col, k;
    cin >> row >> col >> k;

    vector<int> row_flips(row, 0); // 记录每行的翻转次数
    vector<int> col_flips(col, 0); // 记录每列的翻转次数

    for (int i = 0; i < k; i++) {
        char rc;
        int num;
        cin >> rc >> num;
        if (rc == 'R') {
            row_flips[num - 1]++;
        } else {
            col_flips[num - 1]++;
        }
    }

    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // 如果行翻转次数 + 列翻转次数是奇数，则值为 1
            if ((row_flips[i] + col_flips[j]) % 2 == 1) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}