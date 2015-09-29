// Problem#: 1001
// Submission#: 2941321
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char str[4096];

int main() {
    int i;
    while (scanf("%s", str) && str[0] != '0') {
        int childCount = 0, temp, count = 1;
        for (i = strlen(str) - 1; i >= 0; i--) {
            if (str[i] > '2' || (str[i] == '2' && (i < strlen(str) - 1) && str[i+1] > '6')) {
                childCount = count;
            } else if (str[i] == '0') {
                childCount = 0;
                i--;
            } else {
                temp = count;
                count = childCount + count;
                childCount = temp;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
