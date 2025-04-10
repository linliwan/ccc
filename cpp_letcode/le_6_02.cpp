#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vec(vector<T> v) {
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}
// 假如你是一个劫匪，并且决定抢劫一条街上的房子，每个房子内的钱财数量各不相同。(用一个数组表示，例如[2, 7, 9, 3, 1, 1, 1, 3])
// 如果你抢了两栋相邻的房子，则会触发警报机关。求在不触发机关的情况下最多可以抢劫多少钱。

// numb[]记录每个房子可抢劫的金钱，则第n个房子，可以抢numb[n - 1]
// 在跑到第n个房子时，有两种可能：抢 和 不抢。
// 如果不抢，累计金额为f(n-1);
// 如果抢，则累计金额为f(n-2) + numb[n - 1]

// 状态转移方程：
// f(n) = max(f(n-1), f(n-2) + numb[n - 1])

vector<int> numb = {2, 7, 9, 3, 1, 1, 1, 3};


// 递归写法
int rob(int n) {
    if (n == 1) {
        return numb[0];
    } else if (n == 2) {
        return numb[1];
    }
    return max(rob(n - 1), rob(n - 2) + numb[n - 1]);
}


int main() {

    // for循环写法
    // int n = numb.size();

    // vector<int> dp(n, 0);
    // dp[0] = numb[0];  // 如果只有一栋房子，那么最大值就是抢这栋房子
    // dp[1] = max(numb[0], numb[1]);  // 如果只有两栋房子，那么最大值就是抢这两栋房子种的一个

    // for(int i = 2; i < n; i++) {
    //     dp[i] = max(dp[i - 1], dp[i - 2] + numb[i]);   // 到了第三栋房子，就看看之前的两个结果，决定到底抢不抢
    // }

    // print_vec(dp);
    // cout << dp[n - 1] << endl;


    cout << rob(8) << endl;

    return 0;
}