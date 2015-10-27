#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXB    101
#define MAXW    300

int m, d;
int ptrToParent = 0;
int rabbit[MAXB][MAXW];
int ans[MAXW];

void print() {
    int carry = 0;
    for (int i = MAXW - 1; i >= 0; i--) {
        ans[i] = carry;
        for (int j = 1; j <= d; j++) {
            ans[i] = ans[i] + rabbit[j][i];
        }
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
    int k = 0;
    while (k < MAXW && ans[k] == 0) k++;
    while (k < MAXW) {
        printf("%d", ans[k++]);
    }
    printf("\n");
}

void init() {
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < MAXW; j++) {
            rabbit[i][j] = 0;
        }
    }
    for (int i = 0; i < MAXW; i++) ans[i] = 0;
    rabbit[d][MAXW-1] = 1;
    ptrToParent = d;
}

void calculate() {
    int cur = ptrToParent - 1;
    if (cur == 0) cur = d;
    int carry = 0;
    for (int i = MAXW-1; i >= 0; i--) {
        rabbit[cur][i] = rabbit[cur][i] + rabbit[ptrToParent][i] + carry;
        carry = rabbit[cur][i] / 10;
        rabbit[cur][i] %= 10;
    }
    ptrToParent = cur;
}

void solve() {
    init();
    for (int i = 0; i < m; i++) {
        calculate();
    }
    print();
}

int main() {
    while (cin >> d >> m) {
        if (m == 0 && 0 == d)
            break;
        solve();
    }
    return 0;
}
