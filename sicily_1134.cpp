// http://soj.sysu.edu.cn/1134

#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
typedef struct 
{
    int has;
    int need;
} Student;
Student arr[10005];

bool cmp(const Student &a, const Student &b) {
    return a.need <= b.need;
}

int main() {
    while (cin >> n >> s) {
        if (n == 0) break;
        for (int i= 0; i < n; i++) {
            cin >> arr[i].has >> arr[i].need;
        }
        sort(arr, arr+n, cmp);

        bool succeed = true;
        for (int i = 0; i < n; i++) {
            if (arr[i].need <= s) {
                s += arr[i].has;
            } else {
                succeed = false;
                break;
            }
        }
        if (succeed) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
