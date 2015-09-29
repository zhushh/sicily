// Problem#: 1009
// Submission#: 2855772
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Time_limit_code for sicily_1009
#include <iostream>
#include <cmath>
using namespace std;

int arr[9] = {11, 23, 29, 37, 41, 43, 47, 53, 59};

bool isPrimer(int n) {
    int i = 2;
    while (i*i <= n) {
        if (n%i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

// output number format
void output(long long int num, int pw) {
    long long int n = num;

    for (long long int i = 2; i*i <= num; ++i) {
        if (num % i == 0) {
            cout << i << " * ";
            num /= i;
        }
    }

    cout << num << " = " << n << " = ( 2 ^ " << pw << " ) - 1" << endl;
}

int main() {
    long long int n, num;
    cin >> n;
    for (int i = 0; arr[i] <= n && i <= 8; ++i) {
        num = (long long int)(pow(2.0, arr[i])) - 1;
        output(num, arr[i]);
    }
    return 0;
}