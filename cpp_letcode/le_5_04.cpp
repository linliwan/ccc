#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_2d_vec(const vector<vector<T>>& v){
    cout << "[";
    for(size_t i = 0; i < v.size(); i++) {
        cout << "[";
        for(size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j != v[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <typename T>
void print_vec(const vector<T> v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// 给定一个无重复数字的整数数组，求其所有的排列方式。
// 输入是一个一维整数数组，输出是一个二维数组，表示输入数组的所有排列方式。
// Input: [1,2,3]
// Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
// 可以以任意顺序输出，只要包含了所有排列方式即可

vector<int> nums = {1, 2, 3, 4};
int n = nums.size();
vector<vector<int>> result;

void backtrack(int start) {
    if(start == n - 1) {
        cout << "写入result: " << endl;
        result.push_back(nums);
        print_2d_vec(result);
        cout << endl;
        return;
    }
    for(int i = start; i < n; i++){
        cout << "当前nums: ";
        print_vec(nums);
        cout << "nums[" << i << "], nums[" << start << "]互换";
        swap(nums[i], nums[start]);
        print_vec(nums);
        backtrack(start + 1);
        cout << "nums[" << i << "], nums[" << start << "]互换back";
        swap(nums[i], nums[start]);
        print_vec(nums);
    }
}

int main() {
    backtrack(0);
    cout << "最终结果：" << endl;
    print_2d_vec(result);

    return 0;
}