// http://soj.sysu.edu.cn/1035
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

string change(string s) {
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') t.push_back('T');
        else if (s[i] == 'T') t.push_back('A');
        else if (s[i] == 'C') t.push_back('G');
        else if (s[i] == 'G') t.push_back('C');
    }
    return t;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        string DNA;
        map<string, int> src;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> DNA;
            if (src.find(DNA) != src.end()) {
                src[DNA]++;
            } else {
                src[DNA] = 1;
            }
        }
        int count = 0;
        map<string, int>::iterator st = src.begin();
        while (st != src.end()) {
            if (st->second > 0) {
                DNA = change(st->first);
                if (src.find(DNA) != src.end()) {
                    count += min(st->second, src[DNA]);
                    src[DNA] = 0;
                }
            }
            st++;
        }
        cout << count << endl;
    }
    return 0;
}
