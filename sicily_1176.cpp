// http://soj.sysu.edu.cn/1176
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN_INT = -1000000;
const int N = 1002;
int a[N][N];

int solve(vector<int> &v, int st, int ed) {
    if (st+1 >= ed) return 0;
    if (st+2 == ed) return a[st][ed] = max(v[st] - v[st+1], v[st+1] - v[st]);
    if (a[st][ed] != MIN_INT) return a[st][ed];

    int temp = 0;
    // first select v[st]
    if (v[st+1] >= v[ed-1]) {
        temp = v[st] - v[st+1] + solve(v, st+2, ed);
    } else {
        temp = v[st] - v[ed-1] + solve(v, st+1, ed-1);
    }
    // first select v[ed-1]
    if (v[st] >= v[ed-2]) {
        temp = max(v[ed-1] - v[st] + solve(v, st+1, ed-1), temp);
    } else {
        temp = max(v[ed-1] - v[ed-2] + solve(v, st, ed-2), temp);
    }
    return a[st][ed] = temp;
}

int main() {
    int n;
    int count = 1;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> nums;
        int m;
        for (int i = 0; i < n; i++) {
            cin >> m;
            nums.push_back(m);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = MIN_INT;
            }
        }
        int ans = solve(nums, 0, nums.size());
        cout << "In game " << count++ << ", the greedy strategy might lose by as many as " << ans << " points." << endl;
    }
    return 0;
}
