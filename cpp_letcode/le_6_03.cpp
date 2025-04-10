#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vec(vector<T> v) {
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}
// 给定一个数组，求这个数组中连续且等差的子数组一共有多少个。
// 例如： numb = [1,2,3,4]，等差数列有 [1,2,3]、[2,3,4] 和 [1,2,3,4]
// 最简单的等差数组： numb[2] - numb[1] == numb[1] - numb[0]
// 等差数组的数学描述： numb[i] - numb[i - 1] == numb[i - 1] - numb[i - 2]

// 问题分解： 要求所有等差数列的数量，可以分解为求以每一个元素结尾的等差数列的数量，最后求和；

int main() {
    vector<int> numb = {1, 2, 3, 4};
    int n = numb.size();

    vector<int> dp(n, 0); // dp记录以第n个元素结尾的等差数列的数量
    int count;
    //dp[0]  dp[1] 必定为0，因为等差数列至少要有三个元素
    //当有第三个元素时，可以判断，如果符合条件，就记1

    //状态转移方程：当有第四个元素时，依旧判断numb[i] - numb[i - 1] == numb[i - 1] - numb[i - 2]
    // 如果符合条件，则以该元素结尾的等差数列的数量等于前一个元素结尾的等差数列的数量+1，否则为0
    for (int i = 2; i < n; i++){
        if (numb[i] - numb[i - 1] == numb[i - 1] - numb[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        }
    }

    print_vec(dp);
    cout << accumulate(dp.begin(), dp.end(), 0) << endl;

    return 0;
}