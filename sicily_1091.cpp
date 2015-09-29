#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define N 50005
int nums[N];
int n;

typedef struct {
    int curMax;
    bool curUsed;
} Node;

Node sum1[N];
Node sum2[N];

int solve() {
    int curSum = nums[1];
    sum1[1].curMax = nums[1];
    sum1[1].curUsed = true;
    for (int i = 2; i < n; i++) {
        if (curSum < 0) {
            curSum = nums[i];
        } else {
            curSum = curSum + nums[i];
        }

        if (sum1[i-1].curMax < curSum) {
            sum1[i].curMax = curSum;
            sum1[i].curUsed = true;
        } else {
            sum1[i].curMax = sum1[i-1].curMax;
            sum1[i].curUsed = false;
        }
    }

    curSum = nums[n];
    sum2[n].curMax = nums[n];
    sum2[n].curUsed = true;
    for (int i = n-1; i > 1; i--) {
        if (curSum < 0) {
            curSum = nums[i];
        } else {
            curSum = curSum + nums[i];
        }

        if (sum2[i+1].curMax < curSum) {
            sum2[i].curMax = curSum;
            sum2[i].curUsed = true;
        } else {
            sum2[i].curMax = sum2[i+1].curMax;
            sum2[i].curUsed = false;
        }
    }

    int max_sum = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (sum1[i].curUsed) {
            max_sum = max(max_sum, sum1[i].curMax + sum2[i+1].curMax);
        } else {
            max_sum = max(max_sum, sum1[i].curMax + sum2[i].curMax);
        }
    }
    return max_sum;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
