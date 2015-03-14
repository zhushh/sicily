#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100

char map[N][N];

int main() {
    char short_str[12];
    char logng_str[103];
    const char * end = "THEEND";
    while (scanf("%s", short_str)) {
        if (strcmp(short_str, end) == 0) break;
        scanf("%s", logng_str);
        int len1 = strlen(short_str);
        int len2 = strlen(logng_str);
        int raws = len2 / len1;
        int visited[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int k = 0;
        for (int i = 0; i < len1; i++) {
            int col = -1;
            for (int j = 0; j < len1; j++) if (!visited[j]) {
                if (col == -1) col = j;
                else if (short_str[col] > short_str[j]) {
                    visited[col] = 0; col = j;
                }
                visited[col] = 1;
            }
            for (int j = 0; j < raws; j++) {
                map[j][col] = logng_str[k++];
            }
        }
        for (int i = 0; i < raws; i++) {
            map[i][len1] = '\0';
            printf("%s", map[i]);
        }
        printf("\n");
    }
    return 0;
}
