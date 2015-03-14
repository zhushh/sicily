// Problem#: 1509
// Submission#: 3186219
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> seq;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int num;
        vector<int> temp;
        while (cin >> num && num != 0) {
            temp.push_back(num);
            for (int i = 1; i < n; i++) {
                cin >> num;
                temp.push_back(num);
            }
            int k = 1;
            for (int i = 0; i < n;) {
                if (temp[i] == k) {
                    k++;
                    i++;
                } else if (seq.empty()) {
                    seq.push(k);
                    k++;
                } else if (seq.top() == temp[i]) {
                    seq.pop();
                    i++;
                } else if (k < n + 1) {
                    seq.push(k);
                    k++;
                } else {
                    break;
                }
            }
            if (!seq.empty()) {
                cout << "No" << endl;
                while (!seq.empty()) seq.pop();
            } else {
                cout << "Yes" << endl;
            }
            temp.clear();
        }
        cout << endl;
    }
    return 0;
}
