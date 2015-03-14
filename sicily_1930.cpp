#include <cstdio>
#include <cstdlib>

int main() {
    int *arr;
    int t, n, sum;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d", &n);
        arr = (int*)malloc(sizeof(int) * (n+1));
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
        }
        sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[index] > arr[j]) {
                    sum++;
                    index = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
        printf("%d\n", sum);
        free(arr);
    }
    return 0;
}
