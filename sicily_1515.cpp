// http://soj.sysu.edu.cn/1515

#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct {
    int x;
    int y;
    string op;
} State;

// 8! = 40320
int factor[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
bool visited[40500];

State opA(const State &cur) {
    State t = cur;
    t.x = cur.y;
    t.y = cur.x;
    t.op.push_back('A');
    return t;
}

State opB(const State &cur) {
    State t = cur;
    t.x = (cur.x % 1000) * 10 + cur.x / 1000;
    t.y = (cur.y % 1000) * 10 + cur.y / 1000;
    t.op.push_back('B');
    return t;
}

State opC(const State &cur) {
    State t = cur;
    t.x = (cur.x / 1000) * 1000;            // 千位不变
    t.x += ((cur.x % 100) / 10) * 100;
    t.x += ((cur.y % 100) / 10) * 10;
    t.x += cur.x % 10;                      // 个位不变
    t.y = (cur.y / 1000) * 1000;            // 千位不变
    t.y += ((cur.x % 1000) / 100) * 100;
    t.y += ((cur.y % 1000) / 100) * 10;
    t.y += cur.y % 10;                      // 个位不变
    t.op.push_back('C');
    return t;
}

int cantor(int n) {
    int a[8];
    int count;
    for (int i = 7; i >= 0; i--) {
        a[i] = n%10;
        n /= 10;
    }

    // Cantor expansion:
    // X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!
    // 其中a[i]为当前未出现的元素中是排在第几个(从0开始).
    for (int i = 0; i < 7; i++) {
        count = 0;
        for (int j = i+1; j < 8; j++) {
            if (a[i] > a[j]) count++;
        }
        n += count * factor[7-i];
    }
    return n;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        memset(visited, false, sizeof(visited));
        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> x2 >> x3 >> x4;
        cin >> y1 >> y2 >> y3 >> y4;
        State target;
        target.x = x1 * 1000 + x2 * 100 + x3 * 10 + x4;
        target.y = y1 * 1000 + y2 * 100 + y3 * 10 + y4;

        State cur = {1234, 5678, ""};
        queue<State> q;
        q.push(cur);
        visited[cantor(12345678)] = true;
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (cur.op.size() > n) {
                cout << -1 << endl;
                break;
            }

            if (cur.x == target.x && cur.y == target.y) {
                cout << cur.op.size() << " " << cur.op << endl;
                break;
            }

            State temp;
            for (int k = 0; k < 3; k++) {
                if (k == 0) temp = opA(cur);
                if (k == 1) temp = opB(cur);
                if (k == 2) temp = opC(cur);
                int index = cantor(temp.x*10000+temp.y);
                if (!visited[index]) {
                    q.push(temp);
                    visited[index] = true;
                }
            }
        }
    }
    return 0;
}
