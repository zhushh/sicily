// http://soj.sysu.edu.cn/1172

#include <iostream>
using namespace std;

#define MAXN    1005

enum Chess {
    Knight, Queen, Pawn, Empty, Counted
};

typedef struct {
    int x, y;
    Chess t;
} Record;

int n, m;
int chessNum[3];
Chess chessMap[MAXN][MAXN];
Record chess[MAXN];

Chess types[3] = {Queen, Knight, Pawn};

int queenTo[][2] = {
    {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
    {0, 1}, {1, 1}, {1, 0}, {1, -1}
};

int knightTo[][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            chessMap[i][j] = Empty;
        }
    }
}

void input() {
    int cur = 0;
    int x, y;
    for (int i = 0; i < 3; i++) {
        cin >> chessNum[i];
        for (int j = 0; j < chessNum[i]; j++) {
            cin >> x >> y;
            chessMap[x][y] = types[i];
            chess[cur++] = (Record){x,y,types[i]};
        }
    }
}

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int calculate() {
    int sumChess = chessNum[0] + chessNum[1] + chessNum[2];
    int ans = n * m - sumChess;   // sum squares
    for (int i = 0; i < sumChess; i++) {
        if (chess[i].t == Queen || chess[i].t == Knight) {
            for (int k = 0; k < 8; k++) {
                int x = chess[i].x;
                int y = chess[i].y;
                do {
                    x += (chess[i].t == Knight? knightTo[k][0]:queenTo[k][0]);
                    y += (chess[i].t == Knight? knightTo[k][1]:queenTo[k][1]);
                    if (valid(x, y) && (chessMap[x][y] == Empty || chessMap[x][y] == Counted)) {
                        if (chessMap[x][y] == Empty) {
                            ans--;
                            chessMap[x][y] = Counted;
                        }
                        // chessMap[x][y] = Pawn;
                    } else {
                        break;
                    }
                    if (chess[i].t == Knight) break;
                } while (true);
            }
        }
    }
    return ans;
}

void solve(int t) {
    init();
    input();
    cout << "Board "<<t <<" has "<< calculate() <<" safe squares." << endl;
}

int main() {
    int count = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        solve(count++);
    }
    return 0;
}
