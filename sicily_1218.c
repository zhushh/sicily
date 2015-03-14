// Problem#: 1218
// Submission#: 3320413
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int satisfy(int k, int m) {
    return !((m - k*(k+1))%(2*(k+1)));
}
int main() {
    int m, n, k;
    scanf("%d%d", &n, &m);
    m <<= 1;
    for (k = 1; k*k < m; ++k);
    for (; k >= 0; --k) {
        if (satisfy(k, m)) {
            int a = (m - k*(k+1)) / (2*(k+1));
            if (a > 0 && a+k <= n) printf("[%d,%d]\n", a, a+k);
        }
    }
    //if (m <= n) printf("[%d,%d]\n", m, m);
    return 0;
}
