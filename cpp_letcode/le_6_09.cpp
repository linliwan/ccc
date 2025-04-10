#include <bits/stdc++.h>
using namespace std;

// 给定一个未排序的整数数组，求最长的递增子序列长度。
// Input: [10,9,2,5,3,7,101,4]
// Output: 4
// 在这个样例中，最长递增子序列之一是 [2,3,7,101]。

// 状态转移方程：计算以每一个数结尾的递增子序列的长度，思考以某个数结尾的子序列长度与前人的关系

int main() {

    vector<int> num = {10, 9, 2, 5, 3, 7, 101, 4};
    int n = num.size();
    vector<int> dp(n, 1);

    for(int i = 0; i< n; i++) {
        for (int j = 0; j < i; j++){
            if(num[i] > num[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}