// Problem#: 1156
// Submission#: 3353176
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

typedef struct Node_ {
    int used;
    int count_pointer;
    char ch[2];
    int left;
    int right;
} Node;

Node data[1001];

void print(int root) {
    if (root == -1) return;
    printf("%s", data[root].ch);
    print(data[root].left);
    print(data[root].right);
}

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        int index, root;
        for (int i = 0; i < 1001; i++) {
            data[i].count_pointer = 0;
            data[i].used = 0;
            data[i].left = data[i].right = -1;
        }
        for (int i = 1; i < num + 1; i++) {
            scanf("%d", &index);
            data[index].used = 1;
            scanf("%s%d%d", &data[index].ch, &data[index].left, &data[index].right);
            data[data[index].left].count_pointer++;
            data[data[index].right].count_pointer++;
        }
        for (int i = 0; i < 1001; i++) {
            if (data[i].used && data[i].count_pointer == 0) {
                root = i;
                break;
            }
        }
        print(root);
        printf("\n");
    }
    return 0;
}
