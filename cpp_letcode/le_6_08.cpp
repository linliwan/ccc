#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vec(vector<T> v) {
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}
// 已知字母 A-Z 可以表示成数字 1-26。给定一个数字串，求有多少种不同的字符串等价于这个数字串。
// Input: "226"
// Output: 3
// 在这个样例中，有三种解码方式： BZ(2 26)、 VF(22 6) 或 BBF(2 2 6)。

// 关键：找状态转移方程：
// 问自己的问题：226的状态可否由22的状态推理得到？
// 想法：假定22的状态为x，则226在22基础上的状态也为x，因为只要再加一个字母F就可以凑成226，那么这种情况下226的组合可能性和22是一样的！
//      226的状态会不会和第一个2有关联呢？
//      在这个例子中，也是可以的，因为末尾的26也可以是一个合法字母，所以2有多少种组合，226也可以具备这些组合的可能性！
//      假如结尾不是26，是27，那就不行了，因为超出字符边界了！
//      所以226的可能性是2的可能性 + 22的可能性！

//      除此之外，再考虑下数字0的处理，基本就完美了！

int main() {

    string str = "226";

    int n = str.size() + 1;
    vector<int> dp(n, 0);

    dp[0] = 1;
    dp[1] = 1;
    //dp[i + 1]用来跟踪str[i]的状态
    for(int i = 1; i < n - 1; i++){
        if (str[i] != '0') {    // 如果是1-9，可以但字符解码
            dp[i + 1] = dp[i];
        }
        int twoDigit = stoi(str.substr(i - 1, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i + 1] += dp[i - 1];
        }
    }

    print_vec(dp);


    return 0;
}