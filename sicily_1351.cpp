#include <iostream>
#include <vector>
using namespace std;

#define N 1000000
bool visited[N];

int main() {
    int n, c;
    while (cin >> c >> n) {
        int num;
        vector<int> arr;
        for (int i = 0; i < c; i++) visited[i] = false;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (arr.empty()) arr.push_back(num);
            else if (arr[arr.size() - 1] != num) arr.push_back(num);
        }
        vector<int> a;
        for (int i = arr.size() - 1; i >= 0; i--) if (!visited[arr[i]]) {
            visited[arr[i]] = true;
            a.push_back(arr[i]);
        }
        cout << a.size() << endl;
        for (int i = a.size() - 1; i > 0; i--) cout << a[i] << ' ';
        cout << a[0] << endl;
    }
    return 0;
}
