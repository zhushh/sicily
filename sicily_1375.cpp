#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define N 50002

struct Cow {
    int x;
    int breed;
    Cow(int xx, int b) {
        x = xx;
        breed = b;
    }
};

bool cmp(Cow a, Cow b) {
    return a.x <= b.x;
}

int main() {
    int n;
    cin >> n;
    int b, x;
    vector<Cow> cows;
    for (int i = 0; i < n; i++) {
        cin >> b >> x;
        if (b == 0) {
            b = -1;
        }
        cows.push_back(Cow(x, b));
    }
    sort(cows.begin(), cows.end(), cmp);

    vector<int> sum(N, 0);
    sum[0] = cows[0].breed + N;
    for (int i = 1; i < n; i++) {
        sum[i] = cows[i].breed + sum[i-1];
    }

    int ans = 0;
    vector<int> sum_pos(2*N, 0);
    for (int i = 0; i < n; i++) {
        if (sum_pos[sum[i]] == 0) {
            sum_pos[sum[i]] = i;
        } else {
            ans = max(ans, cows[i].x - cows[sum_pos[sum[i]]+1].x);
        }
    }
    cout << ans << endl;

    return 0;
}
