// http://soj.sysu.edu.cn/1050

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

long long Max, goal;

bool dfs(vector<long long> nums, long long temp) {
    nums.push_back(temp);   // reduce the vector copy
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == goal) {
            return true;
        } else if (nums[i] < goal && nums[i] > Max) {
            Max = nums[i];
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            vector<long long> cur;
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    cur.push_back(nums[k]);
                }
            }

            // select operator to compute
            if (dfs(cur, nums[i] + nums[j])) return true;
            if (dfs(cur, nums[i] - nums[j])) return true;
            if (dfs(cur, nums[j] - nums[i])) return true;
            if (dfs(cur, nums[i] * nums[j])) return true;
            if (nums[i] != 0 && nums[j] != 0) {
                if (max(nums[i], nums[j]) % min(nums[i], nums[j]) == 0) {
                    if (dfs(cur, max(nums[i], nums[j])/min(nums[i], nums[j])))
                        return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        vector<long long> nums(4);
        for (int i = 0; i < 4; i++) {
            scanf("%d", &nums[i]);
        }
        int temp;
        scanf("%d", &temp);
        scanf("%d", &goal);

        Max = INT_MIN;
        if (dfs(nums, temp)) {
            cout << goal << endl;
        } else {
            cout << Max << endl;
        }
    }
    return 0;
}
