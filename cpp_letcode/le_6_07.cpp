#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vec(vector<T> v) {
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}
// 输入是给定的正整数，输出也是一个正整数，表示输入的数字最少可以由几个完全平方数相加构成。
// Input: n = 13
// Output: 2

// 分割类型的状态转移，其状态转移方程通常并不依赖相邻的位置，而是依赖于满足分割条件的位置
// 此题的分割位置为：n - 1, n - 4, n - 9, n - 16 .....


int main() {
    int n = 13;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    print_vec(dp);
    cout << dp[n] << endl;

    return 0;
}