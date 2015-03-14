/***********************************************************************
 *  > File Name: 1157_the_hardest_problem.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 05 Oct 2014 05:49:26 PM CST
***********************************************************************/

#include <stdio.h>

int main() {
    int n, max, i, num;
    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &max);
        for (i = 1; i < n; i++) {
            scanf("%d", &num);
            max = num > max ? num : max;
        }
        printf("%d\n", max);
    }
    return 0;
}

