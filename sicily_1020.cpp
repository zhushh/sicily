// http://soj.sysu.edu.cn/1020

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mod(string& s, int d) {
    int ans = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        ans = ans * 10 + s[i] - '0';
        ans %= d;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        string s;
        int n, num;
        vector<int> d;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            d.push_back(num);
        }
        cin >> s;
        cout << "(";
        for (int i = 0; i < n - 1; i++) {
            cout << mod(s, d[i]) << ",";
        }
        cout << mod(s, d[n-1]) << ")" << endl;
    }
    return 0;
}
