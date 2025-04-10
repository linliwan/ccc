// Canadian Computing Competition: 2015 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc15j5

// 这是一个动态规划思想 + 递归实现的例子
// 动态规划：
// 题目其实只关心分配方案，并不关心在某个方案中，饼多的那个分给了谁，这就好办了，也就是说分配方案与具体的人无关

// 根据题意，为了接下来能够尽可能遍历到所有的分配方案，我们把分配规则写的更程式化一些：
//    当n <= k 时（饼少人多），只有 1 种方案
//    当n > k 时（饼多人少），定分配规则：后面的人得到的饼的数量 必须>= 前一个人得到的饼的数量，这样就可以确保算方案的唯一性；

#include <bits/stdc++.h>
using namespace std;


// ******缓存******
// 缓存负责记录   < <饼数, 人数, 最小值>, 结果 >  之间的映射，就是说如果dp(100, 30, 1)以前计算过，就会记录在缓存中，这样第二次调dp(100, 30, 1)时，就直接从缓存取结果了
// <饼数, 人数, 最小值>里面有三个值，没法用pair<int, int>存，只能改成更大的tuple
map<tuple<int, int, int>, int> memo;


int dp(int pie_left, int people_left, int min_value) {

    // 当只有一个人时，所有饼干都归他
    if(people_left == 1) {
        return 1;
    }
    // 当只剩下一块饼干时，就只有一种分配方案了
    if(pie_left == 1) {
        return 1;
    }


    // ******查找缓存******
    auto key = make_tuple(pie_left, people_left, min_value);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }


    int count = 0;

    // 状态转移
    // 假设目前正在 dp(100块饼, 30个人, 1) ，那么只需要看第一个人拿 1、2、3 块饼的情况，分别是dp(99, 29, 1) + dp(98, 29, 2) + dp(97, 29, 3)
    // 因为如果第一个人拿4块饼，后面就必然有人拿到的饼小于4，这就违反了我们定的 “分配规则”
    for(int i = min_value; i <= pie_left / people_left; i++) {
        count += dp(pie_left - i, people_left -1, i);
    }

    // ******写入缓存******
    memo[key] = count;

    return count;
}

int main(){
    int n;   // pie
    int k;   // people

    cin >> n;
    cin >> k;
    int result;
    if(n <= k) {
        result = 1;   // 饼少人多，只有 1 种方案
    } else {
        result = dp(n, k, 1);
    }

    cout << result << endl;
    return 0;
}