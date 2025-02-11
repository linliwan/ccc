// CCC '22 J5 - Square Pool
// Canadian Computing Competition: 2022 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc22j5

// 此解法能拿到 15 分，为deepseek在v3基础上改进的算法
// 为了优化原代码在处理100棵树时的性能问题，我们采用以下改进措施：
//     预处理树的位置：使用两个映射（row_map和col_map）分别按行和列存储树的位置，便于快速查询。
//     间隙检查优化：对于每个可能的正方形边长，检查行或列区间内的最大间隙，而不是逐个遍历所有可能的位置。

// 说白了，就是保留算树木间距、数据与边界间距的逻辑不变，然后把之前暴力破解的部分，改为更加智能的判断逻辑

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
    vector<DistanceInfo> distances;

    map<int, vector<int>> row_map, col_map;

    for (int i = 0; i < t; ++i) {
        int r, c;
        cin >> r >> c;
        trees.push_back({r, c});
        row_map[r].push_back(c);
        col_map[c].push_back(r);
    }

    // 对每行和每列的坐标进行排序
    for (auto& entry : row_map) {
        sort(entry.second.begin(), entry.second.end());
    }
    for (auto& entry : col_map) {
        sort(entry.second.begin(), entry.second.end());
    }

    // 处理树与树之间的行、列间距
    for (int i = 0; i < t; ++i) {
        for (int j = i + 1; j < t; ++j) {
            Tree a = trees[i], b = trees[j];
            if (a.r != b.r) {
                int delta = abs(a.r - b.r) - 1;
                if (a.r > b.r) swap(a, b);
                distances.push_back({delta, "r", a, b});
            }
            if (a.c != b.c) {
                int delta = abs(a.c - b.c) - 1;
                if (a.c > b.c) swap(a, b);
                distances.push_back({delta, "c", a, b});
            }
        }
        // 处理边界情况
        Tree curr = trees[i];
        // 上边界到当前树的行间距
        distances.push_back({curr.r - 1, "r", {0, 0}, curr});
        // 下边界到当前树的行间距
        distances.push_back({n - curr.r, "r", curr, {n+1, n+1}});
        // 左边界到当前树的列间距
        distances.push_back({curr.c - 1, "c", {0, 0}, curr});
        // 右边界到当前树的列间距
        distances.push_back({n - curr.c, "c", curr, {n+1, n+1}});
    }

    sort(distances.begin(), distances.end(), compare);

    // 检查每个可能的distance
    for (const auto& elem : distances) {
        int d = elem.distance;

        if (elem.direction == "r") {
            int r_start = elem.t1.r + 1;
            int r_end = elem.t2.r - 1;

            vector<int> cols;
            auto it_low = row_map.lower_bound(r_start);
            auto it_high = row_map.upper_bound(r_end);
            for (auto it = it_low; it != it_high; ++it) {
                cols.insert(cols.end(), it->second.begin(), it->second.end());
            }
            sort(cols.begin(), cols.end());
            vector<int> sorted = {0};
            sorted.insert(sorted.end(), cols.begin(), cols.end());
            sorted.push_back(n+1);

            int max_gap = 0;
            for (size_t i = 1; i < sorted.size(); ++i) {
                max_gap = max(max_gap, sorted[i] - sorted[i-1] - 1);
            }
            if (max_gap >= d) {
                cout << d << endl;
                return 0;
            }
        } else { // direction == "c"
            int c_start = elem.t1.c + 1;
            int c_end = elem.t2.c - 1;

            vector<int> rows;
            auto it_low = col_map.lower_bound(c_start);
            auto it_high = col_map.upper_bound(c_end);
            for (auto it = it_low; it != it_high; ++it) {
                rows.insert(rows.end(), it->second.begin(), it->second.end());
            }
            sort(rows.begin(), rows.end());
            vector<int> sorted = {0};
            sorted.insert(sorted.end(), rows.begin(), rows.end());
            sorted.push_back(n+1);

            int max_gap = 0;
            for (size_t i = 1; i < sorted.size(); ++i) {
                max_gap = max(max_gap, sorted[i] - sorted[i-1] - 1);
            }
            if (max_gap >= d) {
                cout << d << endl;
                return 0;
            }
        }
    }

    return 0;
}