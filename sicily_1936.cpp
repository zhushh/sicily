#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

struct Position {
    int x, y;
    int steps;
    Position(int x_ = 0, int y_ = 0, int steps_ = 0) {
        x = x_; y = y_; steps = steps_;
    }
};

int map[8][8];
queue<struct Position> path;
int toward[8][8] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

void getPosition(struct Position& p, char * pos) {
    p.x = pos[0] - 'a';
    p.y = pos[1] - '1';
    p.steps = 0;
}

void search(int a, int b, struct Position& pos) {
    if ((pos.x + a >= 0 && pos.x + a < 8)
        && (pos.y + b >= 0 && pos.y + b < 8)
        && (map[pos.x+a][pos.y+b] == 0)) {
        map[pos.x+a][pos.y+b] = 1;
        path.push(Position (pos.x+a, pos.y+b, pos.steps+1));
    }
}

int bfs(struct Position& start, struct Position& end) {
    path.push(start);
    while (!path.empty()) {
        start = path.front();
        if (start.x == end.x && start.y == end.y) break;
        for (int i = 0; i < 8; i++) {
            search(toward[i][0], toward[i][1], start);
        }
        path.pop();
    }
    return start.steps;
}

int main() {
    int t, sum;
    char s[3], e[3];
    scanf("%d", &t);
    while (t-- > 0) {
        memset(map, 0, sizeof(map));
        scanf("%s %s", s, e);
        struct Position st, et;
        getPosition(st, s);
        getPosition(et, e);
        sum = bfs(st, et);
        printf("To get from %s to %s takes %d knight moves.\n", s, e, sum);
        while (!path.empty()) path.pop();
    }
    return 0;
}
