#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

const int MAX = 205;

vector<int> p[MAX];
queue<int> q;
bool visited[MAX];
int N, M;

bool bfs() {
    memset(visited, false, sizeof(visited));
    q.push(0);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (t == N - 1) return true;
        for (int i = 0; i < p[t].size(); i++) {
            if (!visited[p[t][i]]) {
                q.push(p[t][i]);
                visited[p[t][i]] = true;
            }
        }
    }
    return false;
}

int main() {
    int a, b;
    while (scanf("%d", &N) && N != 0) {
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &a, &b);
            p[a].push_back(b);
        }
        if (bfs()) {
            printf("I can post the letter\n");
        } else {
            printf("I can't post the letter\n");
        }
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 0; i < N; i++) {
            p[i].clear();
        }
    }
    return 0;
}
