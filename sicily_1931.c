#include <stdio.h>
int main() {
    int i, j, n, t, count = 0, num[100];
    scanf("%d", &t);
    for (j = 1; j <= t; j++) {
        scanf("%d", &n);
        for (i = 0; i < 99; i++) {
            num[i] = 0;
        }
        for (i = 1; i <= n; i++) {
            num[i] = i;
        }
        for (i = 1; num[i] != 0; i++) {
            if (i%2) printf("%d ", num[i]);
            else num[n+i/2] = num[i];
        }
        printf("\n");
    }
    return 0;
}
