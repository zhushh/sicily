// Problem#: 1293
// Submission#: 3296248
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

int count_len(int num) {
    if (num == 1) return 1;
    num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
    return 1 + count_len(num);
}

int main(void) {
    int maxLen, len;
    int min, max;
    scanf("%d%d", &min, &max);
    if (min > max) {
        min = min + max;
        max = min - max;
        min = min - max;
    }
    maxLen = count_len(min);
    while (min++ < max) {
        len = count_len(min);
        maxLen = maxLen < len ? len : maxLen;
    }
    printf("%d\n", maxLen);
    return 0;
}
