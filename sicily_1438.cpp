#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int t, n, num;
    cin >> t;
    while (t-- > 0) {
        vector<int> a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);
        }
        sort(a.begin(), a.end(), cmp);
        int sum = 0;
        for (int i = 0; i < n; i++) if ((i+1)%3 == 0) {
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
