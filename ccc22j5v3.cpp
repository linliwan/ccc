// CCC '22 J5 - Square Pool
// Canadian Computing Competition: 2022 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc22j5

// 此解法能拿到 12 分，实现方式上已经完全抛弃v1和v2的dp算法
// 考虑到最终的答案是与树之间的间距有关的，所以这个解法改为以树为核心，将所有树与树之间的距离以及树与边界之间的距离算出来，从大到小排序
// 排序的结构中除了记录下树木之间、树与边界的空隙（distance），还同时记录方向信息，即distance是由于两棵树在行上的间距产生的，还是在列上的间距产生的
// 同时，也会记录两棵树的坐标，数值小的树t1在前，数值大的树t2在后

// 接着就是暴力破解了，例如t1和t2两棵树在行（r）方向上产生了间距，那么就在这两行的所有列上尝试找到一个没有树的区间
// 还有三分没有拿到，是当有100棵的时候，出现了tle，应该是暴力破解导致的，看来还是要改进

#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int r, c;
};

struct DistanceInfo {
    int distance;
    string direction;
    Tree t1;
    Tree t2;
};

bool compare(const DistanceInfo& a, const DistanceInfo& b) {
    return a.distance > b.distance; // 降序排序
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<Tree> trees;
    vector<DistanceInfo> distance;

    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        trees.push_back({r, c});
    }

    // 定义边界上的树，以便处理每棵树到四条边界的距离
    Tree side_up_left = {0, 0};
    Tree side_down_right = {n+1, n+1};

    // 处理树之间的行和列距离
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            int delta_r = trees[i].r - trees[j].r;
            int delta_c = trees[i].c - trees[j].c;
            if (delta_r != 0) {
                int dist = abs(delta_r);
                string dir = "r";
                (delta_r > 0) ? distance.push_back({dist - 1, dir, trees[j], trees[i]}) : distance.push_back({dist - 1, dir, trees[i], trees[j]});
            }
            if (delta_c != 0) {
                int dist = abs(delta_c);
                string dir = "c";
                (delta_c > 0) ? distance.push_back({dist - 1, dir, trees[j], trees[i]}) : distance.push_back({dist - 1, dir, trees[i], trees[j]});
            }
        }
        // 到上边界的行距离
        distance.push_back({trees[i].r - 1, "r", side_up_left, trees[i]});
        // 到下边界的行距离
        distance.push_back({n - trees[i].r, "r", trees[i], side_down_right});
        // 到左边界的列距离
        distance.push_back({trees[i].c - 1, "c", side_up_left, trees[i]});
        // 到右边界的列距离
        distance.push_back({n - trees[i].c, "c", trees[i], side_down_right});
    }

    // 按距离降序排序
    sort(distance.begin(), distance.end(), compare);

    // 逐个检查最大可能的正方形
    for (auto& elem : distance) {
        if (elem.direction == "r") {
            // 遍历所有可能的列起始位置
            for (int j = 1; j <= n + 1 - elem.distance; j++) {
                bool valid = true;
                for (auto& tree : trees) {
                    if (tree.r > elem.t1.r && tree.r < elem.t2.r && tree.c > j - 1 && tree.c < j + elem.distance + 1) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    // cout << elem.distance << " " << elem.t1.r << " " << elem.t1.c << " | " << elem.t2.r << " " << elem.t2.c  << endl;
                    cout << elem.distance << endl;
                    return 0;
                }
            }
        } else { // direction == "c"
            // 遍历所有可能的行起始位置
            for (int i = 1; i <= n + 1 - elem.distance; i++) {
                bool valid = true;
                for (auto& tree : trees) {
                    if (tree.c > elem.t1.c && tree.c < elem.t2.c && tree.r > i - 1 && tree.r < i + elem.distance + 1) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    // cout << elem.distance << " " << elem.t1.r << " " << elem.t1.c << " | " << elem.t2.r << " " << elem.t2.c  << endl;
                    cout << elem.distance << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}