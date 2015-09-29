// Problem#: 1007
// Submission#: 2971641
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;

int main() {
    int n /*, raw*/;
    string code, sentence;
    while (cin >> n && n) {
        cin >> code;
        // raw = code.length() / n;
        for (size_t i = 0; i < code.length(); i++) {
            for (int k = 0; k < n; i++, k++) {
                sentence.push_back(code[i]);
            }
            for (int k = n - 1; k >= 0 && (i+k) < code.length(); k--) {
                sentence.push_back(code[i+k]);
            }
            i += n - 1;
        }
        for (int i = 0; i < n; i++) {
            for (size_t j = i; j < sentence.length(); j += n) {
                cout << sentence[j];
            }
        }
        cout << "\n";
        sentence.clear();
    }
    return 0;
}