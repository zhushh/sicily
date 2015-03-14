// Problem#: 1561
// Submission#: 3185662
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int isPrimer(int num) {
    int i = 2;
    for (; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int i, count = 0;
    for (i = 2; count < n; i++) {
        if (isPrimer(i)) {
            count++;
            if (count == n) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}                                 