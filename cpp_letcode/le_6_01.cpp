#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vec(vector<T> v) {
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}

// 给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶
// 状态转移方程 State transfer equation
// f(n) = f(n-1) + f(n-2)
// 因为我们每次可以走一步或者两步，所以第 n 阶可以从第 n-1 或 n-2 阶到达。
// 走到第 n 阶的方法数即为走到第 n-1 阶的方法数加上走到第 n-2 阶的方法数


// 方法1： 数组写法
// int main() {
//     int n = 5;
//     vector<int> dp(n, 1);

//     for(int i = 2; i < n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     print_vec(dp);

// }

// 方法2： 递归函数写法（据说相对节省内存）
int climb(int n){
    if (n == 1 || n == 2) {
        return 1;
    }
    return climb(n -1) + climb(n - 2);
}

int main() {
    cout << climb(5) << endl;
}


