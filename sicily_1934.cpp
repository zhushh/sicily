// Problem#: 1934
// Submission#: 3186028
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

struct node {
    int left, right;
} table[500005];

int main() {
    int t, n, m;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> m;
        table[0].right = 1;
        for (int i = 1; i < n +1; i++) {
            table[i].left = i - 1;
            table[i].right = i + 1;
        }
        int command, x, y;
        for (int i = 0; i < m; i++) {
            cin >> command >> x >> y;
            if (command == 1 && table[x].right == y)
                continue;
            else if (command == 2 && table[x].left == y)
                continue;
            else if (command == 1) {
                int x_left, x_right;
                int y_left;
                x_left = table[x].left;
                x_right = table[x].right;
                y_left = table[y].left;

                table[x_left].right = x_right;
                table[x_right].left = x_left;
                table[x].left = y_left;
                table[y_left].right = x;
                table[x].right = y;
                table[y].left = x;
            } else if (command == 2) {
                int x_left, x_right;
                int y_right;
                x_left = table[x].left;
                x_right = table[x].right;
                y_right = table[y].right;

                table[x_left].right = x_right;
                table[x_right].left = x_left;
                table[x].right = y_right;
                table[y_right].left = x;
                table[x].left = y;
                table[y].right = x;
            }
        }
        for (int i = 0, j = 0; j < n; j++) {
            i = table[i].right;
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
