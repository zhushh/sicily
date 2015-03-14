// Problem#: 1776
// Submission#: 3186374
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int isPrimer(int num) {
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int i, num;
        scanf("%d", &num);
        int divisor = 1;
        for (i = 2; i * i <= num; i++) {
            while (num % (i*i) == 0 && isPrimer(i)) {
                divisor *= i;
                num /= i;
            }
        }
        printf("%d\n", divisor);
    }
    return 0;
}
