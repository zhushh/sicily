#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 200

int mapp[MAX][MAX];


int search(int a, int b, int sum, int n) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                mapp[j][i] = max(mapp[j][i], min(mapp[j][k], mapp[k][i]));
            }
        }
    }
    int count = 0;
    if (sum <= mapp[a - 1][b - 1]) {
        count = 1;
    } else {
        count = (sum / (mapp[a - 1][b - 1] - 1));
        if (sum % (mapp[a - 1][b - 1] - 1) != 0) {
            count++;
        }
    }
    return count;
}

int main(void)
{
    int t, n, m;
    cin >> t;
    while (t-- > 0)
    {
        int a, b, x;
        memset(mapp, 0, sizeof(mapp));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            mapp[a - 1][b - 1] = mapp[b - 1][a - 1] = x;
        }
        cin >> a >> b >> x;
        cout << search(a, b, x, n) << endl;
    }
    return 0;
}
