// Canadian Computing Competition: 2016 Stage 1, Junior #5, Senior #2
// https://dmoj.ca/problem/ccc16s2

#include <bits/stdc++.h>
using namespace std;

int main(){
    int question;
    int n;
    vector<int> dmojistan;
    vector<int> pegland;
    int temp;
    cin >> question;
    cin >> n;

    //这里用for循环来接数据更好一些，不需要先转成string，然后再转成一个个int
    for(int i =0; i < n; i++) {
        cin >> temp;
        dmojistan.push_back(temp);
    }
    for(int i =0; i < n; i++) {
        cin >> temp;
        pegland.push_back(temp);
    }

    int total = 0;

    sort(dmojistan.begin(), dmojistan.end());
    sort(pegland.begin(), pegland.end());

    //如果是问题1，两个列表都从小到大排序，最快的和最快的搭档，最慢的和最慢的搭档
    if (question == 1){
        for (int i = 0; i < n; i++){
            total += max(dmojistan[i], pegland[i]);
        }
    } else {
        // 如果是问题2，就把其中一个vector顺序倒过来，这样就可以确保每个pair都是一个最快的带一个最慢的
        reverse(pegland.begin(), pegland.end());
        for (int i = 0; i < n; i++){
            total += max(dmojistan[i], pegland[i]);
        }
    }

    cout << total << endl;
}