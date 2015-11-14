#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define N 8

typedef struct _Node {
    int x, y;
    int nextCount;
    _Node(int _x=0, int _y=0, int c=0) : x(_x), y(_y), nextCount(c) {}
} Node;

bool visited[N+1][N+1];
int ansSeq[N*N];
int xx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int yy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool valid(int row, int col) {
    return (row >= 0 && row < N && col >= 1 && col <= N);
}

std::vector<Node> expandNext(int row, int col) {
    std::vector<Node> v;
    for (int i = 0; i < 8; i++) {
        if (valid(row+xx[i], col+yy[i]) && !visited[row+xx[i]][col+yy[i]]) {
            Node t(row+xx[i], col+yy[i], 0);
            for (int j = 0; j < 8; j++) {
                if (valid(t.x+xx[j], t.y+yy[j]))
                    t.nextCount++;
            }
            v.push_back(t);
        }
    }
    return v;
}

bool cmp(Node a, Node b) {
    return a.nextCount <= b.nextCount;
}

bool deepthSearch(int current, int steps) {
    if (steps == N*N) {
        return true;
    }
    int row = (current - 1) / N;
    int col = current - row * N;
    std::vector<Node> v = expandNext(row, col);
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        int tmp = v[i].x * N + v[i].y;
        if (!visited[v[i].x][v[i].y]) {
            visited[v[i].x][v[i].y] = true;
            if (deepthSearch(tmp, steps+1)) {
                ansSeq[steps] = tmp;
                return true;
            }
            visited[v[i].x][v[i].y] = false;
        }
    }
    return false;
}

int main() {
    int start;
    while (cin >> start) {
        if (start == -1) break;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                visited[i][j] = false;
            }
        }
        int row = (start - 1)/N;
        int col = start - row * N;
        visited[row][col] = true;
        if (deepthSearch(start, 1)) {
            ansSeq[0] = start;
            for (int i = 0; i < N*N - 1; i++) {
                cout << ansSeq[i] << " ";
            }
            cout << ansSeq[N*N-1] << endl;
        }
    }
    return 0;
}