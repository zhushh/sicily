// http://soj.sysu.edu.cn/1024

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 10005

typedef struct _Road {
    int id;     // flag this road
    int to;     // the destination country
    int d;      // distance between the two cities
    _Road(int i=0, int t=0, int dd=0) : id(i), to(t), d(dd) {}
} Road;

bool roadId[N];

//  m   -- store the road information
//  cur -- the current city id
//  ans -- the max length
int dfs(vector< vector<Road> > &m, int cur) {
    int ans = 0;
    for (int i = 0; i < m[cur].size(); i++) if (!roadId[m[cur][i].id]) {
        roadId[m[cur][i].id] = true;
        int sum = m[cur][i].d + dfs(m, m[cur][i].to);
        ans = max(ans, sum);
        roadId[m[cur][i].id] = false;
    }
    return ans;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector< vector<Road> > mp(N);
        int x, y, d;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y >> d;
            mp[x].push_back(Road(i, y, d));
            mp[y].push_back(Road(i, x, d));
            roadId[i] = false;
        }

        cout << dfs(mp, k) << endl;
    }
    return 0;
}
